#ifndef BUILDING_H
#define BUILDING_H

#include "monopolyboard.h"

class Building: public QObject, public QGraphicsItem {

    Q_OBJECT

    public:
        virtual QRectF boundingRect() const override;
        virtual QPainterPath shape() const override;

        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

        virtual int CalculateCost();

    //protected and not private so it can be inherited
    protected:
        MonopolyBoardSquare* location_;
};

class House: public Building {
    public:
        House(MonopolyBoardSquare* location);

        QRectF boundingRect() const;
        QPainterPath shape() const;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);
};

class Hotel: public Building {
    public:
        Hotel(MonopolyBoardSquare* location);

        QRectF boundingRect() const;
        QPainterPath shape() const;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);
};

#endif // BUILDING_H
