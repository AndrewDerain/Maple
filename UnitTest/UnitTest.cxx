
#include "Runtime/UnitTest.Foundation.hpp"

#include <iostream>


int main() {

    UnitTest::Foundation::TestInt64::RunAll(); 
    UnitTest::Foundation::TestFixedString::RunAll();
    
    return 0;
}
