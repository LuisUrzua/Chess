#pragma once

#include "Piece.h"

class Rook : public Piece
{
    public:
        Rook(Position, Color, Type);
        void displayPiece();
        bool validMove(const Position&);

    private:

};

