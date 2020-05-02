#ifndef MONOPOLYWINDOW_H
#define MONOPOLYWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MonopolyWindow; }
QT_END_NAMESPACE

class MonopolyWindow : public QMainWindow
{
    Q_OBJECT

public:
    MonopolyWindow(QWidget *parent = nullptr);
    ~MonopolyWindow();

private:
    Ui::MonopolyWindow *ui;
};
#endif // MONOPOLYWINDOW_H
