#include <iostream>
#include <vector>
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
typedef std::vector<PtrPiece> VectorPiece;

void initialize(VectorPiece&);
void setPiecesOnBoard(PtrBoard &, VectorPiece&);
void updatePieces(VectorPiece&, PtrBoard&);
void movePiece(VectorPiece&, const PtrPlayer&);

int main()
{
    PtrBoard board = std::shared_ptr<Board>(new Board());
    PtrPlayer white = std::shared_ptr<Player>(new Player(Color::White));
    PtrPlayer black = std::shared_ptr<Player>(new Player(Color::Black));
    VectorPiece pieces;

    initialize(pieces);
    setPiecesOnBoard(board, pieces);

    while (true)
    {
        board->displayBoard();
        updatePieces(pieces, board);
        white->nextMove(pieces, board);
        movePiece(pieces, white);
        board->updateBoard(pieces);

        board->displayBoard();
        updatePieces(pieces, board);
        black->nextMove(pieces, board);
        movePiece(pieces, black);
        board->updateBoard(pieces);
    }

    board->displayBoard();

    std::cout << std::endl << std::endl << std::endl << std::endl;
    
    return 0;
}

void initialize(VectorPiece& pieces)
{
    // Initialize white pieces
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_A, ROW_2), Color::White, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_B, ROW_2), Color::White, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_C, ROW_2), Color::White, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_D, ROW_2), Color::White, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_E, ROW_2), Color::White, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_F, ROW_2), Color::White, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_G, ROW_2), Color::White, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_H, ROW_2), Color::White, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Rook(Position(COL_A, ROW_1), Color::White, Type::Rook)));
    pieces.push_back(std::shared_ptr<Piece>(new Knight(Position(COL_B, ROW_1), Color::White, Type::Knight)));
    pieces.push_back(std::shared_ptr<Piece>(new Bishop(Position(COL_C, ROW_1), Color::White, Type::Bishop)));
    pieces.push_back(std::shared_ptr<Piece>(new Queen(Position(COL_D, ROW_1), Color::White, Type::Queen)));
    pieces.push_back(std::shared_ptr<Piece>(new King(Position(COL_E, ROW_1), Color::White, Type::King)));
    pieces.push_back(std::shared_ptr<Piece>(new Bishop(Position(COL_F, ROW_1), Color::White, Type::Bishop)));
    pieces.push_back(std::shared_ptr<Piece>(new Knight(Position(COL_G, ROW_1), Color::White, Type::Knight)));
    pieces.push_back(std::shared_ptr<Piece>(new Rook(Position(COL_H, ROW_1), Color::White, Type::Rook)));
    // Initialize black pieces
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_A, ROW_7), Color::Black, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_B, ROW_7), Color::Black, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_C, ROW_7), Color::Black, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_D, ROW_7), Color::Black, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_E, ROW_7), Color::Black, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_F, ROW_7), Color::Black, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_G, ROW_7), Color::Black, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Pawn(Position(COL_H, ROW_7), Color::Black, Type::Pawn)));
    pieces.push_back(std::shared_ptr<Piece>(new Rook(Position(COL_A, ROW_8), Color::Black, Type::Rook)));
    pieces.push_back(std::shared_ptr<Piece>(new Knight(Position(COL_B, ROW_8), Color::Black, Type::Knight)));
    pieces.push_back(std::shared_ptr<Piece>(new Bishop(Position(COL_C, ROW_8), Color::Black, Type::Bishop)));
    pieces.push_back(std::shared_ptr<Piece>(new Queen(Position(COL_D, ROW_8), Color::Black, Type::Queen)));
    pieces.push_back(std::shared_ptr<Piece>(new King(Position(COL_E, ROW_8), Color::Black, Type::King)));
    pieces.push_back(std::shared_ptr<Piece>(new Bishop(Position(COL_F, ROW_8), Color::Black, Type::Bishop)));
    pieces.push_back(std::shared_ptr<Piece>(new Knight(Position(COL_G, ROW_8), Color::Black, Type::Knight)));
    pieces.push_back(std::shared_ptr<Piece>(new Rook(Position(COL_H, ROW_8), Color::Black, Type::Rook)));
}

void setPiecesOnBoard(PtrBoard & board, VectorPiece& pieces)
{
    for (auto const & piece : pieces)
    {
        board->insertPiece(piece);
    }
}

void updatePieces(VectorPiece& pieces, PtrBoard& board)
{
    for (auto const& piece : pieces)
    {
        piece->updateMoveList(board);
    }
}

void movePiece(VectorPiece& pieces, const PtrPlayer& player)
{
    for (const auto piece : pieces)
    {
        if (piece->getPosition() == player->getSource() && piece->getColor() == player->getColor())
        {
            piece->setPosition(player->getDestination());
        }
    }

    int index = 0;
    bool erase = false;
    for (const auto piece : pieces)
    {
        if (piece->getPosition() == player->getDestination() && piece->getColor() != player->getColor())
        {
            erase = true;
            break;
        }
        index++;
    }

    if (erase)
    {
        pieces.erase(pieces.begin() + index);
    }
}
