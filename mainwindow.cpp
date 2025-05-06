
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipe.h"
#include "pie.h"
#include "arduinoo.h"
#include "reservationmanager.h"
#include "qrcode.h"

#include <QApplication>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
#include <QRegularExpression>
#include <QFocusEvent>
#include <QProcess>
#include <QVBoxLayout>
#include <QDialog>
#include <QFileDialog>
#include <QList>
#include <QPrinter>
#include <QDate>
#include <QDateEdit>
#include <QDesktopServices>
#include <QDir>
#include <QIcon>
#include <QIntValidator>
#include <QPalette>
#include <QPdfWriter>
#include <QPushButton>
#include <QStandardPaths>
#include <QSystemTrayIcon>
#include <QTextDocument>
#include <QTextStream>
#include <QTimer>
#include <QUrl>
#include <QVector>
#include <QStringList>
#include <QLayout>
#include <QTableView>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlTableModel>

#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    update(false),saisi(true),
    selectedRow(-1),sort(5),v(0),
    ui(new Ui::MainWindow), matchesByDate(),
    m_reservationManager(new ReservationManager(this)),
    smsSender(new SmsSender(
        "d451e0c6871e50231fc36066dd501381-697d944a-8b85-458e-bcae-48125a83c1d4",
        "+447491163443",
        this ))

 // Remplace par ton vrai nom de comboBox


{





    ui->setupUi(this);
    connect(ui->tableView, SIGNAL(activated(QModelIndex)), this, SLOT(on_tableView_activated(QModelIndex)));
    // Ajout du QSortFilterProxyModel ici
    proxyModel = new QSortFilterProxyModel(this); // (déclaré dans le .h)
    proxyModel->setSourceModel(ui->tableView->model());
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);
    proxyModel->sort(1, Qt::AscendingOrder); // Colonne 1

    qDebug() << selectedRow;

    //styleSheet(um); // ← assure-toi que `um` est bien défini
    QString s = "ess";

    v = checkForMatch(true); // ← v doit être déclaré dans la classe
    showWindowsNotification(s);

    if (!v.empty()) {
        qDebug() << "v not empty";
        for (auto& equipe : v) {
            qDebug() << "Sending notification for: " << equipe;
            showWindowsNotification(equipe);
        }
    } else {
        qDebug() << "empty";
    }

    v = checkForMatch(false);
    for (const auto& equipe : v) {
        qDebug() << equipe;
    }

    shuffleTeams(v);
    qDebug() << "after shuffle";

    if (v.size() % 2 == 0) {
        for (const auto& equipe : v)
            qDebug() << equipe;
    } else {
        qDebug() << "need more teams for the tournaments";
    }

    displayOnCalendar();
    refreshPdf();
    setupSerial();


    QPixmap pix("C:/logo");
    ui->logo->setPixmap(pix);

    QWidget *um = ui->upper_menu;

   // connect(ui->email,&QTextEdit::editingFinished, this, &MainWindow::validateEmail);
    connect(ui->email_2, &QLineEdit::editingFinished, this, &MainWindow::onEditingFinished);
    connect(ui->nom_eq_2, &QLineEdit::editingFinished, this, &MainWindow::testNom);
    connect(ui->nb_vict_2, &QLineEdit::editingFinished, this, &MainWindow::testNBV);
    connect(ui->nb_def_2, &QLineEdit::editingFinished, this, &MainWindow::testNBD);
    connect(ui->nb_null_2, &QLineEdit::editingFinished, this, &MainWindow::testNBN);
    connect(ui->nb_pnt_2, &QLineEdit::editingFinished, this, &MainWindow::testNBP);
    connect(ui->entreneur_2, &QLineEdit::editingFinished, this, &MainWindow::testE);
    connect(ui->calendarWidget,&QCalendarWidget::clicked,this, [=](const QDate &date){
        if(matchesByDate.contains(date)){
            qDebug()<<"there is matches";
            QStringList matches;
            for(auto &match:matchesByDate[date]){
                matches<<match;
            }
            QString list=date.toString()+ "\n" + matches.join("\n");
            QMessageBox::information(this, "Matches", list);

        }else{
            qDebug()<<"there is no matches";
        }
    });

    ui->IdTextEdit->setVisible(false);



    //Setup database connection
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("tournois");
    db.setUserName("Montassar");
    db.setPassword("riahi123");

    if (db.open()) {
        qDebug() << "✅ Database connected successfully!";
    } else {
        qDebug() << "❌ Database connection failed: " << db.lastError().text();
    }

    equipe e;
    e.readData(ui->tableView,db);
    // Initialisation - Adaptez les noms selon votre UI
                           m_reservationManager->setSmsSender(smsSender);
    m_reservationManager->loadTournaments(ui->comboTournois);
    m_reservationManager->loadAvailableEquipment(ui->tableMaterielsDisponibles);
    ui->tableMaterielsDisponibles->hideColumn(0);
    ui->affichRES->setModel(M.afficherMateriels());
    ui->affichRES->hideColumn(0);
    connect(ui->AjouterRES, &QPushButton::clicked, this, &MainWindow::on_AjouterRES_clicked);
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

    connect(ui->btnValider, &QPushButton::clicked, this, &MainWindow::onValiderReservation); // Adaptez le nom du bouton

    // Connexion à Arduino
    int ret = A.connect_arduino();

    switch(ret){
    case (0):
        qDebug() << "Arduino connecté au port: " << A.getarduino_port_name();
        break;
    case (1):
        qDebug() << "Arduino détecté mais pas ouvert.";
        break;
    case (-1):
        qDebug() << "Arduino non disponible.";
    }
    // Dans MainWindow.cpp (après connect_arduino())
    if (ret == 0) {
        connect(A.getserial(), &QSerialPort::readyRead, this, &MainWindow::detecterBadge);
    } else {
        qDebug() << "Impossible de connecter le signal readyRead : Arduino non ouvert.";
    }

}




MainWindow::~MainWindow()
{
    if (db.isOpen()) {
        db.close();
        qDebug() << "🔌 Database connection closed.";
    }
    delete ui;
}


void MainWindow::styleSheet(QWidget *um){
    um->setStyleSheet(
        "background-color: black;"
        "color: white;"
        "QHeaderView::section {"
        "background-color: black;"
        "color: white;"
        "font-size: 16px;"
        "font-weight: bold;"
        "text-align: center;"
        "padding: 5px;"

        "}"

        "QTextEdit { background-color: black; color: white; }"

        );
    ui->
        tableView->setStyleSheet(
            "QTableView {"
            "    background-color: white;"  // Table background color
            "    color: #333333;"            // Text color (dark gray for readability)
            "    border: 1px solid #4A90E2;" // Border color (light blue)
            "    font-size: 14px;"           // Font size
            "    selection-background-color: #4A90E2;" // Selected row background (blue)
            "    selection-color: white;"    // Selected text color (white)
            "    alternate-background-color: #f7f7f7;" // Alternating row colors
            "    gridline-color: #e0e0e0;"  // Gridline color (light gray)
            "}"
            "QHeaderView::section {"
            "    background-color: #4A90E2;" // Header background color (blue)
            "    color: white;"              // Header text color (white)
            "    padding: 8px;"              // Padding for header cells
            "    font-weight: bold;"         // Bold header text
            "    text-align: center;"        // Center-align header text
            "}"
            "QScrollBar:vertical {"
            "    background-color: #f7f7f7;" // Scrollbar background color (lighter gray)
            "    border: none;"               // No border
            "    width: 10px;"                // Set the width of the vertical scrollbar
            "    margin: 0px 0px 0px 0px;"    // Margin around the scrollbar
            "    border-radius: 5px;"         // Rounded corners for the scrollbar itself
            "}"
            "QScrollBar::handle:vertical {"
            "    background-color: #4A90E2;" // Handle (slider) color (blue)
            "    min-height: 40px;"           // Minimum height for the handle
            "    border-radius: 6px;"         // Rounded corners for the handle
            "}"
            "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
            "    border: none;"               // Remove borders for the arrows
            "    background: none;"           // Remove background for the arrows
            "    width: 0px;"                 // Remove the width of the arrows
            "    height: 0px;"                // Remove the height of the arrows
            "}"
            "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
            "    background: none;"           // Remove the background color for the add/sub page
            "}"
            "QScrollBar:horizontal {"
            "    background-color: #f7f7f7;" // Horizontal scrollbar background color (lighter gray)
            "    border: none;"               // No border
            "    height: 10px;"               // Set the height of the horizontal scrollbar
            "    margin: 0px 0px 0px 0px;"    // Margin around the scrollbar
            "    border-radius: 5px;"         // Rounded corners for the scrollbar itself
            "}"
            "QScrollBar::handle:horizontal {"
            "    background-color: #4A90E2;" // Handle (slider) color (blue)
            "    min-width: 40px;"            // Minimum width for the handle
            "    border-radius: 6px;"         // Rounded corners for the handle
            "}"
            "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {"
            "    border: none;"               // Remove borders for the arrows
            "    background: none;"           // Remove background for the arrows
            "    width: 0px;"                 // Remove the width of the arrows
            "    height: 0px;"                // Remove the height of the arrows
            "}"
            "QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {"
            "    background: none;"           // Remove the background color for the add/sub page
            "}"

            );
    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #007BFF;"  // Blue
        "    color: white;"
        "    border-radius: 15px;"  // Rounded corners
        "    padding: 8px 15px;"  // Extra padding for better spacing
        "    font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #0056b3;"  // Darker blue on hover
        "}"
        );

    ui->pushButton_2->setStyleSheet(
        "QPushButton {"
        "    background-color: #28A745;"  // Green
        "    color: white;"
        "    border-radius: 15px;"  // Rounded corners
        "    padding: 8px 15px;"  // Extra padding
        "    font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #1e7e34;"  // Darker green on hover
        "}"
        );

    ui->pushButton_17->setStyleSheet(        "QPushButton {"
                                     "    background-color: #28A745;"  // Green
                                     "    color: white;"
                                     "    border-radius: 15px;"  // Rounded corners
                                     "    padding: 8px 15px;"  // Extra padding
                                     "    font-size: 14px;"
                                     "}"
                                     "QPushButton:hover {"
                                     "    background-color: #1e7e34;"  // Darker green on hover
                                     "}");

}
void MainWindow::on_pushButton_17_clicked()
{
    QDate date = ui->date_c->date();
    if(!update)
    {



        equipe eq(0,
                  ui->nom_eq_2->text(),
                  date,
                  ui->entreneur_2->text(),
                  ui->categorie_2->currentText(),
                  ui->nb_vict_2->text().toInt(),
                  ui->nb_def_2->text().toInt(),
                  ui->nb_null_2->text().toInt(),
                  ui->nb_pnt_2->text().toInt(),
                  ui->email_2->text()
                  );
        eq.console_equipe();
        if(saisi)
        {eq.insertData(db);}


        eq.readData(ui->tableView,db);
       ui->tableView->model()->sort(sort,Qt::AscendingOrder);
        if(eq.message){
            QMessageBox::warning(this,"erreur","nom equipe existe");
            qDebug()<<1;
        }
       // readAndOverwriteHtml("C:/gestion_equipe3/report.html");
        generatePDF();

    }else
    {
        update =false;
        equipe eq(ui->IdTextEdit->toPlainText().toInt(),
                  ui->nom_eq_2->text(),
                  date,
                  ui->entreneur_2->text(),
                  ui->categorie_2->currentText(),
                  ui->nb_vict_2->text().toInt(),
                  ui->nb_def_2->text().toInt(),
                  ui->nb_null_2->text().toInt(),
                  ui->nb_pnt_2->text().toInt(),
                  ui->email_2->text()
                  );
        if(saisi){eq.updateData(ui->IdTextEdit->toPlainText().toInt(),db);}

        eq.readData(ui->tableView,db);
        ui->tableView->model()->sort(sort,Qt::AscendingOrder);
        ui->delete_2->setStyleSheet("color : blue");
        if(eq.message){
            QMessageBox::warning(this,"erreur","nom equipe existe");
            qDebug()<<2;
        }
        displayOnCalendar();
        refreshPdf();
    }
    
    setData("","","","","","","",QDate::currentDate(),"","");

    if(dynamicHtmlTemplate("C:/gestion_equipe3/report.html","C:/gestion_equipe3/output.html")){
        qDebug()<<"dynamicHtmlTemplate :: true";
    }else{
        qDebug()<<"dynamicHtmlTemplate :: false";
    }
    generatePDF();
    selectedRow =-1;
}
void MainWindow::setData(QString a,QString b,QString c,QString d,QString e,QString f,QString g,QDate h,QString i,QString j){

    ui->IdTextEdit->setText(a);
    ui->nom_eq_2->setText(b);
    ui->entreneur_2->setText(c);
    ui->nb_vict_2->setText(d);
    ui->nb_def_2->setText(e);
    ui->nb_null_2->setText(g);
    ui->nb_pnt_2->setText(f);
    ui->date_c->setDate(h);
    ui->categorie_2->setCurrentText(i);
    ui->email_2->setText(j);
}





void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel *model = ui->tableView->model();

    // Cast the model to QSqlTableModel for better access to the specific model features
    int rowIndex = index.row();


    setData(model->data(model->index(rowIndex,0)).toString(),
            model->data(model->index(rowIndex,1)).toString(),
            model->data(model->index(rowIndex,2)).toString(),
            model->data(model->index(rowIndex,3)).toString(),
            model->data(model->index(rowIndex,4)).toString(),
            model->data(model->index(rowIndex,5)).toString(),
            model->data(model->index(rowIndex,6)).toString(),
            model->data(model->index(rowIndex,7)).toDate(),
            model->data(model->index(rowIndex,8)).toString(),
            model->data(model->index(rowIndex,9)).toString()
            );

    update =true;

    selectedRow = rowIndex;
    ui->delete_2->setStyleSheet("color: red;");
    qDebug()<<"fun double click : selected row"<<selectedRow;


    // Iterate through columns to get the data for the row

}


void MainWindow::onEditingFinished()
{
    qDebug() << "User finished typing!";
    QString text = ui->email_2->text();
    // Updated regex for email validation
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");

    if (!emailRegex.match(text).hasMatch()) {
        ui->email_err->setText("text@text.text");
        saisi = false;
    } else {
        saisi = true;
        ui->email_err->setText(""); // Clear error if valid
    }
}

void MainWindow::testNom(){

    QRegularExpression regex("^[A-Za-z][A-Za-z ]*$");

    QString teamName = ui->nom_eq_2->text();
    if (regex.match(teamName).hasMatch()) {
        qDebug() << "Valid team name!";
        ui->nom_err->setText("");
        saisi = true;
    } else {
        qDebug() << "Invalid team name!";
        ui->nom_err->setText("Seulement des caracteres");
        saisi = false;
    }
}

void MainWindow::testNBN(){
    QRegularExpression regex("^-?\\d+(\\.\\d+)?$");  // Accepte les nombres entiers et décimaux avec un éventuel signe '-'
    qDebug() << "C'est un nombre!";
    QString teamName = ui->nb_null_2->text();
    if (regex.match(teamName).hasMatch()) {
        qDebug() << "C'est un nombre!";
        ui->null_err->setText("");
        saisi = true;
    } else {
        qDebug() << "Ce n'est pas un nombre!";
        ui->null_err->setText(" chiffre uniquement !");
        saisi = false;
    }
}

void MainWindow::testNBV(){
    QRegularExpression regex("^-?\\d+(\\.\\d+)?$");  // Accepte les nombres entiers et décimaux avec un éventuel signe '-'
    qDebug() << "C'est un nombre!";
    QString teamName = ui->nb_vict_2->text();
    if (regex.match(teamName).hasMatch()) {
        qDebug() << "C'est un nombre!";
        ui->victoire_err->setText("");
        saisi = true;
    } else {
        qDebug() << "Ce n'est pas un nombre!";
        ui->victoire_err->setText(" chiffre uniquement !");
        saisi = false;
    }
}

void MainWindow::testNBD(){
    QRegularExpression regex("^-?\\d+(\\.\\d+)?$");  // Accepte les nombres entiers et décimaux avec un éventuel signe '-'
    qDebug() << "C'est un nombre!";
    QString teamName = ui->nb_def_2->text();
    if (regex.match(teamName).hasMatch()) {
        qDebug() << "C'est un nombre!";
        ui->def_err->setText("");
        saisi = true;
    } else {
        qDebug() << "Ce n'est pas un nombre!";
        ui->def_err->setText(" chiffre uniquement !");
        saisi = false;
    }
}

void MainWindow::testNBP(){
    QRegularExpression regex("^-?\\d+(\\.\\d+)?$");  // Accepte les nombres entiers et décimaux avec un éventuel signe '-'
    qDebug() << "C'est un nombre!";
    QString teamName = ui->nb_pnt_2->text();
    if (regex.match(teamName).hasMatch()) {
        qDebug() << "C'est un nombre!";
        ui->pnt_err->setText("");
        saisi = true;
    } else {
        qDebug() << "Ce n'est pas un nombre!";
        ui->pnt_err->setText(" chiffre uniquement !");
        saisi = false;
    }
}

void MainWindow::testE(){

    QRegularExpression regex("^[A-Za-z][A-Za-z ]*$");

    QString teamName = ui->entreneur_2->text();
    if (regex.match(teamName).hasMatch()) {
        qDebug() << "Valid team name!";
        ui->entreneur_err->setText("");
        saisi = true;
    } else {
        qDebug() << "Invalid team name!";
        ui->entreneur_err->setText("Seulement des caracteres");
        saisi = false;
    }
}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    qDebug() <<index;
    if(index==0){
        sort=5;
    }else if(index==1)
    {
        sort =8;
    }else
    {
        sort =7;
    }
    ui->tableView->model()->sort(sort,Qt::AscendingOrder);
}


void MainWindow::on_delete_2_clicked()
{
    if(selectedRow != -1){
        equipe e;
        int id = ui->tableView->model()->data(ui->tableView->model()->index(selectedRow,0)).toInt();
        e.deleteData(id,ui->tableView,db);
        update = false;
        selectedRow =-1;
        ui->delete_2->setStyleSheet("color: blue;");
        refreshPdf();
        displayOnCalendar();
    }

    setData("","","","","","","",QDate::currentDate(),"","");
    }


void MainWindow::on_pushButton_clicked()
{
    QString text = ui->search_field->text();
    int i = ui->search_box->currentIndex();
    equipe e;
    qDebug()<<ui->search_field->text()<<"\n"<<i;
    QSqlQueryModel *m =e.search(i,text);
    if(m)
    ui->tableView->setModel(m);
}


void MainWindow::on_pushButton_2_clicked()
{
    equipe e;
    e.readData(ui->tableView,db);
}


void MainWindow::generatePDF(){

    QString htmlFilePath = "C:/gestion_equipe3/output.html";  // Explicit file path
    QString pdfFilePath = "C:/gestion_equipe3/output.pdf";

    // Command to execute
    QString command = "wkhtmltopdf --enable-local-file-access \"" + htmlFilePath + "\" \"" + pdfFilePath + "\"";

    // Run the command using QProcess
    QProcess process;
    process.start(command);
    process.waitForFinished();

    // Capture errors and output
    QString errorOutput = process.readAllStandardError();
    QString standardOutput = process.readAllStandardOutput();

    if (process.exitStatus() == QProcess::NormalExit && process.exitCode() == 0) {
        qDebug() << "✅ PDF generated successfully!";
    } else {
        qDebug() << "❌ Error generating PDF: " << process.errorString();
        qDebug() << "🛑 wkhtmltopdf Error Output: " << errorOutput;
    }

    // Check if PDF exists
    if (QFile::exists(pdfFilePath)) {
        qDebug() << "✅ PDF found at:" << pdfFilePath;
    } else {
        qDebug() << "❌ PDF file not found!";
    }
}

void MainWindow::generateHTML2(){
    // Step 1: Fetch data from your database
    QSqlQuery query;
    query.exec("SELECT * FROM EQUIPE");  // Replace with your actual query


    // Step 3: Loop through the results and add them to the HTML
    while (query.next()) {
        int id = query.value(0).toInt();
        QString nom_equipe = query.value(1).toString();
        QString entraineur = query.value(2).toString();
        int nbv = query.value(3).toInt();
        int nbd = query.value(4).toInt();
        int nbp = query.value(5).toInt();
        int nbn = query.value(6).toInt();
        QString date = query.value(7).toDate().toString("yyyy-MM-dd");  // Format date properly
        QString categ = query.value(8).toString();
        QString email = query.value(9).toString();


                   query.prepare("select * from MATCHES");
    if(query.exec()){
        qDebug()<<"from generate html :: success read from matches";
    }else{
        qDebug()<<"from generate html :: success error from matches";
    }
    while(query.next()){
        QString team1 = query.value("TEAM1").toString();
        QString team2 = query.value("TEAM2").toString();
        QString date = query.value("TEAM2").toString();
    }


}
}
void MainWindow::createReportHTML(){
    // Step 1: Fetch data from your database
    QSqlQuery query;
    query.exec("SELECT * FROM EQUIPE");  // Replace with your actual query

    // Step 2: Create the HTML content
    QString htmlContent = "<html><head><title>Report</title></head><body>"
                          "<style>body{font-family:Arial,sans-serif;padding:20px;}table{width:100%;border-collapse:collapse;margin-top:20px;}th,td{border:1px solid #ccc;text-align:center;padding:10px;}th{background-color:#444;color:white;}tr:nth-child(even){background-color:#f2f2f2;}caption{font-size:1.5em;margin-bottom:10px;}</style>"
                          "<h1 style=\"text-align: center;\">Generated Report</h1>"
                          "<h2>EQUIPES :</h2>";

    htmlContent += "<h1></h1>";
    htmlContent += "<table border='1'><tr>"
                   "<th>ID</th><th>Nom Equipe</th><th>Entreneur</th><th>NBV</th><th>NBD</th><th>NBP</th>"
                   "<th>NBN</th><th>Date</th><th>Categorie</th><th>Email</th>"
                   "</tr>";

    // Step 3: Loop through the results and add them to the HTML
    while (query.next()) {
        int id = query.value(0).toInt();
        QString nom_equipe = query.value(1).toString();
        QString entraineur = query.value(2).toString();
        int nbv = query.value(3).toInt();
        int nbd = query.value(4).toInt();
        int nbp = query.value(5).toInt();
        int nbn = query.value(6).toInt();
        QString date = query.value(7).toDate().toString("yyyy-MM-dd");  // Format date properly
        QString categ = query.value(8).toString();
        QString email = query.value(9).toString();

        // Add the data to the HTML table
        htmlContent += QString("<tr>"
                               "<td>%1</td><td>%2</td><td>%3</td><td>%4</td><td>%5</td><td>%6</td>"
                               "<td>%7</td><td>%8</td><td>%9</td><td>%10</td>"
                               "</tr>")
                           .arg(id).arg(nom_equipe).arg(entraineur).arg(nbv).arg(nbd)
                           .arg(nbp).arg(nbn).arg(date).arg(categ).arg(email);
    }

    htmlContent += "</table>";
    htmlContent += "<h2>PLANNING DES MATCH</h2>";
    htmlContent += "<thead><tr><th>Team 1</th><th>Team 2</th><th>Date</th></tr></thead>";
    htmlContent += "<tbody><tr><td>Real Madrid</td><td>Barcelona</td><td>2025-04-10</td></tr><tr><td>Liverpool</td><td>Manchester United</td><td>2025-04-12</td></tr><!-- Add more matches here --></tbody></table>";

    query.prepare("select * from MATCHES");
    if(query.exec()){
        qDebug()<<"from generate html :: success read from matches";
    }else
    {
        qDebug()<<"from generate html :: success error from matches";
    }
    while(query.next()){
        QString team1 = query.value("TEAM1").toString();
        QString team2 = query.value("TEAM2").toString();
        QString date = query.value("TEAM2").toString();
    }

    htmlContent += "</body></html>";

    // Step 4: Write the HTML content to a file
    QFile file("C:/gestion_equipe3/report.html");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << htmlContent;
        file.close();
        qDebug() << "✅ report.html generated successfully!";
    } else {
        qDebug() << "❌ Error creating report.html!";
    }
}



void MainWindow::on_pushButton_20_clicked() {

    QString pdfFilePath = "C:/gestion_equipe3/output.pdf";

    if (QFile::exists(pdfFilePath)) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(pdfFilePath));
        qDebug() << "✅ Opening PDF: " << pdfFilePath;
    } else {
        qDebug() << "❌ PDF file not found!";
    }
}


void MainWindow::on_upper_menu_cellChanged(int row, int column)
{

}


void MainWindow::on_upper_menu_cellClicked(int row, int column)
{
    if(row==0 && column ==1)
    {
        ui->stackedWidget->setCurrentIndex(0);
    }else if(row==1 && column ==1){
        ui->stackedWidget->setCurrentIndex(1);

    }
    qDebug()<<row;
    qDebug()<<column;
}


void MainWindow::showWindowsNotification(QString &s) {
    QProcess process;


    // PowerShell command (ensure proper quoting and escaping)
    QString command = "powershell -Command \""
                      "$module = Get-Module -ListAvailable -Name 'BurntToast'; "
                      "if (-not $module) { "
                      "    Install-Module -Name 'BurntToast' -Force -Scope CurrentUser -Confirm:$false; "
                      "} "
                      "$img = New-BTImage -Source '%1'; "
                      "New-BurntToastNotification -Text 'Reminder', "+s+"' Contre EST ajourd hui 14h20 !' -AppLogo $img\"";


    // Prepare the command with arguments (if needed)
    QString formattedCommand = command.arg("C:/Users/moham/OneDrive/Desktop/download.png");

    // Execute the command
    process.start(formattedCommand);
    process.waitForFinished();

    // Capture output and error
    QString output = process.readAllStandardOutput();
    QString error = process.readAllStandardError();

    // Print output
    qDebug() << "Output:" << output;
    qDebug() << "Error:" << error;
}

std::vector<QString> MainWindow::checkForMatch(bool today) {
    std::vector<QString> ans;

    QSqlQuery query;
    if(today){
        query.prepare("SELECT NOM_EQUIPE FROM EQUIPE WHERE TRUNC(DATE_J) = TO_DATE(:today, 'YYYY-MM-DD')");
        query.bindValue(":today", QDate::currentDate().toString("yyyy-MM-dd"));  // Correct date format
    }else{
        query.prepare("SELECT NOM_EQUIPE FROM EQUIPE WHERE DATE_J IS NULL");
    }

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return ans;  // Return empty vector if query fails
    }

    while (query.next()) {
        if(today)
        qDebug() << "Il y a des équipes qui jouent aujourd'hui";
        ans.push_back(query.value("NOM_EQUIPE").toString());  // Correct conversion
    }

    return ans;  // Return the result
}

void MainWindow::shuffleTeams(std::vector<QString>& teams){
    std::random_device rd;  // Random seed
    std::mt19937 g(rd());   // PRNG
    std::shuffle(teams.begin(), teams.end(), g);
}

void MainWindow::Loterie(std::vector<QString> &v){


    int n=v.size();
    match m;
    QDate start =QDate::currentDate().addDays(5);
    for(int i=0;i<n-1;i+=2)
    {
        m.insert(v[i]+"_VS_"+v[i+1],v[i],v[i+1],start.addDays(i));
    }

}
void MainWindow::setMatches(QSqlDatabase &db){

    QSqlQuery query;
    QSqlQuery query1;
    QSqlQuery query2;
    query.prepare("SELECT * FROM MATCHES");
    if(query.exec()){
        qDebug()<<"query works";
        while(query.next())
        {
            QString team1 = query.value("TEAM1").toString();
            QString team2 = query.value("TEAM2").toString();
            QDate date= query.value("DATE_MATCH").toDate();
            qDebug()<<"team1 :"<<team1;
            qDebug()<<"team2 :"<<team2;
            qDebug()<<"date :"<<date;

            query1.prepare("UPDATE EQUIPE SET DATE_J =:date WHERE NOM_EQUIPE =:nom");
            query1.bindValue(":date",date);
            query1.bindValue(":nom",team1);

            query2.prepare("UPDATE EQUIPE SET DATE_J =:date WHERE NOM_EQUIPE =:nom");
            query2.bindValue(":date",date);
            query2.bindValue(":nom",team2);

            if(query1.exec() && query2.exec()){
                qDebug()<<"update query successeded";
            }else{
                qDebug()<<"update query error";
            }

        }
    }else{
        qDebug()<<"query fails";
    }
}

bool MainWindow::dynamicHtmlTemplate(const QString &templatePath, const QString &outputPath) {
    // Step 1: Open and read the HTML template
    QFile file(templatePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading:" << templatePath;
        return false;
    }

    QTextStream in(&file);
    QString htmlContent = in.readAll();
    file.close();
    qDebug()<<htmlContent;

    QString Matches = "", Equipes = "";

    // Step 2: Fetch MATCHES data
    QSqlQuery query;
    query.prepare("SELECT * FROM MATCHES");
    if (!query.exec()) {
        qDebug() << "Query error on MATCHES";
        return false;
    }

    while (query.next()) {
        QString team1 = query.value("TEAM1").toString();
        QString team2 = query.value("TEAM2").toString();
        QDate date = query.value("DATE_MATCH").toDate();

        Matches += QString("<tr><td>%1</td><td>%2</td><td>%3</td></tr>")
                       .arg(team1)
                       .arg(date.toString("yyyy-MM-dd"))
                       .arg(team2);
    }

    // Step 3: Fetch EQUIPE data
    QSqlQuery query2;
    query2.prepare("SELECT * FROM EQUIPE");
    if (!query2.exec()) {
        qDebug() << "Query error on EQUIPE";
        return false;
    }

    while (query2.next()) {
        QString nom_equipe = query2.value(0).toString();
        QString entraineur = query2.value(1).toString();
        int nbv = query2.value(2).toInt();
        int nbd = query2.value(3).toInt();
        int nbp = query2.value(4).toInt();
        int nbn = query2.value(5).toInt();
        QString date = query2.value(6).toDate().toString("yyyy-MM-dd");
        QString categ = query2.value(7).toString();
        QString email = query2.value(8).toString();

        Equipes += QString("<tr>"
                           "<td>%1</td><td>%2</td><td>%3</td><td>%4</td><td>%5</td>"
                           "<td>%6</td><td>%7</td><td>%8</td><td>%9</td><"
                           "</tr>")
                       .arg(nom_equipe).arg(entraineur)
                       .arg(nbv).arg(nbd).arg(nbp)
                       .arg(nbn).arg(date).arg(categ).arg(email);
    }


    // Step 4: Replace placeholders
    htmlContent.replace("{{matchesRows}}", Matches);
    htmlContent.replace("{{teamsRows}}", Equipes);
    qDebug()<<"***********************************************************************************************************************************"
                "";
    qDebug()<<"html after ";
    qDebug()<<htmlContent;
    // Step 5: Write to new output file (don't overwrite template!)
    QFile outFile(outputPath);
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qDebug() << "Failed to write to output file:" << outputPath;
        return false;
    }

    QTextStream out(&outFile);
    out << htmlContent;
    outFile.close();

    qDebug() << "HTML generated at:" << outputPath;

    return true;
}


void MainWindow::on_pushButton_39_clicked()
{
    v = checkForMatch(true);
    //showWindowsNotification(s);
    if(!v.empty()){
        qDebug()<<" v not empty";
        qDebug()<<" v not empty";
        for ( auto& equipe : v) {
            qDebug() << "Sending notification for: " << equipe;

            /*            QProcess::startDetached("powershell", QStringList()
                                                      << "-Command"
                                                      << QString("New-BurntToastNotification -Text 'Reminder', '%1 a un match aujourd''hui!'")
                                                             .arg(equipe)
                                    );

            QThread::msleep(500);  // Optional: prevents Windows from grouping notifications*/
            qDebug()<<equipe;
            showWindowsNotification(equipe);

        }
    }else{
        qDebug()<<"empty";
    }
    v = checkForMatch(false);
    for(const auto& equipe : v )
    {
        qDebug()<<equipe;
    }
    shuffleTeams(v);
    qDebug()<<"after shuffle";
    if(v.size()%2==0)
        for(const auto& equipe : v )
        {
            qDebug()<<equipe;
        }else
        qDebug()<<"need more teams for the tournements";

    /*    QDate currentDate = QDate::currentDate();

    // Specify a date to compare with (e.g., January 1, 2025)
    QDate specificDate(2025, 1, 1);

    // Compare the dates
    if (currentDate == specificDate) {
        qDebug() << "The dates are the same.";
    }
    }*/
    Loterie(v);
    setMatches(db);
    ui->stackedWidget->setCurrentIndex(1);
    match m;
    ui->tableView_2->setModel(m.readMatches(db));
    displayOnCalendar();
    refreshPdf();
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_11_clicked()
{
    if(selectedRow !=-1){

        qDebug()<<"from modif button =>id :"<<selectedRow;
        smallwindow *window = new smallwindow(this,selectedRow,db);
        window->setAttribute(Qt::WA_DeleteOnClose); // Clean up after close
        window->show(); // or use exec() if you want it modal
        checkForMatch(true);
        selectedRow =-1;
    }
}

void MainWindow::fetchMatches(QMap<QDate, QStringList> &matchesByDate){
    qDebug()<<"*****************************************************************fetchMatch************************************************************************************";
    QSqlQuery query("SELECT * FROM MATCHES");
    matchesByDate.clear();
    while (query.next()) {
        QDate date = query.value("DATE_MATCH").toDate();
        QString match = query.value("TEAM1").toString() + " vs " + query.value("TEAM2").toString();
        matchesByDate[date].append(match);
        qDebug()<<"date :"<<date;
        qDebug()<<"match :"<<match;
    }
    qDebug()<<"***************************************************************************************************************************************************************";
}

void MainWindow:: displayOnCalendar(){
    for (const QDate &date : matchesByDate.keys()) {
        ui->calendarWidget->setDateTextFormat(date, QTextCharFormat()); // resets to default
    }
    fetchMatches(matchesByDate);

    qDebug()<<"les date :";
    QTextCharFormat format;
    format.setBackground(QColor("#ADD8E6"));
    qDebug()<<"************************************************************************displayOnCalendar*****************************************************************************";

    for(auto it =matchesByDate.begin();it != matchesByDate.end() ;it++){

        qDebug()<<it.key();
        qDebug()<<*it;
        ui->calendarWidget->setDateTextFormat(it.key(),format);
        ui->calendarWidget->setHeaderTextFormat(QTextCharFormat());
    }
    qDebug()<<"***************************************************************************************************************************************************************";

}

void MainWindow::on_pushButton_12_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM EQUIPE");
    if(query.exec()){
        qDebug()<<"all equipe are deleted ";
    }else{
        qDebug()<<"all equipe  delete error ";
    }

    query.prepare("DELETE FROM MATCHES");
    if(query.exec()){
        qDebug()<<"all matches are deleted ";
    }else{
        qDebug()<<"all matches  delete error ";
    }
    displayOnCalendar();
    equipe e;
    e.readData(ui->tableView,db);
    refreshPdf();
}

void MainWindow::refreshPdf()
{
    if(dynamicHtmlTemplate("C:/gestion_equipe3/report.html","C:/gestion_equipe3/output.html")){
        qDebug()<<"dynamicHtmlTemplate :: true";
    }else{
        qDebug()<<"dynamicHtmlTemplate :: false";
    }
    generatePDF();
}

/**/

void MainWindow::on_pushButton_40_clicked()
{




    ui->stackedWidget->setCurrentIndex(2);
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MATCHES",db);


    model->setHeaderData(0, Qt::Horizontal, "MATCH");
    model->setHeaderData(1, Qt::Horizontal, "TEAM1");
    model->setHeaderData(2, Qt::Horizontal, "TEAM1");
    model->setHeaderData(3, Qt::Horizontal, "DATE");
    model->setHeaderData(4, Qt::Horizontal, "TEAM1 CHANCE");
    model->setHeaderData(5, Qt::Horizontal, "TEAM1 CHANCE");
    model->setHeaderData(6, Qt::Horizontal, "DRAW");


}




void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_14_clicked()
{
    if(selectedRow != -1){
        int victoire =ui->tableView->model()->data(ui->tableView->model()->index(selectedRow,3)).toInt();
        int defaite =ui->tableView->model()->data(ui->tableView->model()->index(selectedRow,4)).toInt();
        int null =ui->tableView->model()->data(ui->tableView->model()->index(selectedRow,6)).toInt();
        QString nom =ui->tableView->model()->data(ui->tableView->model()->index(selectedRow,1)).toString();
        pieChart * chart = new pieChart(this,victoire,defaite,null,nom);
        if(chart){
            qDebug()<<"detected";
        }
        chart->show();
    }


}

QChartView * MainWindow::createChart(){
    qDebug()<<"ccc";
    QChart *chart =new QChart();
    QChartView *chartView = new QChartView(chart);
    return chartView;
}

void MainWindow::setupSerial() {
    serial = new QSerialPort(this); // pas besoin de refaire QSerialPort *

    serial->setPortName("COM3"); // à remplacer par ton vrai port
    serial->setBaudRate(QSerialPort::Baud9600);
    if (!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Erreur ouverture port" << serial->errorString();
        return;
    }else{
        qDebug()<<"serial  open";
    }
    if(serial->isWritable()){
        qDebug()<<"writable";
    }else{
        qDebug()<<"writable 0";
    }
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
}

void MainWindow::readSerialData() {
    static QString buffer = "";

    QByteArray data = serial->readAll();
    buffer += QString::fromUtf8(data);

    int endLine = buffer.indexOf('\n');
    while (endLine != -1) {
        QString line = buffer.left(endLine).trimmed(); // Prendre une ligne complète
        buffer = buffer.mid(endLine + 1); // Supprimer la ligne traitée

        if (line.startsWith("PWD:")) {
            QString password = line.mid(4);
            qDebug() << "Mot de passe reçu :" << password;
            // Ici tu peux comparer ou traiter le mot de passe

            if(checkId(password)){
                serial->write("OK\n");
                qDebug()<<"OK";
                serial->flush();  // Force l’envoi immédiat.
                sendMatches();
            }else{
                serial->write("RESET\n");
                qDebug()<<"RESET";
                serial->flush();  // Force l’envoi immédiat
            }
        }

        endLine = buffer.indexOf('\n'); // Voir si une autre ligne est déjà arrivée
    }
}
void MainWindow::sendMatches(){
    QSqlQuery query;
    QStringList l;

    query.prepare("SELECT * FROM MATCHES");

    if(query.exec()){
        while(query.next()){
            QString t = query.value("TEAM1").toString() + " vs " +
                        query.value("TEAM2").toString() + " " +
                        query.value("DATE_MATCH").toDate().toString("yyyy-MM-dd");
            //qDebug() << t;
            l.append(t);
        }

        for(const QString &match : l){
            qDebug() << match;
            serial->write(match.toUtf8());
            serial->write("\n"); // newline delimiter
        }

    } else {
        qDebug() << "sendMatches :: query error";
    }
    loterie();
}
void MainWindow::on_pushButton_15_clicked()
{
    sendMatches();
}


void MainWindow::on_pushButton_16_clicked()
{
    sendMatches();
}

bool MainWindow::checkId(QString s) {
    QSqlQuery query;
    query.prepare("SELECT 1 FROM PASSWORDS WHERE PASSWORD = :pwd");
    query.bindValue(":pwd", s);

    if (query.exec()) {
        if (query.next()) {
            // Une ligne correspondante a été trouvée
            return true;
        } else {
            return false;
        }
    } else {
        qDebug() << "checkId :: query error:" << query.lastError().text();
        return false;
    }
}
void MainWindow::loterie(){
    v = checkForMatch(true);
    //showWindowsNotification(s);
    if(!v.empty()){
        qDebug()<<" v not empty";
        qDebug()<<" v not empty";
        for ( auto& equipe : v) {
            qDebug() << "Sending notification for: " << equipe;

            /*            QProcess::startDetached("powershell", QStringList()
                                                      << "-Command"
                                                      << QString("New-BurntToastNotification -Text 'Reminder', '%1 a un match aujourd''hui!'")
                                                             .arg(equipe)
                                    );

            QThread::msleep(500);  // Optional: prevents Windows from grouping notifications*/
            qDebug()<<equipe;
            showWindowsNotification(equipe);

        }
    }else{
        qDebug()<<"empty";
    }
    v = checkForMatch(false);
    for(const auto& equipe : v )
    {
        qDebug()<<equipe;
    }
    shuffleTeams(v);
    qDebug()<<"after shuffle";
    if(v.size()%2==0)
        for(const auto& equipe : v )
        {
            qDebug()<<equipe;
        }else
        qDebug()<<"need more teams for the tournements";

    /*    QDate currentDate = QDate::currentDate();

    // Specify a date to compare with (e.g., January 1, 2025)
    QDate specificDate(2025, 1, 1);

    // Compare the dates
    if (currentDate == specificDate) {
        qDebug() << "The dates are the same.";
    }
    }*/
    Loterie(v);
    setMatches(db);
    ui->stackedWidget->setCurrentIndex(1);
    match m;
    //ui->tableView_2->setModel(m.readMatches(db));
    displayOnCalendar();
    refreshPdf();
}

void MainWindow::on_pushButton_34_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_35_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_46_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_45_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_43_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_55_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_AjouterRES_clicked() {
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

void MainWindow::on_show12_clicked()
{
    ui->affichRES->setModel(M.afficherMateriels());
}


void MainWindow::on_modifie12_clicked()
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


void MainWindow::on_suppp12_clicked()
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
    QSqlDatabase db = QSqlDatabase::database();  // utilise la base déjà configurée

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

void MainWindow::on_btnReserver_clicked()
{
    if (ui->tabWidget_2) {
        ui->tabWidget_2->setCurrentIndex(1); // Affiche l'onglet d'index 1
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
void MainWindow::detecterBadge() {
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "Base de données non connectée !");
        return;
    }

    if (!A.getserial()->isOpen()) {
        qDebug() << "Erreur : Port Arduino non ouvert !";
        return;
    }

    QByteArray data = A.read_from_arduino();
    qDebug() << "Données brutes reçues :" << data.toHex();

    QString idCarte = QString(data).trimmed();
    qDebug() << "ID Carte après trim :" << idCarte;

    if (idCarte.isEmpty()) {
        qDebug() << "Aucune donnée valide reçue.";
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT \"nom\" FROM \"Joueurs\" WHERE \"ID_CARTE\" = :id");
    query.bindValue(":id", idCarte);

    if (!query.exec()) {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Problème de base de données : " + query.lastError().text());
        return;
    }

    if (query.next()) {
        QString nomJoueur = query.value(0).toString();
        QMessageBox::information(this, "Succès", "Joueur : " + nomJoueur);

        // Envoyer au LCD
        QString message = "Joueur: " + nomJoueur + "\n";
        A.write_to_arduino(message.toUtf8());
    } else {
        qDebug() << "Aucun joueur trouvé pour ID :" << idCarte;
        QMessageBox::warning(this, "Inconnu", "Carte non enregistrée.");

        // Envoyer au LCD
        QString message = "Carte Inconnue\n";
        A.write_to_arduino(message.toUtf8());
    }
}





void MainWindow::on_btnValider_clicked()
{

}


//monta//





void MainWindow::on_okM_clicked()
{
    // Fq    // F

    if(!update){
        tournois t(0,ui->nom->text(),
                   ui->lieu->text(),
                   ui->datedebut->date(),
                   ui->datefin->date());
        t.console();
        t.insertData(db);
        t.readData(ui->tableView_2,db);
    }else{
        update =false;
        tournois t(id_update,
                   ui->nom->text(),
                   ui->lieu->text(),
                   ui->datedebut->date(),
                   ui->datefin->date());
        t.updateData(ui->tableView_2,db);
        t.readData(ui->tableView_2,db);
        id_update=-1;
    }
}


void MainWindow::on_suppM_clicked()
{
    int id =ui->id->text().toInt();
    ui->id->setText("");
    qDebug()<<id;
    tournois t;
    t.deleteData(id,ui->tableView_2,db);
}


void MainWindow::on_modifM_clicked()
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
        ui->tableView_2->setModel(T.rechercherTournois(arg1));
    else
        ui->tableView_2->setModel(T.rechercherTournois(arg1));
}


void MainWindow::on_filtrerM_clicked()
{

    tournois T;
    int index = ui->comboBox->currentIndex();
    if (index == 0){
        ui->tableView_2->setModel(T.tri_par_date_debut());
    }else if (index == 1){
        ui->tableView_2->setModel(T.tri_par_date_fin());
    }

}

void MainWindow::on_pdfM_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_2->model()->rowCount();
    const int columnCount = ui->tableView_2->model()->columnCount();

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
            if (!ui->tableView_2->isColumnHidden(column)) {
                QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
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


void MainWindow::on_stasM_clicked()
{
    tournois t;
    t.afficherDiagramme_tournois_Stat();
}





void MainWindow::on_tableView_activated(const QModelIndex &index)
{


    if (!index.isValid()) return;
    QString qrCodeData;

    int row = index.row();
    QString val = ui->tableView_2->model()->index(row, 0).data().toString();
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





