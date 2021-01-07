#pragma once

#include "../../include/const.h"

class Piece
{
    public:
        Piece(Position, Color, Type);
        Position getPosition() const;
        Color getColor() const;
        Type getType() const;
        void setPosition(const Position);
        virtual void move() = 0;

    private:
        Position position;
        Color color;
        Type type;
};

