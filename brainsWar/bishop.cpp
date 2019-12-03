#include "bishop.h"

Bishop::Bishop(std::string name, Cell *c, bool isWhite) : Piece(name, c, isWhite)
{

}

void Bishop::setAllowedCells(Board* board, std::vector<Cell*> ennemy_cells, std::vector<Cell*> ally_cells)
{
    std::vector<Cell*> allowed_cells;
    int x = this->getCell()->getX();
    int y = this->getCell()->getY();
    int i, j;

    // diagonal right down
    i = x + 1;
    j = y + 1;
    while(i < 8 and j < 8) {
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
            j++;
        }
    }

    // diagonal left down
    i = x - 1;
    j = y + 1;
    while(j < 8 and i >= 0)
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
            j++;
        }
    }

    // diagonal top right
    i = x + 1;
    j = y - 1;
    while(j < 8 and i >= 0) {
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
            j--;
        }
    }

    // diagonal top left
    i = x - 1;
    j = y - 1;
    while(j < 8 and i >= 0) {
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
            j--;
        }
    }
    m_allowed_cells.insert(m_allowed_cells.end(), allowed_cells.begin(), allowed_cells.end());
}
