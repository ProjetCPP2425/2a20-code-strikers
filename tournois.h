#ifndef TOURNOIS_H
#define TOURNOIS_H
#include <QString>
#include <QDate>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
class tournois
{
public:
    int id;
    QString nom;
    QString lieu;
    QDate date_debut;
    QDate date_fin;

    tournois();
    tournois(int id,QString nom,QString lieu,QDate date_debut,QDate date_fin);
    void console();
    void insertData(QSqlDatabase db);
    void readData(QTableView *t,QSqlDatabase &db);
    void deleteData(int i,QTableView *t,QSqlDatabase &db);
    void updateData(QTableView *t,QSqlDatabase &db);
};

#endif // TOURNOIS_H
