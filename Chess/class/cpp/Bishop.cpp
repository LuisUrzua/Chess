#include "../hpp/Bishop.h"
#include <iostream>

Bishop::Bishop(Position position, Color color, Type type) : Piece(position, color, type)
{

}

void Bishop::displayPiece()
{
    if (this->getColor() == Color::White)
    {
        std::cout << "B";
    }
    else if (this->getColor() == Color::Black)
    {
        std::cout << "b";
    }
    else
    {
        // Something went wrong
    }
    
}

void Bishop::move()
{

}
