#include <iostream>
#include <string>
using namespace std;

class node {
public:
	string info;
	node* leftchild;
	node* rightchild;

	//Constructor for the node class
	node(string i, node* l, node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree {
public:
	node* ROOT;

	BinaryTree()
	{
		ROOT = NULL; //Initializing ROOT to NULL
	}

	void insert(string element) //Insert a node in the binary search tree
	{
		node* newnode = new node(element, NULL, NULL); //Allocate memory for the new node
		newnode->info = element; //Assign value to the data field of the new node
		newnode->leftchild = NULL; //Make the left child of the new node point to NULL
		newnode->rightchild = NULL; //Make the right child of the new node point to NULL

		node* parent = NULL;
		node* currentnode = NULL;
		search(element, parent, currentnode); //Locate the node which will be the parent of the node to be inserted

		
};
