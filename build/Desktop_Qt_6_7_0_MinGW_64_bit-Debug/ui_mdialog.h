/********************************************************************************
** Form generated from reading UI file 'mdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDIALOG_H
#define UI_MDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_MDialog
{
public:

    void setupUi(QDialog *MDialog)
    {
        if (MDialog->objectName().isEmpty())
            MDialog->setObjectName("MDialog");
        MDialog->resize(400, 300);

        retranslateUi(MDialog);

        QMetaObject::connectSlotsByName(MDialog);
    } // setupUi

    void retranslateUi(QDialog *MDialog)
    {
        MDialog->setWindowTitle(QCoreApplication::translate("MDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MDialog: public Ui_MDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDIALOG_H
