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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QTextEdit *textEdit;
    QLabel *label;
    QLineEdit *nom;
    QLabel *label_2;
    QLineEdit *lieu;
    QLabel *label_3;
    QDateEdit *datedebut;
    QLabel *label_4;
    QDateEdit *datefin;
    QPushButton *pushButton_13;
    QPushButton *pushButton_16;
    QLabel *label_5;
    QPushButton *pushButton;
    QLabel *label_13;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QTableWidget *tableWidget;
    QComboBox *comboBox_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_5;
    QTableView *tableView;
    QLineEdit *id;
    QLabel *label_6;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QWidget *tab_2;
    QLabel *label_19;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QLabel *label_20;
    QGroupBox *groupBox_2;
    QTextEdit *textEdit_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_11;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QLabel *label_21;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1352, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(90, 560, 104, 85));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(180, 10, 1161, 541));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    background-color: #f8f9fa; /* Blanc tr\303\250s clair */\n"
"    border: 2px solid #dcdcdc; /* Bordure gris clair */\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #ffffff; /* Blanc */\n"
"    color: black; /* Texte noir */\n"
"    padding: 8px 15px;\n"
"    border: 1px solid #dcdcdc;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #e3f2fd; /* Bleu tr\303\250s clair pour l'onglet actif */\n"
"    border-bottom: 2px solid #1565c0;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background-color: #f1f1f1; /* Gris tr\303\250s clair au survol */\n"
"}\n"
"\n"
"QTabWidget QWidget {\n"
"    background-color: #ffffff; /* Fond des widgets \303\240 l'int\303\251rieur en blanc */\n"
"}\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 30, 271, 471));
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
"}\n"
""));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(0, 0, 201, 41));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: black; /* Fond noir */\n"
"    color: white; /* Texte blanc pour contraste */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    border: 1px solid #dcdcdc; /* Bordure gris clair */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 5px;\n"
"}\n"
""));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 80, 63, 31));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: black; /* Fond noir */\n"
"    color: white; /* Texte blanc pour contraste */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    padding: 5px; /* Espacement int\303\251rieur */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"}\n"
""));
        nom = new QLineEdit(groupBox);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(10, 120, 201, 28));
        nom->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 159, 63, 31));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: black; /* Fond noir */\n"
"    color: white; /* Texte blanc pour contraste */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    padding: 5px; /* Espacement int\303\251rieur */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"}\n"
""));
        lieu = new QLineEdit(groupBox);
        lieu->setObjectName("lieu");
        lieu->setGeometry(QRect(10, 200, 201, 28));
        lieu->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 249, 101, 31));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: black; /* Fond noir */\n"
"    color: white; /* Texte blanc pour contraste */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    padding: 5px; /* Espacement int\303\251rieur */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"}\n"
""));
        datedebut = new QDateEdit(groupBox);
        datedebut->setObjectName("datedebut");
        datedebut->setGeometry(QRect(10, 290, 201, 29));
        datedebut->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    color: black; /* Texte en noir */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    border: 1px solid #dcdcdc; /* Bordure gris clair */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 3px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/icons/down-arrow.png); /* Ic\303\264ne personnalis\303\251e (optionnel) */\n"
"}\n"
""));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 329, 81, 31));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: black; /* Fond noir */\n"
"    color: white; /* Texte blanc pour contraste */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    padding: 5px; /* Espacement int\303\251rieur */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"}\n"
""));
        datefin = new QDateEdit(groupBox);
        datefin->setObjectName("datefin");
        datefin->setGeometry(QRect(10, 370, 211, 29));
        datefin->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    color: black; /* Texte en noir */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    border: 1px solid #dcdcdc; /* Bordure gris clair */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 3px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/icons/down-arrow.png); /* Ic\303\264ne personnalis\303\251e (optionnel) */\n"
"}\n"
""));
        pushButton_13 = new QPushButton(groupBox);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(50, 420, 91, 31));
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
"}\n"
"\n"
""));
        pushButton_16 = new QPushButton(groupBox);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(170, 420, 91, 31));
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
"\n"
""));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(310, 70, 171, 20));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black; /* Texte en noir */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    font-weight: normal; /* \303\211paisseur normale */\n"
"}\n"
""));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(640, 70, 83, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #87CEEB; /* Bleu ciel clair */\n"
"    color: white; /* Texte en blanc */\n"
"    border: 1px solid #66B3CC; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px 16px; /* Espacement int\303\251rieur */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background-color: #ADD8E6; /* Bleu l\303\251g\303\250rement plus clair lors du survol */\n"
"}\n"
""));
        label_13 = new QLabel(tab);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(760, 70, 81, 20));
        label_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black; /* Texte en noir */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    font-weight: normal; /* \303\211paisseur normale */\n"
"}\n"
""));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(980, 70, 83, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #87CEEB; /* Bleu ciel clair */\n"
"    color: white; /* Texte en blanc */\n"
"    border: 1px solid #66B3CC; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px 16px; /* Espacement int\303\251rieur */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background-color: #ADD8E6; /* Bleu l\303\251g\303\250rement plus clair lors du survol */\n"
"}\n"
""));
        comboBox = new QComboBox(tab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(830, 70, 141, 28));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white; /* Fond blanc */\n"
"    color: black; /* Texte noir */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    border: 1px solid #dcdcdc; /* Bordure gris clair */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Style pour la liste d\303\251roulante */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white; /* Fond blanc */\n"
"    color: black; /* Texte noir */\n"
"    selection-background-color: #c5cae9; /* Fond bleu clair pour l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"    selection-color: black; /* Texte noir pour l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"    border: 1px solid #dcdcdc;\n"
"}\n"
"\n"
"/* Style pour la fl\303\250che du QComboBox */\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icons/down-arrow-black.png); /* Ic\303\264ne de fl\303\250che personnalis\303\251e en noir */\n"
"}"
                        "\n"
"\n"
"/* Option pour une fl\303\250che noire par d\303\251faut (si tu n'as pas l'image personnalis\303\251e) */\n"
"QComboBox::down-arrow {\n"
"    border: 1px solid black; /* Bordure noire pour la fl\303\250che */\n"
"    border-radius: 3px; /* Coins arrondis pour la fl\303\250che */\n"
"}\n"
""));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(370, 170, 661, 221));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: white; /* Fond du tableau en blanc */\n"
"    color: black; /* Texte des cellules en noir */\n"
"    border: 1px solid #dcdcdc; /* Bordure gris clair */\n"
"}\n"
"\n"
"QTableWidget QTableWidgetItem {\n"
"    color: black; /* Texte des \303\251l\303\251ments (cellules) en noir */\n"
"    background-color: transparent; /* Fond transparent pour les cellules */\n"
"}\n"
"\n"
"/* Style pour les lignes s\303\251lectionn\303\251es */\n"
"QTableWidget::item:selected {\n"
"    background-color: #c5cae9; /* Fond bleu clair pour les \303\251l\303\251ments s\303\251lectionn\303\251s */\n"
"    color: black; /* Texte noir pour les \303\251l\303\251ments s\303\251lectionn\303\251s */\n"
"}\n"
"\n"
"/* Style pour l'ent\303\252te des colonnes (si n\303\251cessaire) */\n"
"QTableWidget QHeaderView::section {\n"
"    background-color: #f0f0f0; /* Fond des ent\303\252tes des colonnes */\n"
"    color: black; /* Texte des ent\303\252tes en noir */\n"
"    border: 1px solid #dcdcdc; /* Bord"
                        "ure autour des ent\303\252tes */\n"
"}\n"
""));
        comboBox_2 = new QComboBox(tab);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(490, 70, 141, 28));
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white; /* Fond blanc */\n"
"    color: black; /* Texte noir */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    border: 1px solid #dcdcdc; /* Bordure gris clair */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Style pour la liste d\303\251roulante */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white; /* Fond blanc */\n"
"    color: black; /* Texte noir */\n"
"    selection-background-color: #c5cae9; /* Fond bleu clair pour l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"    selection-color: black; /* Texte noir pour l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"    border: 1px solid #dcdcdc;\n"
"}\n"
"\n"
"/* Style pour la fl\303\250che du QComboBox */\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icons/down-arrow-black.png); /* Ic\303\264ne de fl\303\250che personnalis\303\251e en noir */\n"
"}"
                        "\n"
"\n"
"/* Option pour une fl\303\250che noire par d\303\251faut (si tu n'as pas l'image personnalis\303\251e) */\n"
"QComboBox::down-arrow {\n"
"    border: 1px solid black; /* Bordure noire pour la fl\303\250che */\n"
"    border-radius: 3px; /* Coins arrondis pour la fl\303\250che */\n"
"}\n"
""));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(320, 460, 141, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2ecc71;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    font-size: 14px;\n"
"    padding: 10px 20px;\n"
"    border: none;\n"
"    box-shadow: 3px 3px 5px rgba(0, 0, 0, 0.3);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #27ae60;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1e8449;\n"
"    box-shadow: none;\n"
"}\n"
""));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(750, 460, 131, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2ecc71;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    font-size: 14px;\n"
"    padding: 10px 20px;\n"
"    border: none;\n"
"    box-shadow: 3px 3px 5px rgba(0, 0, 0, 0.3);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #27ae60;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1e8449;\n"
"    box-shadow: none;\n"
"}\n"
""));
        textEdit_2 = new QTextEdit(tab);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(640, 460, 104, 41));
        textEdit_2->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: black; /* Fond noir */\n"
"    color: white; /* Texte blanc pour contraste */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    border: 1px solid #dcdcdc; /* Bordure gris clair */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 5px;\n"
"}\n"
""));
        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(950, 460, 131, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2ecc71;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    font-size: 14px;\n"
"    padding: 10px 20px;\n"
"    border: none;\n"
"    box-shadow: 3px 3px 5px rgba(0, 0, 0, 0.3);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #27ae60;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1e8449;\n"
"    box-shadow: none;\n"
"}\n"
""));
        tableView = new QTableView(tab);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(370, 170, 681, 231));
        tableView->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"color: rgb(7, 7, 7);"));
        id = new QLineEdit(tab);
        id->setObjectName("id");
        id->setGeometry(QRect(440, 110, 131, 28));
        id->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(320, 110, 81, 20));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black; /* Texte en noir */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    font-weight: normal; /* \303\211paisseur normale */\n"
"}\n"
""));
        pushButton_14 = new QPushButton(tab);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(590, 110, 91, 31));
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
"}\n"
"\n"
""));
        pushButton_15 = new QPushButton(tab);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(700, 110, 91, 31));
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
"\n"
""));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_19 = new QLabel(tab_2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 130, 541, 311));
        label_19->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/stas (4).png")));
        pushButton_23 = new QPushButton(tab_2);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(10, 50, 141, 41));
        pushButton_23->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2ecc71;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    font-size: 14px;\n"
"    padding: 10px 20px;\n"
"    border: none;\n"
"    box-shadow: 3px 3px 5px rgba(0, 0, 0, 0.3);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #27ae60;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1e8449;\n"
"    box-shadow: none;\n"
"}\n"
""));
        pushButton_24 = new QPushButton(tab_2);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(710, 50, 141, 41));
        pushButton_24->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2ecc71;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    font-size: 14px;\n"
"    padding: 10px 20px;\n"
"    border: none;\n"
"    box-shadow: 3px 3px 5px rgba(0, 0, 0, 0.3);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #27ae60;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1e8449;\n"
"    box-shadow: none;\n"
"}\n"
""));
        label_20 = new QLabel(tab_2);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(650, 160, 201, 231));
        label_20->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/qr code (1).png")));
        tabWidget->addTab(tab_2, QString());
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 10, 171, 541));
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
"}\n"
""));
        textEdit_3 = new QTextEdit(groupBox_2);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(30, 10, 104, 31));
        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(20, 130, 131, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
"\n"
"\n"
""));
        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(20, 190, 131, 41));
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
"}\n"
"\n"
""));
        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(20, 260, 131, 41));
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
"}\n"
"\n"
""));
        pushButton_11 = new QPushButton(groupBox_2);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(20, 320, 131, 41));
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
"}\n"
"\n"
""));
        pushButton_9 = new QPushButton(groupBox_2);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(20, 380, 131, 41));
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
"}\n"
"\n"
""));
        pushButton_10 = new QPushButton(groupBox_2);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(20, 430, 131, 41));
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
"}\n"
"\n"
""));
        pushButton_12 = new QPushButton(groupBox_2);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(20, 490, 131, 41));
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
"}\n"
"\n"
""));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(40, 50, 81, 71));
        label_21->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/475699257_1127413292009260_5552565568280010640_n (2).jpg")));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1352, 25));
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
        groupBox->setTitle(QString());
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:14px; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">Ajouter un tournois</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Lieu", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Date Debut", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Date Fin", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "ok", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "update", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Rechercher un Tournois :", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Date Debut", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Lieu", nullptr));

        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Id Tournois", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Lieu", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Date de Fin", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Date de Fin", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Id Tournois", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Lieu", nullptr));

        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Exportation PDF", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:14px; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">Id Tournois</span></p></body></html>", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "update", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        label_19->setText(QString());
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "Statistiques ", nullptr));
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "Qr Code", nullptr));
        label_20->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Fonctionnalit\303\251s", nullptr));
        groupBox_2->setTitle(QString());
        textEdit_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700; font-style:italic;\">Menu</span></p></body></html>", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Equipes", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Tournois", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Sponsors", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Ressources", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Joueurs", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Arbires", nullptr));
        label_21->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
