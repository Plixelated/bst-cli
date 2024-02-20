#include <iostream>
#include <string>
#include <Windows.h>
#include <Time.h>
#include <conio.h>
#include "UserInterface.h"
using namespace std;
//USER INTERFACE CLASS

//DEFAULT CONSTRUCTOR
UserInterface::UserInterface()
{
	//Initializes Variables and Sets System Color
	x = y = 0;
	srand(time(NULL));
	system("color 0F");
	defaultColor = 12;
}
//GO TO XY COORDINATES
void UserInterface::goToXY(int x, int y)
{
	if (x >= 0 && y >= 0) {
		COORD kursor;
		kursor.X = x;
		kursor.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), kursor);
	}
}
//SETS CONSOLE CURSOR
void UserInterface::ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	//sets the cursors visiblity by assigning it to function's assigned boolean variable
	SetConsoleCursorInfo(out, &cursorInfo);
}
//SETS TEXT TO RANDOM COLOR
void UserInterface::randomTextColor(int range, int start)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int color;
	color = rand() % range + start;
	SetConsoleTextAttribute(hConsole, color);
}
//SETS TEXT TO SPECIFIC COLOR
void UserInterface::setTextColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
//RESETS TEXT COLOR TO DEFAULT
void UserInterface::resetTextColor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, defaultColor);
}
//DRAWS A BOX USING SPECIAL ASCII CHARACTERS
void UserInterface::drawBox(int width, int height, int widthPosition, int heightPosition)
{

	int i;
	int widthPositionTop = widthPosition;
	int heightPositionFixed = heightPosition;
	int widthPositionFixed = widthPosition;


	//TOP
	for (int i = 0; i < width + 1; i++)
	{
		goToXY(widthPositionTop, heightPositionFixed - 1);
		cout << char(219);
		widthPositionTop++;
	}

	//MIDDLE

	for (int i = 0; i < height; i++)
	{
		goToXY(widthPositionFixed, heightPosition);
		cout << char(219);
		for (int j = 0; j < width - 1; j++)
			cout << " ";
		cout << char(219);
		heightPosition++;
	}

	//BOTTOM

	for (int i = 0; i < width; i++)
	{
		goToXY(widthPosition, height + (heightPositionFixed - 1));
		cout << char(219);
		widthPosition++;
	}
}
//DRAWS A DIVIDER
void UserInterface::drawDivider(int x, int y)
{
	for (int i = 0; i < 39; i++)
	{

		goToXY(x, y);
		cout << char(196);
		x++;
	}
}
//DRAWS A VERTICAL DRIVER
void UserInterface::drawVerticalDivider(int x, int y)
{
	for (int i = 0; i < 10; i++)
	{

		goToXY(x, y);
		cout << char(179);
		y++;
	}
}
//INSERTS PADDING
void UserInterface::padding(int x)
{
	for (int i = 0; i < x; i++)
		cout << " ";
}
//AUTO ADJUSTS PADDING
void UserInterface::paddingAdjust(string value, int y)
{
	int x = y - value.length();
	padding(x);
}
//DISPLAYS TEXT BUTTON GRAPHIC
void UserInterface::displayButton(int color, string text)
{
	setTextColor(color);
	cout << "|" << text << "|";
}
//CHECKS FOR CHAR VALUE
void UserInterface::CheckChar()
{
	while (1)
	{
		char c = 0;
		c = _getch();

		cout << int(c);

	}
}
