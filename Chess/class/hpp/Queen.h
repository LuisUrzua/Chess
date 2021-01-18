#pragma once

#include "Piece.h"

class Queen : public Piece
{
    public:
        Queen(Position, Color, Type);
        void displayPiece();
        void updateMoveList(PtrBoard&);

    private:

};

