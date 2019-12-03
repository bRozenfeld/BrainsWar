#ifndef PIECE_H
#define PIECE_H

#include<string>
#include<vector>
#include<algorithm>

#include "cell.h"
#include "board.h"

//class Cell;
//class Board;

class Piece
{
public:
    Piece(std::string name, Cell *c, bool isWhite);
    Cell* getCell() { return m_cell; }
    std::string getName() { return m_name; }
    std::vector<Cell*> getAllowedCells() { return m_allowed_cells; }
    bool isWhite() { return m_is_white; }
    void setCell(Cell* c) { m_cell = c; }
    void removeAllowedCell(Cell *c);
    void clearAllowedCells() { m_allowed_cells.clear(); }
    std::string toString();
    void virtual setAllowedCells(Board* board, std::vector<Cell*> ennemy_cells, std::vector<Cell*> ally_cells) = 0;
    virtual ~Piece();
private:
    Cell* m_cell;
    std::string m_name;
    bool m_is_white;
protected:
    std::vector<Cell*> m_allowed_cells;
};

#endif // PIECE_H
