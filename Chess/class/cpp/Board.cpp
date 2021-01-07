#include "../hpp/Board.h"

Board::Board()
{
    for (int row = ROW_1; row <= ROW_8; row++)
    {
        for (int col = COL_A; col <= COL_H; col++)
        {
            squares[Position(row, col)] = std::shared_ptr<Square>(new Square(Position(row, col)));
        }
    }
}
