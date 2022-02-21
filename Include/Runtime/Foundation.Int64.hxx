#pragma once
#include "Foundation.Basic.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_BEGIN
struct Float64;
struct String;
__FANTASIA_FOUNDATION_END



__FANTASIA_FOUNDATION_BEGIN

struct Int64 
{
public:
    static Int64 Max();


    static Int64 Min();


public:
    Int64() {};


    ~Int64() {};

    
    Int64(const Int64& other) noexcept;


    Int64(Int64&& other) noexcept;


    Int64(const int32_t value) noexcept;


    Int64(const int64_t value) noexcept;


    Int64(const char value) noexcept;


    Int64(const short value) noexcept;


    Int64(const unsigned short value) noexcept;


    /// @brief 转换为字符串
    String ToString();


    operator int64_t const&() const noexcept; 


    operator int64_t&() noexcept;


    const Int64& operator=(const Int64& other) noexcept;


    const Int64& operator=(Int64&& other) noexcept;


    const Int64& operator=(const int32_t& value) noexcept;


    const Int64& operator=(int32_t&& value) noexcept;


    const Float64& operator=(const Float64& other) noexcept;


    const Float64& operator=(Float64&& other) noexcept;


protected:
    int64_t _StoredValue = 0;
};

__FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)


#ifdef __FANTASIA_OPTION_INLINE
#    include "../../Source/Runtime/Foundation.Int64.impl.hxx"
#endif
