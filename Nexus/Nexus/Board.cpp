#include "StdAfx.h"
#include "Board.h"
#include "Drawer.h"


Board::Board(void)
{
	initBoard();
}

void Board::initBoard()
{
	freeCells.clear();
	for(int i = 0; i < BOARD_HEIGHT; i++)
		for(int j = 0; j < BOARD_WIDTH; j++)
		{
			mBoard[i][j] = 0;
			Cell c = { i, j };
			freeCells.push_back(c);
		}
}

int Board::cellType(int x, int y)
{
	return mBoard[x][y];
}

void Board::addBall(int x, int y, int c)
{
	mBoard[x][y] = c;
}

int Board::getNumFreeCells()
{
	return freeCells.size();
}


Cell Board::getFreeCell(int i)
{
	Cell ret = freeCells[i];
	freeCells.erase(freeCells.begin() + i);
	return ret;
}

void Board::draw()
{
	Drawer::draw(*this);
}

int Board::deleteLines(int x, int y, int c)
{
	int total = 0;
	std::vector<Cell> balls;
	
	int count = 0;
	int px, py;
	
	// left
	py = y - 1;
	while(mBoard[x][py] == c && py >= 0 )
	{
		Cell b = { x, py };
		balls.push_back(b);
		count++;
		py--;
	}
	// right
	py = y + 1;
	while(mBoard[x][py] == c && py < BOARD_WIDTH )
	{
		Cell b = { x, py };
		balls.push_back(b);
		count++;
		py++;
	}

	if(count < 4)
	{
		balls.resize(balls.size() - count);
	}

	count = 0;
	// top
	px = x - 1;
	while(mBoard[px][y] == c && px >= 0 )
	{
		Cell b = { px, y };
		balls.push_back(b);
		count++;
		px--;
	}

	// bottom
	px = x + 1;
	while(mBoard[px][y] == c && px < BOARD_HEIGHT )
	{
		Cell b = { px, y };
		balls.push_back(b);
		count++;
		px++;
	}

	if(count < 4)
	{
		balls.resize(balls.size() - count);
	}

	count = 0;
	// top left
	px = x - 1; py = y - 1;
	while(mBoard[px][py] == c && px >= 0 && py >= 0 )
	{
		Cell b = { px, py };
		balls.push_back(b);
		count++;
		px--;
		py--;
	}

	// bottom right
	px = x + 1; py = y + 1;
	while(mBoard[px][py] == c && px < BOARD_HEIGHT && py < BOARD_WIDTH )
	{
		Cell b = { px, py };
		balls.push_back(b);
		count++;
		px++;
		py++;
	}

	if(count < 4)
	{
		balls.resize(balls.size() - count);
	}

	count = 0;
	// top right
	px = x - 1; py = y + 1;
	while(mBoard[px][py] == c && px >= 0 && py < BOARD_WIDTH )
	{
		Cell b = { px, py };
		balls.push_back(b);
		count++;
		px--;
		py++;
	}

	// bottom left
	px = x + 1; py = y - 1;
	while(mBoard[px][py] == c && px < BOARD_HEIGHT && py >= 0 )
	{
		Cell b = { px, py };
		balls.push_back(b);
		count++;
		px++;
		py--;
	}

	if(count < 4)
	{
		balls.resize(balls.size() - count);
	}

	// there is something to delete, add current ball
	if(balls.size() > 0)
	{
		Cell b = { x, y };
		balls.push_back(b);
	}

	for (unsigned int i = 0; i < balls.size(); i++)
	{
		mBoard[balls[i].x][balls[i].y] = 0;
		freeCells.push_back(balls[i]);
	}
	return balls.size();
}



bool destReached = false;
Node* done;

void Board::goUp(Node* parent, Cell* dest)
{
	
	if(parent->x - 1 < 0 || mBoard[parent->x - 1][parent->y])
	{
		parent->top = 0;
		return;
	}

	Node* top = new Node();
	top->x = parent->x - 1;
	top->y = parent->y;

	parent->top = top;
	top->bottom = parent;
	top->root = parent;

	mBoard[top->x][top->y] = 7;
	
	if(top->x == dest->x && top->y == dest->y)
	{
		done = top; 
	}

	//switch(System::Random().Next(3))
	//{
	//case 0:
	//	goUp(top, dest);
	//	break;
	//case 1:
	//	goRight(top, dest);
	//	break;
	//case 2:
	//	goLeft(top, dest);
	//	break;
	//}
	
	goUp(top, dest);
	goRight(top, dest);
	goLeft(top, dest);
}

void Board::goRight(Node* parent, Cell* dest)
{
	
	if(parent->y + 1 > 8 || mBoard[parent->x][parent->y + 1])
	{
		parent->right = 0;
		return;
	}

	Node* right = new Node();
	right->x = parent->x;
	right->y = parent->y + 1;

	parent->right = right;
	right->left = parent;
	right->root = parent;

	mBoard[right->x][right->y] = 7;
	
	if(right->x == dest->x && right->y == dest->y)
	{
		done = right; 
	}


	//switch(System::Random().Next(3))
	//{
	//case 0:
	//	goUp(right, dest);
	//	break;
	//case 1:
	//	goRight(right, dest);
	//	break;
	//case 2:
	//	goDown(right, dest);
	//	break;
	//}

	goUp(right, dest);
	goRight(right, dest);
	goDown(right, dest);
}

void Board::goDown(Node* parent, Cell* dest)
{
	
	if(parent->x + 1 > 8 || mBoard[parent->x + 1][parent->y])
	{
		parent->bottom = 0;
		return;
	}

	Node* bottom = new Node();
	bottom->x = parent->x + 1;
	bottom->y = parent->y;

	parent->bottom = bottom;
	bottom->top = parent;
	bottom->root = parent;

	mBoard[bottom->x][bottom->y] = 7;
	
	if(bottom->x == dest->x && bottom->y == dest->y)
	{
		done = bottom; 
	}

	//switch(System::Random().Next(3))
	//{
	//case 0:		
	//	goDown(bottom, dest);
	//	break;
	//case 1:
	//	goRight(bottom, dest);
	//	break;
	//case 2:
	//	goLeft(bottom, dest);
	//	break;
	//}

	goDown(bottom, dest);
	goRight(bottom, dest);
	goLeft(bottom, dest);
}

void Board::goLeft(Node* parent, Cell* dest)
{
	
	if(parent->y - 1 < 0 || mBoard[parent->x][parent->y - 1])
	{
		parent->left = 0;
		return;
	}

	Node* left = new Node();
	left->x = parent->x;
	left->y = parent->y - 1;

	parent->left = left;
	left->right = parent;
	left->root = parent;

	mBoard[left->x][left->y] = 7;
	
	if(left->x == dest->x && left->y == dest->y)
	{
		done = left; 
	}

	//switch(System::Random().Next(3))
	//{
	//case 0:		
	//	goUp(left, dest);
	//	break;
	//case 1:
	//	goDown(left, dest);
	//	break;
	//case 2:
	//	goLeft(left, dest);
	//	break;
	//}

	goUp(left, dest);
	goDown(left, dest);
	goLeft(left, dest);
}

std::vector<Cell> Board::findPath(Cell* org, Cell* dest)
{
	std::vector<Cell> path;
	destReached = false;
	Node* root = new Node();
	root->x = org->x;
	root->y = org->y;
	root->root = 0;
	done = 0;

	goUp(root, dest);
	goRight(root, dest);
	goDown(root, dest);
	goLeft(root, dest);

	Node* it = done;
	while(it)
	{
		if(it->x == org->x && it->y == org->y)
			break;
		
		Cell c;
		c.x = it->x;
		c.y = it->y;
		path.push_back(c);
		it = it->root;	
	}

	//push origin
	path.push_back(*org);

	for (unsigned int i = 0; i < freeCells.size(); i++)
	{
		//mBoard[freeCells[i].x][freeCells[i].y] = 0;
	}

	return path;
}

void Board::move(Cell& from, Cell& to)
{
	int color = mBoard[from.x][from.y];
	mBoard[from.x][from.y] = 0;
	mBoard[to.x][to.y] = color;

	for (unsigned int i = 0; i < freeCells.size(); i++)
	{
		if(freeCells[i].x == to.x && freeCells[i].y == to.y)
			freeCells.erase(freeCells.begin() + i);
	}

	freeCells.push_back(from);

}
