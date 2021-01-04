#pragma once

#include "../../include/const.h"

class Piece
{
    public:
        Position getPosition() const;
        Color getColor() const;
        virtual void move() = 0;

    private:
        Position position;
        Color color;
        Type type;
};

