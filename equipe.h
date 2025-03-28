#ifndef EQUIPE_H
#define EQUIPE_H

#include <QtCore>
#include <QString>
#include "QDate"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QtCore>
#include <QSqlTableModel>
#include "QSqlDatabase"
#include "mainwindow.h"
#include <QTableWidget>
#include <QHeaderView>
#include <qstandarditemmodel.h>
#include <QPushButton>
#include <QObject>
#include <QMessageBox>
class MainWindow;


class equipe {

public:

    int id;
    QString nom_equipe;
    QDate date_creation;
    QString entraineur;
    QString categorie;
    int nb_vic;
    int nb_defaite;
    int nb_null;
    int nb_pnt;
    QString email;
    bool message;
    equipe();
    equipe(int id,QString nom_equipe, QDate date,QString entraineur,
           QString categorie,int nb_v,int nb_defaite, int nb_null,int nb_pnt,QString Email);


    void console_equipe();


    int getId();
    QString getNom();
    QDate getDate();
    QString getEntraineur();
    QString getCategorie();
    QString getEmail();
    MainWindow *getUi();
    int getVic();
    int getDef();
    int getNull();
    int getPoints();


    void insertData(QSqlDatabase db);
    void readData(QTableView *tableView, QSqlDatabase &db);
    void deleteData(int id ,QTableView *tableView,QSqlDatabase &db);
    void updateData(int id,QSqlDatabase &db );
    QSqlQueryModel* search(int critere,QString id);


};

#endif // EQUIPE_H
