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
    monopoly_board_view_ = new QGraphicsScene;
    monopoly_board_view_local->setScene(monopoly_board_view_);
    monopoly_board_view_local->setSceneRect(0, 0, monopoly_board_view_local->frameSize().width(), monopoly_board_view_local->frameSize().height());

    board_ = new MonopolyBoard();

    monopoly_board_view_->addItem(board_);


    SetCashLabels();
    SetFloridaLabels();

}

MonopolyWindow::~MonopolyWindow()
{
    delete ui;
}

void MonopolyWindow::RollDiceHelper(){
    if(moves_to_go_ > 0){
        board_->get_players()[current_player_id_ - 1]->Move();
        moves_to_go_--;
        QTimer::singleShot(350, this, SLOT(RollDiceHelper()));
    }
    board_->update();
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

        if(d1 != d2){
            can_roll_ = false;
        }
        else{
            board_->get_players()[current_player_id_ - 1]->get_out_of_florida();
        }

        if(!board_->get_players()[current_player_id_ - 1]->in_florida()){
            RollDiceHelper();
        }
    }
    else{
        std::string s = "Out of rolls for this turn";
        QString qs = s.c_str();
        ui->rollDiceLabel->setText(qs);
    }
}

void MonopolyWindow::on_endTurnButton_pressed(){
    board_->get_players()[current_player_id_ - 1]->ReactToLocation();
    SetLabels();
    board_->update();
    QString qs = NULL;
    ui->rollDiceLabel->setText(NULL);
    if(board_->get_players()[current_player_id_-1]->get_cash() < 0){
        board_->GameOver();
        board_->update();
        ui->goFloridaButton->deleteLater();
        ui->rollDiceButton->deleteLater();
        ui->endTurnButton->deleteLater();
        ui->buyButton->deleteLater();
    }
    else if(current_player_id_ == 1){
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

void MonopolyWindow::SetFloridaLabels(){
    std::string s1 = "Player 1: " + std::to_string(board_->get_players()[0]->get_out_of_florida_free_uses());
    std::string s2 = "Player 2: " + std::to_string(board_->get_players()[1]->get_out_of_florida_free_uses());

    QString qs1 = s1.c_str();
    QString qs2 = s2.c_str();

    ui->goFloridap1Label->setText(qs1);
    ui->goFloridap2Label->setText(qs2);
}

void MonopolyWindow::on_buyButton_pressed(){
    Player *current = board_->get_players()[current_player_id_ - 1];
    if(current->get_location()->square_->get_owner_id() == 0){
        current->get_location()->square_->SetOwner(current_player_id_);
        board_->update();
        current->DecrementCash(current->get_location()->square_->get_price());
        SetCashLabels();
    }
}

void MonopolyWindow::SetLabels(){
    SetCashLabels();
    SetFloridaLabels();
}

void MonopolyWindow::on_goFloridaButton_pressed(){
    Player* current = board_->get_players()[current_player_id_ - 1];
    if(current->get_out_of_florida_free_uses() > 0){
        current->get_out_of_florida();
        current->DecrementOutOfFloridaFreeUses();
    }
    board_->update();
}

void MonopolyWindow::on_buyBuildingButton_pressed(){
    Player* current = board_->get_players()[current_player_id_ - 1];
    if(current->get_location()->square_->get_owner_id() == current->get_id()){
        if(current->get_location()->square_->get_num_buidlings() == 0){
            House* house = new House(current->get_location()->square_);
            current->DecrementCash(house->CalculateCost());
            current->get_location()->square_->QuadruplePrice();
            current->get_location()->square_->IncrementNumBuidlings();
            monopoly_board_view_->addItem(house);
        }
        else if(current->get_location()->square_->get_num_buidlings() == 1){
            Hotel* hotel = new Hotel(current->get_location()->square_);
            current->DecrementCash(hotel->CalculateCost());
            current->get_location()->square_->QuadruplePrice();
            current->get_location()->square_->IncrementNumBuidlings();
            monopoly_board_view_->addItem(hotel);
        }
    }
    board_->update();
    SetLabels();
}
