//#include "mainwindow.h"
#include "counter.h"

#include <QApplication>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QObject>
int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    //QWidget* window = new QWidget;
    QLabel* lbl = new QLabel("0");
    QPushButton* cmdplus = new QPushButton("ADD");
    QPushButton* cmdmins = new QPushButton("REMOVE");


  //window->setWindowTitle("Counter");

    // QVBoxLayout* layout = new QVBoxLayout();

    Counter* countr = new Counter();

    //lbl.show();
    // cmdplus.show();
    // cmdmins.show();

    // layout->addWidget(lbl);
    // layout->addWidget(cmdplus);
    // layout->addWidget(cmdmins);


    QObject::connect(cmdplus, SIGNAL(clicked()), countr, SLOT(slotInc()));
    QObject::connect(cmdmins, SIGNAL(clicked()), countr, SLOT(slotMnc()));

    QObject::connect(countr, SIGNAL(counterChanged(int)), lbl, SLOT(setNum(int)));
    QObject::connect(countr, SIGNAL(goodbye()), app, SLOT(quit()));


    window->resize(200, 100);
    window->show();

    return app.exec();
}
