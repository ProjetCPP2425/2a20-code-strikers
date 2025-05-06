#ifndef MAINWINDOW_H
#define MAINWINDOW_H
// Qt Core & GUI
#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlError>
#include <QtCore>
#include <QSqlTableModel>
#include "QSqlDatabase"
#include <QDebug>
#include "QString"
#include <QDate>
#include <QSortFilterProxyModel>
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QTextStream>
#include <QFile>
#include <QCalendar>
#include <QtGui>
#include <QPainter>
#include <QPrinter>
#include <QPalette>
#include <QInputDialog>

#include <QSystemTrayIcon>



// QtCharts
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QLegend>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

// Autres bibliothèques
#include <algorithm>
#include <random>
#include "match.h"
#include "smallwindow.h"
#include "piechart.h"
#include "materiels.h"
#include "reservationmanager.h"
#include "sms.h"
#include "arduinoo.h"
#include "tournois.h"
#include "qrcode.h"
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;

}
QT_END_NAMESPACE




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSerialPort *serial;

    bool saisi;
    QSqlTableModel t;
    int selectedRow;
    int sort;
    std::vector<QString>v;
    QMap<QDate, QStringList> matchesByDate;
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
     void showWindowsNotification(QString &s );
    void fetchMatches(QMap<QDate, QStringList> &matchesByDate);
     void displayOnCalendar();
    void createPieChart(int v,int d,int n);
     void setupSerial();
    void readSerialData();
     void onReserverClicked();
     void on_qrcodeM_clicked();

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

    std::vector<QString> checkForMatch(bool test);
    void shuffleTeams(std::vector<QString>& teams);
    void Loterie(std::vector<QString>& teams);
    void setMatches(QSqlDatabase &db);
    void generateHTML2();
    bool dynamicHtmlTemplate(const QString &templatePath, const QString &outputPath);
    void refreshPdf();
    void on_pushButton_39_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();
    QChartView  *createChart();
    void on_pushButton_15_clicked();
    void sendMatches();

    void on_pushButton_16_clicked();
    void loterie();
    bool checkId(QString s);

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_55_clicked();



    //ali//
    void on_show12_clicked();
    void on_AjouterRES_clicked();

    void on_suppp12_clicked();

    void on_affichRES_clicked(const QModelIndex &index);

    void on_modifie12_clicked();

    void rechercheMaterielsAuto(const QString &text);
    void on_triTypeComboBox_currentIndexChanged(const QString &text);
    void on_triEtatComboBox_currentIndexChanged(const QString &text);




    void on_pdf_materiels_clicked();

    void on_statbutton_clicked();



    void onValiderReservation();


    void on_btnAnnulerReservation_clicked();

    void on_btnValider_clicked();
    void detecterBadge();

    void on_btnReserver_clicked();


    //monta//
    void on_okM_clicked();

    void on_stasM_clicked();

    void on_pdfM_clicked();

    void on_id_2_textChanged(const QString &arg1);



    void on_filtrerM_clicked();

    void on_suppM_clicked();

    void on_modifM_clicked();
    void on_tableView_activated(const QModelIndex &index);


private:
    Ui::MainWindow *ui;
     QSqlDatabase db;
    QSortFilterProxyModel *proxyModel;
     Materiels M;
     void on_ajouterButton_clicked();
     ReservationManager *m_reservationManager;
     SmsSender *smsSender;
     QByteArray data;
     Arduinoo A;


     bool update;
     int id_update;
     tournois T;
     QSystemTrayIcon *m_trayIcon;
     QStringList m_upcomingEventsEnd;


     void checkUpcomingtournoissEnd();
     void updatetournoissButton();
     void on_checktournoisButton_clicked();

};
#endif // MAINWINDOW_H
