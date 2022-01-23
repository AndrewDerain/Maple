
#include <Runtime/Foundation.Int64.hxx>
#include <Runtime/Foundation.Float64.hxx>
#include <iostream>

namespace UnitTest::Foundation::TestInt64
{
    using namespace Fantasia::Foundation;
    
    Int64 IntValue;
    Float64 FloatValue;

    int RunAll() {
        
        std::string c;
        IntValue = 56;

        Int64 Val0 = 12;
        Int64 Val1(24);
        Int64 Val2(Val0);

        Val0 = Val1 + Val2 * IntValue / Val1 - Val2;

        Float64 Vala = 56.77;
        Float64 Valb = 3.4;

        Val0 = Vala + Val2;

        _PrintVar(Vala);
        _PrintVar(Val2);
        _PrintVar(Val0);

        return 0;
    }

}
