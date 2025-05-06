#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "tournois.h"

#include <QApplication>
#include <QDate>
#include <QDateEdit>
#include <QDebug>
#include <QDesktopServices>
#include <QDir>
#include <QFileDialog>
#include <QIcon>
#include <QIntValidator>
#include <QMessageBox>
#include <QPalette>
#include <QPdfWriter>
#include <QPushButton>
#include <QStandardPaths>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSystemTrayIcon>
#include <QTextDocument>
#include <QTextStream>
#include <QTimer>
#include <QUrl>
#include <QVector>
#include <QStringList>
#include <QLayout>



using namespace qrcodegen;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    update(false),
    id_update(-1)
{
    ui->setupUi(this);

    // --- Connexion à la base de données ---
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("tournois"); // Remplace par ton nom de DSN ODBC réel
    db.setUserName("Montassar");               // Ton nom d'utilisateur
    db.setPassword("riahi123");

    if (db.open()) {
        qDebug() << "Connexion à la base de données réussie.";
    } else {
        qDebug() << "Échec de la connexion à la base de données : " << db.lastError().text();
    }

    // --- Charger les données du tournoi dans la table ---
    tournois tr;
    tr.readData(ui->tableView, db);

    // --- Icône de la barre d’état système ---
    m_trayIcon = new QSystemTrayIcon(this);
    if (QFile::exists(":/icons/notification.png")) {
        m_trayIcon->setIcon(QIcon(":/icons/notification.png"));
    } else {
        m_trayIcon->setIcon(QIcon::fromTheme("dialog-information"));
    }
    m_trayIcon->show();

    // --- Bouton pour vérifier les événements à venir ---
    QPushButton *checkEventsBtn = new QPushButton("Vérifier les événements à venir", this);
    checkEventsBtn->setObjectName("checkEventsButton");
    checkEventsBtn->setGeometry(10, 10, 250, 40);
    checkEventsBtn->setIcon(QIcon(":/icons/notification.png"));
    checkEventsBtn->setIconSize(QSize(20, 20));
    checkEventsBtn->setLayoutDirection(Qt::RightToLeft);
    checkEventsBtn->setStyleSheet(
        "QPushButton {"
        "    padding-right: 5px;"
        "    text-align: left;"
        "}");

    connect(checkEventsBtn, &QPushButton::clicked, this, &MainWindow::on_checktournoisButton_clicked);

    // --- Timer pour vérification périodique des événements ---
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::checkUpcomingtournoissEnd);
    timer->start(3600000); // toutes les heures

    // --- Vérification immédiate au démarrage ---
    checkUpcomingtournoissEnd();
}



MainWindow::~MainWindow()
{
    delete ui;  // ✅ Libère la mémoire pour éviter les fuites
}

void MainWindow::on_pushButton_13_clicked()
{
    // Fq    // F

    if(!update){
        tournois t(0,ui->nom->text(),
                   ui->lieu->text(),
                   ui->datedebut->date(),
                   ui->datefin->date());
        t.console();
        t.insertData(db);
        t.readData(ui->tableView,db);
    }else{
        update =false;
        tournois t(id_update,
                   ui->nom->text(),
                   ui->lieu->text(),
                   ui->datedebut->date(),
                   ui->datefin->date());
        t.updateData(ui->tableView,db);
        t.readData(ui->tableView,db);
        id_update=-1;
    }
}


void MainWindow::on_pushButton_14_clicked()
{
    int id =ui->id->text().toInt();
    ui->id->setText("");
    qDebug()<<id;
    tournois t;
    t.deleteData(id,ui->tableView,db);
}


void MainWindow::on_pushButton_15_clicked()
{
    id_update = ui->id->text().toInt();
    QSqlQuery query(db);

    // Prepare the SQL query
    query.prepare("SELECT * FROM MONTA WHERE ID = :ID");
    query.bindValue(":ID", id_update); // Bind the actual value

    if (query.exec()) {
        // Check if a result is found
        if (query.next()) {
            // Fetch data from the database
            QString nom = query.value("NOM").toString();
            QString lieu = query.value("LIEU").toString();
            QDate date_debut = query.value("DATE_DEBUT").toDate();
            QDate date_fin = query.value("DATE_FIN").toDate();

            // Set values in UI elements
            ui->nom->setText(nom);
            ui->lieu->setText(lieu);
            ui->datedebut->setDate(date_debut);  // Use setDate() for QDateEdit
            ui->datefin->setDate(date_fin);      // Use setDate() for QDateEdit
            update =true;
        } else {
            qDebug() << "No record found for ID:" << id_update;
        }
    } else {
        qDebug() << "Query execution failed:";
    }


}

void MainWindow::on_id_2_textChanged(const QString &arg1)
{
    if(arg1!="")
        ui->tableView->setModel(T.rechercherTournois(arg1));
    else
        ui->tableView->setModel(T.rechercherTournois(arg1));
}


void MainWindow::on_pushButton_2_clicked()
{

    tournois T;
    int index = ui->comboBox->currentIndex();
    if (index == 0){
        ui->tableView->setModel(T.tri_par_date_debut());
    }else if (index == 1){
        ui->tableView->setModel(T.tri_par_date_fin());
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();

    out << "<html>\n"
        << "<head>\n"
        << "<meta charset='utf-8'>\n"
        << QString("<title>%1</title>\n").arg("strTitle")
        << "</head>\n"
        << "<body bgcolor='#ffffff' link='#5000A0'>\n"
        << "<center><h1>Liste des tournois</h1><br><br>\n"
        << "<table border='1' cellspacing='0' cellpadding='2'>\n";

    // headers
    out << "<thead><tr bgcolor='#f0f0f0'><th>Numero</th>";
    for (int column = 0; column < columnCount; ++column) {
        if (!ui->tableView->isColumnHidden(column)) {
            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
        }
    }
    out << "</tr></thead>\n";

    // data rows
    for (int row = 0; row < rowCount; ++row) {
        out << "<tr><td>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; ++column) {
            if (!ui->tableView->isColumnHidden(column)) {
                QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                out << QString("<td>%1</td>").arg(data.isEmpty() ? "&nbsp;" : data);
            }
        }
        out << "</tr>\n";
    }

    out << "</table></center>\n"
        << "</body>\n"
        << "</html>\n";

    QString fileName = QFileDialog::getSaveFileName(nullptr, "Sauvegarder en PDF",
                                                    QDir::homePath() + "/C:/",
                                                    "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    if (QFileInfo(fileName).suffix().isEmpty())
        fileName.append(".pdf");

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    // Set paper size using QPageLayout (Qt 6 style)
    QPageLayout layout = printer.pageLayout();
    layout.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageLayout(layout);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);
}


void MainWindow::on_pushButton_25_clicked()
{
    tournois t;
    t.afficherDiagramme_tournois_Stat();
}





void MainWindow::on_tableView_activated(const QModelIndex &index)
{


    if (!index.isValid()) return;
    QString qrCodeData;

    int row = index.row();
    QString val = ui->tableView->model()->index(row, 0).data().toString();
    qDebug() << "ID sélectionné :" << val;

    QSqlQuery qry;
    qry.prepare("SELECT ID, NOM, LIEU, DATE_DEBUT, DATE_FIN FROM MONTA WHERE ID = :id");
    qry.bindValue(":id", val);  // Sécurité avec requête paramétrée

    if (qry.exec() && qry.next()) {
        ui->nom->setText(qry.value(0).toString());
        ui->lieu->setText(qry.value(1).toString());
        ui->datedebut->setDate(QDate::fromString(qry.value(2).toString(), "yyyy-MM-dd"));
        ui->datefin->setDate(QDate::fromString(qry.value(3).toString(), "yyyy-MM-dd"));


        qrCodeData = "ID : " + qry.value(0).toString() +
                     " | NOM : " + qry.value(1).toString() +
                     " | LIEU : " + qry.value(2).toString() +
                     " | DATE_DEBUT : " + qry.value(3).toString() +
                     " | DATE_FIN : " + qry.value(4).toString() + ";";




    } else {
        qDebug() << "Erreur SQL : " << qry.lastError().text();
    }
    //QR CODE
    using namespace qrcodegen;
    // Create the QR Code object
    QrCode qr = QrCode::encodeText( qrCodeData.toUtf8().data(), QrCode::Ecc::MEDIUM );
    // Obtenir la taille du QR Code
    qint32 sz = qr.getSize();
    // Créer une image avec la taille du QR Code
    QImage im(sz,sz, QImage::Format_RGB32);

    QRgb black = qRgb(  0,  0,  0);
    QRgb white = qRgb(255,255,255);
    for (int y = 0; y < sz; y++)
        for (int x = 0; x < sz; x++)
            im.setPixel(x,y,qr.getModule(x, y) ? black : white );
    // Afficher l'image du QR Code dans un QLabel
    ui->qrCodeLabel_2->setPixmap( QPixmap::fromImage(im.scaled(150,150,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );

}

// Vérifie les tournois qui se terminent demain
void MainWindow::checkUpcomingtournoissEnd()
{
    m_upcomingEventsEnd.clear(); // Effacer les notifications précédentes

    QDate today = QDate::currentDate();
    QDate tomorrow = today.addDays(1);

    QSqlQuery query;
    query.prepare("SELECT ID, NOM, LIEU, DATE_DEBUT, DATE_FIN FROM MONTA WHERE DATE_FIN = :tomorrow");
    query.bindValue(":tomorrow", tomorrow);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la vérification des tournois à venir:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString id = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString lieu = query.value(2).toString();
        QDate dateDebut = query.value(3).toDate();
        QDate dateFin = query.value(4).toDate();

        QString message = QString("⚠️ Le tournoi '%1' (ID: %2) se termine demain (%3)\n"
                                  "Lieu: %4\nDébuté le: %5")
                              .arg(nom)
                              .arg(id)
                              .arg(dateFin.toString("dd/MM/yyyy"))
                              .arg(lieu)
                              .arg(dateDebut.toString("dd/MM/yyyy"));

        // Notification dans la barre d'état système
        if (m_trayIcon && m_trayIcon->isVisible()) {
            m_trayIcon->showMessage(
                "Tournoi sur le point de se terminer",
                message,
                QSystemTrayIcon::Information,
                10000 // 10 secondes
                );
        }

        m_upcomingEventsEnd.append(message); // Stocker pour la consultation
    }

    updatetournoissButton();
}

// Met à jour le bouton de vérification (texte et style)
void MainWindow::updatetournoissButton()
{
    QPushButton *eventsBtn = findChild<QPushButton*>("checkEventsButton");
    if (!eventsBtn) return;

    if (m_upcomingEventsEnd.isEmpty()) {
        eventsBtn->setText("Vérifier les événements à venir");
        eventsBtn->setStyleSheet("");
    } else {
        eventsBtn->setText(QString("Événements à venir (%1)").arg(m_upcomingEventsEnd.size()));
        eventsBtn->setStyleSheet("background-color: #FFA500; font-weight: bold;");
    }
}

// Quand on clique manuellement sur "Vérifier les événements à venir"
void MainWindow::on_checktournoisButton_clicked()
{
    if (m_upcomingEventsEnd.isEmpty()) {
        QMessageBox::information(this, "Événements à venir", "Aucun tournoi ne se termine bientôt.");
        return;
    }

    QString fullMessage = "Tournois se terminant prochainement:\n\n" + m_upcomingEventsEnd.join("\n\n");
    QMessageBox msgBox;
    msgBox.setWindowTitle("Notifications de fin de tournoi");
    msgBox.setText(fullMessage);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}


