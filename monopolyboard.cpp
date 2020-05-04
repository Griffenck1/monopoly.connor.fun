#include "monopolyboard.h"

MonopolyBoard::MonopolyBoard()
{
    game_over_ = false;

    std::string filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/Go.bmp";
    QString qs = filename.c_str();
    QImage go = QImage(qs);

    board_squares_head_ = new Node(new MonopolyBoardSquare(750, 750, SquareType::Go, go));

    int names_used = 0;
    Node* current = board_squares_head_;
    for(int i = 1; i < 24; i++){
        //It just so happens that all of my squares requiring images are divisible by 3
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

    current->next = board_squares_head_;

    players_.push_back(new Player(1, board_squares_head_));
    Player* p2 = players_[0]->clone();
    p2->set_id(2);
    players_.push_back(p2);
    players_[0]->set_other_player(players_[1]);
    players_[1]->set_other_player(players_[0]);


}

QRectF MonopolyBoard::boundingRect() const{
    return(QRectF(0, 0, 875, 875));
}

QPainterPath MonopolyBoard::shape() const{
    QPainterPath path;
    path.addRect(this->boundingRect());
    return path;
}

void MonopolyBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){
    Q_UNUSED(widget);
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

    Node* current = board_squares_head_;
    for(int i = 0; i < 24; i++){
        current->square_->paint(painter, item, widget);
        current = current->next;
    }

    for(Player* p : players_){
        p->paint(painter, item, widget);
    }
}
