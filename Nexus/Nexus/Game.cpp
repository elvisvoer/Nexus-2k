#include "StdAfx.h"
#include "Game.h"
#include "Drawer.h"

Game::Game(void)
{
	pBoard = new Board();
	totalScore = 0;
	gameStarted = false;
	selectedCell = 0;
}

void Game::start()
{
	pBoard->initBoard();
	totalScore = 0;
	selectedCell = 0;
	gameStarted = true;
}

void Game::selectOrMove(int x, int y)
{
	// select
	if(pBoard->cellType(x, y) != 0)
	{
		if(selectedCell == 0)
		{
			selectedCell = new Cell();
		}
		selectedCell->x = x;
		selectedCell->y = y;
	}
	// nothing selected
	else if(!selectedCell)
	{
		return;
	}
	//move
	else
	{
		Cell* dest = new Cell();
		dest->x = x;
		dest->y = y;
		path = pBoard->findPath(selectedCell, dest);
		delete dest;
		dest = 0;
		delete selectedCell;
		selectedCell = 0;
	}
}

void Game::nextMove()
{
	System::Random^ random = gcnew System::Random((int)System::DateTime::Now.Ticks & 0x0000FFFF);

	for(int i = 0; i < 3 && pBoard->getNumFreeCells() > 0; i++)
	{	
		int c = random->Next(6) + 1;
		//int c = 1;
		int pos = random->Next(pBoard->getNumFreeCells());
		Cell freeCell = pBoard->getFreeCell(pos);
		pBoard->addBall(freeCell.x, freeCell.y, c);
		totalScore += 5 * pBoard->deleteLines(freeCell.x, freeCell.y, c);
	}
}

void Game::draw(bool selected)
{
	if(path.size() > 1)
	{
		Cell from = path.back();
		path.pop_back();
		Cell to = path.back();
		pBoard->move(from, to);
	}
	pBoard->draw();
	if(selected && selectedCell != 0)
	{
		Drawer::draw(*selectedCell);
	}
}

Game::~Game(void)
{
	delete pBoard;
	pBoard = 0;
}
