#include "../hpp/Square.h"
#include "../hpp/Piece.h"
#include <iostream>
#include <Windows.h>
#include <string>

Square::Square(Position position)
{
    this->position = position;
}

bool Square::isEmpty() const
{
    return (!(this->piece)) ? true : false;
}

void Square::insertPiece(const std::shared_ptr<Piece> &piece)
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
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x, y };
    SetConsoleCursorPosition(output, pos);
}
