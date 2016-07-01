#include "YoungTableauTests.h"

void YoungTableauTests::DoTests()
{
    TestCreation();
    TestInsert();
    TestExtractMin();
}

void YoungTableauTests::TestCreation()
{
    auto yt = new YoungTableau(3, 3);

    yt->Insert(10);
    yt->Insert(5);
    yt->Insert(30);
    yt->Insert(4);
    yt->Insert(100);
    yt->Insert(74);
    yt->Insert(11);
    cout << "Young Tableu Tests" << endl;
    yt->PrintTable();
    yt->Validate();
    cout << "Creation Test Passed" << endl;
}

void YoungTableauTests::TestInsert()
{
    auto yt = new YoungTableau(10, 10);
    cout << "Starting Young Tableu Insert Test" << endl;

    for (int i = 0; i < 100; i++)
    {
        int x = rand() % 100;
        yt->Insert(x);
    }

    yt->PrintTable();
    yt->Validate();

    
    for (int j = 0; j < 10; j++)
    {
        yt->ExtractMin();
    }

    yt->Validate();

    cout << "Young Tableu Insertion Test passed" << endl;

}

void YoungTableauTests::TestExtractMin()
{
    auto yt = new YoungTableau(10, 10);
    cout << "Starting Young Tableu Extract Min" << endl;

    yt->Insert(0);

    for (int i = 0; i < 80; i++)
    {
        int x = rand() % 100;
        yt->Insert(x);
    }

    int min = yt->ExtractMin();
    _ASSERT(min == 0);
    yt->PrintTable();
    yt->Validate();

    cout << "Extract Min Passed" << endl;

}