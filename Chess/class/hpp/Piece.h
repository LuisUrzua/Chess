#pragma once

#include "../../include/const.h"
#include <memory>
#include <list>

class Board;

typedef std::shared_ptr<Board> PtrBoard;
typedef std::list<Position> ListPos;

class Piece
{
    public:
        Piece(Position, Color, Type);
        Position getPosition() const;
        Color getColor() const;
        Type getType() const;
        void setPosition(const Position);
        virtual void displayPiece() = 0;
        bool isValidMove(const Position&);
        virtual void updateMoveList(PtrBoard&) = 0;
        bool isFirstMove() const;

    private:
        Position position;
        Color color;
        Type type;
        bool first;
    
    protected:
        ListPos moves;
};

