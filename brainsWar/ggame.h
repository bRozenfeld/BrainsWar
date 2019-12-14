#ifndef GGAME_H
#define GGAME_H

#include <vector>

#include "game.h"
#include "gcell.h"
#include "piece.h"
#include "gpromotion.h"

#include <QWidget>
#include <QLabel>
#include <QFont>
#include <QEventLoop>

class GGame : public QWidget
{
Q_OBJECT

public:
    GGame(Game *g);
    GCell* getGCellFromCell(Cell* c);
    void updateGraphics();
private slots:
    void handleButton();
private:
    Game* m_game;
    GCell* m_source;
    GCell* m_destination;
    std::vector<std::vector<GCell*>> m_board;

};

#endif // GGAME_H
