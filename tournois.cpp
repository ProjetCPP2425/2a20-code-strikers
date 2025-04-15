#include "tournois.h"
#include "QSqlTableModel"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include "qsqlquerymodel.h"
#include <QtCharts>
#include <QLayout>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
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
    q.bindValue(":DATE_DEBUT", date_debut)




        ;  // Convert QDate to string
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



QSqlQueryModel *tournois::rechercherTournois(QString recherche)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT ID, NOM, LIEU, DATE_DEBUT, DATE_FIN FROM MONTA "
                    "WHERE (ID LIKE UPPER('%" + recherche + "%') "
                                  "OR UPPER(LIEU) LIKE UPPER('%" + recherche + "%'))");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));
    return model;

}




QSqlQueryModel * tournois::tri_par_date_debut()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM MONTA ORDER BY DATE_DEBUT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));
    return model;
}
QSqlQueryModel * tournois::tri_par_date_fin()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM MONTA ORDER BY DATE_FIN");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));
    return model;
}



QChartView* tournois::DiagrammeCirculaire() {
    QSqlDatabase db = QSqlDatabase::database("my_connection");
    QSqlQuery query(db);
    QPieSeries *series = new QPieSeries();

    query.prepare("SELECT LIEU, COUNT(*) AS count FROM MONTA GROUP BY LIEU");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError();
        delete series; // Éviter les fuites mémoire
        return nullptr;
    }

    while (query.next()) {
        QString LIEU = query.value(0).toString();
        int count = query.value(1).toInt();

        series->append(LIEU, count);
    }

    QList<QColor> couleurs = {
        QColor("#0D47A1"), // Bleu foncé
        QColor("#42A5F5"), // Bleu clair
        QColor("#FF7043")  // Orange
    };

    int couleurIndex = 0;
    for (QPieSlice *slice : series->slices()) {
        QColor couleur = couleurs[couleurIndex % couleurs.size()];
        couleurIndex++;

        slice->setBrush(couleur);

        slice->setLabel(slice->label() + " (" + QString::number(slice->percentage() * 100, 'f', 1) + "%)");

        QObject::connect(slice, &QPieSlice::hovered, [slice](bool state) {
            slice->setExploded(state);
            slice->setLabelVisible(state);
        });
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des tournois par Lieu");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}



void tournois::afficherDiagramme_tournois_Stat() {
    QChartView* chartView = DiagrammeCirculaire();
    if (chartView) {
        QWidget *window = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(chartView);
        window->setLayout(layout);
        window->resize(600, 400);
        window->show();
    } else {
        qDebug() << "Erreur lors de la création du diagramme.";
    }
}



