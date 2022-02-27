///
/// @file Foundation.Float64.hxx
/// 
/// @brief 本文件定义了64位浮点数类型
/// 
/// @date 2022-01-22
/// 
#pragma once
#include "Foundation.Basic.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_DETAIL_BEGIN

/// @brief 64位浮点数
/// @note 操作符已进行重载，可直接比较大小
struct Float64
{
public:
    __api_inline __api_constexpr
    static Float64 Max() noexcept;


    __api_inline __api_constexpr
    static Float64 Min() noexcept;


    __api_inline __api_constexpr
    static Float64 Epsilon() noexcept;


    __always_inine __always_constexpr
    Float64() noexcept {};


    __always_inine __always_constexpr
    ~Float64() noexcept {};


    __api_inline 
    Float64(const Float64& other) noexcept;


    __api_inline 
    Float64(Float64&& other) noexcept;


    __api_inline __api_constexpr
    Float64(double const& value) noexcept;


    __api_inline __api_constexpr
    Float64(double&& value) noexcept;


    __api_inline
    operator double const&() const noexcept;


    __api_inline
    operator double&() noexcept;


    __api_inline
    Float64& operator=(const Float64& other);


    __api_inline
    Float64& operator=(Float64&& other);


    __api_inline
    Float64& operator=(const double& value);


    __api_inline
    Float64& operator=(double&& value);


protected:
    double _StoredValue = 0;
};


__api_inline
Bool  
operator>(Float64& left, Float64& right);


__api_inline
Bool  
operator<(Float64& left, Float64& right);


__api_inline
Bool 
operator==(Float64& left, Float64& right);


__api_inline
Bool 
operator!=(Float64& left, Float64& right);


__api_inline
Bool 
operator>=(Float64& left, Float64& right);


__api_inline
Bool 
operator<=(Float64& left, Float64& right);

__FANTASIA_FOUNDATION_DETAIL_END


__FANTASIA_FOUNDATION_BEGIN
using _Fantasia::Float64;
__FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)


#ifdef __FANTASIA_OPTION_INLINE
#    include "../../Source/Runtime/Foundation.Float64.iapi.hxx"
#endif

#ifdef __FANTASIA_OPTION_HEADER_ONLY
#    include "../../Source/Runtime/Foundation.Float64.impl.cxx"
#endif
