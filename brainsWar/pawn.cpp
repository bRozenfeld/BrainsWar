#include "pawn.h"

Pawn::Pawn(std::string name, Cell *c, bool isWhite) : Piece(name, c, isWhite)
{
    m_start_y = c->getY();
}

void Pawn::setAllowedCells(Board *board, std::vector<Cell *> ennemy_cells, std::vector<Cell *> ally_cells)
{
    std::vector<Cell*> allowed_cells;
    int x = this->getCell()->getX();
    int y = this->getCell()->getY();
    int i, j;

    bool isFirstMove = true;
    if(m_start_y != y) isFirstMove = false;

    // white pawn

    if(isWhite())
    {
        // top direction
        i = x;
        j = y - 1;
        if( j >= 0)
        {
            Cell *c = board->getCell(i,j);
            // the cell as no ally piece, move not allowed
            if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
            {
                allowed_cells.push_back(c);
            }
        }

        if(isFirstMove)
        {
            j = y - 2;
            Cell *c = board->getCell(i,j);
            // the cell as no ally piece, move not allowed
            if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
            {
                allowed_cells.push_back(c);
            }
        }

        // diagonal top right if ennemy
        i = x + 1;
        j = y - 1;
        if(i < 8 and j >= 0)
        {
            Cell *c = board->getCell(i,j);
            // the cell has ennemy piece, move allowed
            if(std::find(ennemy_cells.begin(), ennemy_cells.end(), c) != ennemy_cells.end())
            {
                allowed_cells.push_back(c);
            }
        }

        // diagonal top left if ennemy
        i = x - 1;
        j = y - 1;
        if(i >= 0 and j >= 0)
        {
            Cell *c = board->getCell(i,j);
             // the cell as ennemy piece, move allowed
            if(std::find(ennemy_cells.begin(), ennemy_cells.end(), c) != ennemy_cells.end())
            {
                allowed_cells.push_back(c);
            }
        }
    }
    // black pawn
    // bottom direction
    else
    {
        i = x;
        j = y + 1;
        if( j >= 0)
        {
            Cell *c = board->getCell(i,j);
            // the cell as no ally piece, move not allowed
            if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
            {
                allowed_cells.push_back(c);
            }
        }

        if(isFirstMove)
        {
            j = y + 2;
            Cell *c = board->getCell(i,j);
            // the cell as no ally piece, move not allowed
            if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
            {
                allowed_cells.push_back(c);
            }
        }

        // diagonal bottom left if ennemy
        i = x - 1;
        j = y + 1;
        if(i >= 0 and j < 8)
        {
            Cell *c = board->getCell(i,j);
            // the cell as ennemy piece, move allowed
            if(std::find(ennemy_cells.begin(), ennemy_cells.end(), c) != ennemy_cells.end())
            {
                allowed_cells.push_back(c);
            }
        }

        // diagonal bottom right if ennemy
        i = x + 1;
        j = y + 1;
        if(i < 8 and j < 8)
        {
            Cell *c = board->getCell(i,j);
            // the cell as ennemy, move allowed
            if(std::find(ennemy_cells.begin(), ennemy_cells.end(), c) != ennemy_cells.end())
            {
                allowed_cells.push_back(c);
            }
        }
    }
    m_allowed_cells.insert(m_allowed_cells.end(), allowed_cells.begin(), allowed_cells.end());
}
