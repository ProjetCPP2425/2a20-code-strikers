#include "equipe.h"
#include <QDebug>
equipe::equipe(int id, QString nom_equipe, QDate date_creation, QString entraineur,
               QString categorie, int nb_vic, int nb_defaite, int nb_null,int pnt, QString email)
    : id(id), nom_equipe(nom_equipe), date_creation(date_creation), entraineur(entraineur),
    categorie(categorie), nb_vic(nb_vic), nb_defaite(nb_defaite), nb_null(nb_null),nb_pnt(pnt), email(email) {}

equipe::equipe() {
    id = 0;
    nom_equipe = "";
    date_creation = QDate::currentDate();  // Initialize to the current date
    nb_vic = 0;
    nb_defaite = 0;
    nb_null = 0;
    nb_pnt = 0;
    email = "";
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

    query.prepare("INSERT INTO EQUIPE ( NOM_EQUIPE, ENTRENEUR, NBV, NBD, NBP, NBN, DATE_C, CATEG, EMAIL) "
                  "VALUES (:NOM_EQUIPE, :ENTRENEUR, :NBV, :NBD, :NBP, :NBN, :DATE_C, :CATEG, :EMAIL)");

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
    }
}

void equipe::readData(QTableView *tableView, QSqlDatabase &db){

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID, NOM_EQUIPE, ENTRENEUR, NBV, NBD, NBP, NBN, DATE_C, CATEG, EMAIL FROM EQUIPE",db);
    // Set headers for the first 9 data columns
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Date Création");
    model->setHeaderData(3, Qt::Horizontal, "Entraîneur");
    model->setHeaderData(4, Qt::Horizontal, "Catégorie");
    model->setHeaderData(5, Qt::Horizontal, "Victoires");
    model->setHeaderData(6, Qt::Horizontal, "Défaites");
    model->setHeaderData(7, Qt::Horizontal, "Nuls");
    model->setHeaderData(8, Qt::Horizontal, "Points");
    model->setHeaderData(9, Qt::Horizontal, "Email");

    // Add two extra columns for buttons (Modifier, Supprimer)
    model->insertColumn(10);

    model->setHeaderData(10, Qt::Horizontal, "Supprimer");

    tableView->setModel(model);
    tableView->setColumnHidden(0,true);

    // Set the fixed width for the table view
    tableView->setFixedWidth(930);

    // Calculate the width for each column based on the table width and number of columns
    int columnCount = model->columnCount();
    int columnWidth =(tableView->width()-29.55) / (10);

    // Set each column to have the same width
    for (int i = 0; i < columnCount; ++i) {
       tableView->setColumnWidth(i, columnWidth);
    }

    // Optionally, set the section resize mode to stretch to ensure equal distribution



    for (int row = 0; row < model->rowCount(); row++) {

        QModelIndex idIndex = model->index(row, 0);
        int equipeId = model->data(idIndex).toInt();

        // Create "Supprimer" button
        QPushButton *deleteButton = new QPushButton("Supprimer");

        // Set button in the "Supprimer" column (column 10)
        tableView->setIndexWidget(model->index(row, 10), deleteButton);
        QObject:: connect(deleteButton, &QPushButton::clicked, [this,equipeId,tableView,&db]() {
            qDebug() << "test delete button:" << equipeId;
            this->deleteData(equipeId,tableView,db);
        });


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
    if (!db.isOpen()) {
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
    }
}

