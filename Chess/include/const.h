#pragma once

#define SQUARES	64

enum Color { White, Black };
enum Col { _A, _B, _C, _D, _E, _F, _G, _H };
enum Row { _1, _2, _3, _4, _5, _6, _7, _8 };
enum Type { Pawn, Knight, Bishop, Rook, Queen, King };

typedef struct _Position
{
	int col = -1;
	int row = -1;
} Position;
