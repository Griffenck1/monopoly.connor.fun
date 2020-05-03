#include "monopolyboardsquare.h"



MonopolyBoardSquare::MonopolyBoardSquare(int x, int y, std::string name, int price){
    x_ = x;
    y_ = y;
    type_ = SquareType::Property;
    image_exists_ = false;
    name_ = name;
    square_color_ = QColor(255,255,255);
    price_ = price;
    owner_id_ = 0;
}

MonopolyBoardSquare::MonopolyBoardSquare(int x, int y, SquareType type, QImage image){
    x_ = x;
    y_ = y;
    type_ = type;
    image_ = image;
    image_exists_ = true;
    square_color_ = QColor(255,255,255);
    owner_id_ = 3;
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
        QBrush b = painter->brush();
        painter->setBrush(QBrush(QColor(68,94,109)));
        painter->drawRect(this->boundingRect());
        painter->setPen(QColor(255,196,59));
        QString qs = name_.c_str();
        //This section resizes the font to fit properly
        float factor = (this->boundingRect().width() - 10) / painter->fontMetrics().width(qs);
        if(factor < 1)
        {
            QFont f = painter->font();
            f.setPointSizeF(f.pointSizeF()*factor);
            painter->setFont(f);
        }
        painter->drawText(x_ + 10, y_ + 10, this->boundingRect().width(), 50, NULL, qs);
        qs = ("$"+std::to_string(price_)).c_str();
        painter->drawText(x_ + 10, y_ + 75, this->boundingRect().width(), 50, NULL, qs);
        painter->setBrush(QBrush(square_color_));
        painter->setPen(square_color_);
        painter->drawRect(x_, y_+100, 123, 23);
    }
}

void MonopolyBoardSquare::SetOwner(int id){
    owner_id_ = id;
    if(owner_id_ == 1){
        square_color_ = QColor(0, 0, 200);
    }
    else if(owner_id_ == 2){
        square_color_ = QColor(200, 0, 0);
    }
}

int MonopolyBoardSquare::CalcualteRent(){
    std::cout << name_ + " " + std::to_string(price_/10) << std::endl;
    return price_/10;
}
