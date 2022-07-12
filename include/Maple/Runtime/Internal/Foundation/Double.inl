#pragma once
#include "../../Foundation/Bool.hxx"
#include "../../Foundation/Int64.hxx"
#include "../../Foundation/String.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
{

    inline constexpr
    Double Double::Max() noexcept {
        return std::numeric_limits<double>::max();
    }


    inline constexpr
    Double Double::Min() noexcept {
        return std::numeric_limits<double>::min();
    }


    inline constexpr
    Double Double::Epsilon() noexcept {
        return std::numeric_limits<double>::epsilon();
    }


    inline constexpr
    Double::Double(const double value) noexcept:
        _StoredValue(value) {
    }


    inline constexpr
    Double::Double(const int32_t value) noexcept:
        _StoredValue(value) {
    }


    inline constexpr
    Double::Double(const uint32_t value) noexcept:
        _StoredValue(value) {
    }


    inline constexpr
    Double::Double(const int64_t value) noexcept:
        _StoredValue(value) {
    }


    inline constexpr
    Double::Double(const uint64_t value) noexcept:
        _StoredValue(value) {
    }


    inline constexpr
    Double::operator double const&() const noexcept {
        return _StoredValue;
    }


    inline constexpr
    Double::operator double&() noexcept {
        return _StoredValue;
    }


    inline constexpr
    Double& Double::operator=(const double value) {
        _StoredValue = value;
        return *this;
    }


    inline constexpr
    Bool operator>(Double& left, Double& right) {
        double dif = (double)left - (double)right;
        return dif > Double::Epsilon();
    }


    inline constexpr
    Bool operator<(Double& left, Double& right) {
        double dif = (double)left - (double)right;
        return dif > Double::Epsilon();
    }


    inline constexpr
    Bool operator==(Double& left, Double& right) {
        double dif = (double)left - (double)right;
        return dif >= Double::Epsilon() || dif <= Double::Epsilon();
    }


    inline constexpr
    Bool operator!=(Double& left, Double& right) {
        return !(left == right);
    }


    inline constexpr
    Bool operator>=(Double& left, Double& right) {
        return left > right || left == right;
    }


    inline constexpr
    Bool operator<=(Double& left, Double& right) {
        return left < right || left == right;
    }

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)
