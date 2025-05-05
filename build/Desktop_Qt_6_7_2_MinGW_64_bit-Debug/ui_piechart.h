/********************************************************************************
** Form generated from reading UI file 'piechart.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIECHART_H
#define UI_PIECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pieChart
{
public:
    QWidget *widget;

    void setupUi(QWidget *pieChart)
    {
        if (pieChart->objectName().isEmpty())
            pieChart->setObjectName("pieChart");
        pieChart->resize(429, 295);
        widget = new QWidget(pieChart);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 411, 281));

        retranslateUi(pieChart);

        QMetaObject::connectSlotsByName(pieChart);
    } // setupUi

    void retranslateUi(QWidget *pieChart)
    {
        pieChart->setWindowTitle(QCoreApplication::translate("pieChart", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pieChart: public Ui_pieChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIECHART_H
