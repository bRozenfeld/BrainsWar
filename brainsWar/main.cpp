#include<iostream>

#include "cell.h"
#include "board.h"
#include "game.h"
#include "ggame.h"

#include <QApplication>


using namespace std;

int main(int argc, char *argv[])
{
    Game *g = new Game();
    QApplication app(argc, argv);

    GGame *gg = new GGame(g);
    gg->show();

    return app.exec();

    /*
    Game *g1 = new Game();
    g1->displayBoard();
    g1->displayPossibleMoves();
    cout << endl;

    if(g1->isMovePossible(g1->getBoard()->getCell("A1"), g1->getBoard()->getCell("D1")))
    {
        g1->move(g1->getBoard()->getCell("A1"), g1->getBoard()->getCell("D1"));
        g1->update();
        g1->displayBoard();
        g1->displayPossibleMoves();
        cout << endl;
    }
    else
    {
        cout << "move impossible" << endl;
    }


    if(g1->isMovePossible(g1->getBoard()->getCell("A8"), g1->getBoard()->getCell("B8")))
    {
        g1->move(g1->getBoard()->getCell("A8"), g1->getBoard()->getCell("B8"));
        g1->update();
        g1->displayBoard();
        g1->displayPossibleMoves();
        cout << endl;
    }
    else
    {
        cout << "move impossible" << endl;
    }


    if(g1->isMovePossible(g1->getBoard()->getCell("A2"), g1->getBoard()->getCell("A4")))
    {
        g1->move(g1->getBoard()->getCell("A2"), g1->getBoard()->getCell("A4"));
        g1->update();
        g1->displayBoard();
        g1->displayPossibleMoves();
        cout << endl;
    }
    else
    {
        cout << "move impossible" << endl;
    }


    if(g1->isMovePossible(g1->getBoard()->getCell("B8"), g1->getBoard()->getCell("B5")))
    {
        g1->move(g1->getBoard()->getCell("B8"), g1->getBoard()->getCell("B5"));
        g1->update();
        g1->displayBoard();
        g1->displayPossibleMoves();
        cout << endl;
    }
    else
    {
        cout << "move impossible" << endl;
    }


    if(g1->isMovePossible(g1->getBoard()->getCell("A4"), g1->getBoard()->getCell("A6")))
    {
        g1->move(g1->getBoard()->getCell("A4"), g1->getBoard()->getCell("A6"));
        g1->update();
        g1->displayBoard();
        g1->displayPossibleMoves();
        cout << endl;
    }
    else
    {
        cout << "move impossible" << endl;
    }

    if(g1->isMovePossible(g1->getBoard()->getCell("A4"), g1->getBoard()->getCell("A5")))
    {
        g1->move(g1->getBoard()->getCell("A4"), g1->getBoard()->getCell("A5"));
        g1->update();
        g1->displayBoard();
        g1->displayPossibleMoves();
        cout << endl;
    }
    else
    {
        cout << "move impossible" << endl;
    }

    return 0;
    */

}
