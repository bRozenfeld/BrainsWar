#include "game.h"

Game::Game(int version)
{
    m_board = new Board();
    m_is_white_turn = true;
    m_is_promoted = false;
    if(version == 1) initGame();
    else if(version == 2) initBrainsWar();
    else
    {
        throw WrongModeException();
    }
}


void Game::initBrainsWar()
{
    std::vector<Piece*> white_pieces;
    std::vector<Piece*> black_pieces;

    King *bk = new King("BK", m_board->getCell(4,0), false);
    Pawn *bp1 = new Pawn("BP", m_board->getCell(0,2), false);
    Pawn *bp2 = new Pawn("BP", m_board->getCell(1,2), false);
    Pawn *bp3 = new Pawn("BP", m_board->getCell(2,2), false);
    Pawn *bp4 = new Pawn("BP", m_board->getCell(3,2), false);
    Pawn *bp5 = new Pawn("BP", m_board->getCell(4,2), false);
    Pawn *bp6 = new Pawn("BP", m_board->getCell(5,2), false);
    Pawn *bp7 = new Pawn("BP", m_board->getCell(6,2), false);
    Pawn *bp8 = new Pawn("BP", m_board->getCell(7,2), false);

    King *wk = new King("WK", m_board->getCell(4,7), true);
    Pawn *wp1 = new Pawn("WP", m_board->getCell(0,5), true);
    Pawn *wp2 = new Pawn("WP", m_board->getCell(1,5), true);
    Pawn *wp3 = new Pawn("WP", m_board->getCell(2,5), true);
    Pawn *wp4 = new Pawn("WP", m_board->getCell(3,5), true);
    Pawn *wp5 = new Pawn("WP", m_board->getCell(4,5), true);
    Pawn *wp6 = new Pawn("WP", m_board->getCell(5,5), true);
    Pawn *wp7 = new Pawn("WP", m_board->getCell(6,5), true);
    Pawn *wp8 = new Pawn("WP", m_board->getCell(7,5), true);

    black_pieces.push_back(bp1);
    black_pieces.push_back(bp2);
    black_pieces.push_back(bp3);
    black_pieces.push_back(bp4);
    black_pieces.push_back(bp5);
    black_pieces.push_back(bp6);
    black_pieces.push_back(bp7);
    black_pieces.push_back(bp8);

    white_pieces.push_back(wp1);
    white_pieces.push_back(wp2);
    white_pieces.push_back(wp3);
    white_pieces.push_back(wp4);
    white_pieces.push_back(wp5);
    white_pieces.push_back(wp6);
    white_pieces.push_back(wp7);
      white_pieces.push_back(wp8);


    std::vector<Cell*> cell_used;

    QRandomGenerator64 *gen_x = QRandomGenerator64::system();
    QRandomGenerator64 *gen_y = QRandomGenerator64::system();

    int random_x = gen_x->bounded(0,8);
    int random_y = gen_y->bounded(0,2);

    if(random_y == 0)
    {
        King *bk = new King("BK", m_board->getCell(random_x, random_y), false);
        King *wk = new King("WK", m_board->getCell(random_x, random_y+7), true);
        white_pieces.push_back(wk);
        black_pieces.push_back(bk);
        cell_used.push_back(wk->getCell());
        cell_used.push_back(bk->getCell());

        m_white_player = new Player(true, white_pieces, wk);
        m_black_player = new Player(false, black_pieces, bk);

    }
    else if(random_y == 1)
    {
        King *bk = new King("BK", m_board->getCell(random_x, random_y), false);
        King *wk = new King("WK", m_board->getCell(random_x, random_y+5), true);
        white_pieces.push_back(wk);
        black_pieces.push_back(bk);
        cell_used.push_back(wk->getCell());
        cell_used.push_back(bk->getCell());

        m_white_player = new Player(true, white_pieces, wk);
        m_black_player = new Player(false, black_pieces, bk);
    }

    // add 9 randoms pieces
    for(int i = 0; i < 9; i++)
    {

        QRandomGenerator64 *gen1 = QRandomGenerator64::system();
        int random = gen1->bounded(1,5);

        std::cout << "random : " << random << std::endl;
        std::cout << "random x : " << random_x << std::endl;
        std::cout << "random y : " << random_y << std::endl;


        bool already_taken = true;
        while(already_taken == true)
        {
            random_x = gen_x->bounded(0,8);
            random_y = gen_y->bounded(0,2);

            bool find = false;
            for(auto &c : cell_used)
            {
                if(m_board->getCell(random_x, random_y) == c)
                {
                    find = true;
                    break;
                }
            }

            if(find == true)
            {
                already_taken = true;
            }
            else
            {
                already_taken = false;
            }
        }


        if(random == 1) // queen
        {
            if(random_y == 0)
            {
                Queen *bq = new Queen("BQ", m_board->getCell(random_x, random_y), false);
                Queen *wq = new Queen("WQ", m_board->getCell(random_x, random_y+7), true);
                m_white_player->addPiece(wq);
                m_black_player->addPiece(bq);
                cell_used.push_back(wq->getCell());
                cell_used.push_back(bq->getCell());
            }
            else if(random_y == 1)
            {
                Queen *bq = new Queen("BQ", m_board->getCell(random_x, random_y), false);
                Queen *wq = new Queen("WQ", m_board->getCell(random_x, random_y+5), true);
                m_white_player->addPiece(wq);
                m_black_player->addPiece(bq);
                cell_used.push_back(wq->getCell());
                cell_used.push_back(bq->getCell());
            }

        }
        else if(random == 2) // bishop
        {
            if(random_y == 0)
            {
                Bishop *bb = new Bishop("BB", m_board->getCell(random_x, random_y), false);
                Bishop *wb = new Bishop("WB", m_board->getCell(random_x, random_y+7), true);
                m_white_player->addPiece(wb);
                m_black_player->addPiece(bb);
                cell_used.push_back(wb->getCell());
                cell_used.push_back(bb->getCell());
            }
            else if(random_y == 1)
            {
                Bishop *bb = new Bishop("BB", m_board->getCell(random_x, random_y), false);
                Bishop *wb = new Bishop("WB", m_board->getCell(random_x, random_y+5), true);
                m_white_player->addPiece(wb);
                m_black_player->addPiece(bb);
                cell_used.push_back(wb->getCell());
                cell_used.push_back(bb->getCell());
            }
        }
        else if(random ==3) // rook
        {
            if(random_y == 0)
            {
                Rook *br = new Rook("BR", m_board->getCell(random_x, random_y), false);
                Rook *wr = new Rook("WR", m_board->getCell(random_x, random_y+7), true);
                m_white_player->addPiece(wr);
                m_black_player->addPiece(br);
                cell_used.push_back(wr->getCell());
                cell_used.push_back(br->getCell());
            }
            else if(random_y == 1)
            {
                Rook *br = new Rook("BR", m_board->getCell(random_x, random_y), false);
                Rook *wr = new Rook("WR", m_board->getCell(random_x, random_y+5), true);
                m_white_player->addPiece(wr);
                m_black_player->addPiece(br);
                cell_used.push_back(wr->getCell());
                cell_used.push_back(br->getCell());
            }
        }
        else if(random == 4) // knight
        {
            if(random_y == 0)
            {
                Knight *bn = new Knight("BN", m_board->getCell(random_x, random_y), false);
                Knight *wn = new Knight("WN", m_board->getCell(random_x, random_y+7), true);
                m_white_player->addPiece(wn);
                m_black_player->addPiece(bn);
                cell_used.push_back(wn->getCell());
                cell_used.push_back(bn->getCell());
            }
            else if(random_y == 1)
            {
                Knight *bn = new Knight("BN", m_board->getCell(random_x, random_y), false);
                Knight *wn = new Knight("WN", m_board->getCell(random_x, random_y+5), true);
                m_white_player->addPiece(wn);
                m_black_player->addPiece(bn);
                cell_used.push_back(wn->getCell());
                cell_used.push_back(bn->getCell());
            }
        }

    }


    for(auto &p : m_white_player->getPiecesLeft())
    {
        p->setAllowedCells(m_board, m_black_player->getCellsOccupied(), m_white_player->getCellsOccupied());
        std::cout << p->toString() << std::endl;
    }

}

void Game::initGame()
{

    std::vector<Piece*> white_pieces;
    std::vector<Piece*> black_pieces;

    Rook *br1 = new Rook("BR", m_board->getCell(0,0), false);
    Rook *br2 = new Rook("BR", m_board->getCell(7,0), false);
    Bishop *bb1 = new Bishop("BB", m_board->getCell(2,0), false);
    Bishop *bb2 = new Bishop("BB", m_board->getCell(5,0), false);
    Knight *bn1 = new Knight("BN", m_board->getCell(1,0), false);
    Knight *bn2 = new Knight("BN", m_board->getCell(6,0), false);
    King *bk = new King("BK", m_board->getCell(4,0), false);
    Queen *bq = new Queen("BQ", m_board->getCell(3,0), false);
    Pawn *bp1 = new Pawn("BP", m_board->getCell(0,1), false);
    Pawn *bp2 = new Pawn("BP", m_board->getCell(1,1), false);
    Pawn *bp3 = new Pawn("BP", m_board->getCell(2,1), false);
    Pawn *bp4 = new Pawn("BP", m_board->getCell(3,1), false);
    Pawn *bp5 = new Pawn("BP", m_board->getCell(4,1), false);
    Pawn *bp6 = new Pawn("BP", m_board->getCell(5,1), false);
    Pawn *bp7 = new Pawn("BP", m_board->getCell(6,1), false);
    Pawn *bp8 = new Pawn("BP", m_board->getCell(7,1), false);

    Rook *wr1 = new Rook("WR", m_board->getCell(0,7), true);
    Rook *wr2 = new Rook("WR", m_board->getCell(7,7), true);
    Bishop *wb1 = new Bishop("WB", m_board->getCell(2,7), true);
    Bishop *wb2 = new Bishop("WB", m_board->getCell(5,7), true);
    Knight *wn1 = new Knight("WN", m_board->getCell(1,7), true);
    Knight *wn2 = new Knight("WN", m_board->getCell(6,7), true);
    King *wk = new King("WK", m_board->getCell(4,7), true);
    Queen *wq = new Queen("WQ", m_board->getCell(3,7), true);
    Pawn *wp1 = new Pawn("WP", m_board->getCell(0,6), true);
    Pawn *wp2 = new Pawn("WP", m_board->getCell(1,6), true);
    Pawn *wp3 = new Pawn("WP", m_board->getCell(2,6), true);
    Pawn *wp4 = new Pawn("WP", m_board->getCell(3,6), true);
    Pawn *wp5 = new Pawn("WP", m_board->getCell(4,6), true);
    Pawn *wp6 = new Pawn("WP", m_board->getCell(5,6), true);
    Pawn *wp7 = new Pawn("WP", m_board->getCell(6,6), true);
    Pawn *wp8 = new Pawn("WP", m_board->getCell(7,6), true);


      black_pieces.push_back(br1);
      black_pieces.push_back(br2);
      black_pieces.push_back(bb1);
      black_pieces.push_back(bb2);
      black_pieces.push_back(bn1);
      black_pieces.push_back(bn2);
      black_pieces.push_back(bk);
    black_pieces.push_back(bq);
    black_pieces.push_back(bp1);
    black_pieces.push_back(bp2);
    black_pieces.push_back(bp3);
    black_pieces.push_back(bp4);
    black_pieces.push_back(bp5);
    black_pieces.push_back(bp6);
    black_pieces.push_back(bp7);
    black_pieces.push_back(bp8);

      white_pieces.push_back(wr1);
      white_pieces.push_back(wr2);
    white_pieces.push_back(wb1);
    white_pieces.push_back(wb2);
    white_pieces.push_back(wn1);
    white_pieces.push_back(wn2);
      white_pieces.push_back(wk);
    white_pieces.push_back(wq);
    white_pieces.push_back(wp1);
    white_pieces.push_back(wp2);
    white_pieces.push_back(wp3);
    white_pieces.push_back(wp4);
    white_pieces.push_back(wp5);
    white_pieces.push_back(wp6);
    white_pieces.push_back(wp7);
      white_pieces.push_back(wp8);


    m_white_player = new Player(true, white_pieces, wk);
    m_black_player = new Player(false, black_pieces, bk);

    for(auto &p : m_white_player->getPiecesLeft())
    {
        p->setAllowedCells(m_board, m_black_player->getCellsOccupied(), m_white_player->getCellsOccupied());
    }
}


Piece* Game::getPieceFromCell(Cell *c)
{
    Piece* res = nullptr;
    for(auto &p : m_white_player->getPiecesLeft())
    {
        if(p->getCell() == c)
        {
            res = p;
            break;
        }
    }

    if(res == nullptr)
    {
        for(auto &p : m_black_player->getPiecesLeft())
        {
            if(p->getCell() == c)
            {
                res = p;
                break;
            }
        }
    }

    return res;
}


void Game::displayBoard()
{
    for(unsigned int i = 0; i < 8; i++)
    {
        std::cout << 8-i << " |";
        for(unsigned int j = 0; j < 8; j++)
        {
            Piece *p = getPieceFromCell(m_board->getBoard()[i][j]);
            if(p == nullptr)
            {
                std::cout << "  |";
            }
            else
            {
                std::cout << p->getName() << "|";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "   " << " A " << " B " << " C " << " D " << " E " << " F " << " G " << " H" << std::endl;
    std::cout << std::endl;
}

void Game::displayPossibleMoves()
{
    for(auto &p : m_white_player->getPiecesLeft())
    {
        std::cout << p->toString() << std::endl;
    }

    for(auto &p : m_black_player->getPiecesLeft())
    {
        std::cout << p->toString() << std::endl;
    }
}

void Game::updatePossibleMoves()
{
    if(m_is_white_turn)
    {
        for(auto &p : m_white_player->getPiecesLeft())
        {
            p->clearAllowedCells();
            p->setAllowedCells(m_board, m_black_player->getCellsOccupied(), m_white_player->getCellsOccupied());
        }

        for(auto &p : m_white_player->getPiecesLeft())
        {
            Cell *source = p->getCell();
            for(auto &dest : p->getAllowedCells())
            {
                unsigned i = m_moves_history.size();
                move(source, dest);
                for(auto &bp : m_black_player->getPiecesLeft())
                {
                    bp->clearAllowedCells();
                    bp->setAllowedCells(m_board, m_white_player->getCellsOccupied(), m_black_player->getCellsOccupied());
                }               
                if(m_white_player->isCheck(m_black_player->getPiecesLeft()))
                {
                    p->removeAllowedCell(dest);
                }
                undoLastMove();

                // in case of castling move, one more move
                if(m_moves_history.size() > i)
                {
                    undoLastMove();
                }

            }
        }

        /*
        for(auto &p : m_black_player->getPiecesLeft())
        {
            p->clearAllowedCells();
        }
        */
    }
    else
    {
        for(auto &p : m_black_player->getPiecesLeft())
        {
            p->clearAllowedCells();
            p->setAllowedCells(m_board, m_white_player->getCellsOccupied(), m_black_player->getCellsOccupied());
        }

        for(auto &p : m_black_player->getPiecesLeft())
        {
            //std::vector<Cell*> copy = p->getAllowedCells();
            Cell *source = p->getCell();
            for(auto &dest : p->getAllowedCells())
            {
                unsigned int i = m_moves_history.size();
                move(source, dest);
                for(auto &wp : m_white_player->getPiecesLeft())
                {
                    wp->clearAllowedCells();
                    wp->setAllowedCells(m_board, m_black_player->getCellsOccupied(), m_white_player->getCellsOccupied());
                }
                if(m_black_player->isCheck(m_white_player->getPiecesLeft()))
                {
                    p->removeAllowedCell(dest);
                }
                undoLastMove();

                // in case of castling move, one more move
                if(m_moves_history.size() > i)
                {
                    undoLastMove();
                }
            }
        }

        /*
        for(auto &p : m_white_player->getPiecesLeft())
        {
            p->clearAllowedCells();
        }
        */
    }
}

void Game::move(Cell* from, Cell* to)
{
    Piece* p = getPieceFromCell(from);
    if(p != nullptr)
    {
        Piece* eaten = getPieceFromCell(to);
        if(eaten != nullptr)
        {
            if(eaten->isWhite())
            {
                m_white_player->removePiece(eaten);
            }
            else
            {
                m_black_player->removePiece(eaten);
            }
            //eaten->setCell(nullptr);
        }
        p->setCell(to);
        m_moves_history.push(new Move(from, to, eaten));
    }


    // if roque move, move the tower aswell
    if(typeid(*p) == typeid(King) and std::abs(from->getX() - to->getX()) == 2)
    {
        // white king, big roque
        if(p->isWhite() and to->getX() == 2)
        {
            Piece *p2 = getPieceFromCell(m_board->getCell(0,7));
            p2->setCell(m_board->getCell(3,7));
            m_moves_history.push(new Move(m_board->getCell(0,7), m_board->getCell(3,7), nullptr));
        }
        // white king, little roque
        else if(p->isWhite() and to->getX() == 6)
        {
            Piece *p2 = getPieceFromCell(m_board->getCell(7,7));
            p2->setCell(m_board->getCell(5,7));
            m_moves_history.push(new Move(m_board->getCell(7,7), m_board->getCell(5,7), nullptr));
        }
        // black king, big roque
        else if(!p->isWhite() and to->getX() == 2)
        {
            Piece *p2 = getPieceFromCell(m_board->getCell(0,0));
            p2->setCell(m_board->getCell(3,0));
            m_moves_history.push(new Move(m_board->getCell(0,0), m_board->getCell(3,0), nullptr));
        }
        // black king, little roque
        else if(!p->isWhite() and to->getX() == 6)
        {
            Piece *p2 = getPieceFromCell(m_board->getCell(7,0));
            p2->setCell(m_board->getCell(5,0));
            m_moves_history.push(new Move(m_board->getCell(7,0), m_board->getCell(5,0), nullptr));
        }
    }
}

void Game::undoLastMove()
{
    if(!m_moves_history.empty())
    {
        Move* last_move = m_moves_history.top();
        Cell *from = last_move->getFrom();
        Cell *to = last_move->getTo();
        Piece *p = getPieceFromCell(to);
        Piece *eat = last_move->getPieceEaten();
        if(eat != nullptr)
        {
            eat->setCell(to);
            if(eat->isWhite())
            {
                m_white_player->addPiece(eat);
            }
            else
            {
                m_black_player->addPiece(eat);
            }
        }
        p->setCell(from);
        m_moves_history.pop();
    }
}

bool Game::isMovePossible(Cell *from, Cell *to)
{

    bool res = false;
    Piece* p = getPieceFromCell(from);
    if(p != nullptr)
    {
        for(auto &c : p->getAllowedCells())
        {
            if(c == to)
            {
                res = true;
                break;
            }
        }
    }
    return res;
}


void Game::update()
{
    // check for a pawn promotion
    for(auto &p : m_white_player->getPiecesLeft())
    {
        if(typeid(*p) == typeid(Pawn))
        {
            Pawn* pawn = static_cast<Pawn*>(p);
            if(pawn->getCell()->getY() == 0)
            {
                m_is_promoted = true;
            }
        }
    }

    for(auto &p : m_black_player->getPiecesLeft())
    {
        if(typeid(*p) == typeid(Pawn))
        {
            Pawn* pawn = static_cast<Pawn*>(p);
            if(pawn->getCell()->getY() == 7)
            {
               m_is_promoted = true;
            }
        }
    }

    nextTurn();
    updatePossibleMoves();
    updateIsCastlingMovePossible();


    // clear the moves for the opposite side
    if(m_is_white_turn)
    {
        for(auto &p : m_black_player->getPiecesLeft())
        {
            p->clearAllowedCells();
        }
    }
    else
    {
        for(auto &p : m_white_player->getPiecesLeft())
        {
            p->clearAllowedCells();
        }
    }


    bool isCheckMate = true;
    if(m_is_white_turn)
    {
        for(auto &p : m_white_player->getPiecesLeft())
        {
            if(!(p->getAllowedCells().empty()))
            {
                isCheckMate = false;
                break;
            }
        }
        if(isCheckMate)
        {
            std::cout << "Black player win !" << std::endl;
        }
    }
    else
    {
        for(auto &p : m_black_player->getPiecesLeft())
        {
            if(!(p->getAllowedCells().empty()))
            {
                isCheckMate = false;
                break;
            }
        }
        if(isCheckMate)
        {
            std::cout << "White player win !" << std::endl;
        }
    }
}

void Game::promotion(Cell *c, int choice)
{
    Piece *p = getPieceFromCell(c);

    std::cout << p->toString() << std::endl;

    // Queen
    if(choice == 0)
    {
        if(p->isWhite())
        {
            Queen *q = new Queen("WQ", p->getCell(), true);
            m_white_player->removePiece(p);
            m_white_player->addPiece(q);
        }
        else
        {
            Queen *q = new Queen("BQ", p->getCell(), false);
            m_black_player->removePiece(p);
            m_black_player->addPiece(q);
        }
    }
    // Rook
    else if(choice == 1)
    {
        if(p->isWhite())
        {
            Rook *q = new Rook("WR", p->getCell(), true);
            m_white_player->removePiece(p);
            m_white_player->addPiece(q);
        }
        else
        {
            Rook *q = new Rook("BR", p->getCell(), false);
            m_black_player->removePiece(p);
            m_black_player->addPiece(q);
        }
    }
    // Bishop
    else if(choice == 2)
    {
        if(p->isWhite())
        {
            Bishop *q = new Bishop("WB", p->getCell(), true);
            m_white_player->removePiece(p);
            m_white_player->addPiece(q);
        }
        else
        {
            Bishop *q = new Bishop("BB", p->getCell(), false);
            m_black_player->removePiece(p);
            m_black_player->addPiece(q);
        }
    }
    // Knight
    else if(choice == 3)
    {
        if(p->isWhite())
        {
            Knight *q = new Knight("WN", p->getCell(), true);
            m_white_player->removePiece(p);
            m_white_player->addPiece(q);
        }
        else
        {
            Knight *q = new Knight("BN", p->getCell(), false);
            m_black_player->removePiece(p);
            m_black_player->addPiece(q);
        }
    }
    p->setCell(nullptr);
    m_is_promoted = false;
}

void Game::updateIsCastlingMovePossible()
{
    m_black_player->getKing()->setBigRoqueAllowed(false);
    m_black_player->getKing()->setLittleRoqueAllowed(false);
    m_white_player->getKing()->setBigRoqueAllowed(false);
    m_white_player->getKing()->setLittleRoqueAllowed(false);

    // check for castling (roque)
    // neither rook or king should have moved
    // king shouldn't be checked
    // king shouldn't be checked for each cell he will go
    // all the cells between king and rook have to be empty
    if(isWhiteTurn())
    {
        // king didnt move and king not check
        if(!m_white_player->getKing()->hasMoved() and !m_white_player->isCheck(m_black_player->getPiecesLeft()))
        {
            for(auto &p : m_white_player->getPiecesLeft())
            {
                if(typeid(*p) == typeid(Rook))
                {
                    Rook* rook = dynamic_cast<Rook*>(p);
                    if(!rook->hasMoved())
                    {
                        if(rook->getCell()->getX() == 0)
                        {
                            Cell *c1 = m_board->getCell(3,7);
                            Cell *c2 = m_board->getCell(2,7);
                            // cells empty
                            if(getPieceFromCell(c1) == nullptr and getPieceFromCell(c2) == nullptr)
                            {
                                // not check while moving
                                bool canBeChecked = false;
                                for(auto &ennemy_piece : m_black_player->getPiecesLeft())
                                {
                                    for(auto &c : ennemy_piece->getAllowedCells())
                                    {
                                        if(c == c1 or c == c2)
                                        {
                                            canBeChecked = true;
                                            break;
                                        }
                                    }
                                    if(canBeChecked) break;
                                }
                                if(!canBeChecked)
                                {
                                    m_white_player->getKing()->setBigRoqueAllowed(true);
                                    updatePossibleMoves();
                                }
                            }
                        }
                        else if(rook->getCell()->getX() == 7)
                        {
                            Cell *c1 = m_board->getCell(6,7);
                            Cell *c2 = m_board->getCell(5,7);
                            // cells empty
                            if(getPieceFromCell(c1) == nullptr and getPieceFromCell(c2) == nullptr)
                            {
                                // not check while moving
                                bool canBeChecked = false;
                                for(auto &ennemy_piece : m_black_player->getPiecesLeft())
                                {
                                    for(auto &c : ennemy_piece->getAllowedCells())
                                    {
                                        if(c == c1 or c == c2)
                                        {
                                            canBeChecked = true;
                                            break;
                                        }
                                    }
                                    if(canBeChecked) break;
                                }
                                if(!canBeChecked)
                                {
                                    m_white_player->getKing()->setLittleRoqueAllowed(true);
                                    updatePossibleMoves();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //black turn
    else
    {
        // king didnt move and king not check
        if(!m_black_player->getKing()->hasMoved() and !m_black_player->isCheck(m_white_player->getPiecesLeft()))
        {
            for(auto &p : m_black_player->getPiecesLeft())
            {
                if(typeid(*p) == typeid(Rook))
                {
                    Rook* rook = dynamic_cast<Rook*>(p);
                    if(!rook->hasMoved())
                    {
                        if(rook->getCell()->getX() == 0)
                        {
                            Cell *c1 = m_board->getCell(3,0);
                            Cell *c2 = m_board->getCell(2,0);
                            // cells empty
                            if(getPieceFromCell(c1) == nullptr and getPieceFromCell(c2) == nullptr)
                            {
                                // not check while moving
                                bool canBeChecked = false;
                                for(auto &ennemy_piece : m_white_player->getPiecesLeft())
                                {
                                    for(auto &c : ennemy_piece->getAllowedCells())
                                    {
                                        if(c == c1 or c == c2)
                                        {
                                            canBeChecked = true;
                                            break;
                                        }
                                    }
                                    if(canBeChecked) break;
                                }
                                if(!canBeChecked)
                                {
                                    m_black_player->getKing()->setBigRoqueAllowed(true);
                                    updatePossibleMoves();
                                }
                            }
                        }
                        else if(rook->getCell()->getX() == 7)
                        {
                            Cell *c1 = m_board->getCell(6,0);
                            Cell *c2 = m_board->getCell(5,0);
                            // cells empty
                            if(getPieceFromCell(c1) == nullptr and getPieceFromCell(c2) == nullptr)
                            {
                                // not check while moving
                                bool canBeChecked = false;
                                for(auto &ennemy_piece : m_white_player->getPiecesLeft())
                                {
                                    for(auto &c : ennemy_piece->getAllowedCells())
                                    {
                                        if(c == c1 or c == c2)
                                        {
                                            canBeChecked = true;
                                            break;
                                        }
                                    }
                                    if(canBeChecked) break;
                                }
                                if(!canBeChecked)
                                {
                                    m_black_player->getKing()->setLittleRoqueAllowed(true);
                                    updatePossibleMoves();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


