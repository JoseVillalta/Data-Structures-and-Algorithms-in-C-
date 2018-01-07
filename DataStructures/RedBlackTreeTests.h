#pragma once
#include "RedBlackTree.h"

using namespace std;

class RedBlackTreeTests
{
public:
    void DoTests();
	void PerfTest();
	void CompareWithBST(int limit);
	void CompareWithBSTv2(int limit);
	void HappyPathTest();

};