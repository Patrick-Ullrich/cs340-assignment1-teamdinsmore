/*
CS 340 - Assignment 1
BinarySearchTree.cpp

Purpose: This is where the functions for the BinarySearchTree class are defined.

@author Patrick Ullrich, Austin McPhail
*/

#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include <random>
#include <iostream>
#include "Tree.h"

using namespace std;

void Tree::destroy(Node *leaf) // Recursively deletes each node in the tree, from bottom to top.
{
	if (leaf != NULL)
	{
		destroy(leaf->left);
		destroy(leaf->right);
		if (leaf->left != NULL)
			leaf->left = NULL;
		if (leaf->right != NULL)
			leaf->right = NULL;
		leaf = NULL;
		delete(leaf);
	}
	delete(leaf);
}

void Tree::destroy()
{
	destroy(root);
}

double Tree::getDepthTotal() // Returns the public class variable "depth_total".
{
	return depth_total;
}