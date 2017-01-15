/*
CS 340 - Assignment 1
main.cpp

Purpose: This is the main program, were the user will select the type of tree they wish to use,
enter ther amounf of nodes to be created in each tree, and number of trees. The program will create
said trees, add up the depth of all nodes created, free each tree, and then calculate the average
depth of all of the trees by dividing the total depth by the number of nodes created.

@author Patrick Ullrich, Austin McPhail
*/

#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include <random>
#include <iostream>
#include <cmath>
#include "Node.h"
#include "BinarySearchTree.h"
#include "BinaryTree.h"

using namespace std;

int main() {
	int tree_type;
	int node_amount;
	int tree_amount;
	int progress_counter;
	int print_progress_frequency;
	double total_tree_depth = 0;
	double total_average;

	cout << "Use Binary Search Trees (1), AVL Trees (2), or Binary Trees (3)? ";
	cin >> tree_type;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 4096);
	uniform_int_distribution<int> one_zero(0, 1);

	switch (tree_type) {
	case 1: //Binary Search Trees
		cout << "Enter a number of nodes: ";
		cin >> node_amount;
		cout << "Enter a number of trees: ";
		cin >> tree_amount;
		cout << "Print progress frequency: ";
		cin >> print_progress_frequency;
		progress_counter = 0;
		for (int i = 0; i < tree_amount; i++) {
			BinarySearchTree binarySearchTree;
			for (int j = 0; j < node_amount; j++) {
				int test = dis(gen);
				binarySearchTree.insert(test);
			}
			total_tree_depth += binarySearchTree.getDepthTotal();
			if (progress_counter % print_progress_frequency == 0) {
				cout << "* ";
			}
			progress_counter++;
			binarySearchTree.destroy();
		}
		progress_counter = 0;

		cout << '\n';
		total_average = total_tree_depth / (node_amount * tree_amount);
		cout << "Total depth accumulator: " << total_tree_depth << '\n';
		cout << "Total number of nodes: " << (node_amount * tree_amount) << '\n';
		cout << "Average depth: " << total_average << '\n';
		cout << "Log " << node_amount << ": " << log(node_amount) << '\n';
		cout << "Square Root " << node_amount << ": " << sqrt(node_amount) << '\n';
		break;

	case 2: //AVL Trees
		cout << "Enter a number of nodes: ";
		cin >> node_amount;
		cout << "Enter a number of trees: ";
		cin >> tree_amount;
		cout << "Print progress frequency: ";
		cin >> print_progress_frequency;
		progress_counter = 0;
		for (int i = 0; i < tree_amount; i++) {
			//AVLTree avlTree
			for (int j = 0; j < node_amount; j++) {
				int test = dis(gen);
			//	avlTree.insert(test);
			}
			//total_tree_depth += avlTree.getDepthTotal();
			if (progress_counter % print_progress_frequency == 0) {
				cout << "* ";
			}
			progress_counter++;
			//avlTree.destroy();
		}
		progress_counter = 0;

		cout << '\n';
		total_average = total_tree_depth / (node_amount * tree_amount);
		cout << "Total depth accumulator: " << total_tree_depth << '\n';
		cout << "Total number of nodes: " << (node_amount * tree_amount) << '\n';
		cout << "Average depth: " << total_average << '\n';
		cout << "Log " << node_amount << ": " << log(node_amount) << '\n';
		cout << "Square Root " << node_amount << ": " << sqrt(node_amount) << '\n';
		break;
	case 3: //Binary Trees
		cout << "Enter a number of nodes: ";
		cin >> node_amount;
		cout << "Enter a number of trees: ";
		cin >> tree_amount;
		cout << "Print progress frequency: ";
		cin >> print_progress_frequency;
		progress_counter = 0;
		for (int i = 0; i < tree_amount; i++) {
			BinaryTree binaryTree;

			for (int j = 0; j < node_amount; j++) {
				int test = dis(gen);
				int binary = one_zero(gen);
				binaryTree.insert(test, binary);
			}
			total_tree_depth += binaryTree.getDepthTotal();
			if (progress_counter % print_progress_frequency == 0) {
				cout << "* ";
			}
			progress_counter++;
			binaryTree.destroy();
		}
		progress_counter = 0;

		cout << '\n';
		total_average = total_tree_depth / (node_amount * tree_amount);
		cout << "Total depth accumulator: " << total_tree_depth << '\n';
		cout << "Total number of nodes: " << (node_amount * tree_amount) << '\n';
		cout << "Average depth: " << total_average << '\n';
		cout << "Log " << node_amount << ": " << log(node_amount) << '\n';
		cout << "Square Root " << node_amount << ": " << sqrt(node_amount) << '\n';
		break;
		break;
	}

	return 0;
}