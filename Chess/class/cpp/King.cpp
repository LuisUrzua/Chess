#include "../hpp/King.h"
#include <iostream>

King::King(Position position, Color color, Type type) : Piece(position, color, type)
{

}

void King::displayPiece()
{
    if (this->getColor() == Color::White)
    {
        std::cout << "K";
    }
    else if (this->getColor() == Color::Black)
    {
        std::cout << "k";
    }
    else
    {
        // Something went wrong
    }
}

void King::move()
{

}
