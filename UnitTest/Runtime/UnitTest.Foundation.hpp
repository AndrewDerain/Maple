
#include <Runtime/Basic.Tracer.hxx>
#include <Runtime/Basic.Macro.Trace.hxx>
#include <Fantasia.Foundation>
#include <iostream>

namespace UnitTest::Foundation
{
    using namespace Fantasia; //::Foundation;
    

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
            //TraceScope;

            std::string c;
            IntValue = 56;

            Int64 Val0 {12};
            Int64 Val1(24);
            Int64 Val2(Val0);

            Val0 = Val1 + Val2 * IntValue / Val1 - Val2 - 1;

            Float64 Vala = 56.77;
            Float64 Valb = 3.4;

            Val0 = Vala + Val2;

            bool larger = Vala > Valb;
            
            // TraceWriteVar(Vala);
            // TraceWriteVar(Val2);
            // TraceWriteVar(Val0);

            Cop c1;
            c1.val1 = 9;
            c1.h = 88;

            Cop c2;
            c2 = c1;
            // TraceWriteVar(c2.val1)
            // TraceWriteVar(c2.h)
            
            Int64 Val7, Val8;
            return 0;
        }
    }


    namespace TestFixedString
    {
        FixedString<26> Str0;
        String cstr;

        int RunAll(){
            //TraceScope

            Str0 = "io23";

            Str0 = "j";

            Str0 = "123456789";

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

    namespace TestString
    {
        const char * content = "This is a long text , for string test. 2021-02-21 17:34:21! ";
        String val1;
        String val2;


        void Append() {
            ___FANTASIA_TRACE_SCOPE

            val1.Append("1-");
            val1.Append("334-").Append(content);

            ___FANTASIA_TRACE_WRITE_VAR(val1);



        }


        int RunAll(){
            
            Append();

            return 3;
        }

    }

    namespace TestArray
    {
        Array<double, 4> arr0;
        Array<double, 4> arr1;
        
        int RunAll() 
        {
            arr0 = arr1;

            for(const auto val: arr0) 
            {

            }

            return 0;
        }
    }
}
