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
#include <QTableWidget>
#include <QHeaderView>
#include <qstandarditemmodel.h>
#include <QPushButton>
#include <QObject>
class equipe {
public:

    QString id;
    QString nom_equipe;
    QDate date_creation;
    QString entraineur;
    QString categorie;
    int nb_vic;
    int nb_defaite;
    int nb_null;
    int nb_pnt;
    QString email;

    equipe();

    equipe(QString id,QString nom_equipe, QDate date,QString entraineur,
           QString categorie,int nb_v,int nb_defaite, int nb_null,int nb_pnt,QString Email);

    void console_equipe();


    QString getId();
    QString getNom();
    QDate getDate();
    QString getEntraineur();
    QString getCategorie();
    QString getEmail();
    int getVic();
    int getDef();
    int getNull();
    int getPoints();
    void insertData(QSqlDatabase db);
    void readData(QTableView *tableView, QSqlDatabase &db);
    void deleteData(int id ,QTableView *tableView,QSqlDatabase &db);


};

#endif // EQUIPE_H
