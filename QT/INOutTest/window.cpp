#include "window.h"
#include "./ui_window.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
}

Window::~Window()
{
    delete ui;
}

void Window::on_numplusone_clicked()
{
    counter++;
    ui->numCounter->setText(QString::number(counter));
}


void Window::on_nummunusone_clicked()
{
    counter--;
    ui->numCounter->setText(QString::number(counter));
}



