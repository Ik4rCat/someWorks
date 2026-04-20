#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Window;
}
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window() override;

private slots:
    void on_numplusone_clicked();
    void on_nummunusone_clicked();


private:
    Ui::Window *ui;
    int counter = 0;
};
#endif // WINDOW_H
