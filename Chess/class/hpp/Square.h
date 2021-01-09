#pragma once

#include "../../include/const.h"
#include "Piece.h"
#include <memory>

class Square
{
	public:
		Square(Position);
		bool isEmpty() const;
		void insertPiece(const std::shared_ptr<Piece> &);
		void displaySquare(const int &, const int &);
		void setCursor(const int&, const int&);

	private:
		Position position;
		std::shared_ptr<Piece> piece;
};

