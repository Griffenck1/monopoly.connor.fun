#ifndef MONOPOLYBOARD_H
#define MONOPOLYBOARD_H

#include "monopolyboardsquare.h"

struct Node{
    Node(MonopolyBoardSquare* square){
        square_ = square;
    }
    MonopolyBoardSquare* square_;
    Node* next;
};

class MonopolyBoard: public QObject, public QGraphicsItem {

    Q_OBJECT

    public:
        MonopolyBoard();

        QRectF boundingRect() const override;
        QPainterPath shape() const override;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    private:
        //Locations names is made a global variable for ease of access
        const std::string location_names_[16] = {
            "The Hill", "Engineering Center", "Horoscope", "Monopoly", "C4C", "Cosmos", "Thor", "Solar Inches",
            "Music City", "Tiffins", "Chat", "Projekt Juice", "Long's Peak", "Quarantine Cabin", "Baseball Griffen", "Connor.fun"
        };

        //holds all the locations of board squares that need to be created in order of how they need to be created
        const std::pair<int, int> board_placements_[24]{
            {750, 750}, {625, 750}, {500, 750}, {375, 750}, {250, 750}, {125, 750}, {0, 750},
            {0, 625}, {0, 500}, {0, 375}, {0, 250}, {0, 125}, {0, 0},
            {125, 0}, {250, 0}, {375, 0}, {500, 0}, {625, 0}, {750, 0},
            {750, 125}, {750, 250}, {750, 375}, {750, 500}, {750, 625}
        };

        Node* board_squares_head_;
};

#endif // MONOPOLYBOARD_H
