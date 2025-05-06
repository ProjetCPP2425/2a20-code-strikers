#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QTableWidget>  // Ajouté
#include <QComboBox>     // Ajouté
#include <QSqlQuery>
#include <QDebug>

#include "sms.h"


class ReservationManager : public QObject
{
    Q_OBJECT
public:
    explicit ReservationManager(QObject *parent = nullptr);
    void setSmsSender(SmsSender* sender);  // Nouvelle méthode
    bool makeReservation(int tournamentId, int equipmentId, int quantity, const QString& recipientPhone = "");

    void loadAvailableEquipment(QTableView *table);
    void loadTournaments(QComboBox *comboBox);

private:
    SmsSender* smsSender = nullptr;
};


#endif // RESERVATIONMANAGER_H
