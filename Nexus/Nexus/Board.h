#pragma once
#ifndef _BOARD
#define _BOARD

#define BOARD_WIDTH 9
#define BOARD_HEIGHT 9

class Board
{
	int mBoard[BOARD_HEIGHT][BOARD_WIDTH];
public:
	Board();
	void initBoard();
	void draw();
	~Board();
};

#endif
