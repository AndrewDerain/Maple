///
/// @file Foundation.Int32.hxx
/// 
/// @brief 本文件定义了64位整数类型
/// 
/// @date 2022-06-20
/// 
#pragma once
#include "../Internal/Foundation/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Maple::Foundation
{

    /// @brief  64位整数类型
    /// @note   满足 standard layout 和 trivial
    struct Int32
    {
    public:
        inline constexpr
        static Int32 Max() noexcept;


        inline constexpr
        static Int32 Min() noexcept;


        /// @brief  构造函数。设为 default 以支持 standard_layout 和 trivial。
        Int32() = default;


        /// @brief  析构函数。设为 default 以支持 standard_layout 和 trivial。
        ~Int32() = default;


        /// @brief  移动构造函数。设为 default 以支持 standard_layout 和 trivial。
        Int32(Int32&&) = default;


        /// @brief  拷贝构造函数。设为 default 以支持 standard_layout 和 trivial。
        Int32(const Int32&) = default;


        inline constexpr
        Int32(const int32_t value) noexcept;


        inline constexpr
        Int32(const uint32_t value);


        inline constexpr
        Int32(const char value) noexcept;


        inline constexpr
        Int32(const signed char value) noexcept;


        inline constexpr
        Int32(const unsigned char value) noexcept;


        inline constexpr
        Int32(const short value) noexcept;


        inline constexpr
        Int32(const unsigned short value) noexcept;


        inline constexpr
        Int32(const int64_t value) noexcept;


        inline constexpr
        Int32(const uint64_t value) noexcept;


        /// @brief  转换为字符串
        inline constexpr
        String ToString() const;


        inline constexpr
        operator int32_t const&() const noexcept;


        inline constexpr
        operator int32_t&() noexcept;


        /// @brief  赋值操作符。设为 default 以支持 standard_layout 和 trivial。
        Int32& operator=(Int32&&) = default;


        /// @brief  赋值操作符。设为 default 以支持 standard_layout 和 trivial。
        Int32& operator=(const Int32&) = default;


        inline constexpr
        Int32& operator=(const Float64 other) noexcept;


        inline constexpr
        Int32& operator=(const short value) noexcept;


        inline constexpr
        Int32& operator=(const unsigned short value) noexcept;


        inline constexpr
        Int32& operator=(const int32_t value) noexcept;


        inline constexpr
        Int32& operator=(const uint32_t value) noexcept;


        inline constexpr
        Int32& operator=(const int64_t value) noexcept;


        inline constexpr
        Int32& operator=(const uint64_t value) noexcept;


        inline constexpr
        Int32& operator=(const double value) noexcept;


    protected:
        int32_t _StoredValue;
    };


    // POD 校验。standard layout and trivial。
    static_assert(std::is_trivial_v<Int32>, "Int32 must be trivial!");
    static_assert(std::is_standard_layout_v<Int32>, "Int32 must be standard layout!");

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)


#include "../Internal/Foundation/Int32.inl"
