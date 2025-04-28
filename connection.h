#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool createconnect();
};

#endif // CONNECTION_H
//lahné amlna classe mta Connection w amlna methode createconnect heya li bech naamloulha l appel mba3ed bech nconnectou biha
