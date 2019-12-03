#ifndef QUEEN_H
#define QUEEN_H

#include "bishop.h"
#include "rook.h"
#include "piece.h"

class Queen : public Bishop, public Rook
{
public:
    Queen(std::string name, Cell *c, bool isWhite);
     void setAllowedCells(Board* board, std::vector<Cell*> ennemy_cells, std::vector<Cell*> ally_cells) override;
};

#endif // QUEEN_H
