#ifndef PLAYER_H
#define PLAYER_H

#include<vector>
#include "piece.h"
#include "king.h"
#include "cell.h"

class Player
{
public:
    Player(bool isWhite, std::vector<Piece*> pieces, King *king);
    Player(const Player &p);
    bool isWhite() { if(m_is_white) return true; return false; }
    std::vector<Piece*> getPiecesLeft() { return m_pieces_left; }
    std::vector<Cell*> getCellsOccupied();
    void removePiece(Piece* p);
    void addPiece(Piece *p) { m_pieces_left.push_back(p); }
    bool isCheck(std::vector<Piece*>ennemyPieces);
private:
    bool m_is_white;
    King *m_king;
    std::vector<Piece*> m_pieces_left;
};

#endif // PLAYER_H
