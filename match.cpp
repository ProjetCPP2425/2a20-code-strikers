#include "match.h"

match::match()
{
    id = "";
    team1 ="";
    team2 ="";
    date =QDate::currentDate();
}
match::match(QString a, QString b,QString c,QDate d){
    id = a;
    team1 =b;
    team2 =c;
    date =d;
}

void match::insert(QString a, QString b,QString c,QDate d){
    QSqlQuery query;
    query.prepare("INSERT INTO MATCHES (ID, TEAM1, TEAM2, DATE_MATCH) VALUES (:matchID, :team1, :team2, :date)");
    query.bindValue(":matchID", a);
    query.bindValue(":team1", b);
    query.bindValue(":team2", c);
    query.bindValue(":date", d);

    if (!query.exec()) {
        qDebug() << "Insertion failed:" ;
    } else {
        qDebug() << "Match inserted successfully!";
    }
}

void match::consol(){
    qDebug()<<"MATCH INFO :";
    qDebug()<<id;
    qDebug()<<team1;
    qDebug()<<team2;
    qDebug()<<date;
    qDebug()<<"*****";
}

QSqlQueryModel* match::readMatches(QSqlDatabase &db){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MATCHES",db);
    model->setHeaderData(0, Qt::Horizontal, "TEAM1");
    model->setHeaderData(1, Qt::Horizontal, "DATE_MATCH");
    model->setHeaderData(2, Qt::Horizontal, "TEAM2");
    return model;
}
