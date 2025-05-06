#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tournois.h"
#include <QPainter>
#include "qrcode.h"


#include <QDate>
#include <QTextStream>
#include <QTextDocument>
// Inclure le fichier d'en-tête pour la vue de graphique QtCharts
#include <QtCharts/QChartView>
// Inclure le fichier d'en-tête pour la série de diagramme circulaire QtCharts
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
// Inclure le fichier d'en-tête pour la gestion de la disposition horizontale
#include <QHBoxLayout>
#include <QtCharts/QLegend>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts>
#include <QBarSet>
#include <QBarSeries>
#include <QLayout>
#include <QVector>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QPalette>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }  // ⚠️ Ajout de la déclaration de Ui::MainWindow
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_id_2_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_25_clicked();





    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;  // ✅ Déclaration du pointeur ui
    QSqlDatabase db;
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
