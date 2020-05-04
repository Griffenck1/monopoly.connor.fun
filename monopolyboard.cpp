#include "monopolyboard.h"

/**
Constructor for monopoly board
*/
MonopolyBoard::MonopolyBoard()
{
    game_over_ = false;

    //starts by loding in the Go tile
    std::string filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/Go.bmp";
    QString qs = filename.c_str();
    QImage go = QImage(qs);

    //makes the Go Tile the head of the linked list
    board_squares_head_ = new Node(new MonopolyBoardSquare(750, 750, SquareType::Go, go));

    //The following goes through each space and loads in the appropriate tile int the appropriate location
    int names_used = 0;
    Node* current = board_squares_head_;
    for(int i = 1; i < 24; i++){
        if((i == 3) | (i == 15)){
            filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/StudentDebt.bmp";
            qs = filename.c_str();
            QImage student_debt = QImage(qs);
            current->next = new Node(new MonopolyBoardSquare(board_placements_[i].first, board_placements_[i].second, SquareType::StudentDebt, student_debt));
            current = current->next;
        }
        else if((i == 9) | (i == 21)){
            filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/GetOutFlorida.bmp";
            qs = filename.c_str();
            QImage go_florida = QImage(qs);
            current->next = new Node(new MonopolyBoardSquare(board_placements_[i].first, board_placements_[i].second, SquareType::GetOutOfFloridaFree, go_florida));
            current = current->next;
        }
        else if(i == 6){
            filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/InFlorida.bmp";
            qs = filename.c_str();
            QImage florida = QImage(qs);
            current->next = new Node(new MonopolyBoardSquare(board_placements_[i].first, board_placements_[i].second, SquareType::Florida, florida));
            current = current->next;
        }
        else if(i == 12){
            filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/SegFault.bmp";
            qs = filename.c_str();
            QImage seg_fault = QImage(qs);
            current->next = new Node(new MonopolyBoardSquare(board_placements_[i].first, board_placements_[i].second, SquareType::SegFault, seg_fault));
            current = current->next;
        }
        else if(i == 18){
            filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/GoToFlorida.bmp";
            qs = filename.c_str();
            QImage gt_florida = QImage(qs);
            current->next = new Node(new MonopolyBoardSquare(board_placements_[i].first, board_placements_[i].second, SquareType::GoToFlorida, gt_florida));
            current = current->next;
        }
        else{
            current->next = new Node(new MonopolyBoardSquare(board_placements_[i].first, board_placements_[i].second, location_names_[names_used], i*50));
            names_used++;
            current = current->next;
        }
    }

    //makes the head tail of the linked list connect back to the head
    current->next = board_squares_head_;

    //Creates players and enters them into vector
    players_.push_back(new Player(1, board_squares_head_));
    Player* p2 = players_[0]->clone();
    p2->set_id(2);
    players_.push_back(p2);
    players_[0]->set_other_player(players_[1]);
    players_[1]->set_other_player(players_[0]);


}

/**
Defines the bounds of the board
*/
QRectF MonopolyBoard::boundingRect() const{
    return(QRectF(0, 0, 875, 875));
}

/**
Defines the shape of the board
*/
QPainterPath MonopolyBoard::shape() const{
    QPainterPath path;
    path.addRect(this->boundingRect());
    return path;
}

/**
Paints the board
*/
void MonopolyBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){
    Q_UNUSED(widget);
    //Changes board face when game is over
    if(!game_over_){
        std::string filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/MonopolyBoardFace.bmp";
        QString qs = filename.c_str();
        QImage board_face = QImage(qs);
        painter->drawImage(QRect(125, 125, 625, 625), board_face);
    }
    else{
        std::string filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/Victory.bmp";
        QString qs = filename.c_str();
        QImage board_face = QImage(qs);
        painter->drawImage(QRect(125, 125, 625, 625), board_face);
        std::string s;
        if(players_[0]->get_cash() > players_[1]->get_cash()){
            s = "1";
            painter->setPen(QColor(0, 0 , 255));
        }
        else{
            s = "2";
            painter->setPen(QColor(255, 0 , 0));
        }
        qs = s.c_str();
        painter->drawText(560, 150, 100, 100, NULL, qs);
    }

    //this paints the board in a cascading manner by cycling through the elements held in the linked list, and calling on them to paint themselves
    Node* current = board_squares_head_;
    for(int i = 0; i < 24; i++){
        current->square_->paint(painter, item, widget);
        current = current->next;
    }

    for(Player* p : players_){
        p->paint(painter, item, widget);
    }
}
