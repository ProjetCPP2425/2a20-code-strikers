#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "materiels.h"
#include <QMainWindow>
#include "reservationmanager.h"
#include "sms.h"
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_16_clicked();

    void on_pushButton_18_clicked();

    void on_affichRES_clicked(const QModelIndex &index);

    void on_pushButton_15_clicked();

    void rechercheMaterielsAuto(const QString &text);
     void on_triTypeComboBox_currentIndexChanged(const QString &text);
       void on_triEtatComboBox_currentIndexChanged(const QString &text);




       void on_pdf_materiels_clicked();

       void on_statbutton_clicked();
       void onReserverClicked();
       void onValiderReservation();



   private:
    Ui::MainWindow *ui;
    Materiels M;
    void on_ajouterButton_clicked();
    ReservationManager *m_reservationManager;
     SmsSender *smsSender;
};



#endif // MAINWINDOW_H
