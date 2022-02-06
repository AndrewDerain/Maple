
#include "Runtime/UnitTest.Foundation.hpp"
#include "Runtime/UnitTest.Chrono.hpp"

#include <string>
#include <iostream>


int main() {

    UnitTest::Foundation::TestInt64::RunAll(); 
   /* UnitTest::Foundation::TestFixedString::RunAll();
    */
    UnitTest::Chrono::TestDateTime::RunAll();

    UnitTest::Foundation::TestString::RunAll();

    // char8_t *c = u8"汗";
    // TraceWriteVar((c[0]))
    return 0;
}
