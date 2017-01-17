/*
CS 340 - Assignment 1
AVLTree.cpp

Purpose: This is where the functions for the AVLTree class are defined.

@author Patrick Ullrich, Austin McPhail
*/

#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include <random>
#include <iostream>
#include "AVLTree.h"

using namespace std;

// Default Constructor.
AVLTree::AVLTree()
{
	root = NULL;
	depth_total = 0;
}

// Destructor.
AVLTree::~AVLTree()
{
	destroy();
}

// Utility Method to get Node Balance
int AVLTree::getBalanceFactor(Node *leaf) 
{
	if (leaf == NULL) {
		return 0;
	}

	return (leaf->left != NULL ? leaf->left->height : 0) - (leaf->right != NULL ? leaf->right->height : 0);
}

Node* AVLTree::leftRotate(Node *grandChild) 
{
	// Where parent is the first unbalanced node
	Node *child = grandChild->right;
	Node *subTreeGrandChild = child->left;

	// Rotation
	child->left = grandChild;
	grandChild->right = subTreeGrandChild;

	// Update heights
	grandChild->height = calculateNewHeight(grandChild->left, grandChild->right);
	child->height = calculateNewHeight(child->left, child->right);

	return child;
}

Node* AVLTree::rightRotate(Node *child)
{
	// Where parent is the first unbalanced node
	Node *grandChild = child->left;
	Node *subTreeGrandChild = grandChild->right;

	// Rotation
	grandChild->right = child;
	child->left = subTreeGrandChild;

	// Update heights
	child->height = calculateNewHeight(child->left, child->right);
	grandChild->height = calculateNewHeight(grandChild->left, grandChild->right);

	return grandChild;
}

int AVLTree::calculateNewHeight(Node *left, Node *right)
{
	// 1 + max height between left / right
	if (left == NULL && right != NULL) {
		return 1 + right->height;
	}
	else if (left != NULL && right == NULL) {
		return 1 + left->height;
	}
	else if (left != NULL && right != NULL) {
		return 1 + ((left->height > right->height) ? left->height : right->height);
	}
	else {
		return 1;
	}
}


// Inserts a value into the tree based on its key_value. If the key_value of a node
//is less than its parent, it will be placed on the left. If it is greater, it will be placed on the right.
void AVLTree::insert(int key, Node *leaf)
{
	if (key < leaf->key_value) // if less, then go left
	{
		if (leaf->left != NULL) {
			depth_total++;
			insert(key, leaf->left);
		}
		else {
			leaf->left = new Node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->key_value) // if greater, then go right
	{
		if (leaf->right != NULL) {
			depth_total++;
			insert(key, leaf->right);
		}
		else {
			leaf->right = new Node;
			leaf->right->key_value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

	leaf->height = calculateNewHeight(leaf->left, leaf->right);

	int balanceFactor = getBalanceFactor(leaf);
	
	if (balanceFactor > 1) {

		if (leaf->left != NULL) {
			// Left - Right - Case
			if (key > leaf->left->key_value) {
				depth_total--;
				leaf->left = leftRotate(leaf->left);
				rightRotate(leaf);
			}

			// Left - Left - Case
			if (key < leaf->left->key_value) {
				depth_total--;
				rightRotate(leaf);
			}
		}
	}

	if (balanceFactor < -1) {
		
		if (leaf->right != NULL) {
			// Right - Left - Case
			if (key < leaf->right->key_value) {
				depth_total--;
				leaf->right = rightRotate(leaf->right);
				leftRotate(leaf);
			}

			// Right - Right - Case
			if (key > leaf->right->key_value) {
				depth_total--;
				leftRotate(leaf);
			}
		}
	}

}

// If there is no root, this insert creates the root with value "key". Else, it calls the other insert.
void AVLTree::insert(int key)
{
	if (root != NULL) {
		depth_total++;
		insert(key, root);
	}
	else {
		root = new Node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}