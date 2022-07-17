/// @file Int64.hxx
/// @brief 本文件定义了64位整数类型
#pragma once
#include "../Internal/Foundation/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
{

    /// @brief  64位整数类型
    /// @note   满足 standard layout 和 trivial
    struct Int64
    {
    public:
        inline constexpr
        static Int64 Max() noexcept;


        inline constexpr
        static Int64 Min() noexcept;


        /// @brief  构造函数。设为 default 以支持 standard_layout 和 trivial。
        Int64() = default;


        /// @brief  析构函数。设为 default 以支持 standard_layout 和 trivial。
        ~Int64() = default;


        /// @brief  移动构造函数。设为 default 以支持 standard_layout 和 trivial。
        Int64(Int64&&) = default;


        /// @brief  拷贝构造函数。设为 default 以支持 standard_layout 和 trivial。
        Int64(const Int64&) = default;


        inline constexpr
        Int64(const int64_t value) noexcept;


        inline constexpr
        Int64(const uint64_t value) noexcept;


        inline constexpr
        Int64(const char value) noexcept;


        inline constexpr
        Int64(const signed char value) noexcept;


        inline constexpr
        Int64(const unsigned char value) noexcept;


        inline constexpr
        Int64(const short value) noexcept;


        inline constexpr
        Int64(const unsigned short value) noexcept;


        inline constexpr
        Int64(const int32_t value) noexcept;


        inline constexpr
        Int64(const uint32_t value) noexcept;


        /// @brief  转换为字符串
        inline constexpr
        String ToString() const;


        inline constexpr
        operator int64_t const&() const noexcept;


        inline constexpr
        operator int64_t&() noexcept;


        /// @brief  赋值操作符。设为 default 以支持 standard_layout 和 trivial。
        Int64& operator=(Int64&&) = default;


        /// @brief  赋值操作符。设为 default 以支持 standard_layout 和 trivial。
        Int64& operator=(const Int64&) = default;


        inline constexpr
        Int64& operator=(const Double other) noexcept;


        inline constexpr
        Int64& operator=(const short value) noexcept;


        inline constexpr
        Int64& operator=(const unsigned short value) noexcept;


        inline constexpr
        Int64& operator=(const int32_t value) noexcept;


        inline constexpr
        Int64& operator=(const uint32_t value) noexcept;


        inline constexpr
        Int64& operator=(const int64_t value) noexcept;


        inline constexpr
        Int64& operator=(const uint64_t value) noexcept;


        inline constexpr
        Int64& operator=(const double value) noexcept;


    public:
        int64_t _StoredValue;
    };


    // POD 校验。standard layout and trivial。
    static_assert(std::is_trivial_v<Int64>, "Int64 must be trivial!");
    static_assert(std::is_standard_layout_v<Int64>, "Int64 must be standard layout!");

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)


#include "../Internal/Foundation/Int64.inl"
