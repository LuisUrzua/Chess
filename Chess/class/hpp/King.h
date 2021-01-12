#pragma once

#include "Piece.h"

class King : public Piece
{
    public:
        King(Position, Color, Type);
        void displayPiece();
        bool isValidMove(const Position&, PtrBoard&);
        bool isValidAttack(const Position&, PtrBoard&);
    
    private:
        
};

