#include "RadixTreeTests.h"
#include <iostream>
using namespace std;

void RadixTreeTests::DoTests()
{
    InsertWordsThenFindThemTests();
}

void RadixTreeTests::InsertWordsThenFindThemTests()
{
    cout << "Start of Trie Test" << endl;
    auto trie = new Trie();
    trie->InsertWord("Mary");
    trie->InsertWord("had");
    trie->InsertWord("a");
    trie->InsertWord("Little");
    trie->InsertWord("Lamb");

    _ASSERT(trie->FindWord("Mary") == true);
    _ASSERT(trie->FindWord("Cat") == false);
    _ASSERT(trie->FindWord("a") == true);
    _ASSERT(trie->FindWord("Lambo") == false);

    cout << "Trie Insert and Search Test finished succesfully" << endl;


}