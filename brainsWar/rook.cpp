#include "rook.h"

Rook::Rook(std::string name, Cell *c, bool isWhite) : Piece(name, c, isWhite)
{
    m_has_moved = false;
    m_start_x = c->getX();
    m_start_y = c->getY();
}


void Rook::setAllowedCells(Board* board, std::vector<Cell*> ennemy_cells, std::vector<Cell*> ally_cells)
{
    std::vector<Cell*> allowed_cells;
    int x = this->getCell()->getX();
    int y = this->getCell()->getY();
    int i, j;

    if(m_start_x != x or m_start_y != y) m_has_moved = true;


    //horizontal right
    i = x + 1;
    j = y;
    while(i < 8)
    {
        Cell* c = board->getCell(i,j);
        // the cell has an adverse piece, move allowed
        if(std::find(ennemy_cells.begin(), ennemy_cells.end(), c) != ennemy_cells.end())
        {
            allowed_cells.push_back(c);
            break;
        }
        // the cell as ally piece, move not allowed
        else if(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end())
        {
            break;
        }
        else
        {
            allowed_cells.push_back(c);
            i++;
        }
    }

    //horizontal left
    i = x - 1;
    j = y;
    while(i >= 0)
    {
        Cell* c = board->getCell(i,j);
        // the cell has an adverse piece, move allowed
        if(std::find(ennemy_cells.begin(), ennemy_cells.end(), c) != ennemy_cells.end())
        {
            allowed_cells.push_back(c);
            break;
        }
        // the cell as ally piece, move not allowed
        else if(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end())
        {
            break;
        }
        else
        {
            allowed_cells.push_back(c);
            i--;
        }
    }

    // vertical top
    i = x;
    j = y - 1;
    while(j >= 0)
    {
        Cell* c = board->getCell(i,j);
        // the cell has an adverse piece, move allowed
        if(std::find(ennemy_cells.begin(), ennemy_cells.end(), c) != ennemy_cells.end())
        {
            allowed_cells.push_back(c);
            break;
        }
        // the cell as ally piece, move not allowed
        else if(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end())
        {
            break;
        }
        else
        {
            allowed_cells.push_back(c);
            j--;
        }
    }

    // vertical down
    i = x;
    j = y + 1;
    while(j < 8)
    {
        Cell* c = board->getCell(i,j);
        // the cell has an adverse piece, move allowed
        if(std::find(ennemy_cells.begin(), ennemy_cells.end(), c) != ennemy_cells.end())
        {
            allowed_cells.push_back(c);
            break;
        }
        // the cell as ally piece, move not allowed
        else if(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end())
        {
            break;
        }
        else
        {
            allowed_cells.push_back(c);
            j++;
        }
    }

     m_allowed_cells.insert(m_allowed_cells.end(), allowed_cells.begin(), allowed_cells.end());
}
