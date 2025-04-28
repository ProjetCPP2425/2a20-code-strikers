#include "card.h"
#include "ui_card.h"

card::card(QWidget *parent ,QSqlDatabase &db)
    : QDialog(parent)
    , ui(new Ui::card),db(db)
{
       ui->setupUi(this);


    ui->comboBox_carton->addItem("rouge");
    ui->comboBox_carton->addItem("jaune");
    idJoeur = ui->lineEdit->text().toInt();
    if(ui->comboBox_carton->currentIndex()==0){
        rouge=true;
    }else{
        rouge=false;
    }
    qDebug() << "Card constructor called"; // 🔍 Add this

}

card::~card()
{
    delete ui;
}

void card::on_buttonBox_accepted()
{
    if (!db.open()) {
        qDebug() << "db not open";
        return;
    }
    idJoeur = ui->lineEdit->text().toInt();
    if(ui->comboBox_carton->currentIndex()==0){
        rouge=true;
    }else{
        rouge=false;
    }

    QSqlQuery q(db);

    qDebug()<<rouge;
    qDebug()<<idJoeur;
    if (rouge) {
        q.prepare("UPDATE JOEUR SET ROUGE = :rouge WHERE ID = :id");
        q.bindValue(":rouge", 1);
        q.bindValue(":id", idJoeur);
    } else {
        // Step 1: Select current JAUNE count
        q.prepare("SELECT YELLOW FROM JOEUR WHERE ID = :id");
        q.bindValue(":id", idJoeur);

        if (!q.exec()) {
            qDebug() << "Select failed:" ;
            return;
        }

        int nb = 0;
        if (q.next()) {
            nb = q.value(0).toInt();
        } else {
            qDebug() << "No player found with ID:" << idJoeur;
            return;
        }

        // Step 2: Decide what to do
        if (nb > 0) {
            q.prepare("UPDATE JOEUR SET YELLOW = :jaune, ROUGE = :rouge WHERE ID = :id");
            q.bindValue(":jaune", 0);
            q.bindValue(":rouge", 1);
            q.bindValue(":id", idJoeur);
        } else {
            q.prepare("UPDATE JOEUR SET YELLOW = YELLOW + 1 WHERE ID = :id");
            q.bindValue(":id", idJoeur);
        }
    }

    // Execute the UPDATE
    if (q.exec()) {
        qDebug() << "Carton attribué avec succès";
    } else {
        qDebug() << "Échec de l'attribution du carton:" ;
    }
}
