#include "monopolyboard.h"

MonopolyBoard::MonopolyBoard()
{

}

QRectF MonopolyBoard::boundingRect() const{
    return(QRectF(0, 0, 700, 700));
}

QPainterPath MonopolyBoard::shape() const{
    QPainterPath path;
    path.addRect(this->boundingRect());
    return path;
}

void MonopolyBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){
    Q_UNUSED(widget);

    std::string filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/MonopolyBoardFace.bmp";
    QString qs = filename.c_str();
    QImage board_face = QImage(qs);
    painter->drawImage(QRect(100, 100, 600, 600), board_face);

    filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/Go.bmp";
    qs = filename.c_str();
    QImage go = QImage(qs);
    painter->drawImage(QRect(700, 700, 100, 100), go);
}
