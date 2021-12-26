// runtime.cpp: 定义应用程序的入口点。
//

#include "runtime.h"
#include <Enumerations/EmulationEnviroment.h>
#include <Enumerations/CounterConnectionProtocol.h>

#include <iostream>




int main()
{
    Fantasia::EmulationEnviroment e;
    Fantasia::CounterConnectionProtocol p;


    constexpr auto v = _FANTASIA_MACROFUNC_ARG_COUNT(t, y);


    cout << "Hello CMake." << p.ToString() << endl;
    return 0;
}
