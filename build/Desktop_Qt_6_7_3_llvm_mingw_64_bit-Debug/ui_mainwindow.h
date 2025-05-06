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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QGridLayout *gridLayout_2;
    QTableWidget *upper_menu;
    QGroupBox *groupBox_2;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLabel *logo;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_5;
    QLabel *label_12;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_46;
    QLabel *label_47;
    QLabel *label_48;
    QLabel *label_49;
    QPushButton *pushButton_17;
    QLabel *label_62;
    QTextEdit *IdTextEdit;
    QDateEdit *date_c;
    QComboBox *categorie_2;
    QLabel *nom_err;
    QLineEdit *email_2;
    QLineEdit *nom_eq_2;
    QLineEdit *entreneur_2;
    QLineEdit *nb_vict_2;
    QLineEdit *nb_def_2;
    QLineEdit *nb_pnt_2;
    QLineEdit *nb_null_2;
    QLabel *entreneur_err;
    QLabel *victoire_err;
    QLabel *def_err;
    QLabel *pnt_err;
    QLabel *null_err;
    QLabel *email_err;
    QLabel *label_50;
    QPushButton *pushButton_20;
    QComboBox *comboBox_3;
    QLabel *label_51;
    QPushButton *pushButton_39;
    QPushButton *pushButton_40;
    QCheckBox *checkBox_19;
    QCheckBox *checkBox_20;
    QCheckBox *checkBox_21;
    QCheckBox *checkBox_22;
    QCheckBox *checkBox_24;
    QCheckBox *checkBox_25;
    QCheckBox *checkBox_23;
    QCheckBox *checkBox_26;
    QCheckBox *checkBox_27;
    QCheckBox *checkBox_28;
    QTableView *tableView;
    QComboBox *search_box;
    QLineEdit *search_field;
    QPushButton *delete_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QWidget *page_4;
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QPushButton *pushButton_18;
    QWidget *page_5;
    QPushButton *pushButton_19;
    QTableView *tableView_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1634, 973);
        MainWindow->setMaximumSize(QSize(1634, 16777215));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMaximumSize(QSize(1634, 16777215));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 181, 67);"));
        page = new QWidget();
        page->setObjectName("page");
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 420, 93, 29));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(110, 470, 93, 29));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        horizontalLayout_2 = new QHBoxLayout(page_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName("groupBox");
        stackedWidget_2 = new QStackedWidget(groupBox);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(0, 0, 1634, 735));
        stackedWidget_2->setStyleSheet(QString::fromUtf8("padding:0px;"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        gridLayout_2 = new QGridLayout(page_3);
        gridLayout_2->setObjectName("gridLayout_2");
        upper_menu = new QTableWidget(page_3);
        if (upper_menu->columnCount() < 2)
            upper_menu->setColumnCount(2);
        QBrush brush(QColor(252, 252, 252, 255));
        brush.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setBackground(QColor(0, 0, 0));
        __qtablewidgetitem->setForeground(brush);
        upper_menu->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        upper_menu->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        upper_menu->setObjectName("upper_menu");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(upper_menu->sizePolicy().hasHeightForWidth());
        upper_menu->setSizePolicy(sizePolicy);
        upper_menu->setMaximumSize(QSize(16777215, 100));

        gridLayout_2->addWidget(upper_menu, 0, 1, 1, 2);

        groupBox_2 = new QGroupBox(page_3);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMaximumSize(QSize(200, 16777215));
        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 101, 41));
        label->setStyleSheet(QString::fromUtf8("    color: white; /* Texte en noir */\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color: rgb(0, 0, 0);\n"
"text-align: center;\n"
"\n"
""));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(30, 190, 121, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(30, 280, 121, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(30, 360, 121, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(30, 440, 121, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(30, 520, 121, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(30, 600, 121, 41));
        pushButton_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_9 = new QPushButton(groupBox_2);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(30, 670, 121, 41));
        pushButton_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        logo = new QLabel(groupBox_2);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(40, 90, 91, 91));

        gridLayout_2->addWidget(groupBox_2, 0, 0, 2, 1);

        groupBox_3 = new QGroupBox(page_3);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(244, 244, 244);"));
        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(0, 0, 351, 621));
        groupBox_5->setStyleSheet(QString::fromUtf8(" background-color: #d0f0fd; \n"
"Qtextedit{\n"
"background-color:white;\n"
"}"));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 10, 151, 41));
        label_12->setStyleSheet(QString::fromUtf8("    color: white; /* Texte en noir */\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color: rgb(0, 0, 0);\n"
"text-align: center;\n"
"\n"
""));
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_42 = new QLabel(groupBox_5);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(20, 80, 121, 21));
        label_42->setStyleSheet(QString::fromUtf8("    color: white; /* Texte en noir */\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color: rgb(0, 0, 0);\n"
"text-align: center;\n"
"\n"
""));
        label_42->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_43 = new QLabel(groupBox_5);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(200, 80, 121, 21));
        label_43->setStyleSheet(QString::fromUtf8("    color: white; /* Texte en noir */\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color: rgb(0, 0, 0);\n"
"text-align: center;\n"
"\n"
""));
        label_43->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_44 = new QLabel(groupBox_5);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(20, 180, 121, 21));
        label_44->setStyleSheet(QString::fromUtf8("    color: white; /* Texte en noir */\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color: rgb(0, 0, 0);\n"
"text-align: center;\n"
"\n"
""));
        label_44->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_45 = new QLabel(groupBox_5);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(200, 180, 121, 21));
        label_45->setStyleSheet(QString::fromUtf8("    color: white; /* Texte en noir */\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color: rgb(0, 0, 0);\n"
"text-align: center;\n"
"\n"
""));
        label_45->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_46 = new QLabel(groupBox_5);
        label_46->setObjectName("label_46");
        label_46->setGeometry(QRect(20, 280, 121, 21));
        label_46->setStyleSheet(QString::fromUtf8("    color: white; /* Texte en noir */\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color: rgb(0, 0, 0);\n"
"text-align: center;\n"
"\n"
""));
        label_46->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_47 = new QLabel(groupBox_5);
        label_47->setObjectName("label_47");
        label_47->setGeometry(QRect(200, 280, 121, 21));
        label_47->setStyleSheet(QString::fromUtf8("    color: white; /* Texte en noir */\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color: rgb(0, 0, 0);\n"
"text-align: center;\n"
"\n"
""));
        label_47->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_48 = new QLabel(groupBox_5);
        label_48->setObjectName("label_48");
        label_48->setGeometry(QRect(20, 370, 121, 21));
        label_48->setStyleSheet(QString::fromUtf8("    color: white; /* Texte en noir */\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color: rgb(0, 0, 0);\n"
"text-align: center;\n"
"\n"
""));
        label_48->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_49 = new QLabel(groupBox_5);
        label_49->setObjectName("label_49");
        label_49->setGeometry(QRect(200, 370, 91, 21));
        label_49->setStyleSheet(QString::fromUtf8("    color: white; /* Texte en noir */\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color: rgb(0, 0, 0);\n"
"text-align: center;\n"
"\n"
""));
        label_49->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_17 = new QPushButton(groupBox_5);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(20, 570, 111, 41));
        label_62 = new QLabel(groupBox_5);
        label_62->setObjectName("label_62");
        label_62->setGeometry(QRect(20, 470, 121, 21));
        label_62->setStyleSheet(QString::fromUtf8("    color: white; /* Texte en noir */\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color: rgb(0, 0, 0);\n"
"text-align: center;\n"
"\n"
""));
        label_62->setAlignment(Qt::AlignmentFlag::AlignCenter);
        IdTextEdit = new QTextEdit(groupBox_5);
        IdTextEdit->setObjectName("IdTextEdit");
        IdTextEdit->setGeometry(QRect(200, 580, 104, 31));
        date_c = new QDateEdit(groupBox_5);
        date_c->setObjectName("date_c");
        date_c->setGeometry(QRect(20, 390, 121, 31));
        date_c->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        categorie_2 = new QComboBox(groupBox_5);
        categorie_2->addItem(QString());
        categorie_2->addItem(QString());
        categorie_2->addItem(QString());
        categorie_2->setObjectName("categorie_2");
        categorie_2->setGeometry(QRect(200, 390, 141, 31));
        categorie_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        nom_err = new QLabel(groupBox_5);
        nom_err->setObjectName("nom_err");
        nom_err->setGeometry(QRect(0, 140, 151, 21));
        nom_err->setStyleSheet(QString::fromUtf8("color: rgb(255, 1, 1);\n"
""));
        email_2 = new QLineEdit(groupBox_5);
        email_2->setObjectName("email_2");
        email_2->setGeometry(QRect(20, 490, 121, 31));
        email_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        nom_eq_2 = new QLineEdit(groupBox_5);
        nom_eq_2->setObjectName("nom_eq_2");
        nom_eq_2->setGeometry(QRect(20, 101, 121, 31));
        nom_eq_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        entreneur_2 = new QLineEdit(groupBox_5);
        entreneur_2->setObjectName("entreneur_2");
        entreneur_2->setGeometry(QRect(200, 100, 121, 31));
        entreneur_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        nb_vict_2 = new QLineEdit(groupBox_5);
        nb_vict_2->setObjectName("nb_vict_2");
        nb_vict_2->setGeometry(QRect(20, 200, 121, 31));
        nb_vict_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        nb_def_2 = new QLineEdit(groupBox_5);
        nb_def_2->setObjectName("nb_def_2");
        nb_def_2->setGeometry(QRect(200, 200, 121, 31));
        nb_def_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        nb_pnt_2 = new QLineEdit(groupBox_5);
        nb_pnt_2->setObjectName("nb_pnt_2");
        nb_pnt_2->setGeometry(QRect(20, 300, 121, 31));
        nb_pnt_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        nb_null_2 = new QLineEdit(groupBox_5);
        nb_null_2->setObjectName("nb_null_2");
        nb_null_2->setGeometry(QRect(200, 300, 121, 31));
        nb_null_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        entreneur_err = new QLabel(groupBox_5);
        entreneur_err->setObjectName("entreneur_err");
        entreneur_err->setGeometry(QRect(210, 140, 101, 21));
        entreneur_err->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        victoire_err = new QLabel(groupBox_5);
        victoire_err->setObjectName("victoire_err");
        victoire_err->setGeometry(QRect(30, 240, 101, 21));
        victoire_err->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        def_err = new QLabel(groupBox_5);
        def_err->setObjectName("def_err");
        def_err->setGeometry(QRect(210, 240, 101, 21));
        def_err->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        pnt_err = new QLabel(groupBox_5);
        pnt_err->setObjectName("pnt_err");
        pnt_err->setGeometry(QRect(30, 340, 101, 21));
        pnt_err->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        null_err = new QLabel(groupBox_5);
        null_err->setObjectName("null_err");
        null_err->setGeometry(QRect(180, 340, 131, 21));
        null_err->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"color: rgb(255, 0, 0);"));
        email_err = new QLabel(groupBox_5);
        email_err->setObjectName("email_err");
        email_err->setGeometry(QRect(30, 530, 101, 21));
        email_err->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_50 = new QLabel(groupBox_3);
        label_50->setObjectName("label_50");
        label_50->setGeometry(QRect(360, 50, 91, 21));
        label_50->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_20 = new QPushButton(groupBox_3);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(420, 440, 141, 41));
        pushButton_20->setStyleSheet(QString::fromUtf8("background-color: rgb(104, 255, 23);\n"
"color: rgb(255, 255, 255);"));
        comboBox_3 = new QComboBox(groupBox_3);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(460, 50, 121, 22));
        comboBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_51 = new QLabel(groupBox_3);
        label_51->setObjectName("label_51");
        label_51->setGeometry(QRect(590, 50, 161, 21));
        label_51->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_39 = new QPushButton(groupBox_3);
        pushButton_39->setObjectName("pushButton_39");
        pushButton_39->setGeometry(QRect(750, 440, 121, 41));
        pushButton_39->setStyleSheet(QString::fromUtf8("background-color: rgb(104, 255, 23);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        pushButton_40 = new QPushButton(groupBox_3);
        pushButton_40->setObjectName("pushButton_40");
        pushButton_40->setGeometry(QRect(1190, 460, 121, 41));
        pushButton_40->setStyleSheet(QString::fromUtf8("background-color: rgb(104, 255, 23);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        checkBox_19 = new QCheckBox(groupBox_3);
        checkBox_19->setObjectName("checkBox_19");
        checkBox_19->setGeometry(QRect(1300, 310, 76, 20));
        checkBox_20 = new QCheckBox(groupBox_3);
        checkBox_20->setObjectName("checkBox_20");
        checkBox_20->setGeometry(QRect(1300, 280, 76, 20));
        checkBox_21 = new QCheckBox(groupBox_3);
        checkBox_21->setObjectName("checkBox_21");
        checkBox_21->setGeometry(QRect(1300, 250, 76, 20));
        checkBox_22 = new QCheckBox(groupBox_3);
        checkBox_22->setObjectName("checkBox_22");
        checkBox_22->setGeometry(QRect(1300, 220, 76, 20));
        checkBox_24 = new QCheckBox(groupBox_3);
        checkBox_24->setObjectName("checkBox_24");
        checkBox_24->setGeometry(QRect(1300, 190, 76, 20));
        checkBox_25 = new QCheckBox(groupBox_3);
        checkBox_25->setObjectName("checkBox_25");
        checkBox_25->setGeometry(QRect(1300, 220, 76, 20));
        checkBox_23 = new QCheckBox(groupBox_3);
        checkBox_23->setObjectName("checkBox_23");
        checkBox_23->setGeometry(QRect(1300, 190, 76, 20));
        checkBox_26 = new QCheckBox(groupBox_3);
        checkBox_26->setObjectName("checkBox_26");
        checkBox_26->setGeometry(QRect(1300, 250, 76, 20));
        checkBox_27 = new QCheckBox(groupBox_3);
        checkBox_27->setObjectName("checkBox_27");
        checkBox_27->setGeometry(QRect(1300, 310, 76, 20));
        checkBox_28 = new QCheckBox(groupBox_3);
        checkBox_28->setObjectName("checkBox_28");
        checkBox_28->setGeometry(QRect(1300, 280, 76, 20));
        tableView = new QTableView(groupBox_3);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(360, 140, 981, 261));
        tableView->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        search_box = new QComboBox(groupBox_3);
        search_box->addItem(QString());
        search_box->addItem(QString());
        search_box->addItem(QString());
        search_box->setObjectName("search_box");
        search_box->setGeometry(QRect(890, 50, 101, 22));
        search_box->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        search_field = new QLineEdit(groupBox_3);
        search_field->setObjectName("search_field");
        search_field->setGeometry(QRect(750, 50, 121, 31));
        search_field->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        delete_2 = new QPushButton(groupBox_3);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(980, 450, 93, 29));
        pushButton_10 = new QPushButton(groupBox_3);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(1000, 50, 81, 31));
        pushButton_11 = new QPushButton(groupBox_3);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(1090, 50, 81, 31));
        pushButton_12 = new QPushButton(groupBox_3);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(980, 510, 93, 29));
        pushButton_12->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pushButton_13 = new QPushButton(groupBox_3);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(770, 510, 93, 29));
        pushButton_13->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pushButton_14 = new QPushButton(groupBox_3);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(430, 520, 93, 29));
        pushButton_14->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 44, 44);"));
        pushButton_15 = new QPushButton(groupBox_3);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(430, 560, 75, 24));
        pushButton_16 = new QPushButton(groupBox_3);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(540, 520, 93, 29));
        pushButton_16->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 20, 20);"));

        gridLayout_2->addWidget(groupBox_3, 1, 1, 1, 2);

        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        verticalLayout = new QVBoxLayout(page_4);
        verticalLayout->setObjectName("verticalLayout");
        calendarWidget = new QCalendarWidget(page_4);
        calendarWidget->setObjectName("calendarWidget");

        verticalLayout->addWidget(calendarWidget);

        pushButton_18 = new QPushButton(page_4);
        pushButton_18->setObjectName("pushButton_18");

        verticalLayout->addWidget(pushButton_18);

        stackedWidget_2->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        pushButton_19 = new QPushButton(page_5);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(1300, 100, 75, 24));
        tableView_2 = new QTableView(page_5);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(500, 120, 671, 311));
        tableView_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        stackedWidget_2->addWidget(page_5);

        horizontalLayout_2->addWidget(groupBox);

        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1634, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "equipe", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "tournois", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        QTableWidgetItem *___qtablewidgetitem = upper_menu->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = upper_menu->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Fonctionnalite", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Equipes", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Touenois", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Sponsors", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Ressources", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Joeurs", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Arbitre", nullptr));
        logo->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_3->setTitle(QString());
        groupBox_5->setTitle(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "Ajouter equipe", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "Nom equipe", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "Entreneur", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "Nombre de victoire", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "Nombre de defaite", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "Nombre de point", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "matche Nulls", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "Date de creation", nullptr));
        label_49->setText(QCoreApplication::translate("MainWindow", "categorie", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        label_62->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        categorie_2->setItemText(0, QCoreApplication::translate("MainWindow", "Sinior", nullptr));
        categorie_2->setItemText(1, QCoreApplication::translate("MainWindow", "Junior", nullptr));
        categorie_2->setItemText(2, QString());

        nom_err->setText(QString());
        entreneur_err->setText(QString());
        victoire_err->setText(QString());
        def_err->setText(QString());
        pnt_err->setText(QString());
        null_err->setText(QString());
        email_err->setText(QString());
        label_50->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "Exportation PDF", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "Nombre De Points", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "Categorie", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "Date De Creation", nullptr));

        label_51->setText(QCoreApplication::translate("MainWindow", "Rechercher un Tournois", nullptr));
        pushButton_39->setText(QCoreApplication::translate("MainWindow", "Loterie", nullptr));
        pushButton_40->setText(QCoreApplication::translate("MainWindow", "statistics", nullptr));
        checkBox_19->setText(QString());
        checkBox_20->setText(QString());
        checkBox_21->setText(QString());
        checkBox_22->setText(QString());
        checkBox_24->setText(QString());
        checkBox_25->setText(QString());
        checkBox_23->setText(QString());
        checkBox_26->setText(QString());
        checkBox_27->setText(QString());
        checkBox_28->setText(QString());
        search_box->setItemText(0, QCoreApplication::translate("MainWindow", "Nom Equipe", nullptr));
        search_box->setItemText(1, QCoreApplication::translate("MainWindow", "Entreneur", nullptr));
        search_box->setItemText(2, QCoreApplication::translate("MainWindow", "email", nullptr));

        delete_2->setText(QCoreApplication::translate("MainWindow", "SUPPRIMER", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "cancel", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "modif", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Restart ", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "sendMatch", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
