#ifdef __FANTASIA_OPTION_HEADER_ONLY
#    pragma once
#endif
#include "Foundation.String.iapi.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_DETAIL_BEGIN

__api
void 
String::Storage::HeapStore::Set(const char* value, std::uint16_t len) {

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


__api
void String::Storage::HeapStore::Deallocate() {

    if(StoredValue) {
       delete StoredValue;
       StoredValue = nullptr;
    }
}


__api
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

__FANTASIA_FOUNDATION_DETAIL_END
#pragma pack(pop)
#pragma warning(pop)
