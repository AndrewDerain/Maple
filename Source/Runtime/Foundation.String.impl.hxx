#pragma once
#include <Runtime/Foundation.String.hxx>
#include <Runtime/Foundation.Int64.hxx>
#include <Runtime/Foundation.Bool.hxx>


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_FOUNDATION_BEGIN
String::String() {
}


String::~String() {
    if(!_Storage.IsOnStack)
        _Storage.Heap.Deallocate();
}


_FANTASIA_INLINE 
Int64 
String::MaxCapicity() {
    return std::numeric_limits<std::uint16_t>::max();    
}


_FANTASIA_INLINE 
String::String(const char* value) {
    _Assign(value);
}


_FANTASIA_INLINE 
Int64
String::Length() const {

    if(_Storage.IsOnStack)
        return _Storage.Stack.Length;
    else 
        return _Storage.Heap.Length;
}
/*
    "cmake.buildDirectory" :"${workspaceFolder}/.buildcache"
*/

_FANTASIA_INLINE 
String::operator char const* const() const noexcept {

    if(_Storage.IsOnStack)
        return _Storage.Stack.StoredValue;
    else 
        return _Storage.Heap.StoredValue;
}


_FANTASIA_INLINE 
void 
String::_Assign(const char* value) {

    if(nullptr == value) {
        if(!_Storage.IsOnStack) {
            _Storage.Heap.Reset();
        }

        _Storage.Stack.Reset();
        _Storage.IsOnStack = true;

        return;
    }

    std::uint16_t len = strlen(value);
    if(len < StackMaxCapicity) {
        if(!_Storage.IsOnStack) {
            _Storage.Heap.Reset();
        }
        
        _Storage.Stack.Set(value, len);
        _Storage.IsOnStack = true;
    }
    else {
        _Storage.Heap.Set(value, len);
        _Storage.IsOnStack = false;
    }
}


_FANTASIA_INLINE
void 
String::Storage::StackStore::Reset() {
    Length = 0;
    StoredValue[0] = '\0';
}


_FANTASIA_INLINE
void 
String::Storage::StackStore::Set(const char* value, char len) {
    strcpy(StoredValue, value);
    Length = len;
}


_FANTASIA_INLINE
void String::Storage::
HeapStore::Reset() {

    Length = 0;
    Capicity = 0;

    Deallocate();
}


void String::Storage::
HeapStore::Set(const char* value, std::uint16_t len) {

    if(Capicity > len) {
        strcpy(StoredValue, value);
        Length = len;
    }
    else {
        if(StoredValue) {
            delete StoredValue;
        }

        Length = len;
        Capicity = len + 1;
        StoredValue = new char[Capicity];

        strcpy(StoredValue, value);
    }
}


void String::Storage::
HeapStore::Deallocate() {

    if(StoredValue) {
       delete StoredValue;
       StoredValue = nullptr;
    }
}
_FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)
