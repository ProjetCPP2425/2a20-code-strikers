#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


    MainWindow w;
    if (Connection::createConnection()) {

         w.show();
        qDebug() << "Connexion à la base de données réussie.";

        QMessageBox::information(nullptr, QObject::tr("Base de données ouverte"),
                                 QObject::tr("Connexion réussie.\nCliquez sur Annuler pour fermer."),
                                 QMessageBox::Cancel);
        qDebug() << "✅ Lancement de MainWindow...";
        qDebug() << "✅ MainWindow affichée !";
    } else {
        qDebug() << "❌ Échec de la connexion à la base de données.";

        QMessageBox::critical(nullptr, QObject::tr("Base de données non ouverte"),
                              QObject::tr("Échec de la connexion.\nCliquez sur Annuler pour fermer."),
                              QMessageBox::Cancel);
        return -1;
    }

    return a.exec();
}
