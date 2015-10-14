#include "StdAfx.h"
#include "Drawer.h"

using System::Drawing::Drawing2D::WrapMode;

void Drawer::init(Graphics^ f)
{
	formGraphics = f;
}

void Drawer::draw(Board& b)
{
	for(int i = 0; i < BOARD_HEIGHT; i++)
	{
		for(int j = 0; j < BOARD_WIDTH; j++)
		{
			
			TextureBrush^ texture = gcnew TextureBrush( ball[b.cellType(i, j)], WrapMode::Tile );
			formGraphics->FillRectangle(texture, Rectangle( j * BLOCK_SIZE, i * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE));
			formGraphics->DrawRectangle(border, Rectangle( j * BLOCK_SIZE, i * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE));
			delete texture;
		}
	}
	formGraphics->DrawRectangle(outline, Rectangle(0, 0, BLOCK_SIZE * BOARD_HEIGHT - 1, BLOCK_SIZE * BOARD_WIDTH - 1));
}

void Drawer::draw(Cell& c)
{
	TextureBrush^ texture = gcnew TextureBrush( ball[7], WrapMode::Tile );
	formGraphics->FillRectangle(texture,  c.y * BLOCK_SIZE, c.x * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
	formGraphics->DrawRectangle(border, Rectangle( c.y * BLOCK_SIZE, c.x * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE));
	formGraphics->DrawRectangle(outline, Rectangle(0, 0, BLOCK_SIZE * BOARD_HEIGHT - 1, BLOCK_SIZE * BOARD_WIDTH - 1));
	delete texture;
}