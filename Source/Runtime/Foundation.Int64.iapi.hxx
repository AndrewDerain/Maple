﻿#pragma once
#include <Runtime/Foundation.Float64.hxx>
#include <Runtime/Foundation.String.hxx>
#include <Runtime/Foundation.Int64.hxx>


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_DETAIL_BEGIN

__api_inline 
Int64 
Int64::Max() noexcept {
    return std::numeric_limits<int64_t>::max();
};


__api_inline 
Int64 
Int64::Min() noexcept {
    return std::numeric_limits<int64_t>::min();
}


__api_inline  __api_constexpr
Int64::Int64(const int32_t value) noexcept:
    _StoredValue(value) {
}


__api_inline  __api_constexpr
Int64::Int64(const int64_t value) noexcept:
    _StoredValue(value) {
}


__api_inline 
Int64::Int64(const char value) noexcept { 
    _StoredValue = value; 
}


__api_inline 
Int64::Int64(const short value) noexcept {
    _StoredValue = value;
}


__api_inline 
Int64::Int64(const unsigned short value) noexcept {
    _StoredValue = value;
}


__api_inline __api_constexpr
Int64::operator int64_t const&() const noexcept {
    return _StoredValue;
}


__api_inline __api_constexpr
Int64::operator int64_t&() noexcept {
    return _StoredValue;
}


__api_inline Int64& 
Int64::operator=(const int32_t& value) noexcept {
    _StoredValue = value;
    return *this;
}


__api_inline Int64& 
Int64::operator=(int32_t&& value) noexcept {
    _StoredValue = std::move(value);
    return *this;
}


__api_inline 
const Float64& Int64::
operator=(const Float64& other) noexcept {
    _StoredValue = (double)other;
    return other;
}

__FANTASIA_FOUNDATION_DETAIL_END
#pragma pack(pop)
#pragma warning(pop)
