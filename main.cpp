
/*
Name:					Stefani Moore
Last Date Modified:		10-24-2016
Course:					CSCI 2421 - Data Structures
Assignment:				HW8
Description:			Implement a binary search tree.  Specifically, you will implement a printPreorder,
						printInorder, printPostorder, and findNode member functions.

Status:					Compiles and runs via Microsoft Visual Studios Community 2015 and the csegrid.

						**Meets all requirements as understood by the student**

*/

#include "BSTree.h"

int main()
{
	BSTree* tree = new BSTree;

	//Add elements to the binary search tree
	cout << "Adding 300\n";
	tree->addNode(300);
	cout << "Adding 100\n";
	tree->addNode(100);
	cout << "Adding 200\n";
	tree->addNode(200);
	cout << "Adding 400\n";
	tree->addNode(400);
	cout << endl;

	//Preorder print
	cout << "Preorder print: \n";
	tree->printPreorder(tree->Root());
	cout << endl;

	//Inorder print
	cout << "\nInorder print: \n";
	tree->printInorder(tree->Root());
	cout << endl;

	//Postorder print
	cout << "\nPostorder print: \n";
	tree->printPostorder(tree->Root());
	cout << endl << endl;
	
	//Allocate memory for a new Node
	Node* temp = new Node; 

	int key = 500; //Key element used for member functions

	//Use temp node pointer for return node from the member function
	//if temp == nullptr, node not found; else found
	temp = tree->findNode(key, tree->Root());
	cout << "Node " << key;
	if (temp == nullptr)
		cout << " not found.\n";
	else
		cout << " found.\n";

	key = 600;
	temp = tree->findNode(key, tree->Root());
	cout << "Node " << key;
	if (temp == nullptr)
		cout << " not found.\n";
	else
		cout << " found.\n";

	key = 300;
	temp = tree->findNode(key, tree->Root());
	cout << "Node " << key;
	if (temp == nullptr)
		cout << " not found.\n";
	else
		cout << " found.\n";

	cout << endl;

	temp = tree->min(tree->Root()); //Find minimum 
	cout << "Min = " << temp->Key() << endl; //Use temp node to display current Key, which is the minimum node
	temp = tree->max(tree->Root()); //Find maximum
	cout << "Max = " << temp->Key() << endl; //Use temp node to display current Key, which is the maximum node

	temp = tree->successor(key, tree->Root()); //Find successor
	if (temp != nullptr) //if temp is not nullptr, then a successor was found
		cout << "\nSuccessor to " << key << " = " << temp->Key() << endl; //Display successor node
	else
		cout << "No successor to " << key << endl; //If pointer is nullptr, then no successor exists

	temp = tree->predecessor(key, tree->Root()); //Find predecessor
	if (temp != nullptr) //if temp is not nullptr, then a predecessor was found
		cout << "Predecessor to " << key << " = " << temp->Key() << endl; //Display predecessor
	else
		cout << "No predecessor to " << key << endl; //If pointer is nullptr, then no predecessor exists

	//Delete a node from the tree
	cout << "\nDeleting 300\n";
	tree->deleteNode(tree->Root(), key);

	//Print preorder after deleting node 300
	cout << "\nPreorder print: \n";
	tree->printPreorder(tree->Root());
	cout << endl;

	//Print postorder after deleting node 300
	cout << "\nPostorder print: \n";
	tree->printPostorder(tree->Root());
	cout << endl;

	//Delete tree pointer
	cout << "\nDeleting entire tree pointer\n";
	delete tree;


	cin.get(); //Pause the program
	return  0;
}