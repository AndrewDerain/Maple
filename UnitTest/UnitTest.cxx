
#include "Runtime/UnitTest.Foundation.hpp"
#include "Runtime/UnitTest.Chrono.hpp"

#include <iostream>


int main() {

    //UnitTest::Foundation::TestInt64::RunAll(); 
    //UnitTest::Foundation::TestFixedString::RunAll();
    
    UnitTest::Chrono::TestDateTime::RunAll();


    return 0;
}
