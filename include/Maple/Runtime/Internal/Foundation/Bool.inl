#pragma once
#include "../../Foundation/Int64.hxx"
#include "../../Foundation/Float64.hxx"
#include "../../Foundation/String.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
{

    inline constexpr
    Bool::Bool(const bool value) noexcept:
        _StoredValue(value) {
    };


    inline constexpr
    String Bool::ToString() const {

        if(_StoredValue)
            return "true";
        else
            return "false";
    }


    inline constexpr
    Bool::operator bool const&() const noexcept {
        return _StoredValue;
    }


    inline constexpr
    Bool::operator bool&() noexcept {
        return _StoredValue;
    }


    inline constexpr
    Bool& Bool::operator=(const bool value) noexcept {
        _StoredValue = value;
        return *this;
    }

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)
