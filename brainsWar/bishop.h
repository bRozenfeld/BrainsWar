#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop  : public virtual Piece
{
public:
    Bishop(std::string name, Cell *c, bool isWhite);
    void setAllowedCells(Board* board, std::vector<Cell*> ennemy_cells, std::vector<Cell*> ally_cells) override;
};

#endif // BISHOP_H
