﻿
#include <Runtime/Basic.Tracer.hxx>
#include <Fantasia.Chrono>
#include <iostream>

namespace UnitTest::Chrono
{
    using namespace Fantasia::Chrono;
    
    namespace TestDateTime
    {
        DateTime dt1;

        int RunAll()
        {
            char str[]="20210223 13:44:54";
            dt1 = str;
            
            return 0;
        }
    }
}
