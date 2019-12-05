#ifndef KING_H
#define KING_H


#include "piece.h"

class King : public Piece
{
public:
    King(std::string name, Cell *c, bool isWhite);
    bool hasMoved() { return m_has_moved; }
    void setBigRoqueAllowed(bool allowed) { m_is_big_roque_possible = allowed; }
    void setLittleRoqueAllowed(bool allowed) { m_is_little_roque_possible = allowed; }
    void setAllowedCells(Board* board, std::vector<Cell*> ennemy_cells, std::vector<Cell*> ally_cells) override;
private:
    int m_start_x;
    int m_start_y;
    bool m_has_moved;
    bool m_is_big_roque_possible;
    bool m_is_little_roque_possible;
};

#endif // KING_H
