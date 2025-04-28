#include "uiemp.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "arbitre.h"
#include <QLabel>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();


    return a.exec();
}
