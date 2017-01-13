/*
CS 340 - Assignment 1
Tree.cpp

Purpose: The base class for the different types of Trees.

@author Patrick Ullrich, Austin McPhail
*/
#pragma once

#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include <random>
#include <iostream>
#include "Node.h"

using namespace std;

class Tree {
protected:
	Node *root;
	double depth_total;

	void destroy(Node *leaf);

public:
	void destroy();
	double getDepthTotal();
	virtual void insert() = 0;

};
