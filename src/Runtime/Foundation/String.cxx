
#include "Maple/Runtime/Foundation/String.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
{

#pragma region StringHeapStorage

    MapleDeco(Maple, Runtime, Api)
    void StringHeapStorage::Assign(const char* value, uint64_t len) {

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


    MapleDeco(Maple, Runtime, Api)
    void StringHeapStorage::Deallocate() {

        if(_StoredValue) {
            delete _StoredValue;
            _StoredValue = nullptr;
        }
    }


    MapleDeco(Maple, Runtime, Api)
    void StringHeapStorage::Catenate(const char* value, uint64_t len) {

        Algorithm::CatenateString(
                _StoredValue,
                _Length,
                _Capacity,
                value,
                len);
    }


    MapleDeco(Maple, Runtime, Api)
    void StringHeapStorage::Extend(uint64_t size) {

        uint64_t capacity   = _Capacity + size + 50;
        char*   memory      = new char[capacity];

        memcpy(memory, _StoredValue, _Length + 1);
        delete _StoredValue;

        Replace(memory, _Length, capacity);
    }

#pragma endregion // StringHeapStorage


#pragma region String

    MapleDeco(Maple, Runtime, Api)
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


    MapleDeco(Maple, Runtime, Api)
    void String::_CatenateOnHeap(const char* value, int64_t len) {

        if(_Storage.Heap().Capacity() <= _Storage.Heap().Length() + len) {
            _Storage.Heap().Extend(len);
        }

        _Storage.Heap().Catenate(value, len);
    }

#pragma endregion // String

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)
