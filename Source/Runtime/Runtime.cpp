// runtime.cpp: 定义应用程序的入口点。
//

#include "runtime.h"

#include <iostream>
#include <memory>

#include <_CompileTime/MacroFunction.h>
#include <Addon/DataType.h>


using namespace Fantasia;

int main()
{
    CounterEnviroment env;

    auto V = _FANTASIA_MF_ARG_COUNT(3);

    std::cout << env.ToString() << std::endl;

    return 0;
}
