#include "player.h"

Player::Player(int id){
    id_ = id;
    money_ = 2000;
}

QRectF Player::boundingRect() const{
    if(id_ == 1){
        return(QRectF(location_->square_->get_x() + 10, location_->square_->get_y() + 100, 25, 25));
    }
    else{
        return(QRectF(location_->square_->get_x() + 50, location_->square_->get_y() + 100, 25, 25));
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
