#include "gcell.h"

GCell::GCell(Cell *c, QWidget* parent) : QPushButton(parent)
{
    m_cell = c;
    this->setGeometry(m_cell->getX()*CELL_SIZE + 30, m_cell->getY()*CELL_SIZE, CELL_SIZE, CELL_SIZE);
}

void GCell::setChessSymbol(std::string pieceName)
{
    if(pieceName=="WR") {
        this->setText("\u2656");
    }
    else if(pieceName == "WN") {
        this->setText("\u2658");
    }
    else if(pieceName == "WB") {
        this->setText("\u2657");
    }
    else if(pieceName == "WK") {
        this->setText("\u2654");
    }
    else if(pieceName == "WQ") {
        this->setText("\u2655");
    }
    else if(pieceName == "WP") {
        this->setText("\u2659");
    }
    else if(pieceName=="BR") {
        this->setText("\u265C");
    }
    else if(pieceName == "BN") {
        this->setText("\u265E");
    }
    else if(pieceName == "BB") {
        this->setText("\u265D");
    }
    else if(pieceName == "BK") {
        this->setText("\u265A");
    }
    else if(pieceName == "BQ") {
        this->setText("\u265B");
    }
    else if(pieceName == "BP") {
        this->setText("\u265F");
    }
    else {
        this->setText("");
    }

    QFont font = this->font();
    font.setPointSize(40);
    this->setFont(font);
}
