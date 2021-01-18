#pragma once

#define WHITE_SQUARE 0xDB
#define BLACK_SQUARE 0xFF

#define CODE_PAGE 65001

enum class Color { White, Black, Empty };
enum class Type { Pawn, Knight, Bishop, Rook, Queen, King, Empty };

const int COL_A = 1;
const int COL_B = 2;
const int COL_C = 3;
const int COL_D = 4;
const int COL_E = 5;
const int COL_F = 6;
const int COL_G = 7;
const int COL_H = 8;
const int COL_Z = -1;

const int ROW_1 = 1;
const int ROW_2 = 2;
const int ROW_3 = 3;
const int ROW_4 = 4;
const int ROW_5 = 5;
const int ROW_6 = 6;
const int ROW_7 = 7;
const int ROW_8 = 8;
const int ROW_0 = -1;

struct Position
{
    int col;
    int row;

    Position()
    {
        col = COL_Z;
        row = ROW_0;
    }

    Position(int col, int row)
    {
        this->col = col;
        this->row = row;
    }

    bool operator==(const Position& other) const
    {
        return this->col == other.col && this->row == other.row;
    }

    bool operator<(const Position& other) const
    {
        return this->col < other.col || (this->col == other.col && this->row < other.row);
    }

    bool operator!=(const Position& other) const
    {
        return this->col != other.col || this->row != other.row;
    }

    bool isWithinBounds() const
    {
        return (this->col >= COL_A && this->col <= COL_H && this->row >= ROW_1 && this->row <= ROW_8) ? true : false;
    }
};
