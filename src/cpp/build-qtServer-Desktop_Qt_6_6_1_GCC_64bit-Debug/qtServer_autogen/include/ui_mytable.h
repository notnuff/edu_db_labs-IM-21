/********************************************************************************
** Form generated from reading UI file 'mytable.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTABLE_H
#define UI_MYTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTable
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;

    void setupUi(QWidget *MyTable)
    {
        if (MyTable->objectName().isEmpty())
            MyTable->setObjectName("MyTable");
        MyTable->resize(846, 592);
        verticalLayout = new QVBoxLayout(MyTable);
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(MyTable);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);


        retranslateUi(MyTable);

        QMetaObject::connectSlotsByName(MyTable);
    } // setupUi

    void retranslateUi(QWidget *MyTable)
    {
        MyTable->setWindowTitle(QCoreApplication::translate("MyTable", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyTable: public Ui_MyTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTABLE_H
