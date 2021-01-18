#include "../hpp/Piece.h"
#include <algorithm>

Piece::Piece(Position position, Color color, Type type)
{
    this->position = position;
    this->color = color;
    this->type = type;
    this->first = true;
}

Position Piece::getPosition() const
{
    return this->position;
}

Color Piece::getColor() const
{
    return this->color;
}

Type Piece::getType() const
{
    return this->type;
}

void Piece::setPosition(const Position position)
{
    this->position = position;
    this->first = false;
}

bool Piece::isValidMove(const Position& destination)
{
    // Returns true if move is found
    return (std::find(this->moves.begin(), this->moves.end(), destination) != this->moves.end()) ? true : false;
}

bool Piece::isFirstMove() const
{
    return this->first;
}
