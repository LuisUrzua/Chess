#pragma once

#include "Piece.h"

class Rook : public Piece
{
    public:
        Rook(Position, Color, Type);
        void displayPiece();
        void move();

    private:

};

