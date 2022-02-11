
#include "Runtime/UnitTest.Foundation.hpp"
#include "Runtime/UnitTest.Chrono.hpp"

#include <string>
#include <iostream>


int main() {

    // UnitTest::Foundation::TestInt64::RunAll(); 
    // UnitTest::Foundation::TestFixedString::RunAll();
    // UnitTest::Chrono::TestDateTime::RunAll();
    // UnitTest::Foundation::TestString::RunAll();

    const char* v = "汉子x";
    std::cout << strlen(v) << std::endl;

    const wchar_t* v2 = L"汉子x";
    std::cout << wcslen(v2) << std::endl;
    return 0;
}
