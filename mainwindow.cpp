#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlError>
#include <QPixmap>
#include <QDebug>
#include <QRegularExpression>
#include <QFocusEvent>
#include "equipe.h"
#include <QMessageBox>
#include <QProcess>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    update(false),saisi(true),
    selectedRow(-1),sort(5),
    ui(new Ui::MainWindow)

{

    ui->setupUi(this);

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


    // Create the proxy model
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(ui->tableView->model());
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    // Assign proxy model to table view
    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);

    // Ensure sorting on a valid column (e.g., Name column at index 1)
    proxyModel->sort(sort, Qt::AscendingOrder);


    qDebug()<<selectedRow;
    styleSheet(um);
    //createReportHTML();
    if(dynamicHtmlTemplate("C:/gestion_equipe3/report.html","C:/gestion_equipe3/output.html")){
            qDebug()<<"dynamicHtmlTemplate :: true";
        }else{
        qDebug()<<"dynamicHtmlTemplate :: false";
    }
    generatePDF();
    QString s ="test";
    std::vector<QString>v = checkForMatch(true);
    //showWindowsNotification(s);

        if(!v.empty()){
        qDebug()<<" v not empty";
        qDebug()<<" v not empty";
        for (const auto& equipe : v) {
            qDebug() << "Sending notification for: " << equipe;

            QProcess::startDetached("powershell", QStringList()
                                                      << "-Command"
                                                      << QString("New-BurntToastNotification -Text 'Reminder', '%1 a un match aujourd''hui!'")
                                                             .arg(equipe)
                                    );

            QThread::msleep(500);  // Optional: prevents Windows from grouping notifications
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
    qDebug()<<QDate::currentDate();
    Loterie(v);
    setMatches(db);


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
    }
    
    setData("","","","","","","",QDate::currentDate(),"","");

    if(dynamicHtmlTemplate("C:/gestion_equipe3/report.html","C:/gestion_equipe3/output.html")){
        qDebug()<<"dynamicHtmlTemplate :: true";
    }else{
        qDebug()<<"dynamicHtmlTemplate :: false";
    }
    generatePDF();
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
    selectedRow = model->data(model->index(rowIndex,0)).toInt();
    ui->delete_2->setStyleSheet("color: red;");



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
        e.deleteData(selectedRow,ui->tableView,db);
        update = false;
        selectedRow =-1;
        ui->delete_2->setStyleSheet("color: blue;");
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
                      "New-BurntToastNotification -Text 'Reminder', "+s+"' A un match aujourd hui !' -AppLogo $img\"";


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
        query.prepare("SELECT NOM_EQUIPE FROM EQUIPE");
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
        int id = query2.value(0).toInt();
        QString nom_equipe = query2.value(1).toString();
        QString entraineur = query2.value(2).toString();
        int nbv = query2.value(3).toInt();
        int nbd = query2.value(4).toInt();
        int nbp = query2.value(5).toInt();
        int nbn = query2.value(6).toInt();
        QString date = query2.value(7).toDate().toString("yyyy-MM-dd");
        QString categ = query2.value(8).toString();
        QString email = query2.value(9).toString();

        Equipes += QString("<tr>"
                           "<td>%1</td><td>%2</td><td>%3</td><td>%4</td><td>%5</td>"
                           "<td>%6</td><td>%7</td><td>%8</td><td>%9</td><td>%10</td>"
                           "</tr>")
                       .arg(id).arg(nom_equipe).arg(entraineur)
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
    ui->stackedWidget->setCurrentIndex(1);
    match m;
    ui->tableView_2->setModel(m.readMatches(db));
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

