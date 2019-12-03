#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include "board.h"

class Pawn : public Piece
{
public:
    Pawn(std::string name, Cell *c, bool isWhite);
    void setAllowedCells(Board* board, std::vector<Cell*> ennemy_cells, std::vector<Cell*> ally_cells) override;
private:
    int m_start_y;
};

#endif // PAWN_H
