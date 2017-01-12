/*
	CS 340 - Assignment 1
	Assignment1.cpp
	Purpose: <TODO>

	@author Patrick Ullrich, Austin McPhail
 */

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include <random>
#include <iostream>


const int NODES_ROUND_1 = 4;
const int TREES_ROUND_1 = 4;
const int NODES_ROUND_2 = 8;
const int NODES_ROUND_3 = 16;
const int NODES_ROUND_4 = 4096;


struct Node
{
	int key_value;
	Node *left;
	Node *right;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void insert(int key);
	void destroy();

private:
	void destroy(Node *leaf);
	void insert(int key, Node *leaf);

	Node *root;
};

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	destroy();
}

void BinaryTree::destroy(Node *leaf)
{
	// Post Order Traversal
	if (leaf != NULL) {
		destroy(leaf->left);
		destroy(leaf->right);
		delete leaf;
	}
}

void BinaryTree::destroy()
{
	destroy(root);
}

void BinaryTree::insert(int key, Node *leaf)
{
	if (key < leaf->key_value) {
		if (leaf->left != NULL) {
			insert(key, leaf->left);
		}
		else {
			leaf->left = new Node;
			leaf->key_value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->key_value)
	{
		if (leaf->right != NULL) {
			insert(key, leaf->right);
		}
		else {
			leaf->right = new Node;
			leaf->key_value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}
}

void BinaryTree::insert(int key)
{
	if (root != NULL) {
		insert(key, root);
	}
	else {
		root = new Node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 1);

	for (int i = 0; i < TREES_ROUND_1; i++) {
		BinaryTree binaryTree;

		for (int j = 0; j < NODES_ROUND_1; i++) {
			int test = dis(gen);
			binaryTree.insert(test);
			std::cout << test << '\n';
		}

	}

	return 0;
}