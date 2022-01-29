#pragma once
#include "Basic.CodeLang.CXX.hxx"
#include "Basic.Macro.ProjectDefine.hxx"


_FANTASIA_BEGIN

class Tracer
{
public:
    Tracer(std::string method) {
        _Method = method;
        std::cout << _Method << " -- -> start" << std::endl;
    }

    ~Tracer() {
        std::cout << _Method << " -- -> end" << std::endl << std::endl;
    }

private:
    std::string _Method;
};


#ifdef _FANTASIA_TRACE
#    define TraceScope Fantasia::Tracer ___Tracer(__FUNCTION__);
#    define TraceWriteVar(_Val) \
        std::cout << " |  Var [" << #_Val << "] = [" << _Val << "]" << std::endl;
#else
#    define TraceScope
#    define TraceWriteVar(_Val) 
#endif

_FANTASIA_END
