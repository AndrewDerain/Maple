
#include "Fantasia/Runtime/Foundation/String.h"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Foundation
{

#pragma region StringHeapStorage

    __decorate(Fantasia, api)
    void StringHeapStorage::Assign(const char* value, std::uint16_t len) {

        if(_Capacity > len) {
            strcpy(_StoredValue, value);
            _Length = len;
        }
        else {
            if(_StoredValue) {
                delete _StoredValue;
            }

            _Length      = len;
            _Capacity    = len + 1 + 50;
            _StoredValue = new char[_Capacity];

            strcpy(_StoredValue, value);
        }

        _IsOnStack = false;
    }


    __decorate(Fantasia, api)
    void StringHeapStorage::Deallocate() {

        if(_StoredValue) {
            delete _StoredValue;
            _StoredValue = nullptr;
        }
    }


    void StringHeapStorage::Extend(std::int64_t size) {

        int64_t capacity    = _Capacity + size + 50;
        char*   memory      = new char[capacity];

        memcpy(memory, _StoredValue, _Length + 1);
        delete _StoredValue;

        Replace(memory, _Length, capacity);
    }

#pragma endregion // StringHeapStorage




#pragma region String

    __decorate(Fantasia, api) 
    void String::_MoveToHeap(int64_t reserved_space) {
        
        int64_t capacity    = reserved_space + 14 * 5;
        char*   memory      = new char[capacity];
        Int64   len         = _Storage.Stack().Length();
        
        memcpy(memory,
               _Storage.Stack().Data(),
               _Storage.Stack().Capacity());

        _Storage.Heap().Initialize();
        _Storage.Heap().Replace(memory, len, capacity);
    }


    __decorate(Fantasia, api)
    void String::_CatenateOnHeap(const char* value, int64_t len) {

        if(_Storage.Heap().Capacity() <= _Storage.Heap().Length() + len) {
            _Storage.Heap().Extend(len);
        }

        _Storage.Heap().Catenate(value, len);
    }

#pragma endregion // String

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)
