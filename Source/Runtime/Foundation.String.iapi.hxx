#pragma once
#include <Runtime/Foundation.String.hxx>
#include <Runtime/Foundation.Int64.hxx>
#include <Runtime/Foundation.Bool.hxx>


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_DETAIL_BEGIN

__api_inline
Int64 
String::MaxCapicity() {
    return std::numeric_limits<std::uint16_t>::max();    
}


__api_inline __api_constexpr
String::String() {
}


__api_inline __api_constexpr
String::~String() {
    if(!_Storage.IsOnStack)
        _Storage.Heap.Deallocate();
}


__api_inline __api_constexpr
String::String(const char* value) {
    _Assign(value);
}


__api_inline 
Int64
String::Length() const {

    if(_Storage.IsOnStack)
        return _Storage.Stack.Length;
    else 
        return _Storage.Heap.Length;
}


__api_inline 
String::operator char const* const() const noexcept {

    if(_Storage.IsOnStack)
        return _Storage.Stack.StoredValue;
    else 
        return _Storage.Heap.StoredValue;
}


__api_inline
void 
String::Storage::StackStore::Reset() {
    Length = 0;
    StoredValue[0] = '\0';
}


__api_inline __api_constexpr
void 
String::Storage::StackStore::Set(const char* value, char len) {
    strcpy(StoredValue, value);
    Length = len;
}


__api_inline
void 
String::Storage::HeapStore::Reset() {

    Length = 0;
    Capicity = 0;

    Deallocate();
}


__FANTASIA_FOUNDATION_DETAIL_END
#pragma pack(pop)
#pragma warning(pop)
