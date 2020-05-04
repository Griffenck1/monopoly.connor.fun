#ifndef MONOPOLYWINDOW_H
#define MONOPOLYWINDOW_H

#include <QMainWindow>
#include "building.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MonopolyWindow; }
QT_END_NAMESPACE

class MonopolyWindow : public QMainWindow
{
    Q_OBJECT

public:
    MonopolyWindow(QWidget *parent = nullptr);
    ~MonopolyWindow();

private slots:
    void on_rollDiceButton_clicked();
    void RollDiceHelper();
    void on_endTurnButton_pressed();
    void SetCashLabels();
    void on_buyButton_pressed();
    void SetFloridaLabels();
    void SetLabels();
    void on_goFloridaButton_pressed();

private:
    Ui::MonopolyWindow *ui;

    MonopolyBoard *board_;

    int moves_to_go_;
    int current_player_id_;

    bool can_roll_;
};
#endif // MONOPOLYWINDOW_H
