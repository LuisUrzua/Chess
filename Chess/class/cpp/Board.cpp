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

PtrPiece Board::getPiece(const Position& position)
{
    if (position.isWithinBounds())
    {
        // May return null if no piece is at this square
        return squares[position]->getPiece();
    }

    return NULL;
}

bool Board::isEmptySquare(const Position& position)
{
    if (position.isWithinBounds())
    {
        return squares[position]->isEmpty();
    }
    
    return false;
}

void Board::attackSquare(const Position& position, const Color color)
{
    if (!position.isWithinBounds())
    {
        return;
    }

    squares[position]->attackSquare(color);
}

void Board::updateBoard(VectorPiece& pieces)
{
    for (const auto& square : squares)
    {
        square.second->removePiece();
    }

    for (const auto& piece : pieces)
    {
        squares[piece->getPosition()]->insertPiece(piece);
    }
}

bool Board::isSafe(const Position& position, Color color)
{
    // Assume that position is within board boundaries

    return squares[position]->isSafe(color);
}
