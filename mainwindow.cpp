#include "mainwindow.h"
#include "ui_mainwindow.h"  // ✅ Assure que ce fichier est bien généré
#include "connexion.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)  // ✅ Initialisation correcte
{
    ui->setupUi(this);  // ✅ Charge l'interface depuis mainwindow.ui
}

MainWindow::~MainWindow()
{
    delete ui;  // ✅ Libère la mémoire pour éviter les fuites
}
