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
        pieces[Position(ROW_2, COL_A)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_2, COL_A), Color::White, Type::Pawn));
        pieces[Position(ROW_2, COL_B)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_2, COL_B), Color::White, Type::Pawn));
        pieces[Position(ROW_2, COL_C)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_2, COL_C), Color::White, Type::Pawn));
        pieces[Position(ROW_2, COL_D)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_2, COL_D), Color::White, Type::Pawn));
        pieces[Position(ROW_2, COL_E)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_2, COL_E), Color::White, Type::Pawn));
        pieces[Position(ROW_2, COL_F)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_2, COL_F), Color::White, Type::Pawn));
        pieces[Position(ROW_2, COL_G)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_2, COL_G), Color::White, Type::Pawn));
        pieces[Position(ROW_2, COL_H)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_2, COL_H), Color::White, Type::Pawn));
        pieces[Position(ROW_1, COL_A)] = std::shared_ptr<Piece>(new Rook(Position(ROW_1, COL_A), Color::White, Type::Rook));
        pieces[Position(ROW_1, COL_B)] = std::shared_ptr<Piece>(new Knight(Position(ROW_1, COL_B), Color::White, Type::Knight));
        pieces[Position(ROW_1, COL_C)] = std::shared_ptr<Piece>(new Bishop(Position(ROW_1, COL_C), Color::White, Type::Bishop));
        pieces[Position(ROW_1, COL_D)] = std::shared_ptr<Piece>(new Queen(Position(ROW_1, COL_D), Color::White, Type::Queen));
        pieces[Position(ROW_1, COL_E)] = std::shared_ptr<Piece>(new King(Position(ROW_1, COL_E), Color::White, Type::King));
        pieces[Position(ROW_1, COL_F)] = std::shared_ptr<Piece>(new Bishop(Position(ROW_1, COL_F), Color::White, Type::Bishop));
        pieces[Position(ROW_1, COL_G)] = std::shared_ptr<Piece>(new Knight(Position(ROW_1, COL_G), Color::White, Type::Knight));
        pieces[Position(ROW_1, COL_H)] = std::shared_ptr<Piece>(new Rook(Position(ROW_1, COL_H), Color::White, Type::Rook));
    }
    else if(this->color == Color::Black)
    {
        pieces[Position(ROW_7, COL_A)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_7, COL_A), Color::Black, Type::Pawn));
        pieces[Position(ROW_7, COL_B)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_7, COL_B), Color::Black, Type::Pawn));
        pieces[Position(ROW_7, COL_C)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_7, COL_C), Color::Black, Type::Pawn));
        pieces[Position(ROW_7, COL_D)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_7, COL_D), Color::Black, Type::Pawn));
        pieces[Position(ROW_7, COL_E)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_7, COL_E), Color::Black, Type::Pawn));
        pieces[Position(ROW_7, COL_F)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_7, COL_F), Color::Black, Type::Pawn));
        pieces[Position(ROW_7, COL_G)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_7, COL_G), Color::Black, Type::Pawn));
        pieces[Position(ROW_7, COL_H)] = std::shared_ptr<Piece>(new Pawn(Position(ROW_7, COL_H), Color::Black, Type::Pawn));
        pieces[Position(ROW_8, COL_A)] = std::shared_ptr<Piece>(new Rook(Position(ROW_8, COL_A), Color::Black, Type::Rook));
        pieces[Position(ROW_8, COL_B)] = std::shared_ptr<Piece>(new Knight(Position(ROW_8, COL_B), Color::Black, Type::Knight));
        pieces[Position(ROW_8, COL_C)] = std::shared_ptr<Piece>(new Bishop(Position(ROW_8, COL_C), Color::Black, Type::Bishop));
        pieces[Position(ROW_8, COL_D)] = std::shared_ptr<Piece>(new Queen(Position(ROW_8, COL_D), Color::Black, Type::Queen));
        pieces[Position(ROW_8, COL_E)] = std::shared_ptr<Piece>(new King(Position(ROW_8, COL_E), Color::Black, Type::King));
        pieces[Position(ROW_8, COL_F)] = std::shared_ptr<Piece>(new Bishop(Position(ROW_8, COL_F), Color::Black, Type::Bishop));
        pieces[Position(ROW_8, COL_G)] = std::shared_ptr<Piece>(new Knight(Position(ROW_8, COL_G), Color::Black, Type::Knight));
        pieces[Position(ROW_8, COL_H)] = std::shared_ptr<Piece>(new Rook(Position(ROW_8, COL_H), Color::Black, Type::Rook));
    }
    else
    {
        /* Something went wrong */
    }
}
