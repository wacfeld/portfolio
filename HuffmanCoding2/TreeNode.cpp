#include "stdafx.h"
#include "TreeNode.h"
#include <string>

CTreeNode::CTreeNode(unsigned char name, int count, double prob)
{
	mName = name;
	mCount = count;
	mProb = prob;

	mParent = NULL;
	mLeftChild = NULL;
	mRightChild = NULL;
	mLeftSibling = NULL;
	mRightSibling = NULL;

	mBinaryCode = "";
}


CTreeNode::~CTreeNode(void)
{
}
