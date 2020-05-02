#ifndef MONOPOLYBOARDSQAURE_H
#define MONOPOLYBOARDSQAURE_H

#include <iostream>
#include <QColor>
#include <QGraphicsItem>
#include <QtWidgets>
#include <string>

enum class SquareType { Go, Property, Chance, CommunityChest, Florida, GoToFlorida, SegFault };

class MonopolyBoardSquare: public QObject, public QGraphicsItem {
    Q_OBJECT
    public:
        MonopolyBoardSquare(int x, int y, std::string name, int price);
        MonopolyBoardSquare(int x, int y, SquareType type, QImage image);

        QRectF boundingRect() const override;
        QPainterPath shape() const override;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    private:
        std::string name_;
        bool image_exists_;
        QImage image_;
        SquareType type_;
        int x_;
        int y_;
        int price_;
        int owner_;
        QColor color_;
};

#endif // MONOPOLYBOARDSQAURE_H
