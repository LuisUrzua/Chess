#include "../hpp/Piece.h"

Piece::Piece(Position position, Color color, Type type)
{
    this->position = position;
    this->color = color;
    this->type = type;
}

Position Piece::getPosition() const
{
    return position;
}

Color Piece::getColor() const
{
    return color;
}

Type Piece::getType() const
{
    return type;
}

void Piece::setPosition(const Position position)
{
    this->position = position;
}
