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
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <algorithm>
#include <random>
#include "match.h"
#include <QTextStream>
#include <QFile>
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
    void generatePDF();
    void createReportHTML();


    void on_pushButton_20_clicked();

    void on_upper_menu_cellChanged(int row, int column);

    void on_upper_menu_cellClicked(int row, int column);
    void showWindowsNotification(QString &s );
    std::vector<QString> checkForMatch(bool test);
    void shuffleTeams(std::vector<QString>& teams);
    void Loterie(std::vector<QString>& teams);
    void setMatches(QSqlDatabase &db);
    void generateHTML2();
    bool dynamicHtmlTemplate(const QString &templatePath, const QString &outputPath);
    void on_pushButton_39_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
     QSqlDatabase db;
    QSortFilterProxyModel *proxyModel;

};
#endif // MAINWINDOW_H
