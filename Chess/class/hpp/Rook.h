#pragma once

#include "Piece.h"

class Rook : public Piece
{
    public:
        Rook(Position, Color, Type);
        void displayPiece();
        bool isValidMove(const Position&, PtrBoard&);
        bool isValidAttack(const Position&, PtrBoard&);

    private:

};

