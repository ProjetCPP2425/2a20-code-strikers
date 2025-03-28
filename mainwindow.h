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
#include <QSortFilterProxyModel>


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
    bool saisi;
    QSqlTableModel t;
    int selectedRow;
    int sort;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool connectDatabase();
    void setData(QString a,QString b,QString c,QString d,QString e,QString f,QString g,QDate h,QString i,QString j);
    void validateEmail();
    void onEditingFinished();
    void testNom();
    void testNBV();
    void testNBD();
    void testNBN();
    void testNBP();
    void testE();

private slots:

    void on_pushButton_17_clicked();
    void on_tableView_doubleClicked(const QModelIndex &index);
    void styleSheet(QWidget *um);





    void on_comboBox_3_currentIndexChanged(int index);

    void on_delete_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
     QSqlDatabase db;
    QSortFilterProxyModel *proxyModel;

};
#endif // MAINWINDOW_H
