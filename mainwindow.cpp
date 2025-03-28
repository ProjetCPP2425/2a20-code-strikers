#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlError>
#include <QPixmap>
#include <QDebug>
#include <QRegularExpression>
#include <QFocusEvent>
#include "equipe.h"
#include <QMessageBox>
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
        }

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
        }
    }
    
    setData("","","","","","","",QDate::currentDate(),"","");


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

