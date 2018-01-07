#pragma once
#include "stdafx.h"
#include "RedBlackTreeTests.h"
#include "BinarySearchTree.h"
#include <iostream>
#include "../AlgorithmsInC++/Tests/Support/TimeElapsed.h"
#include "../AlgorithmsInC++/Tests/Support/RandomVector.h"

using namespace std;
void RedBlackTreeTests::DoTests()
{
	HappyPathTest();
	PerfTest();
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
	while (limit < 10000000)
	{
		CompareWithBST(limit);
		limit = limit * 10;
	}

	limit = 10;
	while (limit < 10000000)
	{
		CompareWithBSTv2(limit);
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

void RedBlackTreeTests::CompareWithBSTv2(int limit)
{
	auto bst = new BST<int>();
	auto rbt = new RedBlackTree();
	auto v = new vector<int>();

	int counter = 0;

	cout << "Inserting " << limit << " values to Binary Search Tree using same vector (usv) " << endl;
	LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
	LARGE_INTEGER Frequency;

	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&StartingTime);
	// Start Time BST

	GetRandomVector(*v, limit);
	for(auto i : *v)
	{
		bst->Insert(i);
	}
	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);
	cout << " (usv) Elapsed Microseconds for BST is: " << ElapsedMicroseconds.QuadPart << endl;



	cout << " Inserting " << limit << " values to Red Black Tree (usv) " << endl;
	QueryPerformanceCounter(&StartingTime);
	for (auto i : *v)
	{
		rbt->Insert(i);
	}
	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);
	cout << " (usv) Elapsed Microseconds for RB Tree: " << ElapsedMicroseconds.QuadPart << endl;

	auto v2 = new vector<int>();
	GetRandomVector(*v2, limit);

	cout << " (usv) Searching BST " << limit << " times" << endl;
	QueryPerformanceCounter(&StartingTime);
	for(auto i : *v2)
	{
		bst->Search(i);
	}
	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);
	cout << " (usv) Elapsed Microseconds in BST Search: " << ElapsedMicroseconds.QuadPart << endl;


	cout << " (usv) Searching Red Black Tree " << limit << " times" << endl;
	QueryPerformanceCounter(&StartingTime);
	for (auto i : *v2)
	{
		rbt->Search(i);
	}
	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);
	cout << " Elapsed Time Searching Red Black Tree: " << ElapsedMicroseconds.QuadPart << endl;
	delete v;
	delete v2;
}

