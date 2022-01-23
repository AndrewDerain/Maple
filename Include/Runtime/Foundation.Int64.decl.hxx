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
    static Int64 Max();
    static Int64 Min();

public:
    Int64() noexcept = default;
    ~Int64() noexcept = default;

    Int64(const Int64& other) noexcept;
    Int64(Int64&& other) noexcept;

    Int64(const int32_t& value) noexcept;
    Int64(int32_t&& value) noexcept;

    Int64(const int64_t& value) noexcept;
    Int64(int64_t&& value) noexcept;

public:


public:
    operator int64_t() const noexcept; 
    operator int64_t&() noexcept;

    const Int64& operator=(const Int64& other) noexcept;
    const Int64& operator=(Int64&& other) noexcept;

    const Int64& operator=(const int32_t& value) noexcept;
    const Int64& operator=(int32_t&& value) noexcept;

    const Float64& operator=(const Float64& other) noexcept;
    const Float64& operator=(Float64&& other) noexcept;

protected:
    int64_t _StoredValue;
};

_FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)


#include "Foundation.Int64.impl.hxx"
