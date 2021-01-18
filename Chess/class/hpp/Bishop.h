#pragma once

#include "Piece.h"

class Bishop : public Piece
{
    public:
        Bishop(Position, Color, Type);
        void displayPiece();
        void updateMoveList(PtrBoard&);

    private:

};

