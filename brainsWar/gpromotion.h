#ifndef GPROMOTION_H
#define GPROMOTION_H

#include <QWidget>
#include <QPushButton>

#include "game.h"
#include "ggame.h"
#include "cell.h"

class GPromotion : public QWidget
{
Q_OBJECT

public:
    GPromotion(Game *g, Cell *c);
private slots:
    void queenButtonClicked();
    void rookButtonClicked();
    void bishopButtonClicked();
    void knightButtonClicked();
private:
    Game* m_game;
    Cell* m_cell;
};

#endif // GPROMOTION_H
