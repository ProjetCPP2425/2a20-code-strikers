#ifndef MATERIELS_H
#define MATERIELS_H

#include <QSqlQueryModel>
#include <QString>
#include <QDate>


class Materiels
{
public:
    Materiels();
    Materiels(int, QString, QString, int, QString,  QString, QDate);

    void setId(int n);
    void setNom(QString n);
    void setType(QString n);
    void setQuantite(int n);
    void setEtat(QString n);
    void setLocalisation(QString n);
    void setDATE_AJOUT(QDate n);

    int get_Id();
    QString get_Nom();
    QString get_Type();
    int get_Quantite();
    QString get_Etat();
    QString get_Localisation();
    QDate get_DATE_AJOUT();

    bool ajouterMateriels();
    QSqlQueryModel* afficherMateriels();
    bool supprimerMateriels(int id);
    bool modifierMateriels(int, QString, QString, int, QString, QString, QDate);
    bool rechercherMateriels(int);
    QSqlQueryModel* rechercherMateriels(const QString& nom);
    QSqlQueryModel* trierParType(const QString& type);
    QSqlQueryModel* trierParEtat(const QString& etat);
QSqlQueryModel* rechercherMaterielsParChamp(const QString& champ, const QString& valeur);




private:
    int Id, Quantite;
    QDate DATE_AJOUT;
    QString Nom, Type, Etat, Localisation;

};

#endif // MATERIELS_H
