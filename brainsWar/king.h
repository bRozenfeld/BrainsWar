#ifndef KING_H
#define KING_H


#include "piece.h"

class King : public Piece
{
public:
    King(std::string name, Cell *c, bool isWhite);
    void setAllowedCells(Board* board, std::vector<Cell*> ennemy_cells, std::vector<Cell*> ally_cells) override;
};

#endif // KING_H
