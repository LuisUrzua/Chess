#include "../hpp/Pawn.h"
#include "../hpp/Board.h"
#include <iostream>
#include <Windows.h>

typedef std::shared_ptr<Piece> PtrPiece;

Pawn::Pawn(Position position, Color color, Type type) : Piece(position, color, type)
{
    this->firstMove = true;
}

void Pawn::displayPiece()
{
    if (this->getColor() == Color::White)
    {
        char pawnWhite[] = "\xE2\x99\x9F";
        UINT defaultCP = GetConsoleOutputCP();
        SetConsoleOutputCP(CODE_PAGE);
        printf(pawnWhite);
        SetConsoleOutputCP(defaultCP);
    }
    else if (this->getColor() == Color::Black)
    {
        char pawnBlack[] = "\xE2\x99\x99";
        UINT defaultCP = GetConsoleOutputCP();
        SetConsoleOutputCP(CODE_PAGE);
        printf(pawnBlack);
        SetConsoleOutputCP(defaultCP);
    }
    else
    {
        // Something went wrong
    }
}

bool Pawn::isValidMove(const Position& newPosition, PtrBoard& board)
{
    bool isValid = false;
    Position currentPosition = this->getPosition();
    const int colOffset = 0;
    const int rowOffset = 1;
    const int doubleOffset = 2;
    //PtrPiece pieceOnNewSquare = board->getPiece(newPosition);
    Position intermediateSquare = newPosition;
    intermediateSquare.row += (this->getColor() == Color::White) ? 1 : -1;


    if (this->getColor() == Color::White)
    {
        if ((newPosition.col - currentPosition.col) == colOffset &&
            (newPosition.row - currentPosition.row) == rowOffset &&
            board->isEmptySquare(newPosition))
        {
            isValid = true;
        }
        else if ((newPosition.col - currentPosition.col) == colOffset &&
            (newPosition.row - currentPosition.row) == doubleOffset && 
            board->isEmptySquare(newPosition) &&
            board->isEmptySquare(intermediateSquare) &&
            firstMove)
        {
            isValid = true;
        }
    }
    else
    {

    }

    return isValid;
}

bool Pawn::isValidAttack(const Position&, PtrBoard&)
{
    return false;
}

bool isMoveValid(const Position& newSquare, PtrBoard& board)
{
    bool isValid = false;

    return isValid;
}

bool isAttackValid(const Position& newSquare, PtrBoard& board)
{
    bool isValid = false;

    return isValid;
}
