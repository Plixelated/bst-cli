#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class Tree
{
public:
	//INORDER SORTING METHOD
	void LNR(Node* r);
	//PREORDER SORTING METHOD
	void NLR(Node* r);
	//POSTORDER SORTING METHOD
	void LRN(Node* r);
	//ADDS USER INPUT
	void SortInput(Node* r, int num);
	//DELETES NUMBER FROM TREE
	void Delete(Node*& r, int num);
	//GET LOWEST VALUE IN TREE
	Node* GetMinimumValue(Node* curr);
	//SEARCHES TREE FOR SPECIFIC NUMBER
	void SearchNum(Node*& curr, int num, Node*& parent);
	//VERIFIES VALUES
	void VerifyValue(Node*& r);
};