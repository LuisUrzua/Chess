#include "../hpp/Board.h"

Board::Board()
{
    Position position;
    std::shared_ptr<Square> square;

    for(int col = _A; col <= _H; col++)
    {
        for (int row = _1; row <= _8; row++)
        {
            position.col = col;
            position.row = row;
            square.reset(new Square(position));
            squares[position] = square;
        }
    }
}
