#include "../hpp/Rook.h"
#include "../hpp/Board.h"
#include <iostream>
#include <Windows.h>

Rook::Rook(Position position, Color color, Type type) : Piece(position, color, type)
{

}

void Rook::displayPiece()
{
    if (this->getColor() == Color::White)
    {
        char rookWhite[] = "\xE2\x99\x9C";
        UINT defaultCP = GetConsoleOutputCP();
        SetConsoleOutputCP(CODE_PAGE);
        printf(rookWhite);
        SetConsoleOutputCP(defaultCP);
    }
    else if (this->getColor() == Color::Black)
    {
        char rookBlack[] = "\xE2\x99\x96";
        UINT defaultCP = GetConsoleOutputCP();
        SetConsoleOutputCP(CODE_PAGE);
        printf(rookBlack);
        SetConsoleOutputCP(defaultCP);
    }
    else
    {
        // Something went wrong
    }
}

void Rook::updateMoveList(PtrBoard& board)
{
    this->moves.clear();
    Position position = this->getPosition();
    Color color = this->getColor();
    const int max = 8;

    // Up
    for (int i = 1; i <= max; i++)
    {
        Position destination = position;
        destination.row += i;

        if (!destination.isWithinBounds())
        {
            // Break - no point checking the rest of the range
            break;
        }

        if (board->isEmptySquare(destination))
        {
            this->moves.push_back(destination);
            board->attackSquare(destination, color);
        }
        else
        {
            PtrPiece enemy = board->getPiece(destination);

            if (enemy->getColor() != color)
            {
                this->moves.push_back(destination);
            }

            board->attackSquare(destination, color);
            break;
        }
    }

    // Right
    for (int i = 1; i <= max; i++)
    {
        Position destination = position;
        destination.col += i;

        if (!destination.isWithinBounds())
        {
            // Break - no point checking the rest of the range
            break;
        }

        if (board->isEmptySquare(destination))
        {
            this->moves.push_back(destination);
            board->attackSquare(destination, color);
        }
        else
        {
            PtrPiece enemy = board->getPiece(destination);

            if (enemy->getColor() != color)
            {
                this->moves.push_back(destination);
            }

            board->attackSquare(destination, color);
            break;
        }
    }

    // Down
    for (int i = 1; i <= max; i++)
    {
        Position destination = position;
        destination.row -= i;

        if (!destination.isWithinBounds())
        {
            // Break - no point checking the rest of the range
            break;
        }

        if (board->isEmptySquare(destination))
        {
            this->moves.push_back(destination);
            board->attackSquare(destination, color);
        }
        else
        {
            PtrPiece enemy = board->getPiece(destination);

            if (enemy->getColor() != color)
            {
                this->moves.push_back(destination);
            }

            board->attackSquare(destination, color);
            break;
        }
    }

    // Left
    for (int i = 1; i <= max; i++)
    {
        Position destination = position;
        destination.col -= i;

        if (!destination.isWithinBounds())
        {
            // Break - no point checking the rest of the range
            break;
        }

        if (board->isEmptySquare(destination))
        {
            this->moves.push_back(destination);
            board->attackSquare(destination, color);
        }
        else
        {
            PtrPiece enemy = board->getPiece(destination);

            if (enemy->getColor() != color)
            {
                this->moves.push_back(destination);
            }

            board->attackSquare(destination, color);
            break;
        }
    }
}
