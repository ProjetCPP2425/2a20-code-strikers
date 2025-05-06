#include "connexion.h"

Connection::Connection() {}  // ✅ Constructeur corrigé

QSqlDatabase Connection::createconnect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("tournois"); // Remplace par ton nom de DSN ODBC réel
    db.setUserName("Montassar");               // Ton nom d'utilisateur
    db.setPassword("riahi123");               // Ton mot de passe

    return db; // ✅ Renvoie directement le résultat de l'ouverture
}
