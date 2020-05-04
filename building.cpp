#include "building.h"


QRectF Building::boundingRect() const {

}

QPainterPath Building::shape() const{

}

void Building::AddToLocationValue(){
    location_->QuadruplePrice();
}

int Building::CalculateCost(){
    return(location_->get_price()/2);
}

void Building::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){

}

House::House(MonopolyBoardSquare* location){
    location_ = location;
}

QRectF House::boundingRect() const {
    int x = location_->get_x();
    int y = location_->get_y();
    return(QRectF(x + 25, y + 40, 25, 25));
}

QPainterPath House::shape() const{
    QPainterPath path;
    path.addRect(this->boundingRect());
    return path;
}

void House::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){
    Q_UNUSED(widget);

    QBrush b = painter->brush();
    painter->setBrush(QBrush(QColor(0,255,0)));
    painter->drawRect(this->boundingRect());
}

Hotel::Hotel(MonopolyBoardSquare* location){
    location_ = location;
}

QRectF Hotel::boundingRect() const {
    int x = location_->get_x();
    int y = location_->get_y();
    return(QRectF(x + 60, y + 40, 50, 25));
}

QPainterPath Hotel::shape() const{
    QPainterPath path;
    path.addRect(this->boundingRect());
    return path;
}

void Hotel::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){
    Q_UNUSED(widget);

    QBrush b = painter->brush();
    painter->setBrush(QBrush(QColor(255,0,0)));
    painter->drawRect(this->boundingRect());
}
