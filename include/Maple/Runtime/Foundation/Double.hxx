///
/// @file Foundation.Double.hxx
/// 
/// @brief 本文件定义了64位浮点数类型
/// 
/// @date 2022-01-22
/// 
#pragma once
#include "../Internal/Foundation/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
{

    /// @brief  64位浮点数
    /// @note   操作符已进行重载，可直接比较大小
    ///         满足 standard layout 和 trivial
    struct Double
    {
    public:
        /// @brief  Double 可表示的最大值
        inline constexpr
        static Double Max() noexcept;


        /// @brief  Double 可表示的最小值
        inline constexpr
        static Double Min() noexcept;


        /// @brief  可区分两个 Double 值的最小变化量
        inline constexpr
        static Double Epsilon() noexcept;


        /// @brief  构造函数。设为 default 以支持 standard_layout 和 trivial。
        Double() = default;


        /// @brief  析构函数。设为 default 以支持 standard_layout 和 trivial。
        ~Double() = default;


        /// @brief  移动构造函数。设为 default 以支持 standard_layout 和 trivial。
        inline constexpr
        Double(Double&&) = default;


        /// @brief  拷贝构造函数。设为 default 以支持 standard_layout 和 trivial。
        inline constexpr
        Double(const Double&) = default;


        inline constexpr
        Double(const double value) noexcept;


        inline constexpr
        Double(const int32_t value) noexcept;


        inline constexpr
        Double(const uint32_t value) noexcept;


        inline constexpr
        Double(const int64_t value) noexcept;


        inline constexpr
        Double(const uint64_t value) noexcept;


        inline constexpr
        operator double const&() const noexcept;


        inline constexpr
        operator double&() noexcept;


        /// @brief  赋值操作符。设为 default 以支持 standard_layout 和 trivial。
        inline constexpr
        Double& operator=(Double&&) = default;


        /// @brief  赋值操作符。设为 default 以支持 standard_layout 和 trivial。
        inline constexpr
        Double& operator=(const Double&) = default;


        inline constexpr
        Double& operator=(const double value);


    public:
        double _StoredValue;
    };


    // POD 校验。standard layout and trivial。
    static_assert(std::is_trivial_v<Double>, "Double must be trivial!");
    static_assert(std::is_standard_layout_v<Double>, "Double must be standard layout!");

    
    inline constexpr
    Bool operator>(Double& left, Double& right);


    inline constexpr
    Bool operator<(Double& left, Double& right);


    inline constexpr
    Bool operator==(Double& left, Double& right);


    inline constexpr
    Bool operator!=(Double& left, Double& right);


    inline constexpr
    Bool operator>=(Double& left, Double& right);


    inline constexpr
    Bool operator<=(Double& left, Double& right);

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)


#include "../Internal/Foundation/Double.inl"
