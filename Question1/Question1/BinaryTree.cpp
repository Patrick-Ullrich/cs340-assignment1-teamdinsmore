/*
CS 340 - Assignment 1
BinaryTree.cpp

Purpose: This is where the functions for the BinarySearchTree class are defined.

@author Patrick Ullrich, Austin McPhail
*/

#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include <random>
#include <iostream>
#include "BinaryTree.h"

using namespace std;

// Default Constructor.
BinaryTree::BinaryTree()
{
	root = NULL;
	depth_total = 0;
}

// Destructor.
BinaryTree::~BinaryTree()
{
	destroy();
}

// Inserts a value into the tree based on its key_value. If the key_value of a node
//is less than its parent, it will be placed on the left. If it is greater, it will be placed on the right.
void BinaryTree::insert(int key, int bin, Node *leaf)
{
	if (bin == 0) // if bin == 0, then go left
	{
		if (leaf->left != NULL) {
			depth_total++;
			insert(key, bin, leaf->left);
		}
		else {
			leaf->left = new Node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (bin == 1) // if bin == 1, then go right
	{
		if (leaf->right != NULL) {
			depth_total++;
			insert(key, bin, leaf->right);
		}
		else {
			leaf->right = new Node;
			leaf->right->key_value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}
}

// If there is no root, this insert creates the root with value "key". Else, it calls the other insert.
void BinaryTree::insert(int key, int bin)
{
	if (root != NULL) {
		depth_total++;
		insert(key, bin, root);
	}
	else {
		root = new Node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}