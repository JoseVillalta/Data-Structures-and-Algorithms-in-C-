#include "WordChecker.h"
#include <sstream>


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
    auto wordsNotFoundList = new vector<string>();
    ifstream fileHandle;
    fileHandle.open(file);
    if (fileHandle.is_open())
    {
        string line;
        while (getline(fileHandle, line))
        {
            istringstream iss(line);
            do
            {
                string word;
                iss >> word;
                if (!m_dictionary->Search(word))
                {
                    wordsNotFoundList->push_back(word);
                }

            } while (iss);
            
        }
       
    }
    else
    {
        cout << "Could not open file: " << file << endl;
    }
    return wordsNotFoundList;
}
