#ifdef __FANTASIA_OPTION_HEADER_ONLY
#    pragma once
#endif
#include <Runtime/_Detail/Foundation/String.iapi.hpp>


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Foundation
{

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
    void String::_MoveToHeap(int64_t reserved_space) {
        
        int64_t HeapSize    = reserved_space + _ReservedSpaceCapicity;
        char*   StrVal      = new char[HeapSize];
        auto    Len         = _Storage.Stack.Length;
        
        memcpy(StrVal, _Storage.Stack.StoredValue, _StackMaxCapicity);

        _Storage.Heap.IsOnStack     = false;
        _Storage.Heap.Length        = Len;
        _Storage.Heap.Capicity      = HeapSize;
        _Storage.Heap.StoredValue   = StrVal;
    }


    __api
    void String::_AppendOnHeap(const char* value, int64_t len) {

        if(_Storage.Heap.Capicity <= _Storage.Heap.Length + len) {
            int64_t NewCapicity = _Storage.Heap.Length + len + _ReservedSpaceCapicity;
            char*   StrVal      = new char[NewCapicity];
            
            strcpy(StrVal, _Storage.Heap.StoredValue);
            delete _Storage.Heap.StoredValue;
            
            _Storage.Heap.StoredValue   = StrVal;
            _Storage.Heap.Capicity      = NewCapicity;
            _Storage.Heap.Length        = _Storage.Heap.Length + len;
        }
        else {
            strcat(_Storage.Heap.StoredValue, value);
            _Storage.Heap.Length = _Storage.Heap.Length + len;
        }
    }

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)
