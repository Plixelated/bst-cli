#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <Time.h>
using namespace std;
//USER INTERFACE HEADER
class UserInterface
{
	//Public Functions And Variables
public:
	//Default Text color
	int defaultColor;
	//XY coordinates
	int x, y;
	//DEFAULT CONSTRUCTOR
	UserInterface();
	//SETS CONSOLE CURSOR
	void ShowConsoleCursor(bool showFlag);
	//DRAWS A BOX USING SPECIAL ASCII CHARACTERS
	void drawBox(int width, int height, int widthPosition, int heightPosition);
	//GO TO XY COORDINATES
	void goToXY(int x, int y);
	//SETS TEXT TO SPECIFIC COLOR
	void setTextColor(int color);
	//SETS TEXT TO RANDOM COLOR
	void randomTextColor(int range, int start);
	//DRAWS A DIVIDER
	void drawDivider(int x, int y);
	//DRAWS A VERTICAL DRIVER
	void drawVerticalDivider(int x, int y);
	//INSERTS PADDING
	void padding(int x);
	//AUTO ADJUSTS PADDING
	void paddingAdjust(string value, int y);
	//DISPLAYS TEXT BUTTON GRAPHIC
	void displayButton(int color, string text);
	//RESETS TEXT COLOR TO DEFAULT
	void resetTextColor();
	//CHECKS FOR CHAR VALUE
	void CheckChar();
};