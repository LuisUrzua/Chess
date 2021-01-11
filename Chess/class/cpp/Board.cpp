#include "../hpp/Board.h"
#include "../hpp/Square.h"
#include "../hpp/Piece.h"
#include <iostream>

Board::Board()
{
    for (int col = COL_A; col <= COL_H; col++)
    {
        for (int row = ROW_1; row <= ROW_8; row++)
        {
            squares[Position(col, row)] = std::shared_ptr<Square>(new Square(Position(col, row)));
        }
    }
}

void Board::displayBoard()
{
    system("cls");
    const int colsPerSquare = 7;
    const int rowsPerSquare = 3;
    int cursorX = 0, cursorY = 0;

    for (int i = 0, row = ROW_8; row >= ROW_1; row--, i++)
    {
        for (int j = 0, col = COL_A; col <= COL_H; col++, j++)
        {
            cursorX = colsPerSquare * j;
            cursorY = rowsPerSquare * i;
            squares[Position(col, row)]->displaySquare(cursorX, cursorY);
        }
    }

    std::cout << std::endl << std::endl;
    const std::string columns[] = { "A", "B", "C", "D", "E", "F", "G", "H" };

    for (const std::string & column : columns)
    {
        std::cout << "   " << column << "   ";
    }

    std::cout << std::endl << std::endl;
}

void Board::insertPiece(const PtrPiece & piece)
{
    squares[piece->getPosition()]->insertPiece(piece);
}

PtrPiece Board::getPiece(const Position position)
{
    // May return null if no piece is at this square
    return squares[position]->getPiece();
}
