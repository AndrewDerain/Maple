#pragma once
#include <Fantasia.Basic.Macro.Function.hxx>
#include <Fantasia.Basic.CodeLang.CXX.hxx>


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_DETAIL_BEGIN
_FANTASIA_DETAIL_END

_FANTASIA_BEGIN
namespace Foundation 
{
//fundamental

#define _FANTASIA_FUNDAMENTAL_OPERATERS(_WRAPPER, _BASALTYPE) \
            _WRAPPER(const _BASALTYPE& val) { \
                _StoreVal = val; \
            } \
            _WRAPPER(const _BASALTYPE&& val) { \
                _StoreVal = move(val); \
            } \
            

class _WRAPPER
{
public:
    using _BASALTYPE = uint32_t;

    _BASALTYPE _StoredValue;

    _WRAPPER() = default;
    ~_WRAPPER() = default;

    _WRAPPER(const _WRAPPER& ano) :
        _StoredValue(ano._StoredValue){}

    _WRAPPER(const _WRAPPER&& ano) :
        _StoredValue(move(ano._StoredValue)) {}

    _WRAPPER(const _BASALTYPE& val) :
        _StoredValue(val) {}
    
    _WRAPPER(const _BASALTYPE&& val) :
        _StoredValue(move(val)) {}

    
};

}
_FANTASIA_END
#pragma pack(pop)
#pragma warning(pop)
