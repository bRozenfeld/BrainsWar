#include "king.h"

King::King(std::string name, Cell *c, bool isWhite) : Piece(name, c, isWhite)
{
    m_start_x = c->getX();
    m_start_y = c->getY();
    m_has_moved = false;
    m_is_big_roque_possible = false;
    m_is_little_roque_possible = false;
}


void King::setAllowedCells(Board *board, std::vector<Cell *> ennemy_cells, std::vector<Cell *> ally_cells)
{
    std::vector<Cell*> allowed_cells;
    int x = this->getCell()->getX();
    int y = this->getCell()->getY();
    int i, j;

    if(m_start_x != x or m_start_y != y) m_has_moved = true;

    // right cell
    i = x + 1;
    j = y;
    if(i < 8)
    {
        Cell* c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    // left cell
    i = x - 1;
    j = y;
    if(i >= 0)
    {
        Cell *c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    // top cell
    i = x ;
    j = y - 1;
    if(j >= 0)
    {
        Cell *c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    //down cell
    i = x ;
    j = y + 1;
    if(j < 8)
    {
        Cell *c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    // diagonal top left
    i = x - 1;
    j = y - 1;
    if(i >= 0 and j >= 0)
    {
        Cell *c = board->getCell(i,j);
         // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    // diagonal top right
    i = x + 1;
    j = y - 1;
    if(i < 8 and j >= 0)
    {
        Cell *c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    // diagonal down left
    i = x - 1;
    j = y + 1;
    if(i >= 0 and j < 8)
    {
        Cell *c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }


    // diagonal down right
    i = x + 1;
    j = y + 1;
    if(i < 8 and j < 8)
    {
        Cell *c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    // add the roques cells
    if(isWhite() and m_is_big_roque_possible)
    {
        Cell *c = board->getCell(2,7);
        allowed_cells.push_back(c);
    }

    if(isWhite() and m_is_little_roque_possible)
    {
        Cell *c = board->getCell(6,7);
        allowed_cells.push_back(c);
    }

    if(!isWhite() and m_is_big_roque_possible)
    {
        Cell *c = board->getCell(2,0);
        allowed_cells.push_back(c);
    }

    if(!isWhite() and m_is_little_roque_possible)
    {
        Cell *c = board->getCell(6,0);
        allowed_cells.push_back(c);
    }


    m_allowed_cells.insert(m_allowed_cells.end(), allowed_cells.begin(), allowed_cells.end());
}
