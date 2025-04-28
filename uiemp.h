#include  <arduino.h>
#ifndef UIEMP_H
#define UIEMP_H
#include "arbitre.h"
#include <QMainWindow> // Include the Arbitre class instead of Employee
#include "connection.h"
#include "QSqlQueryModel"
#include "card.h"
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool white ;
    bool yellow;
    bool red;
    int arbitrePlaying;
private slots:
    void on_pushButton_6_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_65_clicked();
    void on_pushButton_64_clicked();
    void on_pushButton_21_clicked();
    void on_lineEditSearch_textChanged(const QString &text);


    void on_pushButton_18_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();
    void on_Modifierui_2_clicked();
    void on_Modifierui_7_clicked();
    void afficherArbitre();  // Adjust method name to match changes

    void on_pushButton_13_clicked();

    void on_pushButton_22_clicked();

    void on_Modifierui_9_clicked();
    void sendMail();
    void fixTextColor(); // Declare fixTextColor method
    void deleteArbitre(int r);

    void on_pushButton_23_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_reset_clicked();
    void updateChrono();
    void createPie(int red, int yellow, int white);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    int selectedRow;
    QTimer *timer;
    QTime elapsedTime;
    QByteArray data;
    arduino A;
};

#endif // UIEMP_H
