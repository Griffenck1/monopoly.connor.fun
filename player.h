#ifndef PLAYER_H
#define PLAYER_H


#include "monopolyboardsquare.h"

/**
The Node Struct handles the interface between the player and the location for the linked list
*/
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

        int get_out_of_florida_free_uses(){return out_of_florida_free_uses_;}

        void Move();

        void DecrementCash(int amount){cash_ -= amount;}

        void IncrementCash(int amount){cash_ += amount;}

        int get_id(){return id_;}
        void set_id(int id){id_ = id;}

        void set_other_player(Player* p){other_player_ = p;}

        Node* get_location(){return location_;}

        //returns true if you are in florida, false if you are not
        bool in_florida(){return in_florida_;}

        void ReactToLocation();

        void get_out_of_florida(){in_florida_ = false;}

        void DecrementOutOfFloridaFreeUses(){out_of_florida_free_uses_--;}

        void IncrementOutOfFloridaFreeUses(){out_of_florida_free_uses_ ++;}


        //Clone method used to make player 2
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
