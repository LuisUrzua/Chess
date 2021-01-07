#pragma once

#define SQUARES	64
#define NUM_PIECES  16
#define ROWS    8

enum class Color { White, Black };
enum class Type { Pawn, Knight, Bishop, Rook, Queen, King };

const int ROW_1 = 1;
const int ROW_2 = 2;
const int ROW_3 = 3;
const int ROW_4 = 4;
const int ROW_5 = 5;
const int ROW_6 = 6;
const int ROW_7 = 7;
const int ROW_8 = 8;
const int ROW_0 = -1;

const int COL_A = 1;
const int COL_B = 2;
const int COL_C = 3;
const int COL_D = 4;
const int COL_E = 5;
const int COL_F = 6;
const int COL_G = 7;
const int COL_H = 8;
const int COL_Z = -1;

struct Position
{
    int row;
    int col;

    Position()
    {
        row = ROW_0;
        col = COL_Z;
    }

    Position(int row, int col)
    {
        this->row = row;
        this->col = col;
    }

    bool operator==(const Position& other) const
    {
        return this->row == other.row && this->col == other.col;
    }

    bool operator<(const Position& other) const
    {
        return this->row < other.row || (this->row == other.row && this->col < other.col);
    }
};
