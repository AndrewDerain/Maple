///
/// @file Foundation.Float64.hxx
/// 
/// @brief 本文件定义了64位浮点数类型
/// 
/// @date 2022-01-22
/// 
#pragma once
#include "_Detail/Foundation/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Foundation
{

    /// @brief 64位浮点数
    /// @note 操作符已进行重载，可直接比较大小
    struct Float64
    {
    public:
        /// @brief Float64 可表示的最大值
        __api_inline __api_constexpr
        static Float64 Max() noexcept;


        /// @brief Float64 可表示的最小值
        __api_inline __api_constexpr
        static Float64 Min() noexcept;


        /// @brief 可区分两个 Float64 值的最小变化量 
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

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)

#ifdef __FANTASIA_OPTION_INLINE
#    include "_Detail/Foundation/Float64.inli.hxx"
#endif
