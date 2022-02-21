///
/// @file Foundation.Int64.hxx
/// 
/// @brief 本文件定义了64位整数类型
/// 
/// @date 2022-01-22
/// 
#pragma once
#include "Foundation.Basic.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_BEGIN

struct Int64 
{
public:
    __api_inline
    static Int64 Max();


    __api_inline
    static Int64 Min();


public:
    __always_inine
    Int64() {};


    __always_inine
    ~Int64() {};

    
    __api_inline
    Int64(const Int64& other) noexcept;


    __api_inline
    Int64(Int64&& other) noexcept;


    __api_inline
    Int64(const int32_t value) noexcept;


    __api_inline
    Int64(const int64_t value) noexcept;


    __api_inline
    Int64(const char value) noexcept;


    __api_inline
    Int64(const short value) noexcept;


    __api_inline
    Int64(const unsigned short value) noexcept;


    /// @brief 转换为字符串
    __api
    String ToString();


    __api_inline
    operator int64_t const&() const noexcept; 


    __api_inline
    operator int64_t&() noexcept;


    __api_inline
    const Int64& operator=(const Int64& other) noexcept;


    __api_inline
    const Int64& operator=(Int64&& other) noexcept;


    __api_inline
    const Int64& operator=(const int32_t& value) noexcept;


    __api_inline
    const Int64& operator=(int32_t&& value) noexcept;


    __api_inline
    const Float64& operator=(const Float64& other) noexcept;


    __api_inline
    const Float64& operator=(Float64&& other) noexcept;


protected:
    int64_t _StoredValue = 0;
};

__FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)


#ifdef __FANTASIA_OPTION_INLINE
#    include "../../Source/Runtime/Foundation.Int64.iapi.hxx"
#endif

#ifdef __FANTASIA_OPTION_HEADER_ONLY
#    include "../../Source/Runtime/Foundation.Int64.impl.cxx"
#endif
