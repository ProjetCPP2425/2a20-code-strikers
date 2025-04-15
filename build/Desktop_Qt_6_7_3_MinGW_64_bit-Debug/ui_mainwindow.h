/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QTabWidget *tabWidget;
    QWidget *Acceuil;
    QLabel *label;
    QLineEdit *recherche;
    QPushButton *pushButton;
    QLabel *label_3;
    QComboBox *triTypeComboBox;
    QPushButton *pdf_materiels;
    QPushButton *pushButton_15;
    QPushButton *pushButton_2;
    QPushButton *btnReserver;
    QPushButton *pushButton_18;
    QGroupBox *groupBox;
    QLineEdit *nomRES;
    QLineEdit *localisationRES;
    QDateEdit *dateRES;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *LocalisationRES;
    QLineEdit *lineEdit_7;
    QPushButton *AjouterRES;
    QLineEdit *quantiteRES;
    QLineEdit *typeRES_2;
    QComboBox *typeComboBox;
    QComboBox *etatComboBox;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QTableView *affichRES;
    QPushButton *pushButton_16;
    QComboBox *triEtatComboBox;
    QPushButton *statbutton;
    QWidget *ReservationWidget;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_14;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QLineEdit *lineEdit_6;
    QLabel *label_4;
    QLabel *reservationHeaderLabel;
    QGroupBox *groupBoxDetails;
    QLineEdit *localisationRES_2;
    QDateEdit *dateRES_2;
    QLineEdit *lineEdit_8;
    QLineEdit *spinQuantite;
    QLineEdit *lineEdit_12;
    QPushButton *AjouterRES_2;
    QSpinBox *spinQuantite_3;
    QComboBox *comboTournois;
    QLineEdit *spinQuantite_2;
    QPushButton *btnAnnulerReservation;
    QPushButton *btnValider;
    QPushButton *btnRetourListe;
    QTableView *tableMaterielsDisponibles;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1129, 657);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-40, 0, 1501, 621));
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(40, 0, 1061, 631));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bold Art")});
        tabWidget->setFont(font);
        Acceuil = new QWidget();
        Acceuil->setObjectName("Acceuil");
        label = new QLabel(Acceuil);
        label->setObjectName("label");
        label->setGeometry(QRect(450, 40, 161, 31));
        recherche = new QLineEdit(Acceuil);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(640, 40, 51, 31));
        pushButton = new QPushButton(Acceuil);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(720, 40, 111, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 170, 255);\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        label_3 = new QLabel(Acceuil);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(490, 100, 51, 31));
        triTypeComboBox = new QComboBox(Acceuil);
        triTypeComboBox->setObjectName("triTypeComboBox");
        triTypeComboBox->setGeometry(QRect(560, 110, 61, 21));
        pdf_materiels = new QPushButton(Acceuil);
        pdf_materiels->setObjectName("pdf_materiels");
        pdf_materiels->setGeometry(QRect(500, 450, 111, 31));
        pdf_materiels->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 127);\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    \n"
"}\n"
"\n"
""));
        pushButton_15 = new QPushButton(Acceuil);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(890, 380, 111, 31));
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 127);\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    \n"
"}"));
        pushButton_2 = new QPushButton(Acceuil);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(730, 100, 81, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 170, 255);\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        btnReserver = new QPushButton(Acceuil);
        btnReserver->setObjectName("btnReserver");
        btnReserver->setGeometry(QRect(670, 530, 111, 31));
        btnReserver->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 0, 0);\n"
"	\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    \n"
"}\n"
"\n"
""));
        pushButton_18 = new QPushButton(Acceuil);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(450, 380, 121, 31));
        pushButton_18->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 127);\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    \n"
"}"));
        groupBox = new QGroupBox(Acceuil);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(170, 0, 241, 581));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background-color: #d0f0fd; /* Bleu ciel clair */\n"
"    border: 2px solid #90caf9; /* Bordure bleu pastel */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #1565c0; /* Texte bleu fonc\303\251 */\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    background-color: transparent; /* Fond du titre transparent */\n"
"    padding: 5px;\n"
"    color: #0d47a1; /* Couleur du titre en bleu fonc\303\251 */\n"
"    font-size: 15px;\n"
"}"));
        nomRES = new QLineEdit(groupBox);
        nomRES->setObjectName("nomRES");
        nomRES->setGeometry(QRect(10, 110, 161, 22));
        localisationRES = new QLineEdit(groupBox);
        localisationRES->setObjectName("localisationRES");
        localisationRES->setGeometry(QRect(10, 420, 161, 22));
        dateRES = new QDateEdit(groupBox);
        dateRES->setObjectName("dateRES");
        dateRES->setGeometry(QRect(10, 500, 161, 22));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(0, 0, 171, 41));
        lineEdit_2->setMinimumSize(QSize(141, 0));
        lineEdit_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-top-color: rgb(0, 0, 0);\n"
"gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"alternate-background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
" border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */"));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(10, 70, 61, 31));
        lineEdit_3->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-top-color: rgb(0, 0, 0);\n"
"gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"alternate-background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
" border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */"));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(10, 140, 71, 31));
        lineEdit_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-top-color: rgb(0, 0, 0);\n"
"gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"alternate-background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
" border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */"));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(10, 300, 61, 31));
        lineEdit_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-top-color: rgb(0, 0, 0);\n"
"gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"alternate-background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
" border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */"));
        LocalisationRES = new QLineEdit(groupBox);
        LocalisationRES->setObjectName("LocalisationRES");
        LocalisationRES->setGeometry(QRect(0, 380, 101, 31));
        LocalisationRES->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-top-color: rgb(0, 0, 0);\n"
"gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"alternate-background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
" border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */"));
        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(0, 460, 101, 31));
        lineEdit_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-top-color: rgb(0, 0, 0);\n"
"gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"alternate-background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
" border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */"));
        AjouterRES = new QPushButton(groupBox);
        AjouterRES->setObjectName("AjouterRES");
        AjouterRES->setGeometry(QRect(60, 540, 111, 31));
        AjouterRES->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 170, 255);\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        quantiteRES = new QLineEdit(groupBox);
        quantiteRES->setObjectName("quantiteRES");
        quantiteRES->setGeometry(QRect(10, 220, 111, 31));
        quantiteRES->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-top-color: rgb(0, 0, 0);\n"
"gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"alternate-background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
" border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */"));
        typeRES_2 = new QLineEdit(groupBox);
        typeRES_2->setObjectName("typeRES_2");
        typeRES_2->setGeometry(QRect(10, 260, 161, 22));
        typeComboBox = new QComboBox(groupBox);
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->setObjectName("typeComboBox");
        typeComboBox->setGeometry(QRect(10, 180, 151, 22));
        etatComboBox = new QComboBox(groupBox);
        etatComboBox->addItem(QString());
        etatComboBox->addItem(QString());
        etatComboBox->addItem(QString());
        etatComboBox->setObjectName("etatComboBox");
        etatComboBox->setGeometry(QRect(10, 340, 161, 22));
        groupBox_2 = new QGroupBox(Acceuil);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 0, 161, 601));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background-color: #d0f0fd; /* Bleu ciel clair */\n"
"    border: 2px solid #90caf9; /* Bordure bleu pastel */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #1565c0; /* Texte bleu fonc\303\251 */\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    background-color: transparent; /* Fond du titre transparent */\n"
"    padding: 5px;\n"
"    color: #0d47a1; /* Couleur du titre en bleu fonc\303\251 */\n"
"    font-size: 15px;\n"
"}"));
        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(20, 480, 111, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db; /* Bleu */\n"
"    color: blue; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(20, 410, 111, 41));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db; /* Bleu */\n"
"    color: blue; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        pushButton_9 = new QPushButton(groupBox_2);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(20, 340, 111, 41));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db; /* Bleu */\n"
"    color: blue; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        pushButton_10 = new QPushButton(groupBox_2);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(20, 270, 111, 41));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db; /* Bleu */\n"
"    color: blue; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        pushButton_11 = new QPushButton(groupBox_2);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(20, 550, 111, 41));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db; /* Bleu */\n"
"    color: blue; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        pushButton_12 = new QPushButton(groupBox_2);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(20, 190, 111, 41));
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db; /* Bleu */\n"
"    color: blue; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        pushButton_13 = new QPushButton(groupBox_2);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(20, 120, 111, 41));
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db; /* Bleu */\n"
"    color: blue; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 70, 101, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-top-color: rgb(0, 0, 0);\n"
"gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"alternate-background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
" border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
""));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 91, 61));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/475699257_1127413292009260_5552565568280010640_n (1).jpg")));
        affichRES = new QTableView(Acceuil);
        affichRES->setObjectName("affichRES");
        affichRES->setGeometry(QRect(490, 160, 471, 181));
        pushButton_16 = new QPushButton(Acceuil);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(670, 410, 121, 31));
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 127);\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    \n"
"}"));
        triEtatComboBox = new QComboBox(Acceuil);
        triEtatComboBox->setObjectName("triEtatComboBox");
        triEtatComboBox->setGeometry(QRect(640, 110, 71, 21));
        statbutton = new QPushButton(Acceuil);
        statbutton->setObjectName("statbutton");
        statbutton->setGeometry(QRect(820, 450, 121, 31));
        statbutton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 127);\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    \n"
"}"));
        tabWidget->addTab(Acceuil, QString());
        ReservationWidget = new QWidget();
        ReservationWidget->setObjectName("ReservationWidget");
        groupBox_3 = new QGroupBox(ReservationWidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(0, 0, 161, 601));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background-color: #d0f0fd; /* Bleu ciel clair */\n"
"    border: 2px solid #90caf9; /* Bordure bleu pastel */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #1565c0; /* Texte bleu fonc\303\251 */\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    background-color: transparent; /* Fond du titre transparent */\n"
"    padding: 5px;\n"
"    color: #0d47a1; /* Couleur du titre en bleu fonc\303\251 */\n"
"    font-size: 15px;\n"
"}"));
        pushButton_14 = new QPushButton(groupBox_3);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(20, 480, 111, 41));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db; /* Bleu */\n"
"    color: blue; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        pushButton_19 = new QPushButton(groupBox_3);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(20, 410, 111, 41));
        pushButton_19->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db; /* Bleu */\n"
"    color: blue; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        pushButton_20 = new QPushButton(groupBox_3);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(20, 340, 111, 41));
        pushButton_20->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db; /* Bleu */\n"
"    color: blue; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        pushButton_21 = new QPushButton(groupBox_3);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(20, 270, 111, 41));
        pushButton_21->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db; /* Bleu */\n"
"    color: blue; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        pushButton_22 = new QPushButton(groupBox_3);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(20, 550, 111, 41));
        pushButton_22->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db; /* Bleu */\n"
"    color: blue; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        pushButton_23 = new QPushButton(groupBox_3);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(20, 190, 111, 41));
        pushButton_23->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db; /* Bleu */\n"
"    color: blue; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        pushButton_24 = new QPushButton(groupBox_3);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(20, 120, 111, 41));
        pushButton_24->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db; /* Bleu */\n"
"    color: blue; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        lineEdit_6 = new QLineEdit(groupBox_3);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(20, 70, 101, 31));
        lineEdit_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-top-color: rgb(0, 0, 0);\n"
"gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"alternate-background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
" border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
""));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 0, 91, 61));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/475699257_1127413292009260_5552565568280010640_n (1).jpg")));
        reservationHeaderLabel = new QLabel(ReservationWidget);
        reservationHeaderLabel->setObjectName("reservationHeaderLabel");
        reservationHeaderLabel->setGeometry(QRect(400, 0, 231, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bold Art")});
        font1.setPointSize(16);
        reservationHeaderLabel->setFont(font1);
        groupBoxDetails = new QGroupBox(ReservationWidget);
        groupBoxDetails->setObjectName("groupBoxDetails");
        groupBoxDetails->setGeometry(QRect(240, 60, 501, 231));
        groupBoxDetails->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background-color: #d0f0fd; /* Bleu ciel clair */\n"
"    border: 2px solid #90caf9; /* Bordure bleu pastel */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #1565c0; /* Texte bleu fonc\303\251 */\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    background-color: transparent; /* Fond du titre transparent */\n"
"    padding: 5px;\n"
"    color: #0d47a1; /* Couleur du titre en bleu fonc\303\251 */\n"
"    font-size: 15px;\n"
"}"));
        localisationRES_2 = new QLineEdit(groupBoxDetails);
        localisationRES_2->setObjectName("localisationRES_2");
        localisationRES_2->setGeometry(QRect(10, 420, 161, 22));
        dateRES_2 = new QDateEdit(groupBoxDetails);
        dateRES_2->setObjectName("dateRES_2");
        dateRES_2->setGeometry(QRect(10, 500, 161, 22));
        lineEdit_8 = new QLineEdit(groupBoxDetails);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(170, 0, 171, 41));
        lineEdit_8->setMinimumSize(QSize(141, 0));
        QFont font2;
        font2.setPointSize(12);
        lineEdit_8->setFont(font2);
        lineEdit_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-top-color: rgb(0, 0, 0);\n"
"gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"alternate-background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
" border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */"));
        spinQuantite = new QLineEdit(groupBoxDetails);
        spinQuantite->setObjectName("spinQuantite");
        spinQuantite->setGeometry(QRect(380, 60, 91, 31));
        spinQuantite->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-top-color: rgb(0, 0, 0);\n"
"gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"alternate-background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
" border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */"));
        lineEdit_12 = new QLineEdit(groupBoxDetails);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(0, 460, 101, 31));
        lineEdit_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-top-color: rgb(0, 0, 0);\n"
"gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"alternate-background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
" border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */"));
        AjouterRES_2 = new QPushButton(groupBoxDetails);
        AjouterRES_2->setObjectName("AjouterRES_2");
        AjouterRES_2->setGeometry(QRect(60, 540, 111, 31));
        AjouterRES_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 170, 255);\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"}"));
        spinQuantite_3 = new QSpinBox(groupBoxDetails);
        spinQuantite_3->setObjectName("spinQuantite_3");
        spinQuantite_3->setGeometry(QRect(360, 100, 131, 22));
        comboTournois = new QComboBox(groupBoxDetails);
        comboTournois->setObjectName("comboTournois");
        comboTournois->setGeometry(QRect(10, 100, 141, 21));
        spinQuantite_2 = new QLineEdit(groupBoxDetails);
        spinQuantite_2->setObjectName("spinQuantite_2");
        spinQuantite_2->setGeometry(QRect(30, 60, 91, 31));
        spinQuantite_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-top-color: rgb(0, 0, 0);\n"
"gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"alternate-background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
" border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */"));
        btnAnnulerReservation = new QPushButton(groupBoxDetails);
        btnAnnulerReservation->setObjectName("btnAnnulerReservation");
        btnAnnulerReservation->setGeometry(QRect(20, 180, 101, 31));
        btnAnnulerReservation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 127);\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    \n"
"}"));
        btnValider = new QPushButton(groupBoxDetails);
        btnValider->setObjectName("btnValider");
        btnValider->setGeometry(QRect(200, 180, 101, 31));
        btnValider->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 127);\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    \n"
"}"));
        btnRetourListe = new QPushButton(groupBoxDetails);
        btnRetourListe->setObjectName("btnRetourListe");
        btnRetourListe->setGeometry(QRect(390, 180, 101, 31));
        btnRetourListe->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 127);\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 10px; /* Bords arrondis */\n"
"    padding: 8px 15px; /* Espacement interne */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    \n"
"}"));
        tableMaterielsDisponibles = new QTableView(ReservationWidget);
        tableMaterielsDisponibles->setObjectName("tableMaterielsDisponibles");
        tableMaterielsDisponibles->setGeometry(QRect(250, 340, 501, 181));
        tableMaterielsDisponibles->setAlternatingRowColors(false);
        tabWidget->addTab(ReservationWidget, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1129, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Rechercher des equipements :", nullptr));
        recherche->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Chercher", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        pdf_materiels->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Filtrer", nullptr));
        btnReserver->setText(QCoreApplication::translate("MainWindow", "Reservation", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        groupBox->setTitle(QString());
        nomRES->setText(QString());
#if QT_CONFIG(whatsthis)
        lineEdit_2->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>fdscv</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "Ajouter des equipements", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "Etat", nullptr));
        LocalisationRES->setText(QCoreApplication::translate("MainWindow", "Localisation", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "Date_d'ajout", nullptr));
        AjouterRES->setText(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        quantiteRES->setText(QCoreApplication::translate("MainWindow", "Quantite", nullptr));
        typeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Ballon", nullptr));
        typeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Terrain", nullptr));
        typeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Piquet", nullptr));
        typeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Filet", nullptr));

        etatComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "R\303\251serv\303\251", nullptr));
        etatComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\303\200 r\303\251parer", nullptr));
        etatComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Libre", nullptr));

        groupBox_2->setTitle(QString());
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Joueurs", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Ressources", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Sponsors", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Tournois", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Arbitres", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Equipes", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "      MENU ", nullptr));
        label_2->setText(QString());
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        statbutton->setText(QCoreApplication::translate("MainWindow", "Statstique", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Acceuil), QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        groupBox_3->setTitle(QString());
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Joueurs", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "Ressources", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "Sponsors", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "Tournois", nullptr));
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "Arbitres", nullptr));
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "Equipes", nullptr));
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("MainWindow", "      MENU ", nullptr));
        label_4->setText(QString());
        reservationHeaderLabel->setText(QCoreApplication::translate("MainWindow", "R\303\251servation de Mat\303\251riel", nullptr));
        groupBoxDetails->setTitle(QString());
#if QT_CONFIG(whatsthis)
        lineEdit_8->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>fdscv</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineEdit_8->setText(QCoreApplication::translate("MainWindow", "           D\303\251tails", nullptr));
        spinQuantite->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251", nullptr));
        lineEdit_12->setText(QCoreApplication::translate("MainWindow", "Date_d'ajout", nullptr));
        AjouterRES_2->setText(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        comboTournois->setPlaceholderText(QCoreApplication::translate("MainWindow", "Choisir un tournoi...", nullptr));
        spinQuantite_2->setText(QCoreApplication::translate("MainWindow", "Tournois", nullptr));
        btnAnnulerReservation->setText(QCoreApplication::translate("MainWindow", "Annuler ", nullptr));
        btnValider->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        btnRetourListe->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ReservationWidget), QCoreApplication::translate("MainWindow", "Fonctionnalites", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
