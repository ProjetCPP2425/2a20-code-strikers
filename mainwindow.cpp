#include "mainwindow.h"
#include "ui_mainwindow.h"  // ✅ Assure que ce fichier est bien généré
#include "connexion.h"
#include "tournois.h"
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),

    ui(new Ui::MainWindow),update(false),id_update(-1)  // ✅ Initialisation correcte
{
    ui->setupUi(this);  // ✅ Charge l'interface depuis mainwindow.ui
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("tournois"); // Remplace par ton nom de DSN ODBC réel
    db.setUserName("Montassar");               // Ton nom d'utilisateur
    db.setPassword("riahi123");
    if(db.open()){
        qDebug()<<"open\n";
    }else{
        qDebug()<<"not open\n";
    }        // Ton mot de passe
    tournois tr;
    tr.readData(ui->tableView,db);
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
