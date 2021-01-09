#include "../hpp/Player.h"
#include "../hpp/Pawn.h"
#include "../hpp/Knight.h"
#include "../hpp/Bishop.h"
#include "../hpp/Rook.h"
#include "../hpp/Queen.h"
#include "../hpp/King.h"


Player::Player(Color color)
{
    this->color = color;

    if(this->color == Color::White)
    {
        pieces[Position(COL_A, ROW_2)] = std::shared_ptr<Piece>(new Pawn(Position(COL_A, ROW_2), Color::White, Type::Pawn));
        pieces[Position(COL_B, ROW_2)] = std::shared_ptr<Piece>(new Pawn(Position(COL_B, ROW_2), Color::White, Type::Pawn));
        pieces[Position(COL_C, ROW_2)] = std::shared_ptr<Piece>(new Pawn(Position(COL_C, ROW_2), Color::White, Type::Pawn));
        pieces[Position(COL_D, ROW_2)] = std::shared_ptr<Piece>(new Pawn(Position(COL_D, ROW_2), Color::White, Type::Pawn));
        pieces[Position(COL_E, ROW_2)] = std::shared_ptr<Piece>(new Pawn(Position(COL_E, ROW_2), Color::White, Type::Pawn));
        pieces[Position(COL_F, ROW_2)] = std::shared_ptr<Piece>(new Pawn(Position(COL_F, ROW_2), Color::White, Type::Pawn));
        pieces[Position(COL_G, ROW_2)] = std::shared_ptr<Piece>(new Pawn(Position(COL_G, ROW_2), Color::White, Type::Pawn));
        pieces[Position(COL_H, ROW_2)] = std::shared_ptr<Piece>(new Pawn(Position(COL_H, ROW_2), Color::White, Type::Pawn));
        pieces[Position(COL_A, ROW_1)] = std::shared_ptr<Piece>(new Rook(Position(COL_A, ROW_1), Color::White, Type::Rook));
        pieces[Position(COL_B, ROW_1)] = std::shared_ptr<Piece>(new Knight(Position(COL_B, ROW_1), Color::White, Type::Knight));
        pieces[Position(COL_C, ROW_1)] = std::shared_ptr<Piece>(new Bishop(Position(COL_C, ROW_1), Color::White, Type::Bishop));
        pieces[Position(COL_D, ROW_1)] = std::shared_ptr<Piece>(new Queen(Position(COL_D, ROW_1), Color::White, Type::Queen));
        pieces[Position(COL_E, ROW_1)] = std::shared_ptr<Piece>(new King(Position(COL_E, ROW_1), Color::White, Type::King));
        pieces[Position(COL_F, ROW_1)] = std::shared_ptr<Piece>(new Bishop(Position(COL_F, ROW_1), Color::White, Type::Bishop));
        pieces[Position(COL_G, ROW_1)] = std::shared_ptr<Piece>(new Knight(Position(COL_G, ROW_1), Color::White, Type::Knight));
        pieces[Position(COL_H, ROW_1)] = std::shared_ptr<Piece>(new Rook(Position(COL_H, ROW_1), Color::White, Type::Rook));
    }
    else if(this->color == Color::Black)
    {
        pieces[Position(COL_A, ROW_7)] = std::shared_ptr<Piece>(new Pawn(Position(COL_A, ROW_7), Color::Black, Type::Pawn));
        pieces[Position(COL_B, ROW_7)] = std::shared_ptr<Piece>(new Pawn(Position(COL_B, ROW_7), Color::Black, Type::Pawn));
        pieces[Position(COL_C, ROW_7)] = std::shared_ptr<Piece>(new Pawn(Position(COL_C, ROW_7), Color::Black, Type::Pawn));
        pieces[Position(COL_D, ROW_7)] = std::shared_ptr<Piece>(new Pawn(Position(COL_D, ROW_7), Color::Black, Type::Pawn));
        pieces[Position(COL_E, ROW_7)] = std::shared_ptr<Piece>(new Pawn(Position(COL_E, ROW_7), Color::Black, Type::Pawn));
        pieces[Position(COL_F, ROW_7)] = std::shared_ptr<Piece>(new Pawn(Position(COL_F, ROW_7), Color::Black, Type::Pawn));
        pieces[Position(COL_G, ROW_7)] = std::shared_ptr<Piece>(new Pawn(Position(COL_G, ROW_7), Color::Black, Type::Pawn));
        pieces[Position(COL_H, ROW_7)] = std::shared_ptr<Piece>(new Pawn(Position(COL_H, ROW_7), Color::Black, Type::Pawn));
        pieces[Position(COL_A, ROW_8)] = std::shared_ptr<Piece>(new Rook(Position(COL_A, ROW_8), Color::Black, Type::Rook));
        pieces[Position(COL_B, ROW_8)] = std::shared_ptr<Piece>(new Knight(Position(COL_B, ROW_8), Color::Black, Type::Knight));
        pieces[Position(COL_C, ROW_8)] = std::shared_ptr<Piece>(new Bishop(Position(COL_C, ROW_8), Color::Black, Type::Bishop));
        pieces[Position(COL_D, ROW_8)] = std::shared_ptr<Piece>(new Queen(Position(COL_D, ROW_8), Color::Black, Type::Queen));
        pieces[Position(COL_E, ROW_8)] = std::shared_ptr<Piece>(new King(Position(COL_E, ROW_8), Color::Black, Type::King));
        pieces[Position(COL_F, ROW_8)] = std::shared_ptr<Piece>(new Bishop(Position(COL_F, ROW_8), Color::Black, Type::Bishop));
        pieces[Position(COL_G, ROW_8)] = std::shared_ptr<Piece>(new Knight(Position(COL_G, ROW_8), Color::Black, Type::Knight));
        pieces[Position(COL_H, ROW_8)] = std::shared_ptr<Piece>(new Rook(Position(COL_H, ROW_8), Color::Black, Type::Rook));
    }
    else
    {
        /* Something went wrong */
    }
}

MapPiece& Player::getPieces()
{
    return pieces;
}
