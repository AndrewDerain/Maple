///
/// @file Foundation.Float64.hxx
/// 
/// @brief 本文件定义了64位浮点数类型
/// 
/// @date 2022-01-22
/// 
#pragma once
#include "../Internal/Foundation/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Maple::Foundation
{

    /// @brief  64位浮点数
    /// @note   操作符已进行重载，可直接比较大小
    ///         满足 standard layout 和 trivial
    struct Float64
    {
    public:
        /// @brief  Float64 可表示的最大值
        inline constexpr
        static Float64 Max() noexcept;


        /// @brief  Float64 可表示的最小值
        inline constexpr
        static Float64 Min() noexcept;


        /// @brief  可区分两个 Float64 值的最小变化量
        inline constexpr
        static Float64 Epsilon() noexcept;


        /// @brief  构造函数。设为 default 以支持 standard_layout 和 trivial。
        Float64() = default;


        /// @brief  析构函数。设为 default 以支持 standard_layout 和 trivial。
        ~Float64() = default;


        /// @brief  移动构造函数。设为 default 以支持 standard_layout 和 trivial。
        inline constexpr
        Float64(Float64&&) = default;


        /// @brief  拷贝构造函数。设为 default 以支持 standard_layout 和 trivial。
        inline constexpr
        Float64(const Float64&) = default;


        inline constexpr
        Float64(const double value) noexcept;


        inline constexpr
        Float64(const int32_t value) noexcept;


        inline constexpr
        Float64(const uint32_t value) noexcept;


        inline constexpr
        Float64(const int64_t value) noexcept;


        inline constexpr
        Float64(const uint64_t value) noexcept;


        inline constexpr
        operator double const&() const noexcept;


        inline constexpr
        operator double&() noexcept;


        /// @brief  赋值操作符。设为 default 以支持 standard_layout 和 trival。
        inline constexpr
        Float64& operator=(const Float64&) = default;


        inline constexpr
        Float64& operator=(const double value);


    protected:
        double _StoredValue;
    };


    // POD 校验。standard layout and trivial。
    static_assert(std::is_trivial_v<Float64>, "Float64 must be trivial!");
    static_assert(std::is_standard_layout_v<Float64>, "Float64 must be standard layout!");

    
    inline constexpr
    Bool operator>(Float64& left, Float64& right);


    inline constexpr
    Bool operator<(Float64& left, Float64& right);


    inline constexpr
    Bool operator==(Float64& left, Float64& right);


    inline constexpr
    Bool operator!=(Float64& left, Float64& right);


    inline constexpr
    Bool operator>=(Float64& left, Float64& right);


    inline constexpr
    Bool operator<=(Float64& left, Float64& right);

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)


#include "../Internal/Foundation/Float64.inl"
