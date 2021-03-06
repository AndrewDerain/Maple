///
/// @file Foundation.Bool.hxx
/// 
/// @brief 本文件定义了布尔类型
/// 
/// @date 2022-02-03
/// 
#pragma once
#include "../Internal/Foundation/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
{

    /// @brief  布尔类型
    /// @note   满足 standard layout 和 trivial
    struct Bool 
    {
    public:
        /// @brief 构造函数。设为 default 以支持 standard_layout 和 trivial。
        Bool() = default;


        /// @brief 析构函数。设为 default 以支持 standard_layout 和 trivial。
        ~Bool() = default;


        /// @brief 移动构造函数。设为 default 以支持 standard_layout 和 trivial。
        inline constexpr
        Bool(Bool&&) = default;


        /// @brief 拷贝构造函数。设为 default 以支持 standard_layout 和 trivial。
        inline constexpr
        Bool(const Bool&) = default;


        inline constexpr
        Bool(const bool value) noexcept;

        
        /// @brief 将布尔值转换为字符串
        /// @return 若值为 true 则返回 "true"，若为 false 则返回 "false"。
        inline constexpr
        String ToString() const;


        inline constexpr
        operator bool const&() const noexcept;


        inline constexpr
        operator bool&() noexcept;


        /// @brief 赋值操作符。设为 default 以支持 standard_layout 和 trivial。
        Bool& operator=(const Bool&) = default;


        inline constexpr
        Bool& operator=(const bool value) noexcept;


    public:
        bool _StoredValue;
    };


    // POD 校验。standard layout and trivial。
    static_assert(std::is_trivial_v<Bool>, "Bool must be trivial!");
    static_assert(std::is_standard_layout_v<Bool>, "Bool must be standard layout!");

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)


#include "../Internal/Foundation/Bool.inl"
