#include "../hpp/Knight.h"
#include "../hpp/Board.h"
#include <iostream>
#include <Windows.h>

Knight::Knight(Position position, Color color, Type type) : Piece(position, color, type)
{

}

void Knight::displayPiece()
{
    if (this->getColor() == Color::White)
    {
        char knightWhite[] = "\xE2\x99\x9E";
        UINT defaultCP = GetConsoleOutputCP();
        SetConsoleOutputCP(CODE_PAGE);
        printf(knightWhite);
        SetConsoleOutputCP(defaultCP);
    }
    else if (this->getColor() == Color::Black)
    {
        char knightBlack[] = "\xE2\x99\x98";
        UINT defaultCP = GetConsoleOutputCP();
        SetConsoleOutputCP(CODE_PAGE);
        printf(knightBlack);
        SetConsoleOutputCP(defaultCP);
    }
    else
    {
        // Something went wrong
    }
}

void Knight::updateMoveList(PtrBoard& board)
{
    this->moves.clear();
    Position position = this->getPosition();
    Position destination;
    Color color = this->getColor();
    const int offset1 = 1;
    const int offset2 = 2;

    // Up(2) & Right(1)
    destination = position;
    destination.row += offset2;
    destination.col += offset1;

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
                this->moves.push_back(destination);
            }
        }
    }

    // Up(1) & Right(2)
    destination = position;
    destination.row += offset1;
    destination.col += offset2;

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
                this->moves.push_back(destination);
            }
        }
    }

    // Down(1) & Right(2)
    destination = position;
    destination.row -= offset1;
    destination.col += offset2;

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
                this->moves.push_back(destination);
            }
        }
    }

    // Down(2) & Right(1)
    destination = position;
    destination.row -= offset2;
    destination.col += offset1;

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
                this->moves.push_back(destination);
            }
        }
    }

    // Down(2) & Left(1)
    destination = position;
    destination.row -= offset2;
    destination.col -= offset1;

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
                this->moves.push_back(destination);
            }
        }
    }

    // Down(1) & Left(2)
    destination = position;
    destination.row -= offset1;
    destination.col -= offset2;

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
                this->moves.push_back(destination);
            }
        }
    }

    // Up(1) & Left(2)
    destination = position;
    destination.row += offset1;
    destination.col -= offset2;

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
                this->moves.push_back(destination);
            }
        }
    }

    // Up(2) & Left(1)
    destination = position;
    destination.row += offset2;
    destination.col -= offset1;

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
                this->moves.push_back(destination);
            }
        }
    }
}
