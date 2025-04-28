#include  <arduino.h>
#include "uiemp.h"
#include "ui_uiemp.h"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include "functions.h"
#include "arbitre.h"
#include <QFileDialog>
#include "smtp.h"
#include <QSortFilterProxyModel>
#include "card.h"
#include <QDesktopServices>
#include <QUrl>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),selectedRow(-1)
    , ui(new Ui::MainWindow),arbitrePlaying(-1)
{
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
    }
QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(fingerarduino()));





    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("tournois");//inserer le nom de la source de données
    db.setUserName("Montassar");//inserer nom de l'utilisateur
    db.setPassword("riahi123");//inserer mot de passe de cet utilisateur
    ui->setupUi(this);

    ui->pushButton_24->setVisible(false);
    fixTextColor();  // Ensure text color is set to black
    //connect(ui->pushButton_27, &QLineEdit::textChanged, this, &MainWindow::on_lineEditSearch_textChanged);
    timer = new QTimer(this);
    elapsedTime = QTime(0, 0, 0); // Starts from 00:00:00

    connect(timer, &QTimer::timeout, this, &MainWindow::updateChrono);

    //ui->label_time->setText(elapsedTime.toString("hh:mm:ss"));


    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect();


    shadowEffect->setBlurRadius(15);
    shadowEffect->setOffset(5, 5);
    shadowEffect->setColor(Qt::gray);

    ui->widget_3->setGraphicsEffect(shadowEffect);

    QGraphicsDropShadowEffect* shadowEffect2 = new QGraphicsDropShadowEffect();
    shadowEffect2->setBlurRadius(15);
    shadowEffect2->setOffset(5, 5);
    shadowEffect2->setColor(Qt::gray);
    ui->widget_4->setGraphicsEffect(shadowEffect2);

    QGraphicsDropShadowEffect* shadowEffect3 = new QGraphicsDropShadowEffect();
    shadowEffect3->setBlurRadius(15);
    shadowEffect3->setOffset(5, 5);
    shadowEffect3->setColor(Qt::gray);
    //ui->widget_6->setGraphicsEffect(shadowEffect3);

    QGraphicsDropShadowEffect* shadowEffect4 = new QGraphicsDropShadowEffect();
    shadowEffect4->setBlurRadius(15);
    shadowEffect4->setOffset(5, 5);
    shadowEffect4->setColor(Qt::gray);
    ui->widget_7->setGraphicsEffect(shadowEffect4);

    QGraphicsDropShadowEffect* shadowEffect5 = new QGraphicsDropShadowEffect();
    shadowEffect5->setBlurRadius(10);
    shadowEffect5->setOffset(2, 2);
    shadowEffect5->setColor(Qt::gray);
    ui->pushButton_6->setGraphicsEffect(shadowEffect5);

    QGraphicsDropShadowEffect* shadowEffect6 = new QGraphicsDropShadowEffect();
    shadowEffect6->setBlurRadius(10);
    shadowEffect6->setOffset(2, 2);
    shadowEffect6->setColor(Qt::gray);
    ui->widget_9->setGraphicsEffect(shadowEffect6);
    afficherArbitre();

}

void MainWindow::fixTextColor()
{
    QPalette palette = ui->nomui->palette();
    palette.setColor(QPalette::Text, Qt::black);
    ui->nomui->setPalette(palette);
    ui->prenomui->setPalette(palette);
    ui->ageui->setPalette(palette);
    //ui->idui->setPalette(palette);
    ui->numui->setPalette(palette);
    ui->nationaliteui->setPalette(palette);
}

void MainWindow::on_lineEditSearch_textChanged(const QString &text)
{
    Arbitre A(0, "", "", 0, "", 0);  // Remplacé "Employee" par "Arbitre"
    QSqlQueryModel *model = A.search(text);  // Appel de la méthode search de la classe Arbitre
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive); // Optionnel
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive); // Optionnel

    // Appliquer au tableau
    ui->tableView->setModel(proxyModel);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_pushButton_65_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_64_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Modifierui_2_clicked()
{
    int idmodif = ui->modifidui->text().toInt();
    Arbitre A(0, "", "", 0, "", 0);  // Remplacé "Employee" par "Arbitre"
    if (A.exist(idmodif))
    {
        ui->stackedWidget->setCurrentIndex(4);
        QString nom;
        QString prenom;
        QString nationalite;
        QString Age;
        int matchs_arbitres;



    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_9_clicked()
{

    QString nom = ui->nomui->text();
    QString prenom = ui->prenomui->text();
    QString age = ui->ageui->text();
    QString matchs_arbitres = ui->numui->text();
    QString nationalite= ui->nationaliteui->text();

    Arbitre A(0, nom ,prenom, age.toInt(), nationalite, matchs_arbitres.toInt());
    A.console();
    A.ajouter(db);
    ui->stackedWidget->setCurrentIndex(1);
    afficherArbitre();
    /*    bool testage, testid;
    int age = ageui.toInt(&testage);
    int id = idui.toInt(&testid);

    //name
    if (!isAlphabetic(nomui))
    {
        QMessageBox::warning(this, "Input Error", "nom is not alphabetic.");
    }
    //prenom
    if (!isAlphabetic(prenomui))
    {
        QMessageBox::warning(this, "Input Error", "prenom is not alphabetic.");
    }

    //age
    if (!testage)
    {
        QMessageBox::warning(this, "Input Error", "age should be a number.");
    }
    else if (age > 60 || age <= 17)
    {
        QMessageBox::warning(this, "Input Error", "you cannot add this arbitre because of his age.");
    }
    //id
    if (!testid)
    {
        QMessageBox::warning(this, "Input Error", "ID should have only numbers.");
    }
    else if (idui.length() != 8)
    {
        QMessageBox::warning(this, "Input Error", "ID should have 8 numbers.");
    }

    A.setNom(nomui);
    A.setPrenom(prenomui);
    A.setId(id);
    A.setMatchsArbitres(matchs_arbitres_ui.toInt());
    A.setAge(age);
    A.setNationalite(nationalite_ui);
    //bool test = A.ajouter();
   //*    if (!test)
    {
        QMessageBox::critical(this, "Input Error", "An error occurred while adding the arbitre.");
    }    ui->nomui->clear();
    ui->prenomui->clear();
    ui->ageui->clear();
    ui->idui->clear();
    ui->numui->clear();
    ui->adressui->clear();
    ui->tableView->setModel(A.afficher());*/

}

void MainWindow::on_pushButton_18_clicked()
{

}

void MainWindow::on_pushButton_20_clicked()
{
    Arbitre A(0, "", "", 0, "", 0);  // Remplacé "Employee" par "Arbitre"
    QString IDString = ui->deleteui->text();
    int ID = IDString.toInt();
    bool test = A.supprimer(ID);

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                                 QObject::tr("Suppression effectuée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(A.afficher());
        proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive); // Optionnel
        proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive); // Optionnel

        // Appliquer au tableau
        ui->tableView->setModel(proxyModel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                              QObject::tr("Suppression non effectuée.\n"
                                          "Click cancel to exit."), QMessageBox::Cancel);
    }
    ui->deleteui->clear();
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(A.afficher());
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive); // Optionnel
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive); // Optionnel

    // Appliquer au tableau
    ui->tableView->setModel(proxyModel);
}

void MainWindow::on_Modifierui_7_clicked()
{
    QString idui =ui->id4->text();
    QString nomui = ui->nomui_4->text();
    QString prenomui = ui->prenomui_4->text();
    QString ageui = ui->ageui_4->text();
    QString matchs_arbitres_ui = ui->numui_4->text();
    QString nationalite_ui = ui->nationaliteui_4->text();

    bool testage;
    int id = idui.toInt();
    int age = ageui.toInt();
    int matchs_arbitres = matchs_arbitres_ui.toInt();

    Arbitre A(id,nomui,prenomui,age,nationalite_ui,matchs_arbitres);
    A.console();
    A.modifier();
    ui->stackedWidget->setCurrentIndex(1);
    afficherArbitre();
    //name
    /*    if (!isAlphabetic(nomui))
    {
        QMessageBox::warning(this, "Input Error", "nom is not alphabetic.");
    }
    //prenom
    if (!isAlphabetic(prenomui))
    {
        QMessageBox::warning(this, "Input Error", "prenom is not alphabetic.");
    }

    //age
    if (!testage)
    {
        QMessageBox::warning(this, "Input Error", "age should be a number.");
    }
    else if (age > 60 || age <= 17)
    {
        QMessageBox::warning(this, "Input Error", "you cannot add this arbitre because of his age.");
    }
*/



}

void MainWindow::on_pushButton_10_clicked()
{
    Arbitre A(0, "", "", 0, "", 0);  // Remplacé "Employee" par "Arbitre"

    // Get the sorted model by name
    QSqlQueryModel *model = A.trier_par_nom();

    // Display the sorted model in the table view
    if (model)
    {
        QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(model);
        proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive); // Optionnel
        proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive); // Optionnel

        // Appliquer au tableau
        ui->tableView->setModel(proxyModel);
    }
    else
    {
        QMessageBox::warning(this, "Erreur de tri", "Le tri n'a pas pu être effectué.");
    }
}



void MainWindow::on_pushButton_13_clicked()
{
    Arbitre A(0, "", "", 0, "", 0);  // Remplacé "Employee" par "Arbitre"
    A.exportDataToPDF();
}

void MainWindow::on_pushButton_22_clicked()
{
    Arbitre A(0, "", "", 0, "", 0);  // Remplacé "Employee" par "Arbitre"
    A.afficherDiagrammeArbitreStat();
}


void MainWindow::on_Modifierui_9_clicked()
{
    sendMail();
}
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("zaabi.3omar@gmail.com", "dyrvzkxhbghunqme" , "smtp.gmail.com");
    //  Smtp::Smtp( const QString &user, const QString &pass, const QString &host, int port, int timeout )
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailsent(QString)));
    //smtp->sendMail("zaabi.3omar@gmail.com", "zaabi.3omar@gmail.com" , "Alert de securite","you entreded wrong password 3 times");
    //  QMessageBox::warning(this, "Erreur de tri", "Ouii oui .");
}


void MainWindow::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::afficherArbitre(){
    if(db.open()){
        qDebug()<<"work";
    }
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ARBITRES");
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive); // Optionnel
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive); // Optionnel

    // Appliquer au tableau
    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true); // Active le tri en cliquant sur les en-têtes

    // Tri initial par exemple sur le nom (colonne 1)
    proxyModel->sort(0, Qt::AscendingOrder);
    ui->tableView->setModel(proxyModel);
    ui->tableView->hideColumn(0);
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    selectedRow = index.row();
    qDebug()<<selectedRow;
    ui->pushButton_24->setVisible(true);
    ui->pushButton_25->setVisible(true);
}

void MainWindow::deleteArbitre(int r){
    QSqlQuery query;
    query.prepare("DELETE FROM ARBITRES WHERE ID= :id");
    query.bindValue(":id",r);
    if(query.exec()){
        qDebug()<<"deleted successfuly";
    }else{
        qDebug()<<"deleted echec";
    }
    afficherArbitre();
}

void MainWindow::on_pushButton_24_clicked()
{
    if(selectedRow != -1){
        int id = ui->tableView->model()->data(ui->tableView->model()->index(selectedRow,0)).toInt();
        qDebug()<<id;
        deleteArbitre(id);
        ui->pushButton_24->setVisible(false);
        ui->pushButton_25->setVisible(false);
        selectedRow=-1;
    }
}


void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    if(selectedRow!=-1){
        int id = ui->tableView->model()->data(ui->tableView->model()->index(selectedRow,0)).toInt();
        Arbitre A;
        qDebug()<<id;
        A.select(id);
        A.console();
        ui->nomui_4->setText(A.getNom());
        ui->prenomui_4->setText(A.getPrenom());
        ui->ageui_4->setText(QString::number(A.getAge())); ;
        ui->nationaliteui_4->setText(A.getNationalite());
        ui->numui_4->setText(QString::number(A.getMatchsArbitres()));
        ui->id4->setText(QString::number(id));
        ui->id4->setVisible(false);
        selectedRow =-1;
    }
}


void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_27_clicked()
{
    /*    QString nom = ui->lineEditSearch->text();
    QSqlQuery q;
    q.prepare("SELECT * FROM ARBITRE WHERE NOM = :nom");
    q.bindValue(":nom",nom);
    if(!q.exec()){
        qDebug()<<nom<<" not found";
    }else{
        QSqlQueryModel *model =new QSqlQueryModel();
        model->setQuery(q);
        QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(model);
        proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive); // Optionnel
        proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive); // Optionnel

        // Appliquer au tableau
        ui->tableView->setModel(proxyModel);
    }*/
    if(selectedRow!=-1){
        int id = ui->tableView->model()->data(ui->tableView->model()->index(selectedRow,0)).toInt();
        qDebug()<<id;

        QSqlQuery query;
        query.prepare("SELECT * FROM ARBITRES WHERE ID = :id");
        query.bindValue(":id",id);
        if(query.exec()){

            if(query.next()){
                int r=query.value("ROUGE").toInt();
                int j=query.value("JAUNE").toInt();
                int b=query.value("BLANC").toInt();
                qDebug()<<r;
                qDebug()<<j;
                qDebug()<<b;
                createPie(query.value("ROUGE").toInt(),query.value("JAUNE").toInt(),query.value("BLANC").toInt());
            }
        }
        selectedRow =-1;

    }
}

void MainWindow ::createPie(int r, int y, int w){
    // Values
    QMap<QString, qreal> values = {
        {"Carton rouge", r},
        {"Carton jaune", y},
        {"clean", w},
    };

    qreal total = 0;
    for (auto val : values)
        total += val;

    // Create the series
    QPieSeries *series = new QPieSeries();

    // Add slices with percentage labels
    for (auto it = values.begin(); it != values.end(); ++it) {
        qreal percent = (it.value() / total) * 100;
        QString label = QString("%1 - %2%").arg(it.key()).arg(QString::number(percent, 'f', 1));
        series->append(label, it.value());
    }

    // Optional: Customize first slice
    QPieSlice *first = series->slices().at(0);
    first->setExploded(true);
    first->setLabelVisible(true);
    first->setBrush(Qt::cyan);
    first->setPen(QPen(Qt::darkBlue, 2));

    // Show all labels
    for (QPieSlice *slice : series->slices()) {
        slice->setLabelVisible(true);
    }

    // Chart setup
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("match (%)");
    chart->legend()->hide();  // hide legend if labels are shown directly

    // Display chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(600, 400);
    chartView->show();

}

void MainWindow::on_pushButton_28_clicked()
{
    if(selectedRow != -1){
        QString location;
        int id = ui->tableView->model()->data(ui->tableView->model()->index(selectedRow,0)).toInt();
        QSqlQuery query;
        query.prepare("SELECT LOCALISATION FROM ARBITRES WHERE ID = :id");
        query.bindValue(":id",id);
        if(query.exec()){
            if(query.next()){
                    id =query.value(0).toInt();
                }
                QString mapUrl = "https://www.google.com/maps?q=48.8588443,2.2943506"; // Eiffel Tower
            QDesktopServices::openUrl(QUrl(mapUrl));
        }
    }
}


void MainWindow::on_pushButton_30_clicked()
{
   card *c = new card(this, db);
    c->show();
}


void MainWindow::on_pushButton_start_clicked()
{
    timer->start(1000); // update every second

    white=true;
    yellow=false;
    red=false;
}


void MainWindow::on_pushButton_stop_clicked()
{
    timer->stop();

}


void MainWindow::on_pushButton_reset_clicked()
{
    timer->stop();
    elapsedTime = QTime(0, 0, 0);
   // ui->label_time->setText(elapsedTime.toString("hh:mm:ss"));
    ui->lcd_chrono->display(elapsedTime.toString("hh:mm:ss"));

}
void MainWindow::updateChrono()
{
   /* elapsedTime = elapsedTime.addSecs(1);
    ui->label_time->setText(elapsedTime.toString("hh:mm:ss"));*/

    elapsedTime = elapsedTime.addSecs(1);
    ui->lcd_chrono->display(elapsedTime.toString("hh:mm:ss"));
}
