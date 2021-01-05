#include "../hpp/Square.h"

Square::Square(Position position)
{
    this->position = position;
}

bool Square::isEmpty() const
{
    return (!(this->piece)) ? true : false;
}

void Square::insertPiece(const std::shared_ptr<Piece> &piece)
{
    if (this->isEmpty())
    {
        this->piece = piece;
    }
    else
    {
        this->piece.reset();
        this->piece = piece;
    }
}
