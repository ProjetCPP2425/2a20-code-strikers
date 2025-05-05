/********************************************************************************
** Form generated from reading UI file 'smallwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMALLWINDOW_H
#define UI_SMALLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_smallwindow
{
public:
    QDialogButtonBox *buttonBox;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *lineEdit;

    void setupUi(QDialog *smallwindow)
    {
        if (smallwindow->objectName().isEmpty())
            smallwindow->setObjectName("smallwindow");
        smallwindow->resize(405, 295);
        buttonBox = new QDialogButtonBox(smallwindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        dateTimeEdit = new QDateTimeEdit(smallwindow);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(90, 110, 194, 26));
        lineEdit = new QLineEdit(smallwindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(90, 70, 113, 26));

        retranslateUi(smallwindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, smallwindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, smallwindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(smallwindow);
    } // setupUi

    void retranslateUi(QDialog *smallwindow)
    {
        smallwindow->setWindowTitle(QCoreApplication::translate("smallwindow", "Dialog", nullptr));
        lineEdit->setText(QCoreApplication::translate("smallwindow", "Match DATE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class smallwindow: public Ui_smallwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMALLWINDOW_H
