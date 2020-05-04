#include "building.h"

/**
Many building methods are left purposefully empty
*/
QRectF Building::boundingRect() const {

}

QPainterPath Building::shape() const{

}

/**
Calculates the cost to build a building
*/
int Building::CalculateCost(){
    return(location_->get_price()/2);
}

void Building::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){

}

/**
House Cosntructor takes only a location
*/
House::House(MonopolyBoardSquare* location){
    location_ = location;
}

/**
Bounding Rect sets the bounds of the object
*/
QRectF House::boundingRect() const {
    int x = location_->get_x();
    int y = location_->get_y();
    return(QRectF(x + 25, y + 40, 25, 25));
}

/**
Defines the shape of the object
*/
QPainterPath House::shape() const{
    QPainterPath path;
    path.addRect(this->boundingRect());
    return path;
}

/**
Paints the house
*/
void House::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){
    Q_UNUSED(widget);

    QBrush b = painter->brush();
    painter->setBrush(QBrush(QColor(0,255,0)));
    painter->drawRect(this->boundingRect());
}

/**
Hotel constructor
*/
Hotel::Hotel(MonopolyBoardSquare* location){
    location_ = location;
}

/**
Same as bounding rec for house, but shifted to the right a bit, and made to be wider
*/
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

/**
Paints the hotel
*/
void Hotel::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){
    Q_UNUSED(widget);

    QBrush b = painter->brush();
    painter->setBrush(QBrush(QColor(255,0,0)));
    painter->drawRect(this->boundingRect());
}
