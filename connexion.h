#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class Connection {
private:
    static QSqlDatabase db;
    Connection() {} // Constructeur privé

public:
    static QSqlDatabase getConnection();
    static bool createConnection();
    static void closeConnection();
};

#endif // CONNECTION_H
