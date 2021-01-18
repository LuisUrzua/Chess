#include "../hpp/Queen.h"
#include "../hpp/Board.h"
#include <iostream>
#include <Windows.h>

Queen::Queen(Position position, Color color, Type type) : Piece(position, color, type)
{

}

void Queen::displayPiece()
{
    if (this->getColor() == Color::White)
    {
        char queenWhite[] = "\xE2\x99\x9B";
        UINT defaultCP = GetConsoleOutputCP();
        SetConsoleOutputCP(CODE_PAGE);
        printf(queenWhite);
        SetConsoleOutputCP(defaultCP);
    }
    else if (this->getColor() == Color::Black)
    {
        char queenBlack[] = "\xE2\x99\x95";
        UINT defaultCP = GetConsoleOutputCP();
        SetConsoleOutputCP(CODE_PAGE);
        printf(queenBlack);
        SetConsoleOutputCP(defaultCP);
    }
    else
    {
        // Something went wrong
    }
}

void Queen::updateMoveList(PtrBoard& board)
{
    this->moves.clear();
    Position position = this->getPosition();
    Color color = this->getColor();
    const int longestDiagonal = 8;

    // Bishop moves

    // Up & Right
    for (int i = 1; i <= longestDiagonal; i++)
    {
        Position destination = position;
        destination.row += i;
        destination.col += i;

        if (!destination.isWithinBounds())
        {
            // Break - no point checking the rest of the diagonal
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

    // Down & Right
    for (int i = 1; i <= longestDiagonal; i++)
    {
        Position destination = position;
        destination.row -= i;
        destination.col += i;

        if (!destination.isWithinBounds())
        {
            // Break - no point checking the rest of the diagonal
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

    // Up & Left
    for (int i = 1; i <= longestDiagonal; i++)
    {
        Position destination = position;
        destination.row += i;
        destination.col -= i;

        if (!destination.isWithinBounds())
        {
            // Break - no point checking the rest of the diagonal
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

    // Down & Left
    for (int i = 1; i <= longestDiagonal; i++)
    {
        Position destination = position;
        destination.row -= i;
        destination.col -= i;

        if (!destination.isWithinBounds())
        {
            // Break - no point checking the rest of the diagonal
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

    const int max = 8;

    // Rook moves

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
