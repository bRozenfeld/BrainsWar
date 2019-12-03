#ifndef MOVE_H
#define MOVE_H

#include "cell.h"
#include "piece.h"

class Move
{
public:
    Move(Cell *from, Cell *to, Piece *eaten);
    Cell* getFrom() { return m_from; }
    Cell* getTo() { return m_to; }
    Piece* getPieceEaten() { return m_eaten; }
    std::string toString();
private:
    Cell *m_from;
    Cell *m_to;
    Piece *m_eaten;
};

#endif // MOVE_H
