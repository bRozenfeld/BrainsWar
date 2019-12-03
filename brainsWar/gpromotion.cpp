#include "gpromotion.h"


GPromotion::GPromotion(Game *g, Cell *c)
{
    m_game = g;
    m_cell = c;

    QPushButton *queen = new QPushButton(this);
    queen->setGeometry(0,0,80,80);
    queen->setText("Queen");

    QPushButton *rook = new QPushButton(this);
    rook->setGeometry(80,0,80,80);
    rook->setText("rook");

    QPushButton *bishop = new QPushButton(this);
    bishop->setGeometry(160,0,80,80);
    bishop->setText("bishop");

    QPushButton *knight = new QPushButton(this);
    knight->setGeometry(240,0,80,80);
    knight->setText("knight");

    QObject::connect(queen, SIGNAL(clicked()), this, SLOT(queenButtonClicked()));
    QObject::connect(rook, SIGNAL(clicked()), this, SLOT(rookButtonClicked()));
    QObject::connect(bishop, SIGNAL(clicked()), this, SLOT(bishopButtonClicked()));
    QObject::connect(knight, SIGNAL(clicked()), this, SLOT(knightButtonClicked()));


    this->setGeometry(0,0,320,80);
}

void GPromotion::queenButtonClicked()
{
    m_game->promotion(m_cell, 0);
    this->hide();
}

void GPromotion::rookButtonClicked()
{
    m_game->promotion(m_cell, 1);
    this->hide();
}

void GPromotion::bishopButtonClicked()
{
    m_game->promotion(m_cell, 2);
    this->hide();
}

void GPromotion::knightButtonClicked()
{
    m_game->promotion(m_cell, 3);
    this->hide();
}
