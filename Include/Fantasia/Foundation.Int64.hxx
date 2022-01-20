#pragma once
#include "Foundation.basic.hxx"
#include "Basic.CodeLang.CXX.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_FOUNDATION_BEGIN
    struct Float64;
_FANTASIA_FOUNDATION_END


_FANTASIA_FOUNDATION_BEGIN
#pragma region Int64 declaration 
struct Int64 
{
public:
    Int64() noexcept = default;
    ~Int64() noexcept = default;

    Int64(const Int64& other) noexcept :
        _StoredValue(other._StoredValue) {
    }

    Int64(Int64&& other) noexcept :
        _StoredValue(move(other)){
    }

    Int64(const int32_t& value) noexcept :
        _StoredValue(value) {
    }

    Int64(int32_t&& value) :
        _StoredValue(value) {
    };

    Int64(const int64_t& value) noexcept :
        _StoredValue(value) {
    }

    Int64(int64_t&& value) noexcept :
        _StoredValue(move(value)) {
    }

    operator int64_t&() { 
        return _StoredValue; 
    }

    Int64& operator=(const Int64& other) {
        _StoredValue = other._StoredValue;
        return *this;
    }

    Int64& operator=(Int64&& other) {
        _StoredValue = other._StoredValue;
        return *this;
    }

    static Int64 Max() {
        return numeric_limits<int64_t>::max();
    };

    static Int64 Min() {
        return numeric_limits<int64_t>::min();
    }

private:
    int64_t _StoredValue;
};
_FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)
