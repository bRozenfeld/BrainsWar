#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public virtual Piece
{
public:
    Rook(std::string name, Cell *c, bool isWhite);
    bool hasMoved() { return m_has_moved; }
    void setAllowedCells(Board* board, std::vector<Cell*> ennemy_cells, std::vector<Cell*> ally_cells) override;
private:
    bool m_has_moved;
    int m_start_x;
    int m_start_y;
};

#endif // ROOK_H
