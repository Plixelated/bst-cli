#include "Tree.h"
#include "Node.h"
#include <iostream>
using namespace std;

//INORDER SORTING METHOD
void Tree::LNR(Node* r)
{
	VerifyValue(r);
	//LEFT
	//If left is not null, move left
	if (r->left != nullptr)
		LNR(r->left);
	//NODE
	//Prints nodes numerical value
	cout << r->num << " ";
	//RIGHT
		//If right is not null, move right
	if (r->right != nullptr)
		LNR(r->right);
};
//PREORDER SORTING METHOD
void Tree::NLR(Node* r)
{
	VerifyValue(r);
	//NODE
	//Prints nodes numerical value
	cout << r->num << " ";
	//LEFT
	//If left is not null, move left
	if (r->left != nullptr)
		NLR(r->left);
	//RIGHT
		//If right is not null, move right
	if (r->right != nullptr)
		NLR(r->right);
};
//POSTORDER SORTING METHOD
void Tree::LRN(Node* r)
{
	VerifyValue(r);
	//LEFT
	//If left is not null, move left
	if (r->left != nullptr)
		LRN(r->left);
	//RIGHT
		//If right is not null, move right
	if (r->right != nullptr)
		LRN(r->right);
	//NODE
	//Prints nodes numerical value
	cout << r->num << " ";
};
//ADDS USER INPUT
void Tree::SortInput(Node* r, int num)
{
	//LEFT
	if (num < r->num)
	{
		//If left node is not null, compare value to next node
		if (r->left != nullptr)
			SortInput(r->left, num);
		else
		{
			//Create New Temporary node
			Node* p = new Node();
			//Set its number value
			p->num = num;
			//Link it from parent
			r->left = p;
		}
	}
	else if (num > r->num) 	//RIGHT
	{
		//If right node is not null, compare value to next node
		if (r->right != nullptr)
			SortInput(r->right, num);
		else
		{
			//Create New Temporary node
			Node* p = new Node();
			//Set its number value
			p->num = num;
			//Link it from parent
			r->right = p;
		}
	}
}
//DELETES NUMBER FROM TREE
void Tree::Delete(Node*& r, int num)
{
	//Creates a parent node
	Node* parent = nullptr;
	//Creates a current node
	Node* curr = r;
	//Searches for specific number and sets our parent and current node values
	SearchNum(curr, num, parent);
	//If current is null
	if (curr == nullptr)
	{
		return;
	}
	//If there are no children node
	if (curr->left == nullptr && curr->right == nullptr)
	{
		//And current isn't set to the root
		if (curr != r)
		{
			//if the left node is the current selection
			if (parent->left == curr)
			{
				//Nullifies left pointer
				parent->left == nullptr;
			}
			else //Otherwise, nullify right pointer
				parent->right = nullptr;
		}
		else //If node is root, set it to null
			r = nullptr;
		//Delete current node
		delete(curr);
	}
	else if (curr->left && curr->right) //If there is two children
	{
		//Find the lowest valume
		Node* successor = GetMinimumValue(curr->right);
		//Store the lowest calue
		int val = successor->num;
		//Recursively Delete Selector
		Delete(r, successor->num);
		//Copy value to current node
		curr->num = val;
	}
	else //If there is only 1 child
	{
		//Created child node
		Node* child = nullptr;
		//If current node has a left child
		if (curr->left)
			child = curr->left; //Set child to left
		else
			child = curr->right; //otherwise, set child to right
		//If current isn't the root
		if (curr != r)
		{
			//current is the left node of parent
			if (curr == parent->left) {
				parent->left = child; //Link parent left node to child
			}
			else {
				parent->right = child; //Link parent right node to child
			}
		}

		//If node is the root, set root to child
		else {
			r = child;
		}
		//Delete current node
		delete(curr);
	}

	
}
//GET LOWEST VALUE IN TREE
Node* Tree::GetMinimumValue(Node* curr)
{
	//While current left point is not null
	while (curr->left != nullptr) {
		curr = curr->left; //Move left
	}
	return curr;
}
//SEARCHES TREE FOR SPECIFIC NUMBER
void Tree::SearchNum(Node*& curr, int num, Node*& parent)
{
	//If current node is not null, and the current value doesn't match searched value
	while (curr != nullptr && curr->num  != num)
	{
		//Move Parent Node to current node
		parent = curr;

		//If value is less than current node
		if (num < curr->num) {
			curr = curr->left; //Go to the left
		}
		else {
			curr = curr->right; //Otherwise, go to the right
		}
	}
}
//VERIFIES VALUES
void Tree::VerifyValue(Node*& r)
{
	//If left pointer is not null
	if (r->left != nullptr)
	{
		//And left pointers value is an invalid value
		if (r->left->num < 0)
		{
			//Set value to 0
			r->left->num = 0;
			//Set left pointer to null
			r->left = nullptr;
		}
	} 
	else if  (r->right != nullptr) //If right pointer is not null
	{
		//And right pointers value is an invalid value
		if (r->right->num < 0)
		{
			//Set value to 0
			r->right->num = 0;
			//Set Right Pointer to null
			r->right = nullptr;
		}
	}
}
