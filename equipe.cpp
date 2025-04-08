#include "equipe.h"
#include <QDebug>
equipe::equipe(int id, QString nom_equipe, QDate date_creation, QString entraineur,
               QString categorie, int nb_vic, int nb_defaite, int nb_null,int pnt, QString email)
    : id(id), nom_equipe(nom_equipe), date_creation(date_creation), entraineur(entraineur),
    categorie(categorie), nb_vic(nb_vic), nb_defaite(nb_defaite), nb_null(nb_null),nb_pnt(pnt), email(email),date_jeux(date_creation),message(false)  {}


equipe::equipe() {
    id = 0;
    nom_equipe = "";
    date_creation = QDate::currentDate();  // Initialize to the current date
    date_jeux =QDate::currentDate();
    nb_vic = 0;
    nb_defaite = 0;
    nb_null = 0;
    nb_pnt = 0;
    email = "";
    message =false;
}

int equipe::getId(){
    return id;
}

QString equipe::getNom(){
    return nom_equipe;
}

QDate equipe::getDate(){
    return date_creation;
}

QString equipe::getEntraineur(){
    return entraineur;
}

QString equipe::getCategorie(){
    return categorie;
}

QString equipe::getEmail(){
    return email;
}

int equipe::getVic(){
    return nb_vic;
}

int equipe::getDef(){
    return nb_defaite;
}

int equipe::getNull(){
    return nb_null;
}

int equipe::getPoints(){
    return nb_pnt;
}

void equipe::console_equipe() {
    qDebug() << "id:" << id;
    qDebug() << "Nom de l'équipe:" << nom_equipe;
    qDebug() << "Date de création:" << date_creation.toString("yyyy-MM-dd");  // Use a formatted string for QDate
    qDebug() << "Date jeux :" <<date_jeux;
    qDebug() << "Entraineur:" << entraineur;
    qDebug() << "Catégorie:" << categorie;
    qDebug() << "Email:" << email;
    qDebug() << "Nombre de victoires:" << nb_vic;
    qDebug() << "Nombre de défaites:" << nb_defaite;
    qDebug() << "Nombre de nuls:" << nb_null;
    qDebug() << "Points:" << nb_pnt;
}




void equipe::insertData(QSqlDatabase db)
{



    //qDebug()<<"id :"<<id;

    QSqlQuery query(db);

    query.prepare("INSERT INTO EQUIPE ( NOM_EQUIPE, ENTRENEUR ,NBV, NBD, NBP, NBN, DATE_C, CATEG, EMAIL) "
                  "VALUES        (:NOM_EQUIPE, :ENTRENEUR,:NBV, :NBD, :NBP, :NBN, :DATE_C, :CATEG, :EMAIL)");

    query.bindValue(":NOM_EQUIPE", this->nom_equipe);
    query.bindValue(":ENTRENEUR", this->entraineur);

    query.bindValue(":NBV", this->nb_vic);
    query.bindValue(":NBD", this->nb_defaite);
    query.bindValue(":NBP", this->nb_pnt);
    query.bindValue(":NBN", this->nb_null);
    query.bindValue(":DATE_C", this->date_creation);
    query.bindValue(":CATEG", this->categorie);
    query.bindValue(":EMAIL", this->email);



    if (query.exec()) {
        qDebug() << "✅ Data inserted successfully!";

    } else {
        qDebug() << "❌ Insert failed: " << query.lastError().text();
        message= true;
    }
}

void equipe::readData(QTableView *tableView, QSqlDatabase &db){

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID, NOM_EQUIPE, ENTRENEUR, NBV, NBD, NBP, NBN, DATE_C, CATEG, EMAIL FROM EQUIPE",db);
    // Set headers for the first 9 data columns
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "ENTRENEUR");
    model->setHeaderData(3, Qt::Horizontal, "Victoire");
    model->setHeaderData(4, Qt::Horizontal, "Defaite");
    model->setHeaderData(5, Qt::Horizontal, "Points");
    model->setHeaderData(6, Qt::Horizontal, "Nulls");
    model->setHeaderData(7, Qt::Horizontal, "Date Creation");
    model->setHeaderData(8, Qt::Horizontal, "Categorie");
    model->setHeaderData(9, Qt::Horizontal, "Email");



    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel();
    proxyModel->setSourceModel(model);  // Set the query model as the source model for the proxy
    proxyModel->setSortRole(Qt::DisplayRole);  // Set the sorting role to the display role

    // Set the proxy model to the table view
    tableView->setModel(proxyModel);

    // Enable sorting (by default, QTableView allows sorting by column headers)
    tableView->setSortingEnabled(true);

    tableView->setColumnHidden(0,true);

    // Set the fixed width for the table view
    tableView->setFixedWidth(930);

    // Calculate the width for each column based on the table width and number of columns
    int columnCount = model->columnCount();
    int columnWidth =(tableView->width()-29.55) / (9);

    // Set each column to have the same width
    for (int i = 0; i < columnCount; ++i) {
       tableView->setColumnWidth(i, columnWidth);
    }


}

void equipe::deleteData(int id ,QTableView *tableView,QSqlDatabase &db ) {
    QSqlQuery query;
    query.prepare("DELETE FROM EQUIPE WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Deleted row with ID:" << id;
        // Refresh the table view
        //readData(tableView, db);
    } else {
        qDebug() << "Error deleting row:" << query.lastError().text();
    }
    readData(tableView,db);
}

void equipe::updateData(int id,QSqlDatabase &db)
{
    // Ensure the database is open
    if (!db.isOpen   ()) {
        qDebug() << "❌ Database is not open!";
        return;
    }

    // Prepare the update query
    QSqlQuery query(db);

    query.prepare("UPDATE EQUIPE SET "
                  "NOM_EQUIPE = :NOM_EQUIPE, "
                  "ENTRENEUR = :ENTRENEUR, "
                  "NBV = :NBV, "
                  "NBD = :NBD, "
                  "NBP = :NBP, "
                  "NBN = :NBN, "
                  "DATE_C = :DATE_C, "
                  "CATEG = :CATEG, "
                  "EMAIL = :EMAIL "
                  "WHERE ID = :ID");

    // Bind the updated values to the placeholders
    query.bindValue(":NOM_EQUIPE", this->nom_equipe);
    query.bindValue(":ENTRENEUR", this->entraineur);
    query.bindValue(":NBV", this->nb_vic);
    query.bindValue(":NBD", this->nb_defaite);
    query.bindValue(":NBP", this->nb_pnt);
    query.bindValue(":NBN", this->nb_null);
    query.bindValue(":DATE_C", this->date_creation);
    query.bindValue(":CATEG", this->categorie);
    query.bindValue(":EMAIL", this->email);
    query.bindValue(":ID", id); // Bind the equipeId to identify the record to update

    // Execute the query
    if (query.exec()) {
        qDebug() << "✅ Data updated successfully!";
    } else {
        qDebug() << "❌ Update failed: " << query.lastError().text();
            message= true;
    }
}

QSqlQueryModel* equipe::search(int critere, QString ID) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    if (critere == 2) {
        bool ok;
        int id = ID.toInt(&ok); // Convert string to int safely

        if (!ok) {
            qDebug() << "Invalid ID format: " << ID;
            return nullptr; // Return nullptr to indicate an error
        }
        query.prepare("SELECT * FROM EQUIPE WHERE ID = :id");
        query.bindValue(":id", id);
    }else if(critere ==1)
    {
        query.prepare("SELECT * FROM EQUIPE WHERE ENTRENEUR = :ENTRENEUR");
        query.bindValue(":ENTRENEUR", ID);
    }
    else if(critere ==0)
    {
        query.prepare("SELECT * FROM EQUIPE WHERE NOM_EQUIPE = :NOM_EQUIPE");
        query.bindValue(":NOM_EQUIPE", ID);
    }



        if (query.exec()) {
            model->setQuery(query); // Set the query result into the model

            if (model->rowCount() > 0) {  // Check if any row was found
                qDebug() << "FOUND ID:" << id;
            } else {
                qDebug() << "No record found for ID:" << id;
            }
        } else {
            qDebug() << "Error executing search query:" << query.lastError().text();
        }

        return model; // Correctly return the model


    return nullptr; // Return nullptr if critere is not 0
}


