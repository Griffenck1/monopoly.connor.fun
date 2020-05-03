#ifndef PLAYER_H
#define PLAYER_H


#include "monopolyboardsquare.h"

struct Node{
    Node(MonopolyBoardSquare* square){
        square_ = square;
    }
    MonopolyBoardSquare* square_;
    Node* next;
};


class Player : public QObject, public QGraphicsItem{
    Q_OBJECT

    public:
        Player(int id);

        QRectF boundingRect() const override;
        QPainterPath shape() const override;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

        void Move(){location_ = location_->next;}

        int get_cash(){return cash_;}

        void DecrementCash(int amount ){cash_ -= amount;}

        int get_id(){return id_;}

        void setLocation(Node* n){location_ = n;}

        Node* get_location(){return location_;}

        void ReactToLocation();

    private:
        Node* location_;
        int id_;
        int cash_;
        int get_out_of_florida_free_;
};

#endif // PLAYER_H
