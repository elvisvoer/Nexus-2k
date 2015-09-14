#include "StdAfx.h"
#include "Board.h"
#include "Drawer.h"

Board::Board()
{
	initBoard();
}

void Board::initBoard()
{
	for(int i = 0; i < BOARD_HEIGHT; i++)
		for(int j = 0; j < BOARD_WIDTH; j++)
			mBoard[i][j] = 0;
}

void Board::draw()
{
	Drawer::draw(*this);
}

Board::~Board()
{
}
