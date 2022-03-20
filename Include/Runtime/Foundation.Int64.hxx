﻿///
/// @file Foundation.Int64.hxx
/// 
/// @brief 本文件定义了64位整数类型
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

    /// @brief 64位整数类型
    struct Int64
    {
    public:
        __api_inline __api_constexpr
        static Int64 Max() noexcept;


        __api_inline __api_constexpr
        static Int64 Min() noexcept;


        /// @brief 构造函数。设为 default 以支持 standard_layout 和 trivial。
        Int64() = default;


        /// @brief 析构函数。设为 default 以支持 standard_layout 和 trivial。
        ~Int64() = default;


        /// @brief 拷贝构造函数。设为 default 以支持 standard_layout 和 trivial。
        Int64(const Int64&) = default;


        __api_inline __api_constexpr
        Int64(int64_t value) noexcept;


        __api_inline __api_constexpr
        Int64(uint64_t value);


        __api_inline __api_constexpr
        Int64(char value) noexcept;


        __api_inline __api_constexpr
        Int64(signed char value) noexcept;


        __api_inline __api_constexpr
        Int64(unsigned char value) noexcept;


        __api_inline __api_constexpr
        Int64(short value) noexcept;


        __api_inline __api_constexpr
        Int64(unsigned short value) noexcept;


        __api_inline __api_constexpr
        Int64(int32_t value) noexcept;


        __api_inline __api_constexpr
        Int64(uint32_t value) noexcept;


        /// @brief 转换为字符串
        __api
        String ToString() const;


        __api_inline __api_constexpr
        operator int64_t const&() const noexcept;


        __api_inline __api_constexpr
        operator int64_t&() noexcept;


        /// @brief 赋值操作符。设为 default 以支持 standard_layout 和 trivial。
        Int64& operator=(const Int64&) = default;


        __api_inline __api_constexpr
        Int64& operator=(Float64 other) noexcept;


        __api_inline __api_constexpr
        Int64& operator=(short value) noexcept;


        __api_inline __api_constexpr
        Int64& operator=(unsigned short value) noexcept;


        __api_inline __api_constexpr
        Int64& operator=(int32_t value) noexcept;


        __api_inline __api_constexpr
        Int64& operator=(uint32_t value) noexcept;


        __api_inline __api_constexpr
        Int64& operator=(int64_t value) noexcept;


        __api_inline __api_constexpr
        Int64& operator=(uint64_t value) noexcept;


        __api_inline __api_constexpr
        Int64& operator=(double value) noexcept;


    protected:
        int64_t _StoredValue;
    };

    // POD 校验。standard layout and trival。
    static_assert(std::is_trivial_v<Int64>, "Int64 must be trival!");
    static_assert(std::is_standard_layout_v<Int64>, "Int64 must be standard layout!");

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)

#ifdef __FANTASIA_OPTION_INLINE
#    include "_Detail/Foundation/Int64.inli.hxx"
#endif
