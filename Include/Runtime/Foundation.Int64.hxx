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
__FANTASIA_FOUNDATION_DETAIL_BEGIN

struct Int64
{
public:
    __api_inline
    static Int64 Max() noexcept;


    __api_inline
    static Int64 Min() noexcept;


    /// @brief 构造函数。设为 default 以支持 standard_layout 和 trival。
    Int64() = default;


    /// @brief 析构函数。设为 default 以支持 standard_layout 和 trival。
    ~Int64() = default;

    
    /// @brief 拷贝构造函数。设为 default 以支持 standard_layout 和 trival。
    Int64(const Int64&) = default;


    __api_inline __api_constexpr
    Int64(const int32_t value) noexcept;


    __api_inline __api_constexpr
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


    __api_inline __api_constexpr
    operator int64_t const&() const noexcept; 


    __api_inline __api_constexpr
    operator int64_t&() noexcept;


    /// @brief 赋值操作符。设为 default 以支持 standard_layout 和 trival。
    Int64& operator=(const Int64&) = default;


    __api_inline
    Int64& operator=(const int32_t& value) noexcept;


    __api_inline
    Int64& operator=(int32_t&& value) noexcept;


    __api_inline
    const Float64& operator=(const Float64& other) noexcept;


protected:
    int64_t _StoredValue;
};


// POD 校验。standard layout and trival。
static_assert(std::is_trivial_v<Int64>, "Int64 must be trival!");
static_assert(std::is_standard_layout_v<_Fantasia::Int64>, "Int64 must be standard layout!");

__FANTASIA_FOUNDATION_DETAIL_END


__FANTASIA_FOUNDATION_BEGIN
using _Fantasia::Int64;
__FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)


#ifdef __FANTASIA_OPTION_INLINE
#    include "../../Source/Runtime/Foundation.Int64.iapi.hxx"
#endif

#ifdef __FANTASIA_OPTION_HEADER_ONLY
#    include "../../Source/Runtime/Foundation.Int64.impl.cxx"
#endif
