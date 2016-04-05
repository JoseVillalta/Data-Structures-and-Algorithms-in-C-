// SpellChecker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Dictionary.h"
#include "WordChecker.h"


int _tmain(int argc, _TCHAR* argv[])
{
    cout << "Main Program Entry" << endl;
    auto dic = new Dictionary();
    dic->Init("dictionary.txt");

    return 0;
}

