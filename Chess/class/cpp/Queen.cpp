#include "../hpp/Queen.h"
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

bool Queen::isValidMove(const Position& newPosition, PtrBoard& board)
{
    return false;
}

bool Queen::isValidAttack(const Position&, PtrBoard&)
{
    return false;
}
