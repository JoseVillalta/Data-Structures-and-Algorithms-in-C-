#pragma once
#include "stdafx.h"
#include "RedBlackTreeTests.h"
#include "BinarySearchTree.h"
#include <iostream>
#include "../AlgorithmsInC++/Tests/Support/TimeElapsed.h"

using namespace std;
void RedBlackTreeTests::DoTests()
{
	HappyPathTest();
	//PerfTest();
}

void RedBlackTreeTests::HappyPathTest()
{
	cout << "Do Red Black Tree Test Tests" << endl;

	auto rbTree = new RedBlackTree();

	rbTree->Insert(7);
	rbTree->Insert(6);
	rbTree->Insert(5);
	rbTree->Insert(4);
	rbTree->Insert(4);
	rbTree->Insert(3);
	rbTree->Insert(2);
	rbTree->Insert(1);

	cout << "Red Black Tree in order" << endl;
	rbTree->InOrder();
	cout << "Red Black Tree Levels " << endl;
	rbTree->LevelOrder();
}

void RedBlackTreeTests::PerfTest()
{
	int limit = 10;
	while (limit < 100000000)
	{
		CompareWithBST(limit);
		limit = limit * 10;
	}

}


void RedBlackTreeTests::CompareWithBST(int limit)
{
	auto bst = new BST<int>();
	auto rbt = new RedBlackTree();

	int counter = 0;

	cout << "Inserting "<<limit<<" values to Binary Search Tree" << endl;
	LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
	LARGE_INTEGER Frequency;

	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&StartingTime);
	// Start Time BST
	while (counter <limit)
	{
		int val = rand();
		bst->Insert(val);
		counter++;
	}
	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);
	cout << " Elapsed Microseconds for BST is: " << ElapsedMicroseconds.QuadPart << endl;



	cout << " Inserting "<<limit<<" values to Red Black Tree" << endl;
	counter = 0;
	QueryPerformanceCounter(&StartingTime);
	while (counter < limit)
	{
		int val = rand();
		rbt->Insert(val);
		counter++;
	}
	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);
	cout << " Elapsed Microseconds for RB Tree: " << ElapsedMicroseconds.QuadPart << endl;


	cout << " Searching BST "<<limit<<" times" << endl;
	counter = 0;
	QueryPerformanceCounter(&StartingTime);
	while (counter < limit)
	{
		int val = rand();
		bst->Search(val);
		counter++;
	}
	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);
	cout << " Elapsed Microseconds in BST Search: " << ElapsedMicroseconds.QuadPart << endl;


	counter = 0;
	cout << " Searching Red Black Tree "<<limit<<" times" << endl;
	QueryPerformanceCounter(&StartingTime);
	while (counter<limit)
	{
		int val = rand();
		rbt->Search(val);
		counter++;
	}
	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);
	cout << " Elapsed Time Searching Red Black Tree: " << ElapsedMicroseconds.QuadPart << endl;
}
