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

	private:
		Position position;
		std::shared_ptr<Piece> piece;
};

