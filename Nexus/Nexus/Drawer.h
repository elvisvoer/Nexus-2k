#pragma once
#ifndef _DRAWER
#define _DRAWER
#include "Board.h"

using namespace System::Drawing;

ref class Drawer
{
	static TextureBrush^ brush;
	static Graphics^ formGraphics;
public:
	static void init(Graphics^);
	static void draw(Board&);
};

#endif
