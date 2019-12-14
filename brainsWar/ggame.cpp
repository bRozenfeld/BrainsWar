#include "ggame.h"

GGame::GGame(Game *g)
{
    m_game = g;
    m_source = nullptr;
    m_destination = nullptr;

    m_board.reserve(8);
    for(int i = 0; i < 8; i++)
    {

        QLabel *label = new QLabel(QString::number(8-i), this);
        label->setGeometry(0,i*80,30,80);
        label->setFont(QFont("times", 25));
        label->setStyleSheet("background-color:#f0b27a");
        std::vector<GCell*> row;
        for(int j = 0; j < 8; j++)
        {
            GCell *gc = new GCell(m_game->getBoard()->getCell(i,j),this);
            gc->setToolTip(QString::fromStdString(m_game->getBoard()->getCell(i,j)->toString()));
            QPalette pal = palette();
            if((i % 2 == 0 and j % 2 == 0) or (i % 2 == 1 and j % 2 == 1))
            {
                gc->setStyleSheet("background-color:  #fae5d3");
            }
            else
            {
                gc->setStyleSheet("background-color: #935116");
            }
            Piece *p = m_game->getPieceFromCell(m_game->getBoard()->getCell(i,j));
            if(p != nullptr)
            {
                gc->setChessSymbol(p->getName());
            }
            else
            {
                gc->setChessSymbol("");
            }
            QObject::connect(gc, SIGNAL(clicked()), this, SLOT(handleButton()));
            row.push_back(gc);
        }
        m_board.push_back(row);
    }
    for(int i = 0; i < 8; i++)
    {
        QString s = "";
        if(i == 0) s = "A";
        else if (i == 1) s = "B";
        else if (i == 2) s = "C";
        else if (i == 3) s = "D";
        else if (i == 4) s = "E";
        else if (i == 5) s = "F";
        else if (i == 6) s = "G";
        else if (i == 7) s = "H";
        QLabel *label = new QLabel(s, this);
        label->setGeometry(i*80 + 30, 8 * 80,80,30);
        label->setFont(QFont("times", 25));
        label->setStyleSheet("background-color: #f0b27a");
    }
}

void GGame::updateGraphics()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            GCell *gc = m_board[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)];
            gc->setToolTip(QString::fromStdString(m_game->getBoard()->getCell(i,j)->toString()));
            QPalette pal = palette();
            Piece *p = m_game->getPieceFromCell(gc->getCell());
            if((i % 2 == 0 and j % 2 == 0) or (i % 2 == 1 and j % 2 == 1))
            {
                gc->setStyleSheet("background-color:#fae5d3");
            }
            else
            {
                gc->setStyleSheet("background-color: #935116");
            }

            if(p != nullptr)
            {
                gc->setChessSymbol(p->getName());
            }
            else
            {
                gc->setChessSymbol("");
            }
        }
    }

    if(m_source != nullptr)
    {
        Piece *p = m_game->getPieceFromCell(m_source->getCell());
        if(p != nullptr)
        {
            for(auto &c : p->getAllowedCells())
            {
                GCell* gc = getGCellFromCell(c);
                if(m_game->getPieceFromCell(c) == nullptr)
                {
                    gc->setText("\u25cf");
                }
                else
                {
                    QFont font = gc->font();
                    font.setPointSize(20);
                    gc->setFont(font);
                }
            }
        }
    }

}

GCell* GGame::getGCellFromCell(Cell* c)
{
    int x = c->getX();
    int y = c->getY();
    return m_board[static_cast<unsigned int>(x)][static_cast<unsigned int>(y)];
}


void GGame::handleButton()
{
    QObject* obj = sender();
    GCell* gc = qobject_cast<GCell*>(obj);
    if(gc)
    {
        Cell *c = gc->getCell();
        //Piece *p = m_game->getPieceFromCell(c);

        if(m_source == nullptr)
        {
            m_source = gc;
        }
        else
        {
            m_destination = gc;
            if(m_game->isMovePossible(m_source->getCell(), m_destination->getCell()))
            {

                m_game->move(m_source->getCell(), m_destination->getCell());
                m_game->update();
                if(m_game->isPromoted())
                {
                    GPromotion *gp = new GPromotion(m_game, c, this);
                    gp->exec();

                    updateGraphics();
                }

                //m_game->displayBoard();
                m_source = nullptr;
                m_destination = nullptr;
            }
            else
            {
                 m_source = gc;
                 m_destination = nullptr;
            }

        }
        updateGraphics();
    }

}
