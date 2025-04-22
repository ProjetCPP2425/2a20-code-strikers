#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QList>
#include <QPrinter>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QDialog>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include "reservationmanager.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
, m_reservationManager(new ReservationManager(this)),
    smsSender(new SmsSender(
        "d451e0c6871e50231fc36066dd501381-697d944a-8b85-458e-bcae-48125a83c1d4",
        "+447491163443",
       this ))

{
    qDebug() << "🚀 Chargement de l'UI...";
    ui->setupUi(this);
    qDebug() << "✅ UI chargée !";
    // Initialisation - Adaptez les noms selon votre UI
    m_reservationManager->setSmsSender(smsSender);
    m_reservationManager->loadTournaments(ui->comboTournois);
    m_reservationManager->loadAvailableEquipment(ui->tableMaterielsDisponibles);
    ui->tableMaterielsDisponibles->hideColumn(0);
    ui->affichRES->setModel(M.afficherMateriels());
    ui->affichRES->hideColumn(0);
    connect(ui->AjouterRES, &QPushButton::clicked, this, &MainWindow::on_ajouterButton_clicked);
    ui->affichRES->setSelectionMode(QAbstractItemView::SingleSelection); // Sélection unique
    ui->affichRES->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->recherche, &QLineEdit::textChanged, this, &MainWindow::rechercheMaterielsAuto);
    ui->triTypeComboBox->addItem("Tous");
    ui->triTypeComboBox->addItem("Ballon");
    ui->triTypeComboBox->addItem("Terrain");
    ui->triTypeComboBox->addItem("Filet");
    ui->triTypeComboBox->addItem("Piquet");

    // Connexion du signal
    connect(ui->triTypeComboBox, &QComboBox::currentTextChanged,
            this, &MainWindow::on_triTypeComboBox_currentIndexChanged);
    ui->triEtatComboBox->addItem("Tous");
    ui->triEtatComboBox->addItem("Libre");
    ui->triEtatComboBox->addItem("Réservé");
    ui->triEtatComboBox->addItem("À réparer");

    // Connexion du signal
    connect(ui->triEtatComboBox, &QComboBox::currentTextChanged,
            this, &MainWindow::on_triEtatComboBox_currentIndexChanged);
    connect(ui->btnReserver, &QPushButton::clicked, this, &MainWindow::onReserverClicked);
    connect(ui->btnValider, &QPushButton::clicked, this, &MainWindow::onValiderReservation); // Adaptez le nom du bouton
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouterButton_clicked() {
    QString nom = ui->nomRES->text().trimmed();
    QString type = ui->typeComboBox->currentText();

    int quantite = ui->typeRES_2->text().toInt();
    QString etat = ui->etatComboBox->currentText();

    QString localisation = ui->localisationRES->text().trimmed();
    QDate DATE_AJOUT = ui->dateRES->date();

    // Contrôle de saisie pour le nom
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez entrer un nom.");
        return;
    }

    QRegularExpression regex("^[A-Za-zÀ-ÿ\\s]{2,30}$");
    if (!regex.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Nom invalide", "Le nom doit contenir uniquement des lettres et des espaces (2 à 30 caractères).");
        return;
    }

    // Création de l'objet seulement si le nom est valide
    Materiels nouveauMateriel;
    nouveauMateriel.setNom(nom);
    nouveauMateriel.setType(type);
    nouveauMateriel.setQuantite(quantite);
    nouveauMateriel.setEtat(etat);
    nouveauMateriel.setLocalisation(localisation);
    nouveauMateriel.setDATE_AJOUT(DATE_AJOUT);

    if (nouveauMateriel.ajouterMateriels()) {
        QMessageBox::information(this, "Succès", "Le matériel a été ajouté avec succès !");
        ui->affichRES->setModel(M.afficherMateriels());
        m_reservationManager->loadAvailableEquipment(ui->tableMaterielsDisponibles);
    } else {
        QMessageBox::critical(this, "Erreur", "Une erreur est survenue lors de l'ajout du matériel.");
    }
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->affichRES->setModel(M.afficherMateriels());
}


void MainWindow::on_pushButton_18_clicked()
{
    QModelIndexList selectedIndexes = ui->affichRES->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une ligne à modifier.");
        return;
    }
    int id = selectedIndexes.first().data().toInt();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment modifier ce matériel ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QString nom = ui->nomRES->text();
        QString type = ui->typeComboBox->currentText();

        int quantite =ui->typeRES_2->text().toInt();
        QString etat = ui->etatComboBox->currentText();

        QString localisation = ui->localisationRES->text();
        QDate dateAjout = ui->dateRES->date();
        if (M.modifierMateriels(id,nom, type, quantite, etat, localisation, dateAjout)) {
            QMessageBox::information(this, "Succès", "Les données ont été modifiées avec succès.");
            ui->affichRES->setModel(M.afficherMateriels());
            m_reservationManager->loadAvailableEquipment(ui->tableMaterielsDisponibles);
        } else {
            QMessageBox::warning(this, "Erreur", "La modification a échoué.");
        }
    } else {
        QMessageBox::information(this, "Annulé", "La modification a été annulée.");
    }
}


void MainWindow::on_affichRES_clicked(const QModelIndex &index)
{
    if (!index.isValid()) return;
    ui->affichRES->selectRow(index.row());

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->affichRES->model());
    if (!model) return;

    QString nom = model->data(model->index(index.row(), 1)).toString();
    QString type = model->data(model->index(index.row(), 2)).toString();
    int quantite = model->data(model->index(index.row(), 3)).toInt();
    QString etat = model->data(model->index(index.row(), 4)).toString();
    QString localisation = model->data(model->index(index.row(), 5)).toString();
    QDate dateAjout = model->data(model->index(index.row(), 6)).toDate();

    ui->nomRES->setText(nom);
    int indexType = ui->typeComboBox->findText(type);
    if (indexType != -1) {
        ui->typeComboBox->setCurrentIndex(indexType);
    }

    ui->typeRES_2->setText(QString::number(quantite));
    int indexEtat = ui->etatComboBox->findText(etat);
    if (indexEtat != -1) {
        ui->etatComboBox->setCurrentIndex(indexEtat);
    }

    ui->localisationRES->setText(localisation);
    ui->dateRES->setDate(dateAjout);

}


void MainWindow::on_pushButton_15_clicked()
{
    QModelIndexList selectedIndexes = ui->affichRES->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une ligne à supprimer.");
        return;
    }

    int id = selectedIndexes.first().data().toInt();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer ce matériel ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (M.supprimerMateriels( id)) {
            QMessageBox::information(this, "Succès", "Le matériel a été supprimé avec succès.");
            ui->affichRES->setModel(M.afficherMateriels());
            m_reservationManager->loadAvailableEquipment(ui->tableMaterielsDisponibles);
        } else {
            QMessageBox::warning(this, "Erreur", "La suppression a échoué.");
        }
    } else {
        QMessageBox::information(this, "Annulé", "La suppression a été annulée.");
    }

}
void MainWindow::rechercheMaterielsAuto(const QString &text)
{
    QString critere = ui->comboCritereRecherche->currentText(); // Récupère le critère sélectionné
    if (text.isEmpty()) {
        ui->affichRES->setModel(M.afficherMateriels()); // Tous les matériels
    } else {
        ui->affichRES->setModel(M.rechercherMaterielsParChamp(critere, text));
    }
}

void MainWindow::on_triTypeComboBox_currentIndexChanged(const QString &text)
{
    QSqlQueryModel* model = M.trierParType(text);
    if (model) {
        ui->affichRES->setModel(model);
    } else {
        qDebug() << "Erreur lors du tri par type";
    }
}
void MainWindow::on_triEtatComboBox_currentIndexChanged(const QString &text)
{
    QSqlQueryModel* model = M.trierParEtat(text);
    if (model) {
        ui->affichRES->setModel(model);
    } else {
        qDebug() << "Erreur lors du tri par état";
    }
}











void MainWindow::on_pdf_materiels_clicked()
{
    QTableView* tableView = ui->affichRES; // Votre tableView pour les matériels

    if (!tableView)
    {
        QMessageBox::critical(nullptr, "ERREUR", "Table view not found.");
        return;
    }

    QAbstractItemModel* model = tableView->model();

    if (!model)
    {
        QMessageBox::critical(nullptr, "ERREUR", "Model not found.");
        return;
    }

    int rowCount = model->rowCount();
    int columnCount = model->columnCount();

    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer PDF", "Materiels.pdf", "PDF files (*.pdf)");
    if (filePath.isEmpty())
    {
        return;
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    QTextDocument document;
    QTextCursor cursor(&document);
    QFile file("C:/Users/ASUS/Documents/aliQT/log.png");
    QString imageBase64;
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray imageData = file.readAll();
        QString base64Data = QString::fromLatin1(imageData.toBase64());
        imageBase64 = "data:image/png;base64," + base64Data;
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de charger l'image du logo.");
    }


    // Style CSS amélioré
    QString htmlContent = "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=UTF-8\">\n"
                          "<title>Liste des Matériels</title>\n"
                          "<style>"
                          "body { font-family: Arial, sans-serif; }"
                          "table {"
                          "   border-collapse: collapse;"
                          "   width: 100%;"
                          "   margin-top: 20px;"
                          "}"
                          "th, td {"
                          "   border: 1px solid #dddddd;"
                          "   text-align: left;"
                          "   padding: 8px;"
                          "}"
                          "th {"
                          "   background-color: #4CAF50;"
                          "   color: white;"
                          "   font-weight: bold;"
                          "}"
                          "tr:nth-child(even) {"
                          "   background-color: #f2f2f2;"
                          "}"
                          ".header {"
                          "   display: flex;"
                          "   justify-content: space-between;"
                          "   align-items: center;"
                          "   margin-bottom: 20px;"
                          "}"
                          ".logo {"
                          "   width: 80px;"
                          "   height: auto;"
                          "}"
                          ".title {"
                          "   color: #2E86C1;"
                          "   text-align: center;"
                          "   margin: 0;"
                          "}"
                          ".date {"
                          "   text-align: right;"
                          "   color: #7F8C8D;"
                          "   font-size: 12px;"
                          "}"
                          "</style>"
                          "</head>\n"
                          "<body>\n"
                          "<div class='header'>"
                          "<img src='" + imageBase64 + "' alt='Logo' class='logo'>"

                          "<div>"
                          "<h1 class='title'>Liste des Matériels</h1>"
                          "<p class='date'>Généré le: " + QDate::currentDate().toString("dd/MM/yyyy") + "</p>"
                                                                          "</div>"
                                                                          "</div>"
                                                                          "<table>\n";

    // En-têtes de colonnes
    htmlContent += "<thead><tr>";
    for (int column = 0; column < columnCount; column++) {
        if (!tableView->isColumnHidden(column)) {
            QString header = model->headerData(column, Qt::Horizontal).toString();
            htmlContent += QString("<th>%1</th>").arg(header);
        }
    }
    htmlContent += "</tr></thead>\n<tbody>";

    // Données des matériels
    for (int row = 0; row < rowCount; row++) {
        htmlContent += "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!tableView->isColumnHidden(column)) {
                QString data = model->data(model->index(row, column)).toString().simplified();
                // Mise en forme spéciale pour l'état
                if (model->headerData(column, Qt::Horizontal).toString() == "Etat") {
                    QString color = (data == "Réservé") ? "#E74C3C" : "#2ECC71";
                    data = QString("<span style='color:%1; font-weight:bold'>%2</span>").arg(color).arg(data);
                }
                htmlContent += QString("<td>%1</td>").arg((!data.isEmpty()) ? data : "&nbsp;");
            }
        }
        htmlContent += "</tr>\n";
    }

    htmlContent += "</tbody></table>\n"
                   "<div style='margin-top: 20px; text-align: right; font-size: 12px; color: #7F8C8D;'>"
                   "Total: " + QString::number(rowCount) + " matériels"
                                                 "</div>\n"
                                                 "</body>\n"
                                                 "</html>\n";

    // Insertion du HTML et impression
    cursor.insertHtml(htmlContent);

    // Ajustement de la taille du document
    document.setPageSize(printer.pageRect(QPrinter::Point).size());

    // Impression avec contrôle des erreurs
    document.print(&printer);
    QMessageBox::information(this, "Succès", "PDF généré avec succès:\n" + filePath);

}





void MainWindow::on_statbutton_clicked()
{
    // 1. Vérifier la connexion à la base de données
    QSqlDatabase db = Connection::getConnection();
    if (!db.isOpen()) {
        if (!db.open()) {
            QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données : " + db.lastError().text());
            return;
        }
    }

    // 2. Création du conteneur principal
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques des matériels");
    dialog->resize(800, 500);

    QTabWidget *tabWidget = new QTabWidget(dialog);

    // 3. Définition des statistiques à afficher
    struct StatInfo {
        QString title;
        QString field;
    };

    QList<StatInfo> stats = {
        {"Répartition par Type", "Type"},
        {"Répartition par État", "Etat"}
    };

    QStringList colors = {
        "#ff6f61", "#6b5b95", "#88b04b", "#f7cac9",
        "#92a8d1", "#955251", "#b565a7", "#009688",
        "#f4b400", "#607d8b"
    };

    // 4. Génération des graphiques
    for (const StatInfo &stat : stats)
    {
        QPieSeries *series = new QPieSeries();
        QSqlQuery query(db);

        QString queryString = QString("SELECT %1, COUNT(*) FROM materiels GROUP BY %1").arg(stat.field);

        if (query.exec(queryString)) {
            int total = 0;
            QMap<QString, int> data;

            // Récupération des données
            while (query.next()) {
                QString label = query.value(0).toString();
                int count = query.value(1).toInt();
                if (!label.isEmpty()) {
                    data[label] = count;
                    total += count;
                }
            }

            // Ajout des tranches avec pourcentages
            int colorIndex = 0;
            for (auto it = data.begin(); it != data.end(); ++it) {
                QString label = it.key();
                int count = it.value();
                double percentage = (double)count / total * 100.0;

                QPieSlice *slice = series->append(QString("%1 (%2%)").arg(label).arg(percentage, 0, 'f', 1), count);
                slice->setLabelVisible();
                slice->setLabelColor(Qt::black);
                slice->setBrush(QColor(colors[colorIndex % colors.size()]));
                colorIndex++;
            }

            // Création du graphique
            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle(stat.title);
            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignRight);

            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);

            // Ajout dans un onglet
            tabWidget->addTab(chartView, stat.title);
        }
    }

    // 5. Affichage de la boîte de dialogue
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(tabWidget);
    dialog->setLayout(layout);
    dialog->exec();
}

void MainWindow::onReserverClicked()
{
    if (ui->tabWidget) {
        ui->tabWidget->setCurrentIndex(1); // Utilisez l'index approprié
    }
}

void MainWindow::onValiderReservation()
{
    // 1. Récupérer la sélection actuelle
    QModelIndexList selected = ui->tableMaterielsDisponibles->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun matériel sélectionné");
        return;
    }

    // 2. Récupérer les données du matériel
    int row = selected.first().row();
    int equipmentId = ui->tableMaterielsDisponibles->model()->data(
                                                                ui->tableMaterielsDisponibles->model()->index(row, 0)).toInt();

    int quantity = ui->spinQuantite_3->value();
    int tournamentId = ui->comboTournois->currentData().toInt();

    // 3. Demander le numéro de téléphone
    bool ok;
    QString recipientPhone = QInputDialog::getText(
        this,
        "Notification SMS",
        "Entrez le numéro complet avec indicatif (+216XXXXXXXX):",
        QLineEdit::Normal,
        "+216", // Valeur par défaut
        &ok
        );

    // Validation stricte
    if (!ok || !recipientPhone.startsWith("+216") || recipientPhone.length() != 12) {
        QMessageBox::warning(this, "Erreur", "Format invalide. Exemple: +21626790445");
        return;
    }

    // 4. Effectuer la réservation
    if (m_reservationManager->makeReservation(tournamentId, equipmentId, quantity, recipientPhone)) {
        QMessageBox::information(this, "Succès", "Réservation confirmée avec notification SMS");
        m_reservationManager->loadAvailableEquipment(ui->tableMaterielsDisponibles);
        ui->affichRES->setModel(M.afficherMateriels()); // Rafraîchir le tableau principal

        ui->tabWidget->setCurrentIndex(0);

    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la réservation");
    }
}

void MainWindow::on_btnAnnulerReservation_clicked()
{
    // Code pour annuler la réservation et revenir à la page d'ajout
    if (ui->tabWidget) {
        ui->tabWidget->setCurrentIndex(0); // Retour à l'onglet d'ajout
    }
}






