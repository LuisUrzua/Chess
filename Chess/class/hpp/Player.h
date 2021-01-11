#pragma once

#include "../../include/const.h"
#include <string>

class Player
{
    public:
        Player(Color);
        std::string nextMove();

    private:
        Color color;
};
