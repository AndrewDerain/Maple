#pragma once
#include "Basic.CodeLang.CXX.hxx"
#include "Basic.Macro.Preconfig.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
___FANTASIA_DETAIL_BEGIN

class Memory
{
public:
    template<typename _T>
    _T* Allocate() {
        return new _T();
    }


    

protected:
    static void* _Allocate() {}
};

___FANTASIA_DETAIL_END
#pragma pack(pop)
#pragma warning(pop)
