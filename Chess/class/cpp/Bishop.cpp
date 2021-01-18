#include "../hpp/Bishop.h"
#include "../hpp/Board.h"
#include <iostream>
#include <Windows.h>

Bishop::Bishop(Position position, Color color, Type type) : Piece(position, color, type)
{

}

void Bishop::displayPiece()
{
    if (this->getColor() == Color::White)
    {
        char bishopWhite[] = "\xE2\x99\x9D";
        UINT defaultCP = GetConsoleOutputCP();
        SetConsoleOutputCP(CODE_PAGE);
        printf(bishopWhite);
        SetConsoleOutputCP(defaultCP);
    }
    else if (this->getColor() == Color::Black)
    {
        char bishopBlack[] = "\xE2\x99\x97";
        UINT defaultCP = GetConsoleOutputCP();
        SetConsoleOutputCP(CODE_PAGE);
        printf(bishopBlack);
        SetConsoleOutputCP(defaultCP);
    }
    else
    {
        // Something went wrong
    }
    
}

void Bishop::updateMoveList(PtrBoard& board)
{
    this->moves.clear();
    Position position = this->getPosition();
    Color color = this->getColor();
    const int longestDiagonal = 8;

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
}
