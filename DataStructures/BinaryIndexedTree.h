#pragma once
#include <vector>

using namespace std;

class BinaryIndexedTree
{
public:
	vector<int> tree;
	BinaryIndexedTree(const vector<int>& Arg);
	void Increase(int index, int delta);
	int GetSum(int left, int right);
private:
	
	int Sum(int index);
};

