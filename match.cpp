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
    int va,vb,da,db,na,nb;
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

    query.prepare("SELECT NBV, NBD ,NBP, NBN FROM EQUIPE WHERE NOM_EQUIPE = :nom");
    query.bindValue(":nom",b);
    if(query.exec()){
        if (query.next()) {
            qDebug() << "Equipe statistics:";
            va= query.value("NBV").toInt();
            da = query.value("NBD").toInt();
            na=query.value("NBN").toInt();
        } else {
            qDebug() << "No matching team found in database.";
        }
    }else{
        qDebug()<<"statistics query error";
    }


    query.prepare("SELECT NBV, NBD ,NBP, NBN FROM EQUIPE WHERE NOM_EQUIPE = :nom");
    query.bindValue(":nom",c);
    if(query.exec()){
        if (query.next()) {
            qDebug() << "Equipe statistics:";
            vb= query.value("NBV").toInt();
            db = query.value("NBD").toInt();
            nb=query.value("NBN").toInt();
        } else {
            qDebug() << "No matching team found in database.";
        }
    }else{
        qDebug()<<"statistics query error";
    }

    if((va+da+na)!= 0 && (vb+nb+db)!=0){
        double PA=static_cast<double>(va)/(va+da+na);

        double PB=1-static_cast<double>(vb)/(vb+db+nb);
        // Insert the calculated probabilities into the database (assuming you have the appropriate columns)
        query.prepare("UPDATE MATCHES SET PA = :PA, PB = :PB , DRAW = :DRAW WHERE ID = :matchID");
        query.bindValue(":PA", PA);
        query.bindValue(":PB", PB);
        query.bindValue(":DRAW", 1-PA*(1-PB)-PB*(1-PA));

        query.bindValue(":matchID", a);  // Updating the match with the correct probabilities

        if (!query.exec()) {
            qDebug() << "Failed to update match probabilities.";
        } else {
            qDebug() << "Match probabilities updated successfully!";
        }
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
