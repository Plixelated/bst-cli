#include "Display.h"
#include "Tree.h"
#include "Node.h"
#include "UserInterface.h"
#include <string>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;
//DEFAULT CONSTRUCTOR
Display::Display()
{
	//Initialized Values
	x = 32;
	y = 1;
	selectedSort = 0;
	sortMethod = "LNR";
}
//DISPLAYS USER MENU
void Display::DisplayMenu()
{	
	ui.goToXY(15, 0);
	ui.displayButton(192, "F1");
	ui.displayButton(12, "LOAD FILE");
	ui.displayButton(192, "F2");
	ui.displayButton(12, "ADD NUMBER");
	ui.displayButton(192, "F3");
	ui.displayButton(12, "REMOVE NUMBER");
	ui.displayButton(192, "F4");
	ui.displayButton(12, "SORT STYLE: " + sortMethod);
	ui.displayButton(192, "ESC");
	ui.displayButton(12, "DISPLAY TREE");
	cout << endl;
}
//DISPLAYS BINARY SEARCH TREE
void Display::DisplayTree(Node* r, int xpos, int ypos, int width)
{
	//Remove Cursor
	ui.ShowConsoleCursor(false);
	//If root is null, exit
	if (r == nullptr)
		return;
	//Go to x and y positions
	ui.goToXY(xpos, ypos);
	//If the value has children
	if (r->left != nullptr || r->right != nullptr)
		ui.setTextColor(111); //Set color to brown
	else
		ui.setTextColor(175); //If value is a leaf, set to green
	//Print out numerical value
	cout << r->num;
	//Pause for animation
	Sleep(500);
	//Draws Branches
	DisplayBranch(r, xpos, ypos);
	//Reduces width by half
	width = width / 2;
	//Keeps numbers from overlapping
	if (width < 2)
		width = 2;
	//Recursively draws the next value
	DisplayTree(r->right, xpos + width, ypos - 2, width);
	DisplayTree(r->left, xpos - width, ypos - 2, width);
}
//DRAWS BRANCHES
void Display::DisplayBranch(Node* r, int xpos, int ypos)
{
	//Sets Text Color
	ui.setTextColor(6);
	//Goes to xy position
	ui.goToXY(xpos + 2, ypos - 1);
	//If value is on the right, print right branch
	if (r->right != nullptr)
		cout << "/";
	ui.goToXY(xpos - 2, ypos - 1);
	//If value is on the left, print left branch
	if (r->left != nullptr)
		cout << "\\";
}
//DIPLAYS VALUES IN CURRENT SORT ORDER
void Display::DisplaySort(Sorting sort)
{
	//Sets xy positions
	int xStart = 35;
	int ypos = 29;
	//Clears Screen
	system("cls");
	//Displays menu
	DisplayMenu();
	//Sets Text Color
	ui.setTextColor(14);
	//Switch statment using Enums for sort order
	//Displays value according to current sort order
	switch (sort)
	{
	case LNR:
		ui.goToXY(xStart, ypos);
		cout << "INORDER: ";
		t.LNR(root);
		break;
	case NLR:
		ui.goToXY(xStart, ypos);
		cout << "PREORDER: ";
		t.NLR(root);
		break;
	case LRN:
		ui.goToXY(xStart, ypos);
		cout << "POSTORER: ";
		t.LRN(root);
		break;
	default:
		break;
	}
}
//CHANGES CURRENT SORT METHOD
void Display::ChangeSort(Sorting sort, string display)
{
	//Sets current sort method enum
	currentSort = sort;
	//Sets current sort method string
	sortMethod = display;
	//Clears Screen
	system("cls");
	//Displays Menu
	DisplayMenu();
	//If there is currently a tree
	if (root != nullptr)
	{
		//Display sort and tree
		DisplaySort(currentSort);
		DisplayTree(root, 50, 27, 20);
	}
	//Resets text color
	ui.resetTextColor();
}
//SETS SORT METHOD MENU TEXT
void Display::SetSortMethod(int sort)
{
	//Switch statement that sets sort method text in menu
	switch (sort)
	{
	case 0:
		ChangeSort(LNR, "LNR");
		break;
	case 1:
		ChangeSort(NLR, "NLR");
		break;
	case 2:
		ChangeSort(LRN, "LRN");
		break;
	default:
		break;
	}
}
//CAPTURES INPUT FROM USER
int Display::CaptureInput()
{
	char c;
	int input = 0;
	string str;

	while (1)
	{
		ui.goToXY(15, y);
		cout << "Please Select an Option: ";

		c = _getch();
		cout << c;

		if (c == 0)
		{
			c = _getch();

			if (c == 59) //F1 Load File
			{
				LoadFile();
				break;
			}
			else if (c == 60) //F2 Add Value
			{
				CaptureNumInput();
				break;
			}
			else if (c == 61) //F3 Delete Value
			{
				DeleteNumber();
				break;
			}
			else if (c == 62) //F4 Toggles Sort Methods
			{
				//Changes Sort Method
				if (selectedSort < 2)
				{
					SetSortMethod(++selectedSort);
				}
				else //Returns to default sort method
				{
					selectedSort = 0;
					SetSortMethod(selectedSort);
				}
			}
		}
		else if (c == 27) //Displays Tree 
			break;
	}

	return input;
}
//GETS INTEGER VALUES FROM USER
int Display::CaptureNumInput()
{
	//x position
	int xStart= 40;
	//Go to xy position
	ui.goToXY(15, y);
	//Clear Screen
	system("cls");
	//Display Menu
	DisplayMenu();
	//Go To Next Line
	ui.goToXY(x, ++y);
	int num = 0;
	//Goes to next line and xStart position
	ui.goToXY(xStart, ++y);
	//Sets Text Color
	ui.setTextColor(9);
	//User Prompt
	cout << "How many numbers would you like to add?" << endl;
	//How many numbers the user wants to add
	int amt = 0;
	//Go to next line
	ui.goToXY(xStart, ++y);
	//Gets amount from user
	cin >> amt;
	//Go to Next Line
	ui.goToXY(xStart, ++y);
	//If select amount is less than the maxInput
	if (amt <= maxInput)
	{
		//User Prompt
		cout << "Please Enter Up To " << amt << " Numbers" << endl;
		ui.goToXY(xStart, ++y);
		//Sets Padding
		int padding = xStart;

		int i = 0;
		//Gets Integer value from user, and adds it to the tree
		do
		{
			cin >> num;
			padding += to_string(num).length() + 1;
			ui.goToXY(padding, y);

			if (root == nullptr)
			{
				root = new Node();
			}
			if (root->num == 0)
			{
				root->num = num;
			}
			else
			t.SortInput(root, num);

			i++;

		} while (i < amt);

	}
	else if (amt > maxInput) //If amout is greater than the max input
	{
		//Notify user of error
		cout << "The Max input is " << maxInput << " Numbers please try again" << endl;
		Sleep(500);
		//Reloads Number Caputre
		CaptureNumInput();
	}
	return num;
}
//DELETES VALUE FROM TREE
void Display::DeleteNumber()
{
	ui.goToXY(15, y);
	//If a tree exists
	if (root != nullptr)
	{
		//User Prompt
		cout << "Please enter the number you would like to remove: ";
		int num;
		//Get number user wnats to remove
		cin >> num;
		//Deletes Value
		t.Delete(root, num);
	}
	else
	{
		//Otherwise, inform User a tree must exist
		cout << "ERROR: The tree cannot be empty, please add a value first";
		Sleep(750);
		system("CLS");
	}
}
//LOADS VALUES FROM FILE
void Display::LoadFile()
{
	system("CLS");
	DisplayMenu();

	int xStart = 36;

	//Asks for file location
	string location;
	ui.x--;
	ui.goToXY(15, 1);
	cout << "ENTER FILE LOCATION: " << endl;

	ui.goToXY(xStart, 1);
	cin >> location;

	//Sets file to Input
	ifstream inFile(location);
	ui.goToXY(ui.x, ++ui.y);
	cout << "Loading File..." << endl;
	int input = 0;

	root = new Node();

	//Adds Values in file to tree
	while (inFile.peek() != -1)
	{
		inFile >> input;
		//If first value
		if (root->num == 0)
			root->num = input; //set root value
		else if (input != -1) //Otherwise, if not at -1, keep adding values
			t.SortInput(root, input);
	}
	//Close File
	inFile.close();
}
//RUNS PROGRAM
void Display::Run()
{
	//Shows Console Cursor
	ui.ShowConsoleCursor(true);
	//Displays menu
	DisplayMenu();
	//Caputers User Input
	CaptureInput();
	//Go to xy position
	ui.goToXY(30, y++);
	//If a tree exists, display it
	if (root != nullptr)
	{
		DisplaySort(currentSort);
		DisplayTree(root, 50, 27, 20);
	}
	//Resets y value
	y = 1;
	//Runs Program Again
	Run();
}