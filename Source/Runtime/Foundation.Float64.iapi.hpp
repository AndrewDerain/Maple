#pragma once
#include <Runtime/Foundation.Int64.hxx>
#include <Runtime/Foundation.Float64.hxx>
#include <Runtime/Foundation.Bool.hxx>


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
__FANTASIA_FOUNDATION_DETAIL_BEGIN

__api_inline __api_constexpr
Float64
Float64::Max() noexcept {
    return std::numeric_limits<double>::max();
}

__api_inline __api_constexpr
Float64
Float64::Min() noexcept {
    return std::numeric_limits<double>::min();
}


__api_inline __api_constexpr
Float64
Float64::Epsilon() noexcept {
    return std::numeric_limits<double>::epsilon();
}


__api_inline __api_constexpr
Float64::Float64(double value) noexcept:
    _StoredValue(value) {
}


__api_inline __api_constexpr
Float64::operator double const&() const noexcept {
    return _StoredValue;
}


__api_inline __api_constexpr
Float64::operator double&() noexcept {
    return _StoredValue;
}


__api_inline __api_constexpr
Float64& 
Float64::operator=(double value) {
    _StoredValue = value;
    return *this;
}


__api_inline
Bool 
operator>(Float64& left, Float64& right) {
    auto dif = (double)left - (double)right;
    return fabs(dif) > std::numeric_limits<double>::epsilon() && dif > 0;
}


__api_inline
Bool 
operator<(Float64& left, Float64& right) {
    auto dif = (double)left - (double)right;
    return fabs(dif) > std::numeric_limits<double>::epsilon() && dif < 0;
}


__api_inline
Bool 
operator==(Float64& left, Float64& right) {
    auto dif = (double)left - (double)right;
    return fabs(dif) <= std::numeric_limits<double>::epsilon();
}


__api_inline
Bool 
operator!=(Float64& left, Float64& right) {
    auto dif = (double)left - (double)right;
    return fabs(dif) > std::numeric_limits<double>::epsilon();
}


__api_inline
Bool 
operator>=(Float64& left, Float64& right) {

    auto dif = (double)left - (double)right;

    if (fabs(dif) <= std::numeric_limits<double>::epsilon())
        return true;
    else 
        return dif > 0;
}


__api_inline
Bool 
operator<=(Float64& left, Float64& right) {

    auto dif = (double)left - (double)right;

    if (fabs(dif) <= std::numeric_limits<double>::epsilon())
        return true;
    else 
        return dif < 0;
}

__FANTASIA_FOUNDATION_DETAIL_END
#pragma pack(pop)
#pragma warning(pop)
