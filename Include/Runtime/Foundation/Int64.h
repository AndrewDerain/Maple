///
/// @file Foundation.Int64.hxx
/// 
/// @brief 本文件定义了64位整数类型
/// 
/// @date 2022-01-22
/// 
#pragma once
#include "../_Detail/Foundation/Predeclars.h"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Foundation
{

    /// @brief 64位整数类型
    struct Int64
    {
    public:
        inline constexpr
        static Int64 Max() noexcept;


        inline constexpr
        static Int64 Min() noexcept;


        /// @brief 构造函数。设为 default 以支持 standard_layout 和 trivial。
        Int64() = default;


        /// @brief 析构函数。设为 default 以支持 standard_layout 和 trivial。
        ~Int64() = default;


        /// @brief 拷贝构造函数。设为 default 以支持 standard_layout 和 trivial。
        Int64(const Int64&) = default;


        inline constexpr
        Int64(int64_t value) noexcept;


        inline constexpr
        Int64(uint64_t value);


        inline constexpr
        Int64(char value) noexcept;


        inline constexpr
        Int64(signed char value) noexcept;


        inline constexpr
        Int64(unsigned char value) noexcept;


        inline constexpr
        Int64(short value) noexcept;


        inline constexpr
        Int64(unsigned short value) noexcept;


        inline constexpr
        Int64(int32_t value) noexcept;


        inline constexpr
        Int64(uint32_t value) noexcept;


        /// @brief 转换为字符串
        __decorate(Fantasia, api)
        String ToString() const;


        inline constexpr
        operator int64_t const&() const noexcept;


        inline constexpr
        operator int64_t&() noexcept;


        /// @brief 赋值操作符。设为 default 以支持 standard_layout 和 trivial。
        Int64& operator=(const Int64&) = default;


        inline constexpr
        Int64& operator=(Float64 other) noexcept;


        inline constexpr
        Int64& operator=(short value) noexcept;


        inline constexpr
        Int64& operator=(unsigned short value) noexcept;


        inline constexpr
        Int64& operator=(int32_t value) noexcept;


        inline constexpr
        Int64& operator=(uint32_t value) noexcept;


        inline constexpr
        Int64& operator=(int64_t value) noexcept;


        inline constexpr
        Int64& operator=(uint64_t value) noexcept;


        inline constexpr
        Int64& operator=(double value) noexcept;


    protected:
        int64_t _StoredValue;
    };


    // POD 校验。standard layout and trivial。
    static_assert(std::is_trivial_v<Int64>, "Int64 must be trivial!");
    static_assert(std::is_standard_layout_v<Int64>, "Int64 must be standard layout!");

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)


#include "../_Detail/Foundation/Int64.inl.h"
