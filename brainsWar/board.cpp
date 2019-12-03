#include "board.h"

Board::Board()
{
    m_board.reserve(8);
    for(int i = 0; i < 8; i++)
    {
        std::vector<Cell *> row;
        for(int j = 0; j < 8; j++)
        {
            row.push_back(new Cell(j,i));
        }
        m_board.push_back(row);
    }
}

Board::Board(const Board &b)
{
    m_board.reserve(8);
    for(int i = 0; i < 8; i++)
    {
        std::vector<Cell *> row;
        for(int j = 0; j < 8; j++)
        {
            row.push_back(new Cell(*b.m_board[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)]));
        }
        m_board.push_back(row);
    }
}

Cell* Board::getCell(std::string cellName)
{
    Cell *c = nullptr;
    for(unsigned i = 0; i < 8; i++)
    {
        for(unsigned j = 0; j < 8; j++)
        {
            if(m_board[i][j]->getName() == cellName)
            {
                c = m_board[i][j];
            }
        }
    }
    return c;
}


void Board::removeCell(std::string cellName)
{
    Cell *c = getCell(cellName);
    for(unsigned int i = 0; i < 8; i++)
    {
        for(unsigned int j = 0; j < 8; j++)
        {
            if(m_board[i][j] == c)
            {
                c->setName("P9");
            }
        }
    }
}
