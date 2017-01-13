/*
CS 340 - Assignment 1
Assignment1.cpp
Purpose: <TODO>

@author Patrick Ullrich, Austin McPhail
*/
#pragma once

#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include <random>
#include <iostream>
#include "Node.h"
#include "Tree.h"

using namespace std;

class BinaryTree : public Tree
{
public:
	BinaryTree();
	~BinaryTree();
	
	void insert(int key, int bin);

private:
	void insert(int key, int bin, Node *leaf);
};
