#pragma once
#ifndef _GAME
#define _GAME

#include "Board.h"

class Game
{
	Board *pBoard;
	int totalScore;
	bool gameStarted;
	Cell *selectedCell;
	std::vector<Cell> path;
public:
	Game(void);
	void start();
	void draw(bool selected = false);
	void nextMove();
	void selectOrMove(int, int);
	inline int getScore() { return totalScore; }
	inline bool isGameStarted(){ return gameStarted; }
	~Game(void);
};

#endif
