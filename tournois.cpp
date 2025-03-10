#include "tournois.h"
#include "QSqlTableModel"
tournois::tournois() {
    id=0;
    nom="";
    lieu="";
    date_debut= QDate::currentDate();
    date_fin= QDate::currentDate();

}
tournois::tournois(int a,QString b,QString c,QDate d,QDate e){
    id=a;
    nom=b;
    lieu=c;
    date_debut=d;
    date_fin=e;
}

void tournois:: console(){

    qDebug()<<id<<"\n";
    qDebug()<<nom<<"\n";
    qDebug()<<lieu<<"\n";
    qDebug()<<date_debut<<"\n";
    qDebug()<<date_fin<<"\n";
}
void tournois::insertData(QSqlDatabase db){
    QSqlQuery query(db);

    // Prepare the query with parameterized values
    query.prepare("INSERT INTO MONTA ( NOM, LIEU, DATE_DEBUT, DATE_FIN) "
                  "VALUES ( :NOM, :LIEU, :DATE_DEBUT, :DATE_FIN)");

    // Bind the values from the object to the query
    //query.bindValue(":ID", 10);  // Assuming 'id' is an integer or similar
    query.bindValue(":NOM", this->nom);  // Assuming 'nom' is a QString
    query.bindValue(":LIEU", this->lieu);  // Assuming 'lieu' is a QString
    query.bindValue(":DATE_DEBUT", this->date_debut);  // Directly bind QDate object
    query.bindValue(":DATE_FIN", this->date_fin);  // Directly bind QDate object

    // Execute the query and check if it was successful
    if (query.exec()) {
        qDebug() << "Insertion valide";
    } else {
        qDebug() << "Insertion non valide: " ;  // Print the error message
    }
}


void tournois::readData(QTableView *t, QSqlDatabase &db) {
    QSqlQueryModel *model = new QSqlQueryModel();

    // Corrected SQL Query with FROM clause
    model->setQuery("SELECT ID, NOM, LIEU, DATE_DEBUT, DATE_FIN FROM MONTA", db);
    t->setModel(model);
}

void tournois::deleteData(int id,QTableView *t,QSqlDatabase &db){
    QSqlQuery q;
    q.prepare("DELETE FROM MONTA WHERE ID = :id");
    q.bindValue(":id",id);
    if(q.exec()){
        qDebug()<<"Deleted row with id :"<<id<<"\n";
    }else{
        qDebug()<<"Delete failed" ;
    }
    this->readData(t,db);
}

void tournois::updateData(QTableView *t, QSqlDatabase &db) {
    QSqlQuery q(db);
    q.prepare("UPDATE MONTA SET "
              "NOM = :NOM, "
              "LIEU = :LIEU, "
              "DATE_DEBUT = :DATE_DEBUT, "
              "DATE_FIN = :DATE_FIN "
              "WHERE ID = :id");  // Fixed missing space before WHERE

    q.bindValue(":id", id);
    q.bindValue(":NOM", nom);
    q.bindValue(":LIEU", lieu);
    q.bindValue(":DATE_DEBUT", date_debut);  // Convert QDate to string
    q.bindValue(":DATE_FIN", date_fin);      // Convert QDate to string

    qDebug() << "Executing update for ID:" << id;
    qDebug() << "Nom:" << nom;
    qDebug() << "Lieu:" << lieu;
    qDebug() << "Date Début:" << date_debut;
    qDebug() << "Date Fin:" << date_fin;

    if (q.exec()) {
        qDebug() << "Update successful for ID:" << id;
    } else {
        qDebug() << "Update failed: ";  // Print SQL error
    }

    // Refresh data in the table view
    readData(t, db);
}



