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
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
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


    /// @brief 构造函数。设为 default 以支持 standard_layout 和 trival。
    Float64() = default;


    /// @brief 析构函数。设为 default 以支持 standard_layout 和 trival。
    ~Float64() = default;


    /// @brief 拷贝构造函数。设为 default 以支持 standard_layout 和 trival。
    Float64(const Float64&) = default;


    __api_inline __api_constexpr
    Float64(double value) noexcept;


    __api_inline __api_constexpr
    operator double const&() const noexcept;


    __api_inline __api_constexpr
    operator double&() noexcept;


    /// @brief 赋值操作符。设为 default 以支持 standard_layout 和 trival。
    Float64& operator=(const Float64&) = default;


    __api_inline __api_constexpr
    Float64& operator=(double value);


protected:
    double _StoredValue;
};


// POD 校验。standard layout and trival。
static_assert(std::is_trivial_v<Float64>, "Float64 must be trival!");
static_assert(std::is_standard_layout_v<Float64>, "Float64 must be standard layout!");


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
