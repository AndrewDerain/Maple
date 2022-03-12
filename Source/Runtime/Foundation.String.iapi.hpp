#pragma once
#include <Runtime/Foundation.String.hxx>
#include <Runtime/Foundation.Int64.hxx>
#include <Runtime/Foundation.Bool.hxx>


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
__FANTASIA_FOUNDATION_DETAIL_BEGIN

__api_inline __api_constexpr
Int64 
String::MaxCapicity() {
    return std::numeric_limits<std::uint16_t>::max();    
}


__api_inline __api_constexpr
Property Int64
String::Length() const {

    if(_Storage.IsOnStack)
        return _Storage.Stack.Length;
    else 
        return _Storage.Heap.Length;
}


 __api_inline __api_constexpr
Property Int64 
String::Capicity() const {
    
    if(_Storage.IsOnStack)
        return Int64(_StackMaxCapicity);
    else 
        return _Storage.Heap.Capicity;
}


__api_inline 
String::String() {
    _Storage.IsOnStack = true;
    _Storage.Stack.Reset();
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


__api_inline __api_constexpr
String& 
String::Append(const String& value) {
    _Append(value, value.Length());
    return *this;
}


__api_inline __api_constexpr
String& 
String::Append(const Bool& value) {
    Append(value.ToString());
    return *this;
}


__api_inline __api_constexpr
String& 
String::Append(const char* value) {
    if(value) {
        _Append(value, strlen(value));
    }
    return *this;
}


__api_inline __api_constexpr
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


__api_inline
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


__api_inline __api_constexpr
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
    if(len < _StackMaxCapicity) {
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


__api_inline __api_constexpr
void 
String::_Append(const char* value, int64_t len) {

    if(_Storage.IsOnStack) {
        if(len < _StackMaxCapicity - _Storage.Stack.Length) {
            _AppendOnStack(value, len);
        }
        else {
            _MoveToHeap(len);
            _AppendOnHeap(value, len);
        }
    }
    else {
        _AppendOnHeap(value, len);
    }
}

__api_inline
void String::_AppendOnStack(const char* value, int64_t len) {
    strcat(_Storage.Stack.StoredValue, value);
    _Storage.Stack.Length += len;
}

__FANTASIA_FOUNDATION_DETAIL_END
#pragma pack(pop)
#pragma warning(pop)
