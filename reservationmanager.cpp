#include "reservationmanager.h"
#include "connexion.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>

ReservationManager::ReservationManager(QObject *parent) : QObject(parent)
{
    if (!Connection::createConnection()) {
        QMessageBox::critical(nullptr, "Erreur", "La connexion à la base de données a échoué");
    }



}
void ReservationManager::setSmsSender(SmsSender* sender) {
    smsSender = sender;
}


void ReservationManager::loadTournaments(QComboBox *comboBox)
{
    if (!comboBox) return;

    QSqlDatabase db = Connection::getConnection();
    QSqlQuery query(db);

    // Utilisation correcte de la casse pour les colonnes de "tournois"
    if (!query.exec("SELECT \"ID\", \"nom\", \"lieu\", \"date debut\", \"date fin\" FROM MONTASSAR.\"tournois\" ORDER BY \"nom\"")) {
        QString error = "Erreur tournois:\n" + query.lastError().text();
        qDebug() << error;
        QMessageBox::warning(nullptr, "Erreur", error);
        return;
    }

    comboBox->clear();
    while (query.next()) {
        comboBox->addItem(query.value(1).toString(), query.value(0)); // "nom", "ID"
    }
}

void ReservationManager::loadAvailableEquipment(QTableView *table)
{
    if (!table) return;

    QSqlDatabase db = Connection::getConnection();
    QSqlTableModel *model = new QSqlTableModel(nullptr, db);

    model->setTable("MONTASSAR.MATERIELS"); // Non sensible à la casse
    model->setFilter("QUANTITE > 0");

    if (!model->select()) {
        qDebug() << "Erreur matériels:" << model->lastError().text();
        delete model;
        return;
    }

    QStringList headers = {"ID", "NOM", "TYPE", "QUANTITE", "ETAT", "LOCALISATION"};
    for (int i = 0; i < headers.size() && i < model->columnCount(); ++i) {
        model->setHeaderData(i, Qt::Horizontal, headers[i]);
    }

    table->setModel(model);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
}

bool ReservationManager::makeReservation(int tournamentId, int equipmentId, int quantity, const QString& recipientPhone)
{
    QSqlDatabase db = Connection::getConnection();

    if (!db.transaction()) {
        qDebug() << "Erreur transaction:" << db.lastError().text();
        return false;
    }

    try {
        // Vérification du stock
        QSqlQuery checkQuery(db);
        checkQuery.prepare("SELECT QUANTITE FROM MONTASSAR.MATERIELS WHERE ID = ?");
        checkQuery.addBindValue(equipmentId);

        if (!checkQuery.exec() || !checkQuery.next()) {
            throw checkQuery.lastError();
        }

        int stockDispo = checkQuery.value(0).toInt();
        if (quantity > stockDispo) {
            throw QSqlError("Quantité demandée supérieure au stock disponible", QString(), QSqlError::UnknownError);
        }

        // Insertion dans RESERVATION
        QSqlQuery insertQuery(db);
        insertQuery.prepare(
            "INSERT INTO MONTASSAR.RESERVATION (ID_RESERVATION, ID_TOURNOI, ID_MATERIEL, QUANTITE_RESERVEE, DATE_RESERVATION) "
            "VALUES (MONTASSAR.SEQUENCE_RESERVATION.NEXTVAL, ?, ?, ?, SYSDATE)"
            );
        insertQuery.addBindValue(tournamentId);
        insertQuery.addBindValue(equipmentId);
        insertQuery.addBindValue(quantity);

        if (!insertQuery.exec()) {
            throw insertQuery.lastError();
        }

        // Mise à jour du stock
        QSqlQuery updateQuery(db);
        updateQuery.prepare("UPDATE MONTASSAR.MATERIELS SET QUANTITE = QUANTITE - ? WHERE ID = ?");
        updateQuery.addBindValue(quantity);
        updateQuery.addBindValue(equipmentId);

        if (!updateQuery.exec()) {
            throw updateQuery.lastError();
        }

        if (!db.commit()) {
            throw db.lastError();
        }

        // Envoi de SMS si sender disponible
        if (smsSender) {
            QString message = QString("Réservation confirmée:\nID Matériel: %1\nQuantité: %2")
                                  .arg(equipmentId).arg(quantity);
            smsSender->sendSms(recipientPhone, message);
        }

        return true;

    } catch (const QSqlError &e) {
        db.rollback();
        qDebug() << "Erreur réservation:" << e.text();
        QMessageBox::critical(nullptr, "Erreur", e.text());
        return false;
    }
}
