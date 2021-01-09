#pragma once

#include "../../include/const.h"
#include "Piece.h"
#include <map>
#include <memory>

typedef std::map<Position, std::shared_ptr<Piece>> MapPiece;

class Player
{
    public:
        Player(Color);
        MapPiece& getPieces();

    private:
        Color color;
        MapPiece pieces;
};
