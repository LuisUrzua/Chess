#include "../hpp/Knight.h"
#include <iostream>

Knight::Knight(Position position, Color color, Type type) : Piece(position, color, type)
{

}

void Knight::displayPiece()
{
    if (this->getColor() == Color::White)
    {
        std::cout << "N";
    }
    else if (this->getColor() == Color::Black)
    {
        std::cout << "n";
    }
    else
    {
        // Something went wrong
    }
}

void Knight::move()
{

}
