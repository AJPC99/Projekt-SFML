#pragma once


struct Position
{
	Position() = default;
	Position(int x, int y) { this->x = x; this->y = y; }
	int x;
	int y;
};