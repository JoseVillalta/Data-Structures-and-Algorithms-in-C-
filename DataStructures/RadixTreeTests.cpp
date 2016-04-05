#include "RadixTreeTests.h"
#include <iostream>
using namespace std;

void RadixTreeTests::DoTests()
{
    InsertWordsThenFindThemTests();
    InsertWordsThenFindCommonPrefixTests();
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

void RadixTreeTests::InsertWordsThenFindCommonPrefixTests()
{
    cout << "Find words that match test" << endl;
    auto trie = new Trie();
    trie->InsertWord("cat");
    trie->InsertWord("can");
    trie->InsertWord("bat");
    trie->InsertWord("cab");
    trie->InsertWord("ant");
    trie->InsertWord("cantine");
    trie->InsertWord("catapult");
    trie->InsertWord("california");
    trie->InsertWord("creole");
    trie->InsertWord("chef");

    trie->DisplayAllMatches("ca");
    cout << "Output should include the words: ";
    cout << "cat,can,cab, cantine, catapult, california" << endl;
}