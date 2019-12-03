#include "queen.h"

Queen::Queen(std::string name, Cell *c, bool isWhite) : Piece(name, c, isWhite), Rook(name, c, isWhite), Bishop(name, c, isWhite)
{

}

void Queen::setAllowedCells(Board *board, std::vector<Cell *> ennemy_cells, std::vector<Cell *> ally_cells)
{
    Bishop::setAllowedCells(board, ennemy_cells, ally_cells);
    Rook::setAllowedCells(board, ennemy_cells, ally_cells);
}


