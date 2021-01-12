#pragma once

#include "Piece.h"

class Knight : public Piece
{
    public:
        Knight(Position, Color, Type);
        void displayPiece();
        bool isValidMove(const Position&, PtrBoard&);
        bool isValidAttack(const Position&, PtrBoard&);

    private:

};

