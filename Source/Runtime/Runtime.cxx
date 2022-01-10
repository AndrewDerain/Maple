// runtime.cpp: 定义应用程序的入口点。
//

#include "Runtime.hxx"

#include <iostream>
#include <memory>

#include <_CompileTime/MacroFunction.hxx>
#include <Foundation/Foundation.hxx>

using namespace Fantasia::Foundation;

int main()
{
    Int64 j;

    Object* o = new Object;

    std::cout << (o == nullptr) << std::endl;

    auto V = _FANTASIA_MF_ARG_COUNT(3);

    return 0;
}
