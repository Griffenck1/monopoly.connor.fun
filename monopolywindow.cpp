#include "monopolywindow.h"
#include "ui_monopolywindow.h"

#include "monopolyboard.h"

MonopolyWindow::MonopolyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MonopolyWindow)
{
    ui->setupUi(this);

    QGraphicsView *monopoly_board_view_local = ui->boardGraphicsView;
    QGraphicsScene *monopoly_board_view = new QGraphicsScene;
    monopoly_board_view_local->setScene(monopoly_board_view);
    monopoly_board_view_local->setSceneRect(0, 0, monopoly_board_view_local->frameSize().width(), monopoly_board_view_local->frameSize().height());

    MonopolyBoard *b = new MonopolyBoard();


    MonopolyBoardSquare *s = new MonopolyBoardSquare(0, 0, SquareType::Property, "Cabin", 200);



    monopoly_board_view->addItem(s);

}

MonopolyWindow::~MonopolyWindow()
{
    delete ui;
}

