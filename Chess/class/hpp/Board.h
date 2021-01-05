#pragma once

#include <map>
#include "Square.h"
#include <memory>

class Board
{
    public:
        Board();

    private:
        std::map<Position, std::shared_ptr<Square>> squares;
};

