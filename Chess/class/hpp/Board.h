#pragma once

#include "../../include/const.h"
#include <map>
#include <memory>

class Square;
class Piece;

typedef std::shared_ptr<Piece> PtrPiece;
typedef std::map<Position, std::shared_ptr<Square>> MapSquare;

class Board
{
    public:
        Board();
        void displayBoard();
        void insertPiece(const PtrPiece &);
        PtrPiece getPiece(const Position) ;

    private:
        MapSquare squares;
};

