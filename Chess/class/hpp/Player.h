#pragma once

#include "../../include/const.h"
#include "Piece.h"
#include <vector>
#include <memory>

class Player
{
    public:
        //Player();

    private:
        //Color color;
        std::vector<std::shared_ptr<Piece>> pieces;
};
