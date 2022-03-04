
#include "Runtime/UnitTest.Foundation.hpp"
#include "Runtime/UnitTest.Chrono.hpp"
#include "Runtime/Basic.Macro.Trace.hxx"

#include <string>
#include <iostream>
#include <vector>


using namespace Fantasia;

int main() {

    std::cout << std::boolalpha 
        << std::is_trivial_v<Float64> << std::endl;
    try
    {
        auto s = new int[9];
        auto m = s[19] = 99;
        std::cerr << m << "[hhh xxx exc]\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "[exc]\n";
    }
    catch(...){

        std::cerr << "[xxx exc]\n";
    }
    
    UnitTest::Foundation::TestString::RunAll();

    //std::is_standard_layout_v
    std::string a;
    a.append("sd");
    std::cout << a << std::endl;
    return 0;
}
