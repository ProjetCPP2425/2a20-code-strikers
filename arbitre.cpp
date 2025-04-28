#include "arbitre.h"
#include <QDebug>
#include <QSqlError>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QInputDialog>
#include <QTextDocument>
#include <QPrinter>
#include <QHeaderView>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QChart>
#include <QChartView>
#include <QVBoxLayout>


QT_USE_NAMESPACE


Arbitre::Arbitre() {}

Arbitre::Arbitre(int id, QString nom, QString prenom, int age, QString nationalite, int MATCHS_ARBITRES)
{
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->age = age;
    this->nationalite = nationalite;
    this->matchs_arbitres = MATCHS_ARBITRES;
}

// Getters
int Arbitre::getId() const { return id; }
QString Arbitre::getNom() const { return nom; }
QString Arbitre::getPrenom() const { return prenom; }
int Arbitre::getAge() const { return age; }
QString Arbitre::getNationalite() const { return nationalite; }
int Arbitre::getMatchsArbitres() const { return matchs_arbitres; }

// Setters
void Arbitre::setId(int value) { id = value; }
void Arbitre::setNom(const QString value) { nom = value; }
void Arbitre::setPrenom(const QString value) { prenom = value; }
void Arbitre::setAge(int value) { age = value; }
void Arbitre::setNationalite(const QString value) { nationalite = value; }
void Arbitre::setMatchsArbitres(int value) { matchs_arbitres = value; }

void Arbitre::ajouter(QSqlDatabase &db)
{
    if(db.open()){
        qDebug()<<"opened succ";
    }else{
        qDebug()<<"open echec";
    }
    QSqlQuery query(db);
    query.prepare("INSERT INTO ARBITRES (NOM, PRENOM, AGE, NATIONALITE, MATCHES_ARBITRES) "
                  "VALUES (:nom, :prenom, :age, :nationalite, :MATCHS_ARBITRES)");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":age", age);
    query.bindValue(":nationalite", nationalite);
    query.bindValue(":MATCHS_ARBITRES", matchs_arbitres);

    if(query.exec()){
        qDebug()<<"ajout succ";
    }else{
        qDebug()<<"ajout failed";
    }
}

QSqlQueryModel* Arbitre::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Arbitres");
    return model;
}

bool Arbitre::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Arbitres WHERE ID = :id");
    query.bindValue(":id", id);
    return query.exec();
}

void Arbitre::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE ARBITRES SET NOM = :nom, PRENOM = :prenom, AGE = :age, "
                  "NATIONALITE = :nationalite, MATCHES_ARBITRES = :MATCHS_ARBITRES WHERE ID = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":age", age);
    query.bindValue(":nationalite", nationalite);
    query.bindValue(":MATCHS_ARBITRES", matchs_arbitres);
    if(query.exec()){
        qDebug()<<"modif sucess";
    }else{
        qDebug()<<"modif echec";
    }
}

bool Arbitre::exist(int id)
{
    QSqlQuery query;
    query.prepare("SELECT ID FROM Arbitres WHERE ID = :id");
    query.bindValue(":id", id);
    query.exec();
    return query.next();
}

/*bool Arbitre::takedata(int id, QString &nom, QString &prenom, int age, QString &nationalite, int &MATCHS_ARBITRES)
{
    QSqlQuery query;
    query.prepare("SELECT nom, prenom, age, nationalite, MATCHS_ARBITRES FROM Arbitres WHERE ID = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next())
    {
        nom = query.value(0).toString();
        prenom = query.value(1).toString();
        age = query.value(2).toInt();
        nationalite = query.value(3).toString();
        MATCHS_ARBITRES = query.value(4).toInt();
        return true;
    }
    return false;
}*/

QSqlQueryModel* Arbitre::search(const QString &searchText)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Arbitres WHERE nom LIKE '%" + searchText + "%' "
                                                                              "OR prenom LIKE '%" + searchText + "%' OR nationalite LIKE '%" + searchText + "%'");
    return model;
}

QSqlQueryModel* Arbitre::trier_par_nom()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Arbitres ORDER BY nom ASC");
    return model;
}

void Arbitre::exportTableToPDF(const QString &fileName)
{
    QPdfWriter pdf(fileName);
    QPainter painter(&pdf);
    QSqlQuery query("SELECT * FROM Arbitres");

    int y = 0;
    painter.drawText(2000, y += 500, "Liste des Arbitres");

    y += 500;
    painter.drawText(500, y, "ID");
    painter.drawText(1000, y, "Nom");
    painter.drawText(2000, y, "Prénom");
    painter.drawText(3000, y, "Âge");
    painter.drawText(4000, y, "Nationalité");
    painter.drawText(5500, y, "Matchs");

    while (query.next())
    {
        y += 500;
        painter.drawText(500, y, query.value(0).toString());
        painter.drawText(1000, y, query.value(1).toString());
        painter.drawText(2000, y, query.value(2).toString());
        painter.drawText(3000, y, query.value(3).toString());
        painter.drawText(4000, y, query.value(4).toString());
        painter.drawText(5500, y, query.value(5).toString());
    }
    painter.end();
}

void Arbitre::afficherDiagrammeArbitreStat()
{
    QSqlQuery query("SELECT nationalite, COUNT(*) FROM Arbitres GROUP BY nationalite");
    while (query.next())
    {
        qDebug() << "Nationalité:" << query.value(0).toString() << " - Total:" << query.value(1).toInt();
    }
}

QChartView* Arbitre::DiagrammeCirculaire()
{
    QPieSeries* series = new QPieSeries();
    QSqlQuery query("SELECT nationalite, COUNT(*) FROM Arbitres GROUP BY nationalite");

    while (query.next())
    {
        series->append(query.value(0).toString(), query.value(1).toInt());
    }

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des arbitres par nationalité");

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}

void Arbitre::exportDataToPDF()
{
    exportTableToPDF("Arbitres.pdf");
}

void Arbitre::rechercher(const QString &critere) {
    search(critere);
}

void Arbitre::console(){
    qDebug()<<getId();
    qDebug()<<getAge();
    qDebug()<<getMatchsArbitres();
    qDebug()<<getNationalite();
    qDebug()<<getNom();
    qDebug()<<getPrenom();
}

void Arbitre::select(int id){
    QSqlQuery q;
    q.prepare("SELECT * FROM ARBITRES WHERE ID = :id");
    q.bindValue(":id",id);
    if(!q.exec()){
        qDebug()<<id<<" not found";
    }else{
        if(q.next()){
            id = q.value("ID").toInt();
            nom = q.value("NOM").toString();
            prenom =q.value("PRENOM").toString();
            age = q.value("AGE").toInt();
            this->nationalite = q.value("NATIONALITE").toString();
            this->matchs_arbitres= q.value("MATCHES_ARBITRES").toInt();
        }
    }

}
