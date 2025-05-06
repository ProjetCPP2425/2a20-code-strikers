#ifndef SMALLWINDOW_H
#define SMALLWINDOW_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class smallwindow;
}
class MainWindow;
class smallwindow : public QDialog
{
    Q_OBJECT

public:
    int id;
    QSqlDatabase db;

    smallwindow(QWidget *parent ,int _id ,QSqlDatabase dataBase);
    ~smallwindow();

private slots:

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::smallwindow *ui;
};

#endif // SMALLWINDOW_H
