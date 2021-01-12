#include "../hpp/Knight.h"
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

bool Knight::isValidMove(const Position& newPosition, PtrBoard& board)
{
    return false;
}

bool Knight::isValidAttack(const Position&, PtrBoard&)
{
    return false;
}
