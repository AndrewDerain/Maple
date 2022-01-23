#pragma once
#include "Foundation.Int64.decl.hxx"
#include "Foundation.Float64.decl.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_FOUNDATION_BEGIN

_FANTASIA_INLINE 
Float64::Float64(const Float64& other) noexcept :
    _StoredValue(other._StoredValue) {
}

_FANTASIA_INLINE 
Float64::Float64(Float64&& other) noexcept: 
    _StoredValue(move(other._StoredValue)) {
}

_FANTASIA_INLINE 
Float64::Float64(double const& value) noexcept :
    _StoredValue(value) {
}

_FANTASIA_INLINE 
Float64::Float64(double&& value) noexcept :
    _StoredValue(move(value)) {
}

_FANTASIA_INLINE 
Float64::operator double() const noexcept {
    return _StoredValue;
}

_FANTASIA_INLINE 
Float64::operator double&() noexcept {
    return _StoredValue;
}

_FANTASIA_INLINE Float64& 
Float64::operator=(const Float64& other) {
    _StoredValue = other._StoredValue;
    return *this;
}

_FANTASIA_INLINE Float64& 
Float64::operator=(Float64&& other) {
    _StoredValue = move(other._StoredValue);
    return *this;
}

_FANTASIA_INLINE Float64& 
Float64::operator=(const double& value) {
    _StoredValue = value;
    return *this;
}

_FANTASIA_INLINE Float64& 
Float64::operator=(double&& value) {
    _StoredValue = move(value);
    return *this;
}

_FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)
