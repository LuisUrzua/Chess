#include "../hpp/Rook.h"
#include <iostream>

Rook::Rook(Position position, Color color, Type type) : Piece(position, color, type)
{

}

void Rook::displayPiece()
{
    if (this->getColor() == Color::White)
    {
        std::cout << "R";
    }
    else if (this->getColor() == Color::Black)
    {
        std::cout << "r";
    }
    else
    {
        // Something went wrong
    }
}

void Rook::move()
{

}
