/*
CS 340 - Assignment 1
Node.cpp

Purpose: This is where the Node class is defined.

@author Patrick Ullrich, Austin McPhail
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include <random>
#include <iostream>

using namespace std;

class Node {
public:
	int key_value; //stores the key
	Node *left; // points to its left leaf
	Node *right; // points to its right leaf
};