// CommandLineCharBST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BSTCommandHandler.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    auto cl = new BSTCommandHandler();
    cl->Run();
    return 0;
}

