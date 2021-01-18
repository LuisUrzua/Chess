#include "../hpp/Pawn.h"
#include "../hpp/Board.h"
#include <iostream>
#include <Windows.h>

typedef std::shared_ptr<Piece> PtrPiece;

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

bool Pawn::isEnpassant() const
{
    return false;
}

void Pawn::updateMoveList(PtrBoard& board)
{
    this->moves.clear();
    Position position = this->getPosition();
    Color color = this->getColor();
    const int zero = 0;
    const int leftCol = -1;
    const int rightCol = 1;
    int oneRow;
    int twoRow;

    switch (color)
    {
        case Color::White:
            oneRow = 1;
            twoRow = 2;
            break;
        case Color::Black:
            oneRow = -1;
            twoRow = -2;
            break;
        default:
            // Something went wrong
            return;
    } 

    Position forward1(position.col + zero, position.row + oneRow);
    Position forward2(position.col + zero, position.row + twoRow);
    Position captureL(position.col + leftCol, position.row + oneRow);
    Position captureR(position.col + rightCol, position.row + oneRow);
    
    if (board->isEmptySquare(forward1) && forward1.isWithinBounds())
    {
        this->moves.push_back(forward1);
    }

    if (board->isEmptySquare(forward2) && forward2.isWithinBounds())
    {
        this->moves.push_back(forward2);
    }

    if (!board->isEmptySquare(captureL) && captureL.isWithinBounds())
    {
        PtrPiece enemy = board->getPiece(captureL);
        
        if (enemy->getColor() != color)
        {
            this->moves.push_back(captureL);
            board->attackSquare(captureL, this->getColor());
        }
    }

    if (!board->isEmptySquare(captureR) && captureR.isWithinBounds())
    {
        PtrPiece enemy = board->getPiece(captureR);

        if (enemy->getColor() != color)
        {
            this->moves.push_back(captureR);
            board->attackSquare(captureR, this->getColor());
        }
    }

    // En passant capture
    if (board->isEmptySquare(captureL) && captureL.isWithinBounds())
    {
        Position enpassant(captureL.col, captureL.row);
        enpassant.row += (this->getColor() == Color::White) ? -1 : 1;

        if (!board->isEmptySquare(enpassant))
        {
            PtrPiece enemy = board->getPiece(enpassant);

            if (enemy->getColor() != color && enemy->getType() == Type::Pawn)
            {
                std::shared_ptr<Pawn> enemyPawn = std::dynamic_pointer_cast<Pawn> (enemy);

                if (enemyPawn->isEnpassant())
                {
                    this->moves.push_back(captureL);
                    board->attackSquare(captureL, this->getColor());
                }
            }
        }
    }
    // En passant capture
    if (board->isEmptySquare(captureR) && captureR.isWithinBounds())
    {
        Position enpassant(captureR.col, captureR.row);
        enpassant.row += (this->getColor() == Color::White) ? -1 : 1;
        
        if (!board->isEmptySquare(enpassant))
        {
            PtrPiece enemy = board->getPiece(enpassant);

            if (enemy->getColor() != color && enemy->getType() == Type::Pawn)
            {
                std::shared_ptr<Pawn> enemyPawn = std::dynamic_pointer_cast<Pawn> (enemy);

                if (enemyPawn->isEnpassant())
                {
                    this->moves.push_back(captureR);
                    board->attackSquare(captureR, this->getColor());
                }
            }
        }
    }
}
