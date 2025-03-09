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
    void setData(QString a,QString b,QString c,QString d,QString e,QString f,QString g,QDate h,QString i,QString j);
    void validateEmail();
    void onEditingFinished();
    void testNom();
private slots:
    void on_pushButton_17_clicked();






    void on_tableView_doubleClicked(const QModelIndex &index);




private:
    Ui::MainWindow *ui;
     QSqlDatabase db;


};
#endif // MAINWINDOW_H
