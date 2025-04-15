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

<<<<<<< HEAD


    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel();
    proxyModel->setSourceModel(model);  // Set the query model as the source model for the proxy
    proxyModel->setSortRole(Qt::DisplayRole);  // Set the sorting role to the display role

    // Set the proxy model to the table view
    tableView->setModel(proxyModel);

    // Enable sorting (by default, QTableView allows sorting by column headers)
    tableView->setSortingEnabled(true);

=======
    // Add two extra columns for buttons (Modifier, Supprimer)
    model->insertColumn(10);

    model->setHeaderData(10, Qt::Horizontal, "Supprimer");

    tableView->setModel(model);
>>>>>>> ff7121065ed14647e53859f56b943d662d3c421a
    tableView->setColumnHidden(0,true);

    // Set the fixed width for the table view
    tableView->setFixedWidth(930);

    // Calculate the width for each column based on the table width and number of columns
    int columnCount = model->columnCount();
<<<<<<< HEAD
    int columnWidth =(tableView->width()-29.55) / (9);
=======
    int columnWidth =(tableView->width()-29.55) / (10);
>>>>>>> ff7121065ed14647e53859f56b943d662d3c421a

    // Set each column to have the same width
    for (int i = 0; i < columnCount; ++i) {
       tableView->setColumnWidth(i, columnWidth);
    }

<<<<<<< HEAD
=======
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

>>>>>>> ff7121065ed14647e53859f56b943d662d3c421a

}

void equipe::deleteData(int id ,QTableView *tableView,QSqlDatabase &db ) {
    QSqlQuery query;
    QString adversaire;
    query.prepare(R"(
    SELECT TEAM1 AS Adversaire FROM MATCHES
    WHERE TEAM2 = (SELECT NOM_EQUIPE FROM EQUIPE WHERE ID = :id)
    UNION
    SELECT TEAM2 AS Adversaire FROM MATCHES
    WHERE TEAM1 = (SELECT NOM_EQUIPE FROM EQUIPE WHERE ID = :id)
)");
    query.bindValue(":id", id);
    if(query.exec()){
        qDebug()<<"adversaire reussi";
        while(query.next()){
            adversaire = query.value("Adversaire").toString();
            qDebug() << "Adversaire :" << adversaire;
        }
    }else{
        qDebug()<<"adversaire echec";

    }
    query.prepare("UPDATE EQUIPE SET DATE_J = NULL WHERE NOM_EQUIPE = :nom");

    query.bindValue(":nom",adversaire);
    if(query.exec()){
        qDebug()<<"advairsaire date_j update succ";
    }else{
        qDebug()<<"advairsaire date_j update echec";
    }
    query.prepare(R"(
    DELETE FROM MATCHES
    WHERE TEAM1 = (SELECT NOM_EQUIPE FROM EQUIPE WHERE ID = :id)
       OR TEAM2 = (SELECT NOM_EQUIPE FROM EQUIPE WHERE ID = :id)
)");    query.bindValue(":id", id);
    if(query.exec()){
        qDebug()<<"delete of match of the equipe success";
    }else{
        qDebug()<<"delete of match of the equipe failed";
    }
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
<<<<<<< HEAD
=======
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
>>>>>>> ff7121065ed14647e53859f56b943d662d3c421a
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

        query.prepare("SELECT * FROM EQUIPE WHERE EMAIL = :EMAIL");
        query.bindValue(":EMAIL", ID);
    }else if(critere ==1)
    {
        bool ok;
        int id = ID.toInt(&ok); // Convert string to int safely

        if (!ok) {
            qDebug() << "Invalid ID format: " << ID;
            return nullptr; // Return nullptr to indicate an error
        }
        query.prepare("SELECT * FROM EQUIPE WHERE ENTRENEUR = :ENTRENEUR");
        query.bindValue(":ENTRENEUR", ID);
    }
    else if(critere ==0)
    {
        bool ok;
        int id = ID.toInt(&ok); // Convert string to int safely

        if (!ok) {
            qDebug() << "Invalid ID format: " << ID;
            return nullptr; // Return nullptr to indicate an error
        }
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


