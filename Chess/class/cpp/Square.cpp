#include "../hpp/Square.h"
#include "../hpp/Piece.h"
#include <iostream>
#include <Windows.h>
#include <string>

Square::Square(Position position)
{
    this->position = position;
    this->whiteAttackers = 0;
    this->blackAttackers = 0;
}

bool Square::isEmpty() const
{
    return (!(this->piece)) ? true : false;
}

void Square::insertPiece(const PtrPiece &piece)
{
    if (this->isEmpty())
    {
        this->piece = piece;
    }
    else
    {
        this->piece.reset();
        this->piece = piece;
    }
}

PtrPiece Square::getPiece() const
{
    return this->piece;
}

void Square::removePiece()
{
    if (this->isEmpty())
    {
        // This does nothing
    }
    else
    {
        this->piece.reset();
    }
}

void Square::displaySquare(const int &startingX, const int &startingY)
{
    const int colsPerSquare = 7;
    const int rowsPerSquare = 3;
    const int midCol = 3;
    const int midRow = 1;
    Color color = ((this->position.col + this->position.row) % 2 != 0) ? Color::White : Color::Black;
    
    for (int i = 0; i < rowsPerSquare; i++)
    {
        for (int j = 0; j < colsPerSquare; j++)
        {
            int currentX = startingX + j;
            int currentY = startingY + i;
            setCursor(currentX, currentY);
            if (i == midRow && j == midCol)
            {
                if (this->isEmpty())
                {
                    if (color == Color::White)
                    {
                        std::cout << char(WHITE_SQUARE);
                    }
                    else
                    {
                        std::cout << char(BLACK_SQUARE);
                    }
                }
                else
                {
                    this->piece->displayPiece();
                }
            }
            else if (i == midRow && j == (midCol + 1))
            {
                if (this->isEmpty())
                {
                    if (color == Color::White)
                    {
                        std::cout << char(WHITE_SQUARE);
                    }
                    else
                    {
                        std::cout << char(BLACK_SQUARE);
                    }
                }
                else
                {
                    std::cout << char(BLACK_SQUARE);
                }
            }
            else
            {
                if (color == Color::White)
                {
                    std::cout << char(WHITE_SQUARE);
                }
                else
                {
                    std::cout << char(BLACK_SQUARE);
                }
            }
            if (i == midRow && this->position.col == COL_H && j == (colsPerSquare - 1))
            {
                std::cout << "   " << std::to_string(this->position.row);
            }
        }
    }
}

void Square::setCursor(const int & x, const int & y)
{
    short col_x = (short)x;
    short row_y = (short)y;
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { col_x, row_y };
    SetConsoleCursorPosition(output, pos);
}

void Square::attackSquare(const Color color)
{
    if (color == Color::White)
    {
        this->whiteAttackers++;
    }
    else if (color == Color::Black)
    {
        this->blackAttackers++;
    }
}

void Square::resetAttackers()
{
    this->whiteAttackers = 0;
    this->blackAttackers = 0;
}

bool Square::isSafe(Color color)
{
    bool safe = false;

    if (color == Color::White)
    {
        if (blackAttackers == 0)
        {
            safe = true;
        }
    }
    else if (color == Color::Black)
    {
        if (whiteAttackers == 0)
        {
            safe = true;
        }
    }

    return safe;
}
