#ifndef CARD_H
#define CARD_H

#include <QDialog>
#include <qsqldatabase.h>
#include <QSqlQuery>

namespace Ui {
class card;
}

class card : public QDialog
{
    Q_OBJECT

public:
     card(QWidget *parent,QSqlDatabase &db );
    ~card();
    int idJoeur;
    bool rouge;
    QSqlDatabase db;

private slots:
    void on_buttonBox_accepted();


private:
    Ui::card *ui;
    void attribuerCarte();

};

#endif // CARD_H
