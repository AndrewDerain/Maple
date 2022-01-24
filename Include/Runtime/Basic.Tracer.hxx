#pragma once
#include "Basic.CodeLang.CXX.hxx"
#include "Basic.Macro.ProjectDefine.hxx"


_FANTASIA_BEGIN

class Tracer
{
public:
    Tracer(string method) {
        _Method = method;
        cout << _Method << " -- -> start" << endl;
    }

    ~Tracer() {
        cout << _Method << " -- -> end" << endl << endl;
    }

private:
    string _Method;
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
