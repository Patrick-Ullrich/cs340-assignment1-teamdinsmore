#pragma once

#include <stdio.h>
/*
CS 340 - Assignment 1
BinarySearchTree.cpp

Purpose: This is where the functions for the AVLTree class are defined.

@author Patrick Ullrich, Austin McPhail
*/

#include <stdlib.h>  
#include <time.h>
#include <random>
#include <iostream>
#include "Node.h"
#include "Tree.h"

using namespace std;

class AVLTree : public Tree
{
public:
	AVLTree();
	~AVLTree();

	void insert(int key);

private:
	void insert(int key, Node *leaf);
	int getBalanceFactor(Node *leaf);
	Node* leftRotate(Node *leaf);
	Node* rightRotate(Node *leaf);
	int calculateNewHeight(Node *left, Node *right);
};
