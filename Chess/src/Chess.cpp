#include <iostream>
#include <map>
#include <memory>
#include "../include/const.h"
#include "../class/hpp/Board.h"
#include "../class/hpp/Player.h"
#include "../class/hpp/Pawn.h"
#include "../class/hpp/Knight.h"
#include "../class/hpp/Bishop.h"
#include "../class/hpp/Rook.h"
#include "../class/hpp/Queen.h"
#include "../class/hpp/King.h"

typedef std::shared_ptr<Board> PtrBoard;
typedef std::shared_ptr<Player> PtrPlayer;
typedef std::shared_ptr<Piece> PtrPiece;
typedef std::map<Position, PtrPiece> MapPiece;

void initialize(MapPiece &);
void setPiecesOnBoard(PtrBoard &, MapPiece &);

int main()
{
    PtrBoard board = std::shared_ptr<Board>(new Board());
    PtrPlayer white = std::shared_ptr<Player>(new Player(Color::White));
    PtrPlayer black = std::shared_ptr<Player>(new Player(Color::Black));
    MapPiece pieces;

    initialize(pieces);
    setPiecesOnBoard(board, pieces);

    board->displayBoard();


    std::cout << std::endl << std::endl << std::endl << std::endl;
    
    return 0;
}

void initialize(MapPiece & pieces)
{
    // Initialize white pieces
    pieces[Position(COL_A, ROW_2)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_A, ROW_2), Color::White, Type::Pawn   ));
    pieces[Position(COL_B, ROW_2)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_B, ROW_2), Color::White, Type::Pawn   ));
    pieces[Position(COL_C, ROW_2)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_C, ROW_2), Color::White, Type::Pawn   ));
    pieces[Position(COL_D, ROW_2)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_D, ROW_2), Color::White, Type::Pawn   ));
    pieces[Position(COL_E, ROW_2)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_E, ROW_2), Color::White, Type::Pawn   ));
    pieces[Position(COL_F, ROW_2)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_F, ROW_2), Color::White, Type::Pawn   ));
    pieces[Position(COL_G, ROW_2)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_G, ROW_2), Color::White, Type::Pawn   ));
    pieces[Position(COL_H, ROW_2)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_H, ROW_2), Color::White, Type::Pawn   ));
    pieces[Position(COL_A, ROW_1)] = std::shared_ptr<Piece>(new Rook    (Position(COL_A, ROW_1), Color::White, Type::Rook   ));
    pieces[Position(COL_B, ROW_1)] = std::shared_ptr<Piece>(new Knight  (Position(COL_B, ROW_1), Color::White, Type::Knight ));
    pieces[Position(COL_C, ROW_1)] = std::shared_ptr<Piece>(new Bishop  (Position(COL_C, ROW_1), Color::White, Type::Bishop ));
    pieces[Position(COL_D, ROW_1)] = std::shared_ptr<Piece>(new Queen   (Position(COL_D, ROW_1), Color::White, Type::Queen  ));
    pieces[Position(COL_E, ROW_1)] = std::shared_ptr<Piece>(new King    (Position(COL_E, ROW_1), Color::White, Type::King   ));
    pieces[Position(COL_F, ROW_1)] = std::shared_ptr<Piece>(new Bishop  (Position(COL_F, ROW_1), Color::White, Type::Bishop ));
    pieces[Position(COL_G, ROW_1)] = std::shared_ptr<Piece>(new Knight  (Position(COL_G, ROW_1), Color::White, Type::Knight ));
    pieces[Position(COL_H, ROW_1)] = std::shared_ptr<Piece>(new Rook    (Position(COL_H, ROW_1), Color::White, Type::Rook   ));
    // Initialize black pieces
    pieces[Position(COL_A, ROW_7)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_A, ROW_7), Color::Black, Type::Pawn   ));
    pieces[Position(COL_B, ROW_7)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_B, ROW_7), Color::Black, Type::Pawn   ));
    pieces[Position(COL_C, ROW_7)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_C, ROW_7), Color::Black, Type::Pawn   ));
    pieces[Position(COL_D, ROW_7)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_D, ROW_7), Color::Black, Type::Pawn   ));
    pieces[Position(COL_E, ROW_7)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_E, ROW_7), Color::Black, Type::Pawn   ));
    pieces[Position(COL_F, ROW_7)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_F, ROW_7), Color::Black, Type::Pawn   ));
    pieces[Position(COL_G, ROW_7)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_G, ROW_7), Color::Black, Type::Pawn   ));
    pieces[Position(COL_H, ROW_7)] = std::shared_ptr<Piece>(new Pawn    (Position(COL_H, ROW_7), Color::Black, Type::Pawn   ));
    pieces[Position(COL_A, ROW_8)] = std::shared_ptr<Piece>(new Rook    (Position(COL_A, ROW_8), Color::Black, Type::Rook   ));
    pieces[Position(COL_B, ROW_8)] = std::shared_ptr<Piece>(new Knight  (Position(COL_B, ROW_8), Color::Black, Type::Knight ));
    pieces[Position(COL_C, ROW_8)] = std::shared_ptr<Piece>(new Bishop  (Position(COL_C, ROW_8), Color::Black, Type::Bishop ));
    pieces[Position(COL_D, ROW_8)] = std::shared_ptr<Piece>(new Queen   (Position(COL_D, ROW_8), Color::Black, Type::Queen  ));
    pieces[Position(COL_E, ROW_8)] = std::shared_ptr<Piece>(new King    (Position(COL_E, ROW_8), Color::Black, Type::King   ));
    pieces[Position(COL_F, ROW_8)] = std::shared_ptr<Piece>(new Bishop  (Position(COL_F, ROW_8), Color::Black, Type::Bishop ));
    pieces[Position(COL_G, ROW_8)] = std::shared_ptr<Piece>(new Knight  (Position(COL_G, ROW_8), Color::Black, Type::Knight ));
    pieces[Position(COL_H, ROW_8)] = std::shared_ptr<Piece>(new Rook    (Position(COL_H, ROW_8), Color::Black, Type::Rook   ));
}

void setPiecesOnBoard(PtrBoard & board, MapPiece & pieces)
{
    for (auto const & piece : pieces)
    {
        board->insertPiece(piece.second);
    }
}
