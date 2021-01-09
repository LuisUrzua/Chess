#include "../hpp/Pawn.h"
#include <iostream>

Pawn::Pawn(Position position, Color color, Type type) : Piece(position, color, type)
{

}

void Pawn::displayPiece()
{
    if (this->getColor() == Color::White)
    {
        std::cout << "P";
    }
    else if (this->getColor() == Color::Black)
    {
        std::cout << "p";
    }
    else
    {
        // Something went wrong
    }
}

void Pawn::move()
{

}
