//
// Created by 宋豪杰 on 2022/7/10.
//

#pragma once
#include "../Internal/Foundation/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
{

    struct Byte
    {
    public:
        /// @brief  Byte 可表示的最大值
        inline constexpr
        static Byte Max() noexcept;


        /// @brief  Byte 可表示的最小值
        inline constexpr
        static Byte Min() noexcept;


        /// @brief  构造函数。设为 default 以支持 standard_layout 和 trivial。
        Byte() = default;


        /// @brief  析构函数。设为 default 以支持 standard_layout 和 trivial。
        ~Byte() = default;


        /// @brief  移动构造函数。设为 default 以支持 standard_layout 和 trivial。
        inline constexpr
        Byte(Byte&&) = default;


        /// @brief  拷贝构造函数。设为 default 以支持 standard_layout 和 trivial。
        inline constexpr
        Byte(const Byte&) = default;


        /// @brief  赋值操作符。设为 default 以支持 standard_layout 和 trivial。
        inline constexpr
        Byte& operator=(const Byte&) = default;


    public:
        int8_t _StoredValue;
    };


} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)
