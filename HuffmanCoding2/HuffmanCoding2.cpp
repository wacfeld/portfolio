// HuffmanCoding2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "numSymbols.h"

#include "Alphabet.h"
#include <iostream>

#include <exception>
//#include "TreeNode.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int * testNum = new int(5);
	if(testNum != NULL)
	{
		delete(testNum);
	}


	unsigned char nameArray[NUM_SYMBOLS] = {'a','b','c','d'};
	double probArray[NUM_SYMBOLS] = {0.1,0.5,0.2,0.2};

	CAlphabet alphaset(NUM_SYMBOLS);

	CTreeNode * rootNode;

	if(alphaset.initProbAndSymbols(probArray, nameArray) == false)
	{
		std::cout << "Probs don't add to 1" << std::endl;
		return 0;
	}

	alphaset.initTree();
	while(true)
	{
		bool didMerge = alphaset.mergeTwoLeastNodes();
		if(!didMerge)
		{
			rootNode = alphaset.mTreeRoot;
			break;
		}

	}

	alphaset.assignBinaryCodes(rootNode,NULL);
	alphaset.listBinaryCodes();

	alphaset.freeTree();
    //alphaset.freeAllMemory();
	

	//printf("printf anything to stop");
	//unsigned char c;
	//scanf_s("%c", &c);
 	
	std::cout << "Done\n";
	
	return 1 ;
	
}

