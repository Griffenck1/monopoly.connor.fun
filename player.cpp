#include "player.h"

Player::Player(int id, Node* location){
    location_ = location;
    id_ = id;
    cash_ = 2000;
    in_florida_ = false;
    out_of_florida_free_uses_ = 0;
}

QRectF Player::boundingRect() const{
    int y_drop = 100;
    if(in_florida_ == true){
        y_drop = 50;
    }
    if(id_ == 1){
        return(QRectF(location_->square_->get_x() + 30, location_->square_->get_y() + y_drop, 25, 25));
    }
    else{
        return(QRectF(location_->square_->get_x() + 70, location_->square_->get_y() + y_drop, 25, 25));
    }
}

QPainterPath Player::shape() const{
    QPainterPath path;
    path.addRect(this->boundingRect());
    return path;
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){
    Q_UNUSED(widget);

    QBrush b = painter->brush();

    if(id_ == 1){
        painter->setBrush(QBrush(QColor(0,0,255)));
    }
    else{
        painter->setBrush(QBrush(QColor(255,0,0)));
    }
    painter->drawRect(this->boundingRect());
}

void Player::ReactToLocation(){
    int location_id = location_->square_->get_owner_id();
    SquareType location_type = location_->square_->get_square_type();

    if(location_type == SquareType::Property){
        if(((location_id == 1) | (location_id == 2)) & (id_ != location_id))
        {
            int rent = location_->square_->CalcualteRent();
            this->DecrementCash(rent);
            other_player_->IncrementCash(rent);
        }
    }
    else if(location_type == SquareType::SegFault){
        std::cout << "Seg Fault!" <<std::endl;
    }
    else if(location_type == SquareType::StudentDebt){
        this->DecrementCash(200);
    }
    else if(location_type == SquareType::GoToFlorida){
        in_florida_ = true;
        while(location_->square_->get_square_type() != SquareType::Florida){
            location_ = location_->next;
        }
    }
    else if(location_type == SquareType::GetOutOfFloridaFree){
        out_of_florida_free_uses_++;
    }
    else if(location_type == SquareType::Go){
        cash_ += 200;
    }
}

void Player::Move(){
    if(location_->square_->get_square_type() == SquareType::Go){
        cash_ += 200;
    }
    location_ = location_->next;
}
