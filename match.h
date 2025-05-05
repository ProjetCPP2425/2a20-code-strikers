#ifndef MATCH_H
#define MATCH_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
class match
{
    QString id;
    QString team1;
    QString team2;
    QDate date;
public:
    match();
    match(QString id, QString team1,QString team2,QDate date);
    void insert(QString id, QString team1,QString team2,QDate date);
    void consol();

    QSqlQueryModel* readMatches(QSqlDatabase &db);
};

#endif // MATCH_H

