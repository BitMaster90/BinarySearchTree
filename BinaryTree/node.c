#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include "Node.h"

bool DeleteNodeFromTree(Node **Root, unsigned int Value) {
	Node *Parent;
	Node *CurrentNode;
	Node *Min;
	Node *MinParent;
	if (*Root == NULL) {
		return false;
	}
	if ((*Root)->Value == Value) {
		CurrentNode = *Root;
		Parent = *Root;
	}
	else {
		Parent = FindParentInTree(Root, Value);
		if (Parent == NULL) {
			return false;
		}
		if (Parent->Value < Value) {
			CurrentNode = Parent->Right;
		}
		else {
			CurrentNode = Parent->Left;
		}
	}
	if (CurrentNode->Left == NULL && CurrentNode->Right == NULL) {
		if (Parent->Left == CurrentNode) {
			Parent->Left = NULL;
		}
		else if (Parent->Right == CurrentNode) {
			Parent->Right = NULL;
		}
		else {
			*Root = NULL;
		}
		free(CurrentNode);
	}
	else if (CurrentNode->Left == NULL) {
		if (Parent->Left == CurrentNode) {
			Parent->Left = CurrentNode->Right;
		}
		else if (Parent->Right == CurrentNode) {
			Parent->Right = CurrentNode->Right;
		}
		else {
			*Root = CurrentNode->Right;
		}
		free(CurrentNode);
	}
	else if (CurrentNode->Right == NULL) {
		if (Parent->Left == CurrentNode) {
			Parent->Left = CurrentNode->Left;
		}
		else if (Parent->Right == CurrentNode) {
			Parent->Right = CurrentNode->Left;
		}
		else {
			*Root = CurrentNode->Left;
		}
		free(CurrentNode);
	}
	else {
		Min = FindMinimumInTree(&CurrentNode->Right);
		MinParent = FindParentInTree(Root, Min->Value);
		CurrentNode->Value = Min->Value;
		DeleteNodeFromTree(&MinParent, Min->Value);
	}
}



bool AddToTree(Node **Root, unsigned int Value) {
	Node *CurrentNodePointer;
	Node *PreviousNodePointer;
	if (*Root == NULL) {
		CurrentNodePointer = (Node *)malloc(sizeof(Node));
		if (CurrentNodePointer == NULL) {
			return false;
		}
		CurrentNodePointer->Value = Value;
		CurrentNodePointer->Right = NULL;
		CurrentNodePointer->Left = NULL;
		*Root = CurrentNodePointer;
		return true;
	}
	CurrentNodePointer = *Root;
	PreviousNodePointer = *Root;
	while (CurrentNodePointer != NULL) {
		PreviousNodePointer = CurrentNodePointer;
		if (Value < CurrentNodePointer->Value) {
			CurrentNodePointer = CurrentNodePointer->Left;
		}
		else {
			CurrentNodePointer = CurrentNodePointer->Right;
		}
	}
	if (Value < PreviousNodePointer->Value) {
		PreviousNodePointer->Left = (Node *)malloc(sizeof(Node));
		if (PreviousNodePointer->Left == NULL) {
			return false;
		}
		else {
			PreviousNodePointer->Left->Value = Value;
			PreviousNodePointer->Left->Left = NULL;
			PreviousNodePointer->Left->Right = NULL;
		}
	}
	else {
		PreviousNodePointer->Right = (Node *)malloc(sizeof(Node));
		if (PreviousNodePointer->Right == NULL) {
			return false;
		}
		else {
			PreviousNodePointer->Right->Value = Value;
			PreviousNodePointer->Right->Left = NULL;
			PreviousNodePointer->Right->Right = NULL;
		}
	}
	return true;

}

void PrintTree(Node **Root) {
	Node *CurrentNodePointer;
	if (*Root == NULL) {
		return;
	}
	CurrentNodePointer = *Root;
	PrintTree(&CurrentNodePointer->Left);
	printf("Node is %d \n", CurrentNodePointer->Value);
	PrintTree(&CurrentNodePointer->Right);
}

bool SearchTree(Node **Root, unsigned int Value) {
Node *CurrentPointer;
bool RetVal;
if ((*Root) == NULL) {
	return false;
}
if ((*Root)->Value == Value) {
	return true;
}
CurrentPointer = *Root;
if (Value < CurrentPointer->Value) {
	RetVal = SearchTree(&CurrentPointer->Left, Value);
}
else {
	RetVal = SearchTree(&CurrentPointer->Right, Value);
}
return RetVal;
}

bool AddToTreeRecursion(Node **Root, unsigned int Value) {
	Node *CurrentPointer;
	bool RetVal;
	if (*Root == NULL) {
		*Root = (Node *)malloc(sizeof(Node));
		if (*Root == NULL) {
			return false;
		}
		else {
			(*Root)->Value = Value;
			(*Root)->Left = NULL;
			(*Root)->Right = NULL;
			return true;
		}
	}
	CurrentPointer = *Root;
	if (Value < CurrentPointer->Value) {
		RetVal = AddToTreeRecursion(&CurrentPointer->Left, Value);
	}
	else {
		RetVal = AddToTreeRecursion(&CurrentPointer->Right, Value);
	}
	return RetVal;
}

void AddToBinarySearch(unsigned int *Array, unsigned int Value) {
	unsigned int index;
	index = DoBinarySearch(Array, Value, 0, 9);
}


int DoBinarySearch(unsigned int *Array, unsigned int Value, unsigned int Start, unsigned int End) {
	unsigned int mid;
	int temp;
	if (End != Start) {
		mid = ((End + Start) + 1) / 2;
	}
	else {
		mid = Start;
	}
	if (Array[mid] == Value) {
		return mid;
	}
	if (Start == End) {
		return -1;
	}
	if (Value < Array[mid]) {
		temp = DoBinarySearch(Array, Value, Start, mid - 1);
	}
	else {
		temp = DoBinarySearch(Array, Value, mid + 1, End);
	}
	return temp;
}

Node * FindMinimumInTree(Node **Root) {
	Node  *Min;
	Node *CurrentNode;
	if (*Root == NULL) {
		return NULL;
	}
	if ((*Root)->Left == NULL) {
		return *Root;
	}
	CurrentNode = *Root;
	Min = FindMinimumInTree(&CurrentNode->Left);
	return Min;
}

Node *FindKMinimumInTree(Node **Root, unsigned int K) {
	static unsigned int Count = 0;
	static unsigned int FoundKMin = 0;
	Node *CurrentNode;
	static Node *KMin = NULL;
	if (*Root == NULL) {
		return NULL;
	}
	CurrentNode = *Root;
	FindKMinimumInTree(&CurrentNode->Left,K);
	Count++;
	if (Count == K) {
		KMin = CurrentNode;
		FoundKMin = 1;
		return KMin;
	}
	if (FoundKMin == 0) {
		FindKMinimumInTree(&CurrentNode->Right, K);
	}
	return KMin;
}

Node * FindSecondMinimumInTree(Node **Root) {
	Node *SecondMin;
	Node  *Min;
	Min = FindMinimumInTree(Root);
	if (Min->Right == NULL) {
		SecondMin = FindParentInTree(Root, Min->Value);
	}
	else {
		SecondMin = FindMinimumInTree(&Min->Right);
	}
	return SecondMin;
}

Node * FindParentInTree(Node **Root, unsigned int Value) {
	Node *CurrentNode;
	Node *Parent;
	Parent = NULL;
	if (*Root == NULL) {
		return NULL;
	}
	if ((*Root)->Left != NULL) {
		if ((*Root)->Left->Value == Value) {
			return *Root;
		}
	}
	if ((*Root)->Right != NULL) {
		if ((*Root)->Right->Value == Value) {
			return *Root;
		}
	}
	CurrentNode = *Root;
	Parent = FindParentInTree(&CurrentNode->Left,Value);
	if (Parent == NULL) {
		Parent = FindParentInTree(&CurrentNode->Right, Value);
	}
	return Parent;
}

Node * FindLowestCommonAncestor(Node **Root, unsigned int Child1, unsigned int Child2) {
	Node *CurrentNodePointer;
	if (*Root == NULL) {
		return NULL;
	}
	if (SearchTree(Root, Child1) == false || SearchTree(Root, Child2) == false) {
		return NULL;
	}
	CurrentNodePointer = *Root;
	while (CurrentNodePointer) {
		if (Child1 < CurrentNodePointer->Value && Child2 < CurrentNodePointer->Value) {
			CurrentNodePointer = CurrentNodePointer->Left;
		}
		else if (Child1 > CurrentNodePointer->Value && Child2 > CurrentNodePointer->Value) {
			CurrentNodePointer = CurrentNodePointer->Right;
		}
		else {
			return CurrentNodePointer;
		}
	}
	return NULL;
}