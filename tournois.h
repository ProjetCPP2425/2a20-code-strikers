#ifndef TOURNOIS_H
#define TOURNOIS_H
#include <QString>
#include <QDate>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlQueryModel>
#include <QChartView>


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


    QSqlQueryModel * rechercherTournois(QString recherche);

    QSqlQueryModel * tri_par_date_debut();
    QSqlQueryModel * tri_par_date_fin();

    void afficherDiagramme_tournois_Stat();
    QChartView* DiagrammeCirculaire();


};

#endif // TOURNOIS_H
