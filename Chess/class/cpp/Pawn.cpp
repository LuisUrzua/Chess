#include "../hpp/Pawn.h"
#include <iostream>
#include <Windows.h>

Pawn::Pawn(Position position, Color color, Type type) : Piece(position, color, type)
{

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

bool Pawn::validMove(const Position & newPosition)
{
    return false;
}
