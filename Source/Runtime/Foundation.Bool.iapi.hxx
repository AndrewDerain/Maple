#pragma once
#include <Runtime/Foundation.Bool.hxx>
#include <Runtime/Foundation.String.hxx>


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_BEGIN

__api_inline 
Bool::Bool(const Bool& other) noexcept:
    _StoredValue(other._StoredValue) {
}


__api_inline 
Bool::Bool(Bool&& other) noexcept:
    _StoredValue(std::move(other)) {
}


__api_inline 
Bool::Bool(const bool& value) noexcept:
    _StoredValue(value) {
}


__api_inline 
Bool::Bool(bool&& value) noexcept:
    _StoredValue(value) {
};


__api_inline 
String Bool::ToString() {
    if(_StoredValue) 
        return "true";
    else
        return "false";
}


__api_inline 
Bool::operator bool const&() const noexcept {
    return _StoredValue;
}


__api_inline
Bool::operator bool&() noexcept {
    return _StoredValue;
}


__api_inline
const Bool& 
Bool::operator=(const Bool& other) noexcept {
    _StoredValue = other._StoredValue;
    return *this;
}


__api_inline
const Bool& 
Bool::operator=(Bool&& other) noexcept {
    _StoredValue = other._StoredValue;
    return *this;
}


__api_inline
const Bool& 
Bool::operator=(const bool& value) noexcept {
    _StoredValue = value;
    return *this;
}


__api_inline
const Bool& 
Bool::operator=(bool&& value) noexcept {
    _StoredValue = std::move(value);
    return *this;
}

__FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)
