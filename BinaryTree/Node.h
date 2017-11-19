#pragma once
#include<stdbool.h>
#ifndef NODE_H
#define NODE_H
typedef struct Node Node;

struct Node {
	unsigned int Value;
	Node *Left;
	Node *Right;
};

bool AddToTree(Node **, unsigned int);
void PrintTree(Node **);
bool SearchTree(Node **, unsigned int);
bool AddToTreeRecursion(Node **, unsigned int);
void AddToBinarySearch(unsigned int *, unsigned int);
int DoBinarySearch(unsigned int *, unsigned int, unsigned int, unsigned int);
Node * FindMinimumInTree(Node **);
Node * FindSecondMinimumInTree(Node **);
Node * FindParentInTree(Node **, unsigned int);
Node * FindKMinimumInTree(Node **, unsigned int);
Node * FindLowestCommonAncestor(Node **, unsigned int, unsigned int);
bool DeleteNodeFromTree(Node **, unsigned int);
#endif

