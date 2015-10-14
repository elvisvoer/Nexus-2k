#pragma once
#ifndef _DRAWER
#define _DRAWER

#include "Board.h"

using namespace System::Drawing;


ref class Drawer
{
	static array<Bitmap^>^ ball = { 
		(Bitmap^)Image::FromFile( "img\\free.png", true ),
		(Bitmap^)Image::FromFile( "img\\blue.png", true ),
		(Bitmap^)Image::FromFile( "img\\red.png", true ),
		(Bitmap^)Image::FromFile( "img\\green.png", true ),
		(Bitmap^)Image::FromFile( "img\\yellow.png", true ),
		(Bitmap^)Image::FromFile( "img\\purple.png", true ),
		(Bitmap^)Image::FromFile( "img\\bleau.png", true ),
		(Bitmap^)Image::FromFile( "img\\selected.png", true )
	};
	static Pen^ border = gcnew Pen(Color::White);
	static Pen^ outline = gcnew Pen(Color::Black);
	
public:
	static Graphics^ formGraphics;
	static void init(Graphics^ f);
	static void draw(Board&);
	static void draw(Cell&);
};

#endif
