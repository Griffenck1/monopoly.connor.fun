#include "monopolywindow.h"
#include "ui_monopolywindow.h"

MonopolyWindow::MonopolyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MonopolyWindow)
{
    ui->setupUi(this);

    moves_to_go_ = 0;

    current_player_id_ = 1;

    can_roll_ = true;


    //initialize randum number seed
    srand(time(NULL));


    QGraphicsView *monopoly_board_view_local = ui->boardGraphicsView;
    QGraphicsScene *monopoly_board_view = new QGraphicsScene;
    monopoly_board_view_local->setScene(monopoly_board_view);
    monopoly_board_view_local->setSceneRect(0, 0, monopoly_board_view_local->frameSize().width(), monopoly_board_view_local->frameSize().height());

    board_ = new MonopolyBoard();

    monopoly_board_view->addItem(board_);


    SetCashLabels();
}

MonopolyWindow::~MonopolyWindow()
{
    delete ui;
}

void MonopolyWindow::RollDiceHelper(){
    if(moves_to_go_ > 0){
        board_->get_players()[current_player_id_ - 1]->Move();
        board_->update();
        moves_to_go_--;
        QTimer::singleShot(350, this, SLOT(RollDiceHelper()));
    }

}

void MonopolyWindow::on_rollDiceButton_clicked(){
    if(can_roll_ == true){
        int d1 = rand() % 6 + 1;
        int d2 = rand() % 6 + 1;
        int sum = d1+d2;

        std::string s = std::to_string(d1) + "+" + std::to_string(d2) + "=" + std::to_string(sum);
        QString qs = s.c_str();
        ui->rollDiceLabel->setText(qs);

        moves_to_go_ = sum;
        RollDiceHelper();
        if(d1 != d2){
            can_roll_ = false;
        }
    }
    else{
        std::string s = "Out of rolls for this turn";
        QString qs = s.c_str();
        ui->rollDiceLabel->setText(qs);
    }
}

void MonopolyWindow::on_endTurnButton_pressed(){
    if(current_player_id_ == 1){
        current_player_id_ = 2;
        can_roll_ = true;
    }
    else{
        current_player_id_ = 1;
        can_roll_ = true;
    }
}

void MonopolyWindow::SetCashLabels(){
    std::string s1 = "Player 1: $" + std::to_string(board_->get_players()[0]->get_cash());
    std::string s2 = "Player 2: $" + std::to_string(board_->get_players()[1]->get_cash());

    QString qs1 = s1.c_str();
    QString qs2 = s2.c_str();

    ui->player1CashLabel->setText(qs1);
    ui->player2CashLabel->setText(qs2);
}
