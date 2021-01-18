#pragma once

#include "Piece.h"

class Pawn : public Piece
{
    public:
        Pawn(Position, Color, Type);
        void displayPiece();
        bool isEnpassant() const;
        void updateMoveList(PtrBoard&);

    private:
};

