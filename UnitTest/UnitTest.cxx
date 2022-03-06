
#include "Runtime/UnitTest.Foundation.hpp"
#include "Runtime/UnitTest.Chrono.hpp"
#include "Runtime/Basic.Macro.Trace.hxx"

#include <string>
#include <iostream>
#include <vector>


using namespace Fantasia;

int main() {

    
    UnitTest::Foundation::TestString::RunAll();
	UnitTest::Foundation::TestInt64::RunAll();

    return 0;
}
