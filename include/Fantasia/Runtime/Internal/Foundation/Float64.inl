#pragma once
#include "../../Foundation/Bool.hxx"
#include "../../Foundation/Int64.hxx"
#include "../../Foundation/String.hxx"


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
    Float64::Float64(const double value) noexcept:
        _StoredValue(value) {
    }


    inline constexpr
    Float64::Float64(const int32_t value) noexcept:
        _StoredValue(value) {
    }


    inline constexpr
    Float64::Float64(const uint32_t value) noexcept:
        _StoredValue(value) {
    }


    inline constexpr
    Float64::Float64(const int64_t value) noexcept:
        _StoredValue(value) {
    }


    inline constexpr
    Float64::Float64(const uint64_t value) noexcept:
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
    Float64& Float64::operator=(const double value) {
        _StoredValue = value;
        return *this;
    }


    inline constexpr
    Bool operator>(Float64& left, Float64& right) {
        double dif = (double)left - (double)right;
        return dif > Float64::Epsilon();
    }


    inline constexpr
    Bool operator<(Float64& left, Float64& right) {
        double dif = (double)left - (double)right;
        return dif > Float64::Epsilon();
    }


    inline constexpr
    Bool operator==(Float64& left, Float64& right) {
        double dif = (double)left - (double)right;
        return dif >= Float64::Epsilon() || dif <= Float64::Epsilon();
    }


    inline constexpr
    Bool operator!=(Float64& left, Float64& right) {
        return !(left == right);
    }


    inline constexpr
    Bool operator>=(Float64& left, Float64& right) {
        return left > right || left == right;
    }


    inline constexpr
    Bool operator<=(Float64& left, Float64& right) {
        return left < right || left == right;
    }

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)
