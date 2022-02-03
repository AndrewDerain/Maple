
#include <Runtime/Basic.Tracer.hxx>
#include <Fantasia.Foundation>
#include <iostream>

namespace UnitTest::Foundation
{
    using namespace Fantasia::Foundation;
    

    namespace TestInt64
    {
        Int64 IntValue;
        Float64 FloatValue;

        struct Cop
        {
            Int64 val1;
            double h;
        };
        

        int RunAll() {
            TraceScope;

            std::string c;
            IntValue = 56;

            Int64 Val0 = 12;
            Int64 Val1(24);
            Int64 Val2(Val0);

            Val0 = Val1 + Val2 * IntValue / Val1 - Val2;

            Float64 Vala = 56.77;
            Float64 Valb = 3.4;

            Val0 = Vala + Val2;

            bool larger = Vala > Valb;
            
            TraceWriteVar(Vala);
            TraceWriteVar(Val2);
            TraceWriteVar(Val0);

            Cop c1;
            c1.val1 = 9;
            c1.h = 88;

            Cop c2;
            c2 = c1;
            TraceWriteVar(c2.val1)
            TraceWriteVar(c2.h)
            
            return 0;
        }
    }


    namespace TestFixedString
    {
        FixedString<26> Str0;


        int RunAll(){
            TraceScope

            Str0 = "io23";
            TraceWriteVar(Str0.data())
            TraceWriteVar(Str0.Length())

            Str0 = "j";
            TraceWriteVar(Str0.data())
            TraceWriteVar(Str0.Length())

            Str0 = "123456789";
            TraceWriteVar(Str0.data())
            TraceWriteVar(Str0.Length())
            return 0;
        }
    }


    namespace TestBool
    {
        Bool Val0;
        Bool Val1(true);
        Bool Val2(Val0);

        int RunAll(){
            Val0 = Val1;
            Val2 = Val0 = Val1;

            auto f = Val0 == Val2;
            Val0 = 3 == 4;
            return 3;
        }
    }
}
