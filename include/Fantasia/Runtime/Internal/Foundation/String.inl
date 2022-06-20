#pragma once
#include "../../Foundation/Bool.hxx"
#include "../../Foundation/Int64.hxx"
#include "../../Foundation/Float64.hxx"


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
        _StoredValue{'\0'} {
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
    const char* StringStackStorage::Data() const {
        return _StoredValue;
    }


    inline constexpr
    void StringStackStorage::Reset() {
        _Length         = 0;
        _StoredValue[0] = '\0';
        _IsOnStack      = true;
    }


    inline constexpr
    void StringStackStorage::Assign(const char* value, int8_t len) {

        Algorithm::CopyString(
                _StoredValue, _StackMaxCapacity,
                value, len);

        _Length     = len;
        _IsOnStack  = true;
    }


    template<std::signed_integral _T>
    inline constexpr
    void StringStackStorage::Assign(_T value) {

        _Length = Algorithm::ConvertSignedIntegerToStringT(value, _StoredValue);
        _IsOnStack = true;
    }


    template<std::unsigned_integral _T>
    inline constexpr
    void StringStackStorage::Assign(_T value) {

        _Length = Algorithm::ConvertUnsignedIntegerToStringT(value, _StoredValue);
        _IsOnStack = true;
    }


    inline constexpr
    void StringStackStorage::Catenate(const char* value, int8_t len) {

        Algorithm::CatenateString(
                _StoredValue,
                _Length,
                _StackMaxCapacity,
                value,
                len);
    }

#pragma endregion // StringStackStorage


#pragma region StringHeapStorage

    inline
    Int64 StringHeapStorage::Capacity() const {
        return _Capacity;
    };


    inline
    Int64 StringHeapStorage::Length() const {
        return _Length;
    }


    inline
    const char* StringHeapStorage::Data() const {
        return _StoredValue;
    }


    inline
    void StringHeapStorage::Initialize() {

        _Length         = 0;
        _Capacity       = 0;
        _StoredValue    = nullptr;
        _IsOnStack      = false;
    }


    template<std::signed_integral _T>
    inline
    void StringHeapStorage::Assign(_T value) {

        _Length = Algorithm::ConvertSignedIntegerToStringT(value, _StoredValue);
        _IsOnStack = true;
    }


    template<std::unsigned_integral _T>
    inline
    void StringHeapStorage::Assign(_T value) {

        _Length = Algorithm::ConvertUnsignedIntegerToStringT(value, _StoredValue);
        _IsOnStack = true;
    }


    inline
    void StringHeapStorage::Replace(char* memory, uint16_t length, uint16_t capacity) {
        _StoredValue    = memory;
        _Length         = length;
        _Capacity       = capacity;
    }

#pragma endregion // StringHeapStorage


#pragma region StringStorage

    inline
    StringHeapStorage& StringStorage::Heap() {
        return *(StringHeapStorage*)(&_MemorySpace);
    }


    inline
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
        return std::numeric_limits<uint16_t>::max();
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
    String::String(const String& other) {
        _Assign(other);
    }


    inline constexpr
    String::String(const char* value) {
        _Assign(value);
    }


    inline
    String& String::Catenate(const String& value) {
        _Catenate(value, value.Length());
        return *this;
    }


    inline
    String& String::Catenate(const Bool& value) {
        Catenate(value.ToString());
        return *this;
    }


    inline
    String& String::Catenate(const char* value) {
        if(value) {
            _Catenate(value, Algorithm::CountStringLength(value));
        }
        return *this;
    }


    inline constexpr
    const String String::Catenate(const char* value) const{
        String Target = {};

        Target._Storage.Stack().Assign(
                _Storage.Stack().Data(),
                _Storage.Stack().Length());

        Target._Storage.Stack().Catenate(
                value,
                Algorithm::CountStringLength(value));

        return Target;
    }


    inline constexpr
    Bool String::IsOnStack() const {
        return _Storage.IsOnStack();
    }


    inline constexpr
    String::operator char const* const() const noexcept {

        if(_Storage.IsOnStack())
            return _Storage.Stack().Data();
        else 
            return _Storage.Heap().Data();
    }


    inline constexpr
    String& String::operator=(const char* value) {
        _Assign(value);
        return *this;
    }


    inline constexpr
    void String::_Assign(const char* value) {

        if(nullptr == value) {

            if(!_Storage.IsOnStack()) {
                _Storage.Heap().Deallocate();
            }

            _Storage.Stack().Reset();
            return;
        }

        std::uint16_t len = Algorithm::CountStringLength(value);

        if(len < _Storage.Stack().Capacity()) {

            if(!_Storage.IsOnStack()) {
                _Storage.Heap().Deallocate();
            }
            _Storage.Stack().Assign(value, len);
        }
        else {

            if(_Storage.IsOnStack()) {
               _Storage.Heap().Initialize();
            }
            _Storage.Heap().Assign(value, len);
        }
    }


    inline
    void String::_Catenate(const char* value, std::int64_t len) {

        if(_Storage.IsOnStack()) {

            if(len < _Storage.Stack().Capacity() - _Storage.Stack().Length()) {
                _Storage.Stack().Catenate(value, len);
            }
            else {
                _MoveToHeap(len);
                _CatenateOnHeap(value, len);
            }
        }
        else {
            _CatenateOnHeap(value, len);
        }
    }

#pragma endregion


#pragma region

    inline constexpr
    Bool operator==(const String& left, const String& right) noexcept {
        return Algorithm::CompareString(left, right) == 0;
    }


    inline constexpr
    Bool operator!=(const String& left, const String& right) noexcept {
        return Algorithm::CompareString(left, right) != 0;
    }


    inline constexpr
    Bool operator>(const String& left, const String& right) noexcept {
        return Algorithm::CompareString(left, right) > 0;
    }


    inline constexpr
    Bool operator<(const String& left, const String& right) noexcept {
        return Algorithm::CompareString(left, right) < 0;
    }


    inline constexpr
    Bool operator>=(const String& left, const String& right) noexcept {
        return Algorithm::CompareString(left, right) >= 0;
    }


    inline constexpr
    Bool operator<=(const String& left, const String& right) noexcept {
        return Algorithm::CompareString(left, right) <= 0;
    }


    inline constexpr
    const char* begin(const String& string) {
        if(string._Storage.IsOnStack()) {
            return string._Storage.Stack().Data();
        }
        else {
            return string._Storage.Heap().Data();
        }
    }


    inline constexpr
    const char* end(const String& string) {

        if(string._Storage.IsOnStack()) {
            return string._Storage.Stack().Data()
                + string._Storage.Stack().Length();
        }
        else {
            return string._Storage.Heap().Data()
                + string._Storage.Heap().Length();
        }
    }

#pragma endregion

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)
