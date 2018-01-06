#include "BinaryIndexedTree.h"



BinaryIndexedTree::BinaryIndexedTree(const vector<int>& Arg)
{
	tree.resize(Arg.size());
	for (int i = 0; i < tree.size(); i++)
		Increase(i, Arg[i]);
}

void BinaryIndexedTree::Increase(int index, int delta)
{
	for (; index < (int)tree.size(); index |= index + 1)
		tree[index] += delta;
}

int BinaryIndexedTree::GetSum(int left, int right)
{
	return Sum(right) - Sum(left - 1);
}

int BinaryIndexedTree::Sum(int index)
{
	int sum = 0;
	while (index >= 0)
	{
		sum += tree[index];
		index &= index + 1;
		index--;
	}
	return sum;
}