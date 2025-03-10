#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connection {
public:
    Connection();
    QSqlDatabase createconnect();
};

#endif // CONNECTION_H
