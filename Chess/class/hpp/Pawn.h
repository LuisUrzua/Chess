#pragma once

#include "Piece.h"

class Pawn : public Piece
{
    public:
        Pawn(Position, Color, Type);
        void displayPiece();
        void move();

    private:
};

