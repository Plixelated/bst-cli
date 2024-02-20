#pragma once
#include "Tree.h"
#include "Node.h"
#include "UserInterface.h"
#include <string>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;
//Maximum Value Input
const int maxInput = 10;
//Enum for different sorting methods
enum Sorting
{
	LNR, NLR, LRN
};

class Display
{
public:
	//Variables:
	//User Interface Object
	UserInterface ui;
	//Tree Object
	Tree t;
	//Root Node
	Node* root;
	//Selected Sort Method
	int selectedSort;
	//Sort Method
	string sortMethod;
	//Current Sorting Method
	Sorting currentSort;
	//XY Positions
	int x;
	int y;

	//FUNCTIONS:
	//DEFAULT CONSTRUCTOR
	Display();
	//DISPLAYS USER MENU
	void DisplayMenu();
	//DISPLAYS BINARY SEARCH TREE
	void DisplayTree(Node* r, int xpos, int ypos, int width);
	//DRAWS BRANCHES
	void DisplayBranch(Node* r, int xpos, int ypos);
	//DIPLAYS VALUES IN CURRENT SORT ORDER
	void DisplaySort(Sorting sort);
	//CHANGES CURRENT SORT METHOD
	void ChangeSort(Sorting sort, string display);
	//SETS SORT METHOD MENU TEXT
	void SetSortMethod(int sort);
	//CAPTURES INPUT FROM USER
	int CaptureInput();
	//GETS INTEGER VALUES FROM USER
	int CaptureNumInput();
	//DELETES VALUEFROM TREE
	void DeleteNumber();
	//LOADS VALUES FROM FILE
	void LoadFile();
	//RUNS PROGRAM
	void Run();
};