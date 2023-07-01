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

		if (parent == NULL) //if the parent is NULL (tree is empty)
		{
			ROOT = newnode; // Mark the new node as ROOT
			return; //exit
		}

		if (element < parent->info)  //if the value in the data field of the new node is less than that of the paren
		{
			parent->leftchild = newnode; //Make the left child of the parent point to the new node
		}
		else if (element > parent->info) // If the value in the data field of the new node is greater than that of the parent
		{
			parent->rightchild = newnode; //Make the right child of the parent point to the new node
		}
	}
	void search(string element, node*& parent, node*& currentnode)
	{
		//This function searches the currentNode of the speciefed Node as well the current Node of its parent
		currentnode = ROOT;
		parent = NULL;
		while ((currentnode != NULL) && (currentnode->info != element))
		{
			parent = currentnode;
			if (element < currentnode->info)
				currentnode = currentnode->leftchild;
			else
				currentnode = currentnode->rightchild;
		}
	}

	void inorder(node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}
};





