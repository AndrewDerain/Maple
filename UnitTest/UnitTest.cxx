
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
    
    //std::is_standard_layout_v

    return 0;
}
