#include "BinaryIndexedTreeTest.h"
#include <iostream>
#include <vector>
using namespace std;

void FenwickTreeTest::DoTests()
{
	cout << endl;
	cout << "Fenwick Tests" << endl;
	vector<int> input = { 1,2,3,4,5,6,7,8,9 };
	auto ft = new BinaryIndexedTree(input);
	int result = ft->GetSum(0, 4);
	_ASSERT(result == 15);
	int res2 = ft->GetSum(0, 5);
	_ASSERT(res2 == 21);
}