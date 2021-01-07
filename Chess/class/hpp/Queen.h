#pragma once

#include "Piece.h"

class Queen : public Piece
{
    public:
        Queen(Position, Color, Type);
        void  move();

    private:

};

