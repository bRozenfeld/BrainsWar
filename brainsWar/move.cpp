#include "move.h"

Move::Move(Cell *from, Cell *to, Piece *eaten)
{
    m_from = from;
    m_to = to;
    m_eaten = eaten;
}

std::string Move::toString()
{
    std::string s = m_from->toString() + " -> " + m_to->toString();
    if(m_eaten != nullptr)
    {
         s += " Previous piece: " + m_eaten->toString();
    }
    return s;
}
