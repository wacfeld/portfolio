#include "stdafx.h"
#include <iostream>
#include "Alphabet.h"

CAlphabet::CAlphabet(int size)
{
	//mSize = size;
	mTreeRoot = NULL;
	mListHead = NULL;
	mListTail = NULL;

	mSize = size;	
	probArr = new double(mSize);
	symbolArr = new unsigned char(mSize);
	countArr = new int(mSize);
	indexArr = new int(mSize);
	
}

void CAlphabet::freeAllMemory()
{
	if(probArr!=NULL)
	{
		free(probArr);
		probArr = NULL;
	}

	if(countArr!=NULL)
	{
		free(countArr);
		countArr = NULL;
	}

	if(symbolArr != NULL)
	{
		free(symbolArr);
		symbolArr = NULL;
	}

	if(indexArr != NULL)
	{
		free(indexArr);
		indexArr = NULL;
	}
	
	//freeTree();
}



CAlphabet::~CAlphabet(void)
{
	delete(probArr);
	delete(countArr);
	delete(symbolArr);
	delete(indexArr);
}



bool CAlphabet::initProbAndSymbols(double probs[], unsigned char symbols[])
{

	//First init probs:
	double matchOne = 0;
	for(int i = 0; i < NUM_SYMBOLS; i++)
	{
		probArr[i] = probs[i];
		matchOne += probs[i];
	}

	if(matchOne > 1.00000001 && matchOne < 0.999999999)
	{
		return false;
	}

	// init symbols:
	for(int i = 0; i < NUM_SYMBOLS; i++)
	{
		symbolArr[i] = symbols[i];
	}

	return true;
}

void CAlphabet::initIndexes()
{
	for(int i = 0; i < NUM_SYMBOLS; i++)
	{
		indexArr[i] = i;
	}

}

void CAlphabet::swapInts(int * int1, int * int2)
{
	int swap = *int1;
	*int1 = *int2;
	*int2 = swap;
}

void CAlphabet::swapDoubles(double * double1, double * double2)
{
	double swap = *double1;
	*double1 = *double2;
	*double2 = swap;
}

void CAlphabet::bubbleSortProbs()
{// Bubble sorts probs and indexes

	for(int i = 0; i < NUM_SYMBOLS; i++)
	{
		for(int j = i + 1; j < NUM_SYMBOLS; j++)
		{
			if(probArr[i] < probArr[j])
			{
				swapDoubles(probArr+i,probArr+j);
				swapInts(indexArr+i,indexArr+j);
			}

		}

	}


}



CTreeNode * CAlphabet::initTree()
{

	initIndexes();
	bubbleSortProbs();
	
	mListHead = new CTreeNode(symbolArr[indexArr[0]], countArr[indexArr[0]], probArr[0]);

	CTreeNode * currentNode = mListHead;
	CTreeNode * lastNode = mListHead;

	for(int i = 1; i < NUM_SYMBOLS; i++)
	{
		currentNode = new CTreeNode(symbolArr[indexArr[i]], countArr[indexArr[i]], probArr[i]);
		currentNode->mLeftSibling = lastNode;
		lastNode->mRightSibling = currentNode;
		mListTail = currentNode;
		lastNode = currentNode;
	}

	return mListHead;

}


bool CAlphabet::mergeTwoLeastNodes()
{
	CTreeNode * orphan1 = NULL;
	CTreeNode * orphan2 = NULL;

	CTreeNode * currentNode = mListTail;
	
	while(true)
	{
		if(currentNode == mListHead)
		{
			if(currentNode->mParent == NULL)
			{
				if(orphan1 == NULL)
				{
					orphan1 = currentNode;
				}
			
				else if(orphan2 == NULL) 
				{
					orphan2 = currentNode;
				}
			
				
			}

			break;
		}

		if(currentNode->mParent == NULL)
		{
			if(orphan1 == NULL)
			{
				orphan1 = currentNode;
			}
			
			else if(orphan2 == NULL) 
			{
				orphan2 = currentNode;
			}
			
			else
			{
				break;
			}
			
		}

		

		currentNode = currentNode->mLeftSibling;
	}

	if(orphan1 != NULL && orphan2 != NULL)
	{
		
		CTreeNode * mergedOrphanNode = new CTreeNode(NULL, NULL, orphan1->mProb + orphan2->mProb);
		mergedOrphanNode->mRightChild = orphan1;
		mergedOrphanNode->mLeftChild = orphan2;
		orphan1->mParent = mergedOrphanNode;
		orphan2->mParent = mergedOrphanNode;

		currentNode = mListHead;

		while(true)
		{
			if(mergedOrphanNode->mProb > 0.99999999 && mergedOrphanNode->mProb < 1.00000000001)
			{
				mListHead->mLeftSibling = mergedOrphanNode;
				mergedOrphanNode->mRightSibling = mListHead;
				mTreeRoot = mergedOrphanNode;
				mListHead = mergedOrphanNode;
				break;
			}


		
			if(currentNode->mProb < mergedOrphanNode->mProb)
			{

				mergedOrphanNode->mRightSibling = currentNode;
				mergedOrphanNode->mLeftSibling = currentNode->mLeftSibling;
				currentNode->mLeftSibling->mRightSibling = mergedOrphanNode;
				currentNode->mLeftSibling = mergedOrphanNode;
				break;
			}

			currentNode = currentNode->mRightSibling;
		}
		return true;
	}
	return false;

}


void CAlphabet::assignBinaryCodes(CTreeNode * currentNode, CTreeNode * parent)
{

	if(parent == NULL)
	{
		assignBinaryCodes(currentNode->mLeftChild, currentNode);
		assignBinaryCodes(currentNode->mRightChild, currentNode);
		return;
	}

	if(currentNode->mParent->mLeftChild == currentNode)
	{
		currentNode->mBinaryCode = currentNode->mParent->mBinaryCode + "1";
	}
	else
	{
		currentNode->mBinaryCode = currentNode->mParent->mBinaryCode + "0";
	}

	
	if(currentNode->mLeftChild == NULL && currentNode->mRightChild == NULL)//Leaf node
	{
		return;
	}

	assignBinaryCodes(currentNode->mLeftChild, currentNode);
	assignBinaryCodes(currentNode->mRightChild, currentNode);

}


void CAlphabet::listBinaryCodes()
{
	CTreeNode * currentNode = mTreeRoot;


	while(true)
	{
		if(currentNode->mLeftChild == NULL && currentNode->mRightChild == NULL)// List codeword of leaf node
		{
			
			std::cout << "Codeword for symbol " << std::string(1,  currentNode->mName) << " is " << currentNode->mBinaryCode << std::endl;
		}

		if(currentNode->mRightSibling == NULL)
		{
			break;
		}

		
		currentNode = currentNode->mRightSibling; // Keep this at end of method
	}

	
}


void CAlphabet::freeTree()
{

	int i = 0;

	CTreeNode * currentNode = mListHead;

	while(currentNode != NULL)
	{
		CTreeNode * currentRightSibling = currentNode->mRightSibling;
		delete(currentNode);
		i++;

		currentNode = currentRightSibling;
	}

	if(i != 2 * NUM_SYMBOLS - 1)
	{
		std::cout << "Something wrong with mListHead" << std::endl;
	}
	else
	{
		std::cout << "Freed list successfully" << std::endl;
	}

	
	mListHead = NULL;

}
