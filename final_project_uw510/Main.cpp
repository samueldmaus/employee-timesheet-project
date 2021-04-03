#include "TestHarness.h"

#include <iostream>


int main()
{
    srand(::time_t(NULL));

    TestResult tr;
    TestRegistry::runAllTests(tr);

    char ch;
    std::cin >> ch;

    return 0;
}