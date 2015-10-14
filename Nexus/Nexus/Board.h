#pragma once
#ifndef _BOARD
#define _BOARD

#include <vector>

#define BLOCK_SIZE 40
#define BOARD_WIDTH 9
#define BOARD_HEIGHT 9

struct Cell
{
	int x;
	int y;
};

struct Node: public Cell
{
	struct Node* top;
	struct Node* right;
	struct Node* bottom;
	struct Node* left;
	struct Node* root;
};

class Board
{
	int mBoard[BOARD_HEIGHT][BOARD_WIDTH];
	std::vector<Cell> freeCells;
	void goUp(Node* parent, Cell* dest);
	void goRight(Node* parent, Cell* dest);
	void goDown(Node* parent, Cell* dest);
	void goLeft(Node* parent, Cell* dest);
public:
	Board(void);
	void initBoard();
	int cellType(int, int);
	void addBall(int, int, int);
	int getNumFreeCells();
	Cell getFreeCell(int i);
	std::vector<Cell> findPath(Cell*, Cell*);
	void move(Cell& from, Cell& to);
	void draw();
	int deleteLines(int, int, int c);
};

#endif // end BOARD def
