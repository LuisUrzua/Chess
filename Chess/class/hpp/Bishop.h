#pragma once

#include "Piece.h"

class Bishop : public Piece
{
    public:
        Bishop(Position, Color, Type);
        void displayPiece();
        bool isValidMove(const Position&, PtrBoard&);
        bool isValidAttack(const Position&, PtrBoard&);

    private:

};

