#include "connexion.h"

QSqlDatabase Connection::db;

QSqlDatabase Connection::getConnection() {
    if (!db.isOpen()) {
        createConnection();
    }
    return db;
}

bool Connection::createConnection() {
    if (db.isOpen()) return true;

    db = QSqlDatabase::addDatabase("QODBC", "ORACLE_CONN"); // Nom unique
    db.setDatabaseName("foot");
    db.setUserName("MONTASSAR");
    db.setPassword("riahi123");

    if (!db.open()) {
        qDebug() << "Erreur connexion Oracle:" << db.lastError().text();
        return false;
    }
    qDebug() << "Connexion Oracle établie";
    return true;
}

void Connection::closeConnection() {
    if (db.isOpen()) {
        db.close();
        QSqlDatabase::removeDatabase("ORACLE_CONN");
    }
}
