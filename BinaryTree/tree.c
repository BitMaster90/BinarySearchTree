#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"Node.h"

int main(void) {
	Node *Root;
	unsigned int temp,i;
	unsigned int Value;
	unsigned int K;
	unsigned int Child1;
	unsigned int Child2;
	Node *Min;
	Node *SecondMin;
	Node *KMin;
	Node *Parent;
	Node *LCA;
	unsigned int Array[10] = { 6,13,15,16,17,19,23,26,32,90 };
	Root = NULL;
	AddToTreeRecursion(&Root, 10);
	AddToTreeRecursion(&Root, 6);
	AddToTreeRecursion(&Root, 13);
	AddToTreeRecursion(&Root, 3);
	AddToTreeRecursion(&Root, 8);
	AddToTreeRecursion(&Root, 5);
	AddToTreeRecursion(&Root, 4);
	
	PrintTree(&Root);
	for (temp = 0; temp < 11; temp++) {
		if (SearchTree(&Root, temp) == true) {
			printf("Tree has value %d \n", temp);
		}
		else {
			printf("Tree does not have value %d \n", temp);
		}
	}
	Min = FindMinimumInTree(&Root);
	if (Min == NULL) {
		printf("Tree is empty \n");
	}
	else {
		printf("Minimum value in Tree is %d \n", Min->Value);
	}
	SecondMin = FindSecondMinimumInTree(&Root);
	if (SecondMin == NULL) {
		printf("Tree is empty \n");
	}
	else {
		printf("Second Minimum value in Tree is %d \n", SecondMin->Value);
	}
	K = 5;
	KMin = FindKMinimumInTree(&Root,K);
	if (KMin == NULL) {
		printf("Tree is empty \n");
	}
	else {
		printf("%d KMinimum value in Tree is %d \n", K,KMin->Value);
	}
	Parent = FindParentInTree(&Root, 8);
	if (Parent == NULL) {
		printf("Parent not found \n");
	}
	else {
		printf("Parent node is %d \n", Parent->Value);
	}
	printf("Array is : \n");
	for (i = 0; i < 10; i++) {
		printf("%d ", Array[i]);
	}
	printf("\n");
	Value = 5;
	temp = DoBinarySearch(Array, Value, 0, 9);
	if ( temp != -1) {
		printf("Value %d found at index %d\n", Value, temp);
	}
	else {
		printf("Value %d not found \n", Value);
	}
	Child1 = 5;
	Child2 = 8;
	printf("Lowest common ancestor for %d and %d in the tree is :\n", Child1, Child2);
	LCA = FindLowestCommonAncestor(&Root, Child1, Child2);
	if (LCA == NULL) {
		printf("No LCA \n");
	}
	else {
		printf("LCA is %d \n", LCA->Value);
	}
}

