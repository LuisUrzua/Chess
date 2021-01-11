#pragma once

#include "Piece.h"

class Knight : public Piece
{
    public:
        Knight(Position, Color, Type);
        void displayPiece();
        bool validMove(const Position&);

    private:

};

