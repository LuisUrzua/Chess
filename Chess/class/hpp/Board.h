#pragma once

#include "../../include/const.h"
#include <map>
#include <memory>

class Square;
class Player;

typedef std::map<Position, std::shared_ptr<Square>> MapSquare;
typedef std::shared_ptr<Player> PtrPlayer;

class Board
{
    public:
        Board();
        void displayBoard();
        void setupPieces();

    private:
        MapSquare squares;
        PtrPlayer whitePlayer;
        PtrPlayer blackPlayer;
};

