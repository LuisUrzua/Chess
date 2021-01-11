#include "../hpp/King.h"
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

bool King::validMove(const Position& newPosition)
{
    return false;
}
