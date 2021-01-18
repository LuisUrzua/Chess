#include "../hpp/King.h"
#include "../hpp/Board.h"
#include <iostream>
#include <Windows.h>

King::King(Position position, Color color, Type type) : Piece(position, color, type)
{

}

void King::displayPiece()
{
    if (this->getColor() == Color::White)
    {
        char kingWhite[] = "\xE2\x99\x9A";
        UINT defaultCP = GetConsoleOutputCP();
        SetConsoleOutputCP(CODE_PAGE);
        printf(kingWhite);
        SetConsoleOutputCP(defaultCP);
    }
    else if (this->getColor() == Color::Black)
    {
        char kingBlack[] = "\xE2\x99\x94";
        UINT defaultCP = GetConsoleOutputCP();
        SetConsoleOutputCP(CODE_PAGE);
        printf(kingBlack);
        SetConsoleOutputCP(defaultCP);
    }
    else
    {
        // Something went wrong
    }
}

void King::updateMoveList(PtrBoard& board)
{
    this->moves.clear();
    Position position = this->getPosition();
    Position destination;
    Color color = this->getColor();
    const int offset = 1;

    // Col(0), Row(1) 
    destination = position;
    destination.col += 0;
    destination.row += offset;

    if (destination.isWithinBounds())
    {
        board->attackSquare(destination, color);

        if (board->isEmptySquare(destination))
        {
            this->moves.push_back(destination);
        }
        else
        {
            PtrPiece enemy = board->getPiece(destination);

            if (enemy->getColor() != color)
            {
                if (board->isSafe(destination, color))
                {
                    this->moves.push_back(destination);
                }
            }
        }
    }

    // Col(1), Row(1) 
    destination = position;
    destination.col += offset;
    destination.row += offset;

    if (destination.isWithinBounds())
    {
        board->attackSquare(destination, color);

        if (board->isEmptySquare(destination))
        {
            this->moves.push_back(destination);
        }
        else
        {
            PtrPiece enemy = board->getPiece(destination);

            if (enemy->getColor() != color)
            {
                if (board->isSafe(destination, color))
                {
                    this->moves.push_back(destination);
                }
            }
        }
    }

    // Col(1), Row(0) 
    destination = position;
    destination.col += offset;
    destination.row += 0;

    if (destination.isWithinBounds())
    {
        board->attackSquare(destination, color);

        if (board->isEmptySquare(destination))
        {
            this->moves.push_back(destination);
        }
        else
        {
            PtrPiece enemy = board->getPiece(destination);

            if (enemy->getColor() != color)
            {
                if (board->isSafe(destination, color))
                {
                    this->moves.push_back(destination);
                }
            }
        }
    }

    // Col(1), Row(-1) 
    destination = position;
    destination.col += offset;
    destination.row -= offset;

    if (destination.isWithinBounds())
    {
        board->attackSquare(destination, color);

        if (board->isEmptySquare(destination))
        {
            this->moves.push_back(destination);
        }
        else
        {
            PtrPiece enemy = board->getPiece(destination);

            if (enemy->getColor() != color)
            {
                if (board->isSafe(destination, color))
                {
                    this->moves.push_back(destination);
                }
            }
        }
    }

    // Col(0), Row(-1) 
    destination = position;
    destination.col += 0;
    destination.row -= offset;

    if (destination.isWithinBounds())
    {
        board->attackSquare(destination, color);

        if (board->isEmptySquare(destination))
        {
            this->moves.push_back(destination);
        }
        else
        {
            PtrPiece enemy = board->getPiece(destination);

            if (enemy->getColor() != color)
            {
                if (board->isSafe(destination, color))
                {
                    this->moves.push_back(destination);
                }
            }
        }
    }

    // Col(-1), Row(-1) 
    destination = position;
    destination.col -= offset;
    destination.row -= offset;

    if (destination.isWithinBounds())
    {
        board->attackSquare(destination, color);

        if (board->isEmptySquare(destination))
        {
            this->moves.push_back(destination);
        }
        else
        {
            PtrPiece enemy = board->getPiece(destination);

            if (enemy->getColor() != color)
            {
                if (board->isSafe(destination, color))
                {
                    this->moves.push_back(destination);
                }
            }
        }
    }

    // Col(-1), Row(0) 
    destination = position;
    destination.col -= offset;
    destination.row += 0;

    if (destination.isWithinBounds())
    {
        board->attackSquare(destination, color);

        if (board->isEmptySquare(destination))
        {
            this->moves.push_back(destination);
        }
        else
        {
            PtrPiece enemy = board->getPiece(destination);

            if (enemy->getColor() != color)
            {
                if (board->isSafe(destination, color))
                {
                    this->moves.push_back(destination);
                }
            }
        }
    }

    // Col(-1), Row(1) 
    destination = position;
    destination.col -= offset;
    destination.row += offset;

    if (destination.isWithinBounds())
    {
        board->attackSquare(destination, color);

        if (board->isEmptySquare(destination))
        {
            this->moves.push_back(destination);
        }
        else
        {
            PtrPiece enemy = board->getPiece(destination);

            if (enemy->getColor() != color)
            {
                if (board->isSafe(destination, color))
                {
                    this->moves.push_back(destination);
                }
            }
        }
    }


}
