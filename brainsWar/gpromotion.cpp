#include "gpromotion.h"


// a supprimer

GPromotion::GPromotion(Game *g, Cell *c, QWidget *parent) : QDialog(parent)
{
    m_game = g;
    m_cell = c;

    std::cout << "test" << std::endl;

    QPushButton *queen = new QPushButton(this);
    queen->setGeometry(0,0,80,80);
    if(c->getY() == 0) queen->setText("\u2655");
    else if (c->getY() == 7) queen->setText("\u265B");

    QPushButton *rook = new QPushButton(this);
    rook->setGeometry(80,0,80,80);
    if(c->getY() == 0) rook->setText("\u2656");
    else if (c->getY() == 7) rook->setText("\u265C");

    QPushButton *bishop = new QPushButton(this);
    bishop->setGeometry(160,0,80,80);
    if(c->getY() == 0) bishop->setText("\u2657");
    else if (c->getY() == 7) bishop->setText("\u265D");

    QPushButton *knight = new QPushButton(this);
    knight->setGeometry(240,0,80,80);
    if(c->getY() == 0) knight->setText("\u2658");
    else if (c->getY() == 7) knight->setText("\u265E");

    QObject::connect(queen, SIGNAL(clicked()), this, SLOT(queenButtonClicked()));
    QObject::connect(rook, SIGNAL(clicked()), this, SLOT(rookButtonClicked()));
    QObject::connect(bishop, SIGNAL(clicked()), this, SLOT(bishopButtonClicked()));
    QObject::connect(knight, SIGNAL(clicked()), this, SLOT(knightButtonClicked()));


    this->setGeometry(parent->geometry().x(), parent->geometry().y(),320,80);

    QFont font = this->font();
    font.setPointSize(40);
    this->setFont(font);
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
