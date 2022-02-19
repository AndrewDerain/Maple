#pragma once
#include <Runtime/Foundation.Bool.hxx>
#include <Runtime/Foundation.String.hxx>


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_FOUNDATION_BEGIN

_FANTASIA_INLINE 
Bool::Bool(const Bool& other) noexcept :
    _StoredValue(other._StoredValue) {
}

_FANTASIA_INLINE 
Bool::Bool(Bool&& other) noexcept :
    _StoredValue(std::move(other)) {
}

_FANTASIA_INLINE 
Bool::Bool(const bool& value) noexcept :
    _StoredValue(value) {
}

_FANTASIA_INLINE 
Bool::Bool(bool&& value) noexcept:
    _StoredValue(value) {
};

_FANTASIA_INLINE 
String
Bool::ToString() {
    if(_StoredValue) 
        return "true";
    else
        return "false";
}

_FANTASIA_INLINE 
Bool::operator bool const&() const noexcept {
    return _StoredValue;
}

_FANTASIA_INLINE 
Bool::operator bool&() noexcept {
    return _StoredValue;
}

_FANTASIA_INLINE const Bool& 
Bool::operator=(const Bool& other) noexcept {
    _StoredValue = other._StoredValue;
    return *this;
}

_FANTASIA_INLINE const Bool&
Bool::operator=(Bool&& other) noexcept {
    _StoredValue = other._StoredValue;
    return *this;
}

_FANTASIA_INLINE const Bool& 
Bool::operator=(const bool& value) noexcept {
    _StoredValue = value;
    return *this;
}

_FANTASIA_INLINE const Bool& 
Bool::operator=(bool&& value) noexcept {
    _StoredValue = std::move(value);
    return *this;
}

_FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)
