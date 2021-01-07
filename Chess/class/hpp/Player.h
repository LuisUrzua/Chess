#pragma once

#include "../../include/const.h"
#include "Piece.h"
#include <map>
#include <memory>

class Player
{
    public:
        Player(Color);

    private:
        Color color;
        std::map<Position, std::shared_ptr<Piece>> pieces;
};
