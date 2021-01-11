#pragma once

#include "Piece.h"

class Queen : public Piece
{
    public:
        Queen(Position, Color, Type);
        void displayPiece();
        bool validMove(const Position &);

    private:

};

