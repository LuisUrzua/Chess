#pragma once

#include "../../include/const.h"
#include <memory>

class Piece;

typedef std::shared_ptr<Piece> PtrPiece;

class Square
{
	public:
		Square(Position);
		bool isEmpty() const;
		void insertPiece(const PtrPiece &);
		PtrPiece getPiece() const;
		void removePiece();
		void displaySquare(const int &, const int &);
		void setCursor(const int&, const int&);
		void attackSquare(const Color);
		void resetAttackers();
		bool isSafe(Color);

	private:
		Position position;
		PtrPiece piece;
		int whiteAttackers;
		int blackAttackers;
};

