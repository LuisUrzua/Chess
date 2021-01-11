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
		void insertPiece(const std::shared_ptr<Piece> &);
		void removePiece();
		void displaySquare(const int &, const int &);
		void setCursor(const int&, const int&);

	private:
		Position position;
		PtrPiece piece;
};

