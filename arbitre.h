#ifndef ARBITRE_H
#define ARBITRE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QtCharts/QChartView>
#include <QSqlDatabase>
QT_USE_NAMESPACE

    class Arbitre
{
private:
    int id;
    QString nom;
    QString prenom;
    int age;
    QString nationalite;
    int matchs_arbitres;

public:
    // Constructeur par défaut
    Arbitre();
    // Constructeur avec paramètres
    Arbitre(int ID, QString nom, QString prenom, int age, QString nationalite, int matchs_arbitres);

    // Getters
    int getId() const;
    QString getNom() const;
    QString getPrenom() const;
    int getAge() const;
    QString getNationalite() const;
    int getMatchsArbitres() const;

    // Setters
    void setId(int value);
    void setNom(const QString value);
    void setPrenom(const QString value);
    void setAge(int value);
    void setNationalite(const QString value);
    void setMatchsArbitres(int value);

    // Méthodes de gestion des arbitres
    void ajouter(QSqlDatabase &db);
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    void modifier();
    bool exist(int id);
    bool takedata(int id, QString &nom, QString &prenom, int age, QString &nationalite, int &matchs_arbitres);
    QSqlQueryModel* search(const QString &searchText);
    QSqlQueryModel* trier_par_nom();
    void exportTableToPDF(const QString &fileName);
    void afficherDiagrammeArbitreStat();
    QChartView* DiagrammeCirculaire();
    void exportDataToPDF();
    void rechercher(const QString &critere);
    void console();
    void afficherArbitres();
    void select(int id);
};

#endif // ARBITRE_H
