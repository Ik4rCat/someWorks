/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *numCounter;
    QPushButton *nummunusone;
    QPushButton *numplusone;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName("Window");
        Window->resize(800, 600);
        centralwidget = new QWidget(Window);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 20, 781, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        numCounter = new QLabel(gridLayoutWidget);
        numCounter->setObjectName("numCounter");
        numCounter->setCursor(QCursor(Qt::CursorShape::BusyCursor));
        numCounter->setAutoFillBackground(true);
        numCounter->setFrameShape(QFrame::Shape::NoFrame);
        numCounter->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(numCounter, 1, 0, 1, 1);

        nummunusone = new QPushButton(gridLayoutWidget);
        nummunusone->setObjectName("nummunusone");
        nummunusone->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        gridLayout->addWidget(nummunusone, 3, 0, 1, 1);

        numplusone = new QPushButton(gridLayoutWidget);
        numplusone->setObjectName("numplusone");
        numplusone->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        gridLayout->addWidget(numplusone, 2, 0, 1, 1);

        Window->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Window);
        statusbar->setObjectName("statusbar");
        Window->setStatusBar(statusbar);

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "Window", nullptr));
        numCounter->setText(QCoreApplication::translate("Window", "0", nullptr));
        nummunusone->setText(QCoreApplication::translate("Window", "-1", nullptr));
        numplusone->setText(QCoreApplication::translate("Window", "+1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
