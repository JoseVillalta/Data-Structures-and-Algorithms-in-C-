#include "WordChecker.h"


WordChecker::WordChecker(Dictionary * dic)
{
    m_dictionary = dic;
}


WordChecker::~WordChecker()
{
    delete m_dictionary;
}

vector<string> * WordChecker::ScanFile(string file)
{
    vector<string> wordsNotFoundList;
    ifstream fileHandle;
    fileHandle.open(file);
    if (fileHandle.is_open())
    {

    }
    else
    {
        cout << "Could not open file: " << file << endl;
    }

}
