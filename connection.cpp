#include "connection.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("tournois");//inserer le nom de la source de données
    db.setUserName("Montassar");//inserer nom de l'utilisateur
    db.setPassword("riahi123");//inserer mot de passe de cet utilisateur

    if (db.open()){
        qDebug()<<"connexion succ";
    }else{
        qDebug()<<"conn ech";
    }
        test=true;





    return  test;
}
