// runtime.cpp: 定义应用程序的入口点。
//

#include "Runtime.hxx"

#include <iostream>
#include <memory>

#include <_CompileTime/MacroFunction.hxx>
#include <Foundation/BaseOn.hxx>

class B : Fantasia::Foundation::BaseOn<int>
{

};


int main()
{

    auto V = _FANTASIA_MF_ARG_COUNT(3);


    return 0;
}
