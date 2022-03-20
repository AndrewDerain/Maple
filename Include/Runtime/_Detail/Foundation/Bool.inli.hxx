#pragma once
#include <Runtime/Foundation.Bool.hxx>
#include <Runtime/Foundation.String.hxx>


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Foundation
{

    __api_inline __api_constexpr
    Bool::Bool(bool value) noexcept:
        _StoredValue(value) {
    };


    __api_inline __api_constexpr
    String Bool::ToString() const {
        if(_StoredValue) 
            return "true";
        else
            return "false";
    }


    __api_inline __api_constexpr
    Bool::operator bool const&() const noexcept {
        return _StoredValue;
    }


    __api_inline __api_constexpr
    Bool::operator bool&() noexcept {
        return _StoredValue;
    }


    __api_inline __api_constexpr
    Bool& 
    Bool::operator=(bool value) noexcept {
        _StoredValue = value;
        return *this;
    }

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)

#ifdef __FANTASIA_OPTION_HEADER_ONLY
#    include "../../../Source/Runtime/Foundation.Bool.impl.cxx"
#endif
