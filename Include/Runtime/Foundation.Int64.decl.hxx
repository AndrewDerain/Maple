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
struct Int64 
{
public:
    Int64() noexcept = default;
    ~Int64() noexcept = default;

    Int64(const Int64& other) noexcept;
    Int64(Int64&& other) noexcept;

    Int64(const int32_t& value) noexcept;
    Int64(int32_t&& value) noexcept;

    Int64(const int64_t& value) noexcept;
    Int64(int64_t&& value) noexcept;

    explicit operator int64_t&();

    Int64& operator=(const Int64& other);
    Int64& operator=(Int64&& other) noexcept ;

    static Int64 Max();
    static Int64 Min();

private:
    int64_t StoredValue;
};
_FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)


#include "Foundation.Int64.impl.hxx"
