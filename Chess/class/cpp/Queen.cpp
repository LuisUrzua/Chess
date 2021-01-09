#include "../hpp/Queen.h"
#include <iostream>

Queen::Queen(Position position, Color color, Type type) : Piece(position, color, type)
{

}

void Queen::displayPiece()
{
    if (this->getColor() == Color::White)
    {
        std::cout << "Q";
    }
    else if (this->getColor() == Color::Black)
    {
        std::cout << "q";
    }
    else
    {
        // Something went wrong
    }
}

void Queen::move()
{

}
