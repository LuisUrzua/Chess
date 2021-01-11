#include "../hpp/Rook.h"
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

bool Rook::validMove(const Position& newPosition)
{
    return false;
}
