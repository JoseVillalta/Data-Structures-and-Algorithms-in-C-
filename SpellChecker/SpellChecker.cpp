// SpellChecker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "Dictionary.h"
#include "WordChecker.h"

using namespace std;
/*Console application that reads words in a text file and looks up each of them
in a dictionary to check its spelling*/
int _tmain(int argc, _TCHAR* argv[])
{
    cout << "Main Program Entry" << endl;
    auto dic = new Dictionary();
    dic->Init("dictionary.txt");
    auto spellChecker = new WordChecker(dic);
    vector<string> * vector = spellChecker->ScanFile("WordList.txt");
    cout << "List of words not found in dictionary" << endl;
    for (auto i : *vector)
    {
        cout << i << endl;
    }



    return 0;
}

