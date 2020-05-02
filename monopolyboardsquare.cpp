#include "monopolyboardsquare.h"



MonopolyBoardSquare::MonopolyBoardSquare(int x, int y, SquareType type){
    x_ = x;
    y_ = y;
    type_ = type;
    image_exists_ = false;
}

MonopolyBoardSquare::MonopolyBoardSquare(int x, int y, SquareType type, QImage image){
    x_ = x;
    y_ = y;
    type_ = type;
    image_ = image;
    image_exists_ = true;
}

QRectF MonopolyBoardSquare::boundingRect() const{
    return QRectF(x_, y_, 125, 125);
}

QPainterPath MonopolyBoardSquare::shape() const{
    QPainterPath path;
    path.addRect(this->boundingRect());
    return path;
}

void MonopolyBoardSquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){
    Q_UNUSED(widget);

    //image will exist for all squares except chance, community chest, and properties
    if(image_exists_){
        painter->drawImage(QRect(x_, y_, 125, 125), image_);
    }
    else{

    }
}
