#ifndef GAME_H
#define GAME_H

#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>

#include "piece.h"
#include "board.h"
#include "player.h"
#include "rook.h"
#include "cell.h"
#include "king.h"
#include "move.h"
#include "pawn.h"
#include "bishop.h"
#include "queen.h"
#include "knight.h"

class Game
{
public:
    Game();
    Board* getBoard() { return m_board; }
    Piece* getPieceFromCell(Cell* c);
    bool isMovePossible(Cell* from, Cell* to);
    bool isWhiteTurn() { return m_is_white_turn; }
    bool isPromoted() { return m_is_promoted; }
    void displayBoard();
    void displayPossibleMoves();
    void updatePossibleMoves();
    void move(Cell* from, Cell* to);
    void undoLastMove();
    void nextTurn() { m_is_white_turn = !m_is_white_turn; }
    void update();
    void promotion(Cell *c, int choice);
private:
    Board *m_board;
    Player *m_white_player;
    Player *m_black_player;
    std::stack<Move*> m_moves_history;
    bool m_is_white_turn;
    bool m_is_promoted;
    // methods
    void initGame();
};

#endif // GAME_H
