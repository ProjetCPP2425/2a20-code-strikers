#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"  // ✅ Inclut la bonne classe

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    //Connection c;  // ✅ Utilisation correcte de la classe

    /*    if (c.createconnect()) {
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\\nClick Cancel to exit."),
                                 QMessageBox::Cancel);
        w.show();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\\nClick Cancel to exit."),
                              QMessageBox::Cancel);
    }
    */
     w.show();
    return a.exec();
}
