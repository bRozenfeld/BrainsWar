#include "player.h"


Player::Player(bool isWhite, std::vector<Piece*> pieces, King *king)
{
    m_is_white = isWhite;
    m_pieces_left = pieces;
    m_king = king;
}

Player::Player(const Player &p)
{
    m_is_white = p.m_is_white;
    m_king = new King(*p.m_king);
    m_pieces_left = p.m_pieces_left;
}

std::vector<Cell*> Player::getCellsOccupied()
{
    std::vector<Cell*> res;
    for(auto &p : m_pieces_left)
    {
        res.push_back(p->getCell());
    }
    return res;
}

void Player::removePiece(Piece *p)
{
    m_pieces_left.erase(remove(m_pieces_left.begin(), m_pieces_left.end(), p), m_pieces_left.end());
}

bool Player::isCheck(std::vector<Piece *> ennemyPieces)
{
    for(auto &p : ennemyPieces)
    {
        for(auto &c : p->getAllowedCells())
        {
            if(c == m_king->getCell())
            {
                return true;
            }
        }
    }
    return false;
}
