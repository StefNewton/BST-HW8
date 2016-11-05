/*
Name:					Stefani Moore
Last Date Modified:		10-24-2016
Assignment:				HW8
*/

//*******************************************************************
//BSTree.cpp
//
//Contains BSTree class implentations 
//
//Changes made to .cpp File
// 1. Added cout statement to destructor so a statement is printed when
//	  destructor is called
// 2. Added findNode implementation
// 3. Added print preorder, inorder, and postorder function implementations
// 4. Changed return of predecessor function from nullptr to thisKey so that
//	  if a predecessor exists the node pointer will be returned. If there is
//	  no left branch exists, nullptr is still returned.
//
//*******************************************************************

#include "BSTree.h"

// Constructor
BSTree::BSTree() {
    root = nullptr;
}

// Destructor
BSTree::~BSTree() {

	cout << "Tree pointer deleted\n";
    freeNode(root);
}

// Free the node
void BSTree::freeNode(Node* leaf)
{
    if ( leaf != NULL )
    {
        freeNode(leaf->Left());
        freeNode(leaf->Right());
        free(leaf);
    }
    
}

// Add a node
void BSTree::addNode(int key)
{
    // No elements. Add the root
    if ( root == nullptr ) {
        Node* n = new Node();
        n->setKey(key);
        root = n;
    }
    else {
        addNode(key, root);
    }
}

// Add a node (private)
void BSTree::addNode(int key, Node* leaf) {
    if ( key <= leaf->Key() )
    {
        if ( leaf->Left() != nullptr )
            addNode(key, leaf->Left());
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setParent(leaf);
            leaf->setLeft(n);
        }
    }
    else
    {
        if ( leaf->Right() != nullptr )
            addNode(key, leaf->Right());
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setParent(leaf);
            leaf->setRight(n);
        }
    }
}

// Find a node
Node* BSTree::findNode(int key, Node* node)
{
	if (node != nullptr)
	{
		if (key == node->Key()) //Once key == Key() return node pointer
		{
			return node; 
		}
		if (key < node->Key()) //if key is less than Key() traverse left
		{
			return findNode(key, node->Left());
		}
		else //if key is greater than Key() traverse right
			return findNode(key, node->Right());
	}
	else
		return node; //return nullptr if tree Node is null
}

// Print the BSTree
//Print the tree from root, to left, to right sub-trees
void BSTree::printPreorder(Node* node)
{
	if (node) //print as long as node is not null
	{
		cout << node->Key() << " ";
		printPreorder(node->Left());
		printPreorder(node->Right());
	}
}

//Print the tree from left, to root, to right sub-trees
void BSTree::printInorder(Node* node)
{
	if (node) //Print as long as node is not null
	{
		printInorder(node->Left());
		cout << node->Key() << " ";
		printInorder(node->Right());
	}
}

//Print the tree from left, to right, to root sub-trees
void BSTree::printPostorder(Node* node)
{
	if (node) //Print as long as node is not null
	{
		printPostorder(node->Left());
		printPostorder(node->Right());
		cout << node->Key() << " ";
	}
}

// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
Node* BSTree::min(Node* node)
{
    Node* tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Left() )
    {
        tempNode = min(node->Left());
    }
    else
        tempNode = node;

    return tempNode;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
Node* BSTree::max(Node* node)
{
    Node * tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Right() )
        tempNode = max(node->Right());
    else
        tempNode = node;
 
    return tempNode;
}

// Find successor to a node
// Find the node, get the node with max value
// for the right sub-BSTree to get the successor
Node* BSTree::successor(int key, Node *node)
{
    Node* thisKey = findNode(key, node);
    if ( thisKey )
        return max(thisKey->Right());

        return thisKey;
}

// Find predecessor to a node
// Find the node, get the node with max value
// for the left sub-BSTree to get the predecessor
Node* BSTree::predecessor(int key, Node *node)
{
    Node* thisKey = findNode(key, node);
    if ( thisKey )
        return max(thisKey->Left());
    return thisKey; //Changed from nullptr to thisKey so that the proper value is returned
}

Node* BSTree::deleteNode(Node* root,int key)
{
    
    /* Given a binary search tree and a key, this function deletes the key
     and returns the new root */
    
    // base case
    if (root == nullptr)
        return root;
    
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->Key())
    {
        root->setLeft(deleteNode(root->Left(), key));
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->Key())
        root->setRight(deleteNode(root->Right(), key));
    
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->Left() == NULL)
        {
            Node *temp = root->Right();
            free(root);
            return temp;
        }
        else if (root->Right() == NULL)
        {
            Node *temp = root->Left();
            free(root);
            return temp;
        }
        
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node* temp = min(root->Right());
        
        // Copy the inorder successor's content to this node
        root->setKey(temp->Key());
        
        // Delete the inorder successor
        root->setRight(deleteNode(root->Right(), temp->Key()));
    }
    return root;
    
}
