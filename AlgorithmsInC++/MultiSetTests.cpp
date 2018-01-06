#include "MultiSetTests.h"
#include "MultiSet.h"

void MultiSetsTest::DoTests()
{
    GenerateTests();
}

void MultiSetsTest::GenerateTests()
{
    int input[4] = { 1, 1, 2, 2 };
    auto ms = new MultiSetBuilder();
    ms->GenerateMultiset(input,4);
}

