#include "YoungTableTests.h"

void YoungTableTests::DoTests()
{
    TestCreation();
    TestInsert();
}

void YoungTableTests::TestCreation()
{
    auto yt = new YoungTable(3, 3);

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

void YoungTableTests::TestInsert()
{
    auto yt = new YoungTable(10, 10);
    cout << "Starting Young Tableu Insert Test" << endl;

    for (int i = 0; i < 100; i++)
    {
        int x = rand() % 100;
        yt->Insert(x);
    }

    yt->PrintTable();
    yt->Validate();

    cout << "Young Tableu Insertion Test passed" << endl;

}