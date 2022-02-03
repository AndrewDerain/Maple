﻿#pragma once
#include <Runtime/Foundation.Int64.hxx>
#include <Runtime/Foundation.Float64.hxx>

#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_FOUNDATION_BEGIN

_FANTASIA_INLINE Int64 
Int64::Max() {
    return std::numeric_limits<int64_t>::max();
};

_FANTASIA_INLINE Int64 
Int64::Min() {
    return std::numeric_limits<int64_t>::min();
}

_FANTASIA_INLINE 
Int64::Int64(const Int64& other) noexcept :
    _StoredValue(other._StoredValue) {
}

_FANTASIA_INLINE 
Int64::Int64(Int64&& other) noexcept :
    _StoredValue(std::move(other)) {
}

_FANTASIA_INLINE 
Int64::Int64(const int32_t& value) noexcept :
    _StoredValue(value) {
}

_FANTASIA_INLINE 
Int64::Int64(int32_t&& value) noexcept:
    _StoredValue(value) {
};

_FANTASIA_INLINE 
Int64::Int64(const int64_t& value) noexcept :
    _StoredValue(value) {
}

_FANTASIA_INLINE 
Int64::Int64(int64_t&& value) noexcept :
    _StoredValue(std::move(value)) {
}

_FANTASIA_INLINE 
Int64::operator int64_t() const noexcept {
    return _StoredValue;
}

_FANTASIA_INLINE 
Int64::operator int64_t&() noexcept {
    return _StoredValue;
}

_FANTASIA_INLINE const Int64& 
Int64::operator=(const Int64& other) noexcept {
    _StoredValue = other._StoredValue;
    TraceScope
    return *this;
}

_FANTASIA_INLINE const Int64&
Int64::operator=(Int64&& other) noexcept {
    _StoredValue = other._StoredValue;
    TraceScope
    return *this;
}

_FANTASIA_INLINE const Int64& 
Int64::operator=(const int32_t& value) noexcept {
    _StoredValue = value;
    return *this;
}

_FANTASIA_INLINE const Int64& 
Int64::operator=(int32_t&& value) noexcept {
    _StoredValue = std::move(value);
    return *this;
}

_FANTASIA_INLINE const Float64& 
Int64::operator=(const Float64& other) noexcept{
    _StoredValue = (double)other;
    return other;
}

_FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)
