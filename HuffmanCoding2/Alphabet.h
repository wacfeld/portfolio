#pragma once
#include <string>
#include "TreeNode.h"
#include "numSymbols.h"


class CAlphabet
{

public:

	CAlphabet(int size);
	~CAlphabet(void);

	CTreeNode * mTreeRoot;
	CTreeNode * mListHead;
	CTreeNode * mListTail;

	int mSize;
	
	double * probArr;
	unsigned char * symbolArr;
	int * countArr;
	int * indexArr;

	bool initProbAndSymbols(double probs[], unsigned char symbols[]);
	CTreeNode * initTree();
	bool mergeTwoLeastNodes();
	void assignBinaryCodes(CTreeNode * currentNode, CTreeNode * parent);
	void listBinaryCodes();
	void initIndexes();

	void bubbleSortProbs();
	void swapInts(int * int1, int * int2);
	void swapDoubles(double * double1, double * double2);

	void freeTree();

	void freeAllMemory();
};

