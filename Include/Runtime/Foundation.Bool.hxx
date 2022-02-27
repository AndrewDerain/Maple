///
/// @file Foundation.Bool.hxx
/// 
/// @brief 本文件定义了布尔类型
/// 
/// @date 2022-02-03
/// 
#pragma once
#include "Foundation.Basic.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_DETAIL_BEGIN

struct Bool 
{
public:
    __always_inine __always_constexpr
    Bool() noexcept {};


    __always_inine __always_constexpr
    ~Bool() noexcept {};


    __api_inline __api_constexpr
    Bool(const Bool& other) noexcept;

    
    __api_inline __api_constexpr
    Bool(Bool&& other) noexcept;


    __api_inline __api_constexpr
    Bool(const bool& value) noexcept;


    __api_inline __api_constexpr
    Bool(bool&& value) noexcept;

    
    /// @brief 将布尔值转换为字符串
    /// @return 若值为 true 则返回 "true"，若为 false 则返回 "false"。
    __api_inline __api_constexpr
    String ToString();


    __api_inline __api_constexpr
    operator bool const&() const noexcept;


    __api_inline __api_constexpr
    operator bool&() noexcept;


    __api_inline __api_constexpr
    const Bool& operator=(const Bool& other) noexcept;


    __api_inline __api_constexpr
    const Bool& operator=(Bool&& other) noexcept;


    __api_inline __api_constexpr
    const Bool& operator=(const bool& value) noexcept;


    __api_inline __api_constexpr
    const Bool& operator=(bool&& value) noexcept;


protected:
    bool _StoredValue = false;
};

__FANTASIA_FOUNDATION_DETAIL_END


__FANTASIA_FOUNDATION_BEGIN
using _Fantasia::Bool;
__FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)


#ifdef __FANTASIA_OPTION_INLINE
#    include "../../Source/Runtime/Foundation.Bool.iapi.hxx"
#endif

#ifdef __FANTASIA_OPTION_HEADER_ONLY
#    include "../../Source/Runtime/Foundation.Bool.impl.cxx"
#endif
