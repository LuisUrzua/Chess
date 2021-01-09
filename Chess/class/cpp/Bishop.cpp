#include "../hpp/Bishop.h"
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

void Bishop::move()
{

}
