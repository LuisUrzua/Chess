#pragma once

#include <map>
#include "Square.h"
#include <memory>

class Board
{
    public:
        Board();
        void displayBoard();
        void setCursor(const int, const int);

    private:
        std::map<Position, std::shared_ptr<Square>> squares;
};

