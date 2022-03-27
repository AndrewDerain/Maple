#pragma once
#include "../../Foundation/Int64.hxx"
#include "../../Foundation/Bool.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Foundation
{

#pragma region StringStackStorage

    inline constexpr
    Int64 StringStackStorage::Capacity() noexcept {
        return _StackMaxCapacity;
    }


    inline constexpr
    Int64 StringStackStorage::ReservedSpaceCapacity() noexcept {
        return _ReservedSpaceCapacity;
    }


    inline constexpr
    Int64 StringStackStorage::MaxIntegerValueOnStack() noexcept {
        return _MaxIntegerValueOnStack;
    }


    inline constexpr
    Int64 StringStackStorage::MinIntegerValueOnStack() noexcept {
        return _MinIntegerValueOnStack;
    }


    inline constexpr
    Float64 StringStackStorage::MaxFloatValueOnStack() noexcept {
        return _MaxFloatValueOnStack;
    }


    inline constexpr
    Float64 StringStackStorage::MinFloatValueOnStack() noexcept {
        return _MinFloatValueOnStack;
    }


    inline constexpr
    StringStackStorage::StringStackStorage():
        _IsOnStack{true},
        _Length{0},
        _StoredValue{} {
    }


    inline constexpr
    Bool StringStackStorage::IsOnStack() const noexcept {
        return _IsOnStack;
    }


    inline constexpr
    Int64 StringStackStorage::Length() const {
        return _Length;
    }


    inline constexpr
    char* StringStackStorage::StoredValue() {
        return _StoredValue;
    }


    inline constexpr
    const char* StringStackStorage::StoredValue() const {
        return _StoredValue;
    }


    inline constexpr
    void StringStackStorage::Reset() {
        _Length         = 0;
        _StoredValue[0] = '\0';
        _IsOnStack      = true;
    }


    inline constexpr
    void StringStackStorage::Set(const char* value, int8_t len) {
        CopyString(_StoredValue, _StackMaxCapacity, value, len);
        _Length     = len;
        _IsOnStack  = true;
    }


    inline
    void StringStackStorage::Catenate(const char* value, int64_t len) {

        CatenateString(
                _StoredValue,
                _Length,
                _StackMaxCapacity,
                value,
                len);

        _Length += len;
    }


    inline constexpr
    void StringStackStorage::Catenate(const char* value, int64_t len) const {

        CatenateString(
                const_cast<char*>(_StoredValue),
                _Length,
                _StackMaxCapacity,
                value,
                len);

        *const_cast<std::int8_t*>(&_Length) = _Length + len;
    }

#pragma endregion // StringStackStorage




#pragma region StringHeapStorage

    inline constexpr
    Int64 StringHeapStorage::Capacity() const {
        return _Capacity;
    };


    inline constexpr
    Int64 StringHeapStorage::Length() const {
        return _Length;
    }


    inline constexpr
    const char* StringHeapStorage::StoredValue() const {
        return _StoredValue;
    }


    inline
    void StringHeapStorage::Initialize() {

        _Length         = 0;
        _Capacity       = 0;
        _StoredValue    = nullptr;
        _IsOnStack      = false;
    }


    inline
    void StringHeapStorage::Reset() {

        Deallocate();

        _Length     = 0;
        _Capacity   = 0;

        _IsOnStack  = false;
    }


    inline constexpr
    void StringHeapStorage::Replace(char* memory, std::uint16_t length, std::uint16_t capacity) {
        _StoredValue    = memory;
        _Length         = length;
        _Capacity       = capacity;
    }


    inline constexpr
    void StringHeapStorage::Catenate(const char* value, int64_t len) {

        CatenateString(
                _StoredValue,
                _Length,
                _Capacity,
                value,
                len);

        _Length += len;
    }

#pragma endregion // StringHeapStorage




#pragma region StringStorage

    inline constexpr
    StringHeapStorage& StringStorage::Heap() {
        return *(StringHeapStorage*)(&_MemorySpace);
    }


    inline constexpr
    const StringHeapStorage& StringStorage::Heap() const {
        return *(const StringHeapStorage*)(&_MemorySpace);
    }


    inline constexpr
    StringStackStorage& StringStorage::Stack() {
        return _MemorySpace;
    }


    inline constexpr
    const StringStackStorage& StringStorage::Stack() const {
        return _MemorySpace;
    }


    inline constexpr
    Bool StringStorage::IsOnStack() const {
        return Stack().IsOnStack();
    }

#pragma endregion // StringStorage




#pragma region String

    inline constexpr
    Int64 String::MaxCapacity() {
        return std::numeric_limits<std::uint16_t>::max();    
    }


    inline constexpr
    Int64 String::Length() const {

        if(_Storage.IsOnStack())
            return _Storage.Stack().Length();
        else 
            return _Storage.Heap().Length();
    }


    inline constexpr
    Int64 String::Capacity() const {
        
        if(_Storage.IsOnStack())
            return _Storage.Stack().Capacity();
        else 
            return _Storage.Heap().Capacity();
    }


    inline constexpr
    String::String() {
        _Storage.Stack().Reset();
    }


    inline constexpr
    String::~String() {
        if(!_Storage.IsOnStack())
            _Storage.Heap().Deallocate();
    }


    inline constexpr
    String::String(const char* value) {
        _Catenate(value);
    }


    inline constexpr
    String& String::Catenate(const String& value) {
        _Catenate(value, value.Length());
        return *this;
    }


    inline constexpr
    String& String::Catenate(const Bool& value) {
        Catenate(value.ToString());
        return *this;
    }


    inline
    String& String::Catenate(const char* value) {

        if(value) {
            _Catenate(value, CountStringLength(value));
        }

        return *this;
    }


    inline constexpr
    const String& String::Catenate(const char* value) const {

        if(value) {
            auto len = CountStringLength(value);

            if(_Storage.IsOnStack()) {
                if (len < _Storage.Stack().Capacity() - _Storage.Stack().Length()) {
                    _Storage.Stack().Catenate(value, len);
                }
            }
        }

        return *this;
    }


    template<Size _Size>
    inline constexpr
    String& String::Catenate(const char (&value)[_Size]) {
        _Catenate(value, CountStringLength(value));
        return *this;
    }


    inline constexpr
    String::operator char const* const() const noexcept {

        if(_Storage.IsOnStack())
            return _Storage.Stack().StoredValue();
        else 
            return _Storage.Heap().StoredValue();
    }


    inline constexpr
    void String::_Catenate(const char* value) {

        if(nullptr == value) {

            if(!_Storage.IsOnStack()) {
                _Storage.Heap().Reset();
            }

            _Storage.Stack().Reset();
            return;
        }

        std::uint16_t len = CountStringLength(value);

        if(len < _Storage.Stack().Capacity()) {

            if(!_Storage.IsOnStack()) {
                _Storage.Heap().Deallocate();
            }
            
            _Storage.Stack().Set(value, len);
        }
        else {
            _Storage.Heap().Set(value, len);
        }
    }


    inline constexpr
    void String::_Catenate(const char* value, std::int64_t len) {

        if(_Storage.IsOnStack()) {

            if(len < _Storage.Stack().Capacity() - _Storage.Stack().Length()) {
                _Storage.Stack().Catenate(value, len);
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

#pragma endregion




#pragma region

    inline constexpr
    Int64 CountStringLength(const char* string) noexcept {
        Int64 len = 0;
        while(string[len] != '\0') len++;
        return len;
    }


    inline constexpr
    Int64 CompareString(const String& left, const String& right) noexcept {

        if(left.Length() != right.Length()) {
            return left.Length() - right.Length();
        }
        else {
            for(Int64 i = 0; i <= left.Length(); i++) {
                if(left[i] != right[i])
                    return left[i] - right[i];
            }
        }

        return 0;
    }


    inline constexpr
    void CopyString(
            char*           left,
            std::int64_t    left_capacity,
            const char*     right,
            std::int64_t    right_len) {

        int i = 0;

        for(; i < left_capacity && i <= right_len && right[i] != '\0'; ++i) {
            left[i] = right[i];
        }

        left[i] = '\0';
    }


    inline constexpr
    void CatenateString(
            char*           left,
            std::int64_t    left_length,
            std::int64_t    left_capacity,
            const char*     right,
            std::int64_t    right_length) {

        int i = 0;

        for(; i < left_capacity && i < right_length; ++i) {
            left[i + left_length] = right[i];
        }

        left[i + left_length] = '\0';
    }

#pragma endregion




#pragma region

    inline constexpr
    Bool operator==(const String& left, const String& right) noexcept {
        return CompareString(left, right) == 0;
    }


    inline constexpr
    Bool operator!=(const String& left, const String& right) noexcept {
        return CompareString(left, right) != 0;
    }


    inline constexpr
    Bool operator>(const String& left, const String& right) noexcept {
        return CompareString(left, right) > 0;
    }


    inline constexpr
    Bool operator<(const String& left, const String& right) noexcept {
        return CompareString(left, right) < 0;
    }


    inline constexpr
    Bool operator>=(const String& left, const String& right) noexcept {
        return CompareString(left, right) >= 0;
    }


    inline constexpr
    Bool operator<=(const String& left, const String& right) noexcept {
        return CompareString(left, right) <= 0;
    }

#pragma endregion

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)
