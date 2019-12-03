#include "knight.h"

Knight::Knight(std::string name, Cell *c, bool isWHite) : Piece(name, c, isWHite)
{

}

void Knight::setAllowedCells(Board *board, std::vector<Cell*> ennemy_cells, std::vector<Cell*> ally_cells)
{
    std::vector<Cell*> allowed_cells;
    int x = this->getCell()->getX();
    int y = this->getCell()->getY();
    int i, j;

    // up -> left
    i = x - 1;
    j = y - 2;
    if(i >= 0 and j >= 0)
    {
        Cell* c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    // left -> up
    i = x - 2;
    j = y - 1;
    if(i >= 0 and j >= 0)
    {
        Cell* c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    // left -> down
    i = x - 2;
    j = y + 1;
    if(i >= 0 and j < 8)
    {
        Cell* c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    // down -> left
    i = x - 1;
    j = y + 2;
    if(i >= 0 and j < 8)
    {
        Cell* c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    // down -> right
    i = x + 1;
    j = y + 2;
    if(i < 8 and j < 8)
    {
        Cell* c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    // right -> down
    i = x + 2;
    j = y + 1;
    if(i < 8 and j < 8)
    {
        Cell* c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    // right -> top
    i = x + 2;
    j = y - 1;
    if(i < 8 and j >= 0)
    {
        Cell* c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    // top -> right
    i = x + 1;
    j = y - 2;
    if(i < 8 and j >= 0 )
    {
        Cell* c = board->getCell(i,j);
        // the cell as no ally piece, move allowed
        if(!(std::find(ally_cells.begin(), ally_cells.end(), c) != ally_cells.end()))
        {
            allowed_cells.push_back(c);
        }
    }

    m_allowed_cells.insert(m_allowed_cells.end(), allowed_cells.begin(), allowed_cells.end());
}
