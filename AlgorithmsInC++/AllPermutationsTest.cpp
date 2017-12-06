#include "AllPermutationsTest.h"
#include "construct_all_permutations.h"
#include "permute_string.h"
#include <iostream>

using namespace std;

void AllPermutationsTest::DoTests()
{
    TestAllPerms();
    TestPermutations();
    
}

void AllPermutationsTest::TestAllPerms()
{
    cout << "All Permutations Test Start" << endl;
    auto pb = new PermutationBuilder();
    pb->GeneratePermutations(3);
    pb->GeneratePermutations(4);
    pb->GeneratePermutations(5);
    cout << "All Permutations Test Done" << endl;

}

void AllPermutationsTest::TestPermutations()
{
    cout << "Test Permutations of a String Start" << endl;
    string a = "ABC";
    permute(a, 0, 2);
}

