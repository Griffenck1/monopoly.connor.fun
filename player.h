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
        Player(int id, Node* location);
        Player(Player* p);

        QRectF boundingRect() const override;
        QPainterPath shape() const override;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

        int get_cash(){return cash_;}

        void Move();

        void DecrementCash(int amount){cash_ -= amount;}

        void IncrementCash(int amount){cash_ += amount;}

        int get_id(){return id_;}
        void set_id(int id){id_ = id;}

        void set_other_player(Player* p){other_player_ = p;}

        Node* get_location(){return location_;}

        void ReactToLocation();

        bool in_florida(){return in_florida_;}

        void get_out_of_florida(){in_florida_ = false;}

        void DecrementOutOfFloridaFreeUses(){out_of_florida_free_uses_--;}

        void IncrementOutOfFloridaFreeUses(){out_of_florida_free_uses_ ++;}

        int get_out_of_florida_free_uses(){return out_of_florida_free_uses_;}

        Player* clone(){return new Player(this);}

    private:
        Player* other_player_;
        Node* location_;
        int id_;
        int cash_;
        int out_of_florida_free_uses_;
        bool in_florida_;
};

#endif // PLAYER_H
