#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlError>
#include <QtCore>
#include <QSqlTableModel>
#include "QSqlDatabase"
#include "QDebug"
#include "QString"
#include "QDate"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool update;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool connectDatabase();
    void setData(QString a,QString b,QString c,QString d,QString e,QString f,QString g,QString h,QString i,QString j);

private slots:
    void on_pushButton_17_clicked();




    void on_pushButton_19_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
     QSqlDatabase db;

};
#endif // MAINWINDOW_H
