#pragma once

#include "Piece.h"

class Queen : public Piece
{
    public:
        Queen(Position, Color, Type);
        void displayPiece();
        bool isValidMove(const Position&, PtrBoard&);
        bool isValidAttack(const Position&, PtrBoard&);

    private:

};

