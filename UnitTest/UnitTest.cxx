
#include "Runtime/UnitTest.Foundation.hpp"
#include "Runtime/UnitTest.Chrono.hpp"

#include <string>
#include <iostream>

class AppImpl {
public:
    void print() {
        std::cout << "AppImpl" << std::endl;
    }
};

class App {
public:
    App() {

    }
    
public:
    void print() {
        std::cout << "AppImpl" << std::endl;
    }
};

using namespace Fantasia;

int main() {

    // UnitTest::Foundation::TestInt64::RunAll(); 
    // UnitTest::Foundation::TestFixedString::RunAll();
    // UnitTest::Chrono::TestDateTime::RunAll();
    // UnitTest::Foundation::TestString::RunAll();

    const char* v = "汉子x";
    std::cout << strlen(v) << std::endl;

    const wchar_t* v2 = L"汉子x";
    std::cout << wcslen(v2) << std::endl;


    const char ByteFlagOnStack = 0x0011;

    std::string v3 = "汉子x";
    

    Float64 val2 = 90;

    Float64 val1 = 80;

    std::cout << (val1 == val2).ToString() << std::endl;

    return 0;
}
