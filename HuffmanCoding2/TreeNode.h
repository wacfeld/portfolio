#pragma once
#include <string>

class CTreeNode
{
public:
	unsigned char mName;
	int mCount;
	double mProb;
	std::string mBinaryCode;

	CTreeNode * mParent;
	CTreeNode * mLeftChild;
	CTreeNode * mRightChild;
	CTreeNode * mLeftSibling;
	CTreeNode * mRightSibling;

	CTreeNode(unsigned char name, int count, double prob);
	~CTreeNode(void);
};

