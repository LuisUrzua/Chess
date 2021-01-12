#pragma once

#include "../../include/const.h"
#include <memory>

class Board;

typedef std::shared_ptr<Board> PtrBoard;

class Piece
{
    public:
        Piece(Position, Color, Type);
        Position getPosition() const;
        Color getColor() const;
        Type getType() const;
        void setPosition(const Position);
        virtual void displayPiece() = 0;
        virtual bool isValidMove(const Position&, PtrBoard&) = 0;
        virtual bool isValidAttack(const Position&, PtrBoard&) = 0;

    private:
        Position position;
        Color color;
        Type type;
};

