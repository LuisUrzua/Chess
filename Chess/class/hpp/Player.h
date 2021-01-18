#pragma once

#include "../../include/const.h"
#include <string>
#include <map>
#include <memory>
#include <vector>

class Piece;
class Board;

typedef std::shared_ptr<Piece> PtrPiece;
typedef std::map<Position, PtrPiece> MapPiece;
typedef std::shared_ptr<Board> PtrBoard;
typedef std::vector<PtrPiece> VectorPiece;

class Player
{
    public:
        Player(Color);
        Color getColor() const;
        void nextMove(const VectorPiece&, const PtrBoard&);
        Position getMostRecentMove() const;
        bool isInputValid(const std::string&, const VectorPiece&, const PtrBoard&);
        Position getSource() const;
        Position getDestination() const;
        bool findPiece(const VectorPiece&, const Position&);

    private:
        Color color;
        Position move;
        Position source;
        Position destination;
};
