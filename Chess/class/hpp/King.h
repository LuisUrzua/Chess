#pragma once

#include "Piece.h"

class King : public Piece
{
    public:
        King(Position, Color, Type);
        void displayPiece();
        bool validMove(const Position &);
    
    private:
        
};

