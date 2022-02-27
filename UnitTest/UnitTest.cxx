
#include "Runtime/UnitTest.Foundation.hpp"
#include "Runtime/UnitTest.Chrono.hpp"
#include "Runtime/Basic.Macro.Trace.hxx"

#include <string>
#include <iostream>
#include <vector>


using namespace Fantasia;

int main() {

    // UnitTest::Foundation::TestInt64::RunAll(); 
     UnitTest::Foundation::TestFixedString::RunAll();
    // UnitTest::Chrono::TestDateTime::RunAll();


    UnitTest::Foundation::TestString::RunAll();

    const char* v = "汉子x";
    std::cout << strlen(v) << std::endl;

    const wchar_t* v2 = L"汉子x";
    std::cout << wcslen(v2) << std::endl;


    const char ByteFlagOnStack = 0x0011;

    std::string v3 = "汉子x";
    
    Float64 val2 = 90;

    Float64 val1 = 80;

    std::cout << (val1 > val2).ToString() << std::endl;

    std::cout << (val1 == val2).ToString() << std::endl;

    std::vector<int> vec;
    
    std::begin(vec);

    std::cout << "--------" << std::endl;
    Bool bVal;
    std::cin >> bVal; 
    std::cout << bVal.ToString() << std::endl;


    ___FANTASIA_TRACE_SCOPE;
    ___FANTASIA_TRACE_WRITE_LINE("ALKSJD" << 3344 << "| ASDF");


    return 0;
}
