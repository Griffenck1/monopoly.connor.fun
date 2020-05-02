#ifndef MONOPOLYBOARD_H
#define MONOPOLYBOARD_H

#include <iostream>
#include <QColor>
#include <QGraphicsItem>
#include <QtWidgets>


class MonopolyBoard: public QObject, public QGraphicsItem {

    Q_OBJECT

    public:
        MonopolyBoard();

        QRectF boundingRect() const override;
        QPainterPath shape() const override;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
};

#endif // MONOPOLYBOARD_H
