#pragma once

#include "Piece.h"

class Bishop : public Piece
{
    public:
        Bishop(Position, Color, Type);
        void displayPiece();
        bool validMove(const Position &);

    private:

};

