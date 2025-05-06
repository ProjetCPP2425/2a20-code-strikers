#include "materiels.h"
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Materiels::Materiels() {
    Nom = "";
    Type = "";
    Quantite = 0;
    Etat = "";
    Localisation = "";
    DATE_AJOUT = QDate::currentDate();

}

Materiels::Materiels(int Id, QString Nom, QString Type, int Quantite, QString Etat, QString Localisation, QDate DATE_AJOUT) {
    this->Id = Id;
    this->Nom = Nom;
    this->Type = Type;
    this->Quantite = Quantite;
    this->Etat = Etat;

    this->Localisation = Localisation;
    this->DATE_AJOUT =DATE_AJOUT;
}

int Materiels::get_Id() { return Id; }
QString Materiels::get_Nom() { return Nom; }
QString Materiels::get_Type() { return Type; }
QDate Materiels::get_DATE_AJOUT() { return DATE_AJOUT; }
QString Materiels::get_Etat() { return Etat; }
int Materiels::get_Quantite() { return Quantite; }
QString Materiels::get_Localisation() { return Localisation; }

void Materiels::setId(int Id) { this->Id = Id; }
void Materiels::setNom(QString Nom) { this->Nom = Nom; }
void Materiels::setType(QString Type) { this->Type = Type; }
void Materiels::setEtat(QString Etat) { this->Etat = Etat; }
void Materiels::setQuantite(int Quantite) { this->Quantite = Quantite; }
void Materiels::setLocalisation(QString Localisation) { this->Localisation = Localisation; }
void Materiels::setDATE_AJOUT(QDate DATE_AJOUT) { this->DATE_AJOUT = DATE_AJOUT; }

QSqlQueryModel* Materiels::afficherMateriels()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // Obtenir la connexion
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen()) {
        if (!db.open()) {
            qDebug() << "Erreur d'ouverture de la base de données:" << db.lastError().text();
            return model; // Retourne un modèle vide plutôt que nullptr
        }
    }

    QSqlQuery query(db); // Important: passer la connexion
    query.prepare("SELECT * FROM MATERIELS");

    if (!query.exec()) {
        qDebug() << "Erreur d'exécution de la requête:" << query.lastError().text();
        return model;
    }

    model->setQuery(query);

    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Localisation"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date_Ajout"));

    return model;
}

bool Materiels::ajouterMateriels() {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    // Passez la connexion au query
    query.prepare("INSERT INTO materiels (Nom, Type, Quantite, Etat, Localisation, DATE_AJOUT) VALUES (:Nom, :Type, :Quantite, :Etat, :Localisation, :DATE_AJOUT)");
    query.bindValue(":Nom", Nom);
    query.bindValue(":Type", Type);
    query.bindValue(":Quantite", Quantite);
    query.bindValue(":Etat", Etat);
    query.bindValue(":Localisation", Localisation);
    query.bindValue(":DATE_AJOUT", DATE_AJOUT);

    return query.exec();
}

bool Materiels::supprimerMateriels(int id) {
    // 1. Obtenir la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);


    // 2. Vérifier que la connexion est ouverte
    if (!db.isOpen()) {
        if (!db.open()) {
            qDebug() << "Erreur: Impossible d'ouvrir la connexion à la base de données";
            qDebug() << db.lastError().text();
            return false;
        }
    }

    // 3. Préparer la requête SQL avec paramètre lié

    query.prepare("DELETE FROM materiels WHERE id = :id");
    query.bindValue(":id", id);

    // 4. Exécuter la requête et vérifier le résultat
    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression du matériel:";
        qDebug() << "Requête SQL:" << query.lastQuery();
        qDebug() << "Erreur SQL:" << query.lastError().text();
        return false;
    }

    // 5. Vérifier si des lignes ont été effectivement supprimées
    if (query.numRowsAffected() <= 0) {
        qDebug() << "Avertissement: Aucun matériel supprimé (ID non trouvé?)";
        return false;
    }

    // 6. Journaliser la suppression réussie
    qDebug() << "Matériel ID" << id << "supprimé avec succès";
    return true;
}

bool Materiels::modifierMateriels(int id, QString nom, QString type, int quantite, QString etat, QString localisation, QDate DATE_AJOUT) {
    // Obtenir la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::database();

    // Vérifier que la connexion est ouverte
    if (!db.isOpen()) {
        qDebug() << "Erreur: La connexion à la base de données n'est pas ouverte";
        return false;
    }

    // Préparer la requête SQL avec des paramètres liés
    QSqlQuery query(db);
    query.prepare("UPDATE materiels SET "
                  "Nom = :nom, "
                  "Type = :type, "
                  "Quantite = :quantite, "
                  "Etat = :etat, "
                  "Localisation = :localisation, "
                  "DATE_AJOUT = :date_ajout "
                  "WHERE ID = :id");

    // Lier les valeurs aux paramètres
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":quantite", quantite);
    query.bindValue(":etat", etat);
    query.bindValue(":localisation", localisation);
    query.bindValue(":date_ajout", DATE_AJOUT);

    // Exécuter la requête et vérifier le résultat
    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification du matériel:";
        qDebug() << "Requête SQL:" << query.lastQuery();
        qDebug() << "Erreur:" << query.lastError().text();
        return false;
    }

    // Vérifier si des lignes ont été affectées
    if (query.numRowsAffected() <= 0) {
        qDebug() << "Aucune ligne modifiée - ID peut-être inexistant";
        return false;
    }

    return true;
}
QSqlQueryModel* Materiels::rechercherMaterielsParChamp(const QString& champ, const QString& valeur) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::database();


    if (!db.isOpen() && !db.open()) {
        qDebug() << "Erreur connexion BD:" << db.lastError().text();
        return model;
    }

    QString champSQL;

    if (champ == "Nom") champSQL = "Nom";
    else if (champ == "Localisation") champSQL = "Localisation";
    else champSQL = "Nom"; // Valeur par défaut

    QSqlQuery query(db);
    QString requete = QString("SELECT * FROM MONTASSAR.MATERIELS WHERE %1 LIKE :valeur").arg(champSQL);
    query.prepare(requete);
    query.bindValue(":valeur", "%" + valeur + "%");

    if (!query.exec()) {
        qDebug() << "Erreur recherche:" << query.lastError().text();
        return model;
    }

    model->setQuery(std::move(query));
    return model;
}

QSqlQueryModel* Materiels::trierParType(const QString& type) {
    QSqlQueryModel* model = new QSqlQueryModel();

    // 1. Obtenir la connexion
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen() && !db.open()) {
        qDebug() << "Erreur: Connexion non ouverte -" << db.lastError().text();
        return model;
    }

    // 2. Préparer la requête selon le type
    QSqlQuery query(db);
    if (type == "Tous") {
        if (!query.exec("SELECT * FROM materiels ORDER BY Type, Nom")) {
            qDebug() << "Erreur tri par type (tous):" << query.lastError().text();
            return model;
        }
    } else {
        query.prepare("SELECT * FROM materiels WHERE Type = :type ORDER BY Nom");
        query.bindValue(":type", type);
        if (!query.exec()) {
            qDebug() << "Erreur tri par type spécifique:" << query.lastError().text();
            return model;
        }
    }

    // 3. Assigner la requête au modèle avec std::move
    model->setQuery(std::move(query));

    // 4. Définir les en-têtes
    QString headers[] = {"ID", "Nom", "Type", "Quantité", "État", "Localisation", "Date Ajout"};
    for (int i = 0; i < 7; ++i) {
        model->setHeaderData(i, Qt::Horizontal, headers[i]);
    }

    return model;
}

QSqlQueryModel* Materiels::trierParEtat(const QString& etat) {
    QSqlQueryModel* model = new QSqlQueryModel();

    // 1. Obtenir la connexion
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen() && !db.open()) {
        qDebug() << "Erreur: Connexion non ouverte -" << db.lastError().text();
        return model;
    }

    // 2. Préparer la requête selon l'état
    QSqlQuery query(db);
    if (etat == "Tous") {
        if (!query.exec("SELECT * FROM materiels ORDER BY Etat, Nom")) {
            qDebug() << "Erreur tri par état (tous):" << query.lastError().text();
            return model;
        }
    } else {
        query.prepare("SELECT * FROM materiels WHERE Etat = :etat ORDER BY Nom");
        query.bindValue(":etat", etat);
        if (!query.exec()) {
            qDebug() << "Erreur tri par état spécifique:" << query.lastError().text();
            return model;
        }
    }

    // 3. Assigner la requête au modèle avec std::move
    model->setQuery(std::move(query));

    // 4. Définir les en-têtes (cohérents avec trierParType)
    QString headers[] = {"ID", "Nom", "Type", "Quantité", "État", "Localisation", "Date Ajout"};
    for (int i = 0; i < 7; ++i) {
        model->setHeaderData(i, Qt::Horizontal, headers[i]);
    }

    return model;
}
