#ifndef BOARD_H
#define BOARD_H

#include<vector>
#include<string>
#include "cell.h"

class Board
{
public:
    Board();
    Board(const Board &b);
    Cell* getCell(int x, int y) { return m_board[static_cast<unsigned int>(y)][static_cast<unsigned int>(x)]; }
    Cell* getCell(std::string cellName);
    void removeCell(std::string cellName);
    std::vector<std::vector<Cell*>> getBoard() { return m_board; }
private:
    std::vector<std::vector<Cell*>> m_board;
};

#endif // BOARD_H
