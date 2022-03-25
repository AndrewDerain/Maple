#pragma once
#include "../../Foundation/Bool.hxx"
#include "../../Foundation/Int64.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Foundation
{

    inline constexpr
    Float64 Float64::Max() noexcept {
        return std::numeric_limits<double>::max();
    }


    inline constexpr
    Float64 Float64::Min() noexcept {
        return std::numeric_limits<double>::min();
    }


    inline constexpr
    Float64 Float64::Epsilon() noexcept {
        return std::numeric_limits<double>::epsilon();
    }


    inline constexpr
    Float64::Float64(double value) noexcept:
        _StoredValue(value) {
    }


    inline constexpr
    Float64::operator double const&() const noexcept {
        return _StoredValue;
    }


    inline constexpr
    Float64::operator double&() noexcept {
        return _StoredValue;
    }


    inline constexpr
    Float64& Float64::operator=(double value) {
        _StoredValue = value;
        return *this;
    }


    inline constexpr
    Bool operator>(Float64& left, Float64& right) {
        auto dif = (double)left - (double)right;
        return fabs(dif) > std::numeric_limits<double>::epsilon() && dif > 0;
    }


    inline constexpr
    Bool operator<(Float64& left, Float64& right) {
        auto dif = (double)left - (double)right;
        return fabs(dif) > std::numeric_limits<double>::epsilon() && dif < 0;
    }


    inline constexpr
    Bool operator==(Float64& left, Float64& right) {
        auto dif = (double)left - (double)right;
        return fabs(dif) <= std::numeric_limits<double>::epsilon();
    }


    inline constexpr
    Bool operator!=(Float64& left, Float64& right) {
        auto dif = (double)left - (double)right;
        return fabs(dif) > std::numeric_limits<double>::epsilon();
    }


    inline constexpr
    Bool operator>=(Float64& left, Float64& right) {

        auto dif = (double)left - (double)right;

        if (fabs(dif) <= std::numeric_limits<double>::epsilon())
            return true;
        else 
            return dif > 0;
    }


    inline constexpr
    Bool operator<=(Float64& left, Float64& right) {

        auto dif = (double)left - (double)right;

        if (fabs(dif) <= std::numeric_limits<double>::epsilon())
            return true;
        else 
            return dif < 0;
    }

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)
