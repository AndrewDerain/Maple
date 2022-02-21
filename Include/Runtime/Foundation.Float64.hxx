﻿#pragma once
#include "Foundation.Basic.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_BEGIN
struct Bool;
struct Int64;
struct String;
__FANTASIA_FOUNDATION_END



__FANTASIA_FOUNDATION_BEGIN

/// @brief 64位浮点数
/// @note 已对比较操作符进行重载，可直接比较大小
struct Float64
{
public:
    __api_inline static Float64 Max();


    __api_inline static Float64 Min();


    __api_inline static Float64 Epsilon();


    __always_inine
    Float64() {};


    __always_inine
    ~Float64() {};


    __api_inline
    Float64(const Float64& other) noexcept;


    __api_inline
    Float64(Float64&& other) noexcept;


    __api_inline
    Float64(double const& value) noexcept;


    __api_inline
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

__FANTASIA_FOUNDATION_END

__api_inline
Fantasia::Bool  
operator>(
    Fantasia::Float64& left, 
    Fantasia::Float64& right);
    
__api_inline
Fantasia::Bool  
operator<(
    Fantasia::Float64& left, 
    Fantasia::Float64& right);


__api_inline
Fantasia::Bool 
operator==(
    Fantasia::Float64& left, 
    Fantasia::Float64& right);


__api_inline
Fantasia::Bool 
operator!=(
    Fantasia::Float64& left, 
    Fantasia::Float64& right);


__api_inline
Fantasia::Bool 
operator>=(
    Fantasia::Float64& left, 
    Fantasia::Float64& right);


__api_inline
Fantasia::Bool 
operator<=(
    Fantasia::Float64& left, 
    Fantasia::Float64& right);


#pragma pack(pop)
#pragma warning(pop)


#ifdef __FANTASIA_OPTION_INLINE
#    include "../../Source/Runtime/Foundation.Float64.iapi.hxx"
#endif

#ifdef __FANTASIA_OPTION_HEADER_ONLY
#    include "../../Source/Runtime/Foundation.Float64.impl.cxx"
#endif
