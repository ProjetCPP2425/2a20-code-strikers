#include "smallwindow.h"
#include "ui_smallwindow.h"
#include "mainwindow.h"
smallwindow::smallwindow(QWidget *parent,int id,QSqlDatabase db)
    : QDialog(parent),
    id(id)
    , ui(new Ui::smallwindow)
{
    ui->setupUi(this);
    this->id=id;
    this->db =db;
}

smallwindow::~smallwindow()
{
    delete ui;
}

void smallwindow::on_buttonBox_rejected()
{
    this->rejected();
    qDebug()<<id;
    qDebug()<<"rejected";
}


void smallwindow::on_buttonBox_accepted()
{
    this->accepted();
    qDebug()<<id;
    qDebug()<<"accepted";
    qDebug()<<id;
    qDebug()<<ui->dateTimeEdit->dateTime();
    QSqlQuery q(db);
    q.prepare("UPDATE EQUIPE SET "
                  "DATE_J = :DATE_J "
              "WHERE ID = :ID");
    q.bindValue(":DATE_J",ui->dateTimeEdit->dateTime());

    q.bindValue(":ID",id);
    if(q.exec()){
        qDebug()<<"date j modified succ";
    }else{
        qDebug()<<"date j modification echec";
    }
    q.prepare("SELECT DATE_J , NOM_EQUIPE FROM EQUIPE WHERE ID=:ID");
    q.bindValue(":ID",id);
    if(q.exec()){
        if(q.next()){
            QDate date = q.value("DATE_J").toDate();
            if(date ==QDate::currentDate()){
                QString name =q.value("NOM_EQUIPE").toString();
                QObject *p=parent();
                MainWindow *m =qobject_cast<MainWindow *>(p);
                m->showWindowsNotification(name);
            }
        }
    }else{
        qDebug()<<"here ";
    }
}

