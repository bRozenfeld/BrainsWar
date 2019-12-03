#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public virtual Piece
{
public:
    Rook(std::string name, Cell *c, bool isWhite);
    void setAllowedCells(Board* board, std::vector<Cell*> ennemy_cells, std::vector<Cell*> ally_cells) override;
};

#endif // ROOK_H
