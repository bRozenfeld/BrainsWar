#ifndef GCELL_H
#define GCELL_H

#include "cell.h"
#include <QPushButton>

class GCell : public QPushButton
{
Q_OBJECT

public:
    GCell(Cell *c, QWidget* parent);
    Cell* getCell() { return m_cell; }
    void setChessSymbol(std::string pieceName);
private:
    Cell* m_cell;
    static const int CELL_SIZE = 80;
};

#endif // GCELL_H
