#include "monopolyboard.h"

MonopolyBoard::MonopolyBoard()
{

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

    std::string filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/MonopolyBoardFace.bmp";
    QString qs = filename.c_str();
    QImage board_face = QImage(qs);
    painter->drawImage(QRect(125, 125, 625, 625), board_face);

    filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/Go.bmp";
    qs = filename.c_str();
    QImage go = QImage(qs);
    painter->drawImage(QRect(750, 750, 125, 125), go);

    filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/SegFault.bmp";
    qs = filename.c_str();
    QImage seg = QImage(qs);
    painter->drawImage(QRect(0, 0, 125, 125), seg);

    filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/InFlorida.bmp";
    qs = filename.c_str();
    QImage inFlor = QImage(qs);
    painter->drawImage(QRect(0, 750, 125, 125), inFlor);

    filename = "/home/griffen/Programming/CSCI_3010/HW5/monopoly.connor.fun/images/GoToFlorida.bmp";
    qs = filename.c_str();
    QImage GoFlor = QImage(qs);
    painter->drawImage(QRect(750, 0, 125, 125), GoFlor);
}
