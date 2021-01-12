#pragma once

#include "Piece.h"

class Pawn : public Piece
{
    public:
        Pawn(Position, Color, Type);
        void displayPiece();
        bool isValidMove(const Position&, PtrBoard&);
        bool isValidAttack(const Position&, PtrBoard&);

    private:
        bool firstMove;
};

