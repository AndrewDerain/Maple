﻿#pragma once
#include <Runtime/Foundation.Int64.hxx>
#include <Runtime/Foundation.Float64.hxx>
#include <Runtime/Foundation.Bool.hxx>


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
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


__api_inline
Float64::Float64(const Float64& other) noexcept:
    _StoredValue(other._StoredValue) {
}


__api_inline
Float64::Float64(Float64&& other) noexcept: 
    _StoredValue(std::move(other._StoredValue)) {
}


__api_inline __api_constexpr
Float64::Float64(double const& value) noexcept:
    _StoredValue(value) {
}


__api_inline __api_constexpr
Float64::Float64(double&& value) noexcept:
    _StoredValue(std::move(value)) {
}


__api_inline
Float64::operator double const&() const noexcept {
    return _StoredValue;
}


__api_inline
Float64::operator double&() noexcept {
    return _StoredValue;
}


__api_inline
Float64& 
Float64::operator=(const Float64& other) {
    _StoredValue = other._StoredValue;
    return *this;
}


__api_inline
Float64& 
Float64::operator=(Float64&& other) {
    _StoredValue = std::move(other._StoredValue);
    return *this;
}


__api_inline
Float64& 
Float64::operator=(const double& value) {
    _StoredValue = value;
    return *this;
}


__api_inline
Float64& 
Float64::operator=(double&& value) {
    _StoredValue = std::move(value);
    return *this;
}

__api_inline
Bool 
operator>(Float64& left, Float64& right) {
        TraceScope
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
