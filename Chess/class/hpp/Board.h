#pragma once

#include "../../include/const.h"
#include <map>
#include <memory>
#include <vector>

class Square;
class Piece;

typedef std::shared_ptr<Piece> PtrPiece;
typedef std::map<Position, std::shared_ptr<Square>> MapSquare;
typedef std::map<Position, PtrPiece> MapPiece;
typedef std::vector<PtrPiece> VectorPiece;

class Board
{
    public:
        Board();
        void displayBoard();
        void insertPiece(const PtrPiece&);
        PtrPiece getPiece(const Position&);
        bool isEmptySquare(const Position&);
        void attackSquare(const Position&, const Color);
        void updateBoard(VectorPiece&);
        bool isSafe(const Position&, Color);

    private:
        MapSquare squares;
};

