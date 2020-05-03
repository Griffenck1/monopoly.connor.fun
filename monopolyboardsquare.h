#ifndef MONOPOLYBOARDSQAURE_H
#define MONOPOLYBOARDSQAURE_H

#include <iostream>
#include <QColor>
#include <QGraphicsItem>
#include <QtWidgets>
#include <string>
#include <vector>

//These three are used for random #number generation
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum class SquareType { Go, Property, StudentDebt, GetOutOfFloridaFree, Florida, GoToFlorida, SegFault };

class MonopolyBoardSquare: public QObject, public QGraphicsItem {
    Q_OBJECT
    public:
        MonopolyBoardSquare(int x, int y, std::string name, int price);
        MonopolyBoardSquare(int x, int y, SquareType type, QImage image);

        QRectF boundingRect() const override;
        QPainterPath shape() const override;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

        int get_x(){return x_;}
        int get_y(){return y_;}

        void set_owner_id(int id){owner_id_ = id;}
        int get_owner_id(){return  owner_id_;}

        int get_price(){return price_;}

        std::string get_name(){return name_;}

        void SetOwner(int owner_id_);

    private:
        std::string name_;
        bool image_exists_;
        QImage image_;
        SquareType type_;
        int x_;
        int y_;
        int price_;
        //0 for no owner, 1 for player 1, 2 for player 2, 3 for not ownable
        int owner_id_;
        QColor square_color_;
};

#endif // MONOPOLYBOARDSQAURE_H
