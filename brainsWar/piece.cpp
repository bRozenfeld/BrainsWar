#include "piece.h"

Piece::Piece(std::string name, Cell *c, bool isWhite)
{
    m_cell = c;
    m_name = name;
    m_is_white = isWhite;
}


std::string Piece::toString()
{
    std::string s = m_name;
    s += " : ";
    s += m_cell->getName();
    s += " -> |";
    for(auto &c : m_allowed_cells)
    {
        s += c->getName();
        s += "|";
    }

    return s;
}

void Piece::removeAllowedCell(Cell *c)
{
    for(unsigned int i = 0; i < m_allowed_cells.size(); i++)
    {
        if(c == m_allowed_cells[i])
        {
            m_allowed_cells.erase(m_allowed_cells.begin() + static_cast<int>(i));
        }
    }
}


Piece::~Piece()
{

}

