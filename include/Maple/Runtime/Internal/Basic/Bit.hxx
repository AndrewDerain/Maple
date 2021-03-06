//
// Created by 宋豪杰 on 2022/6/13.
//

#pragma once
#include "CodeLang.CXX.hxx"
#include "Preconfig.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple
{

    /// @brief 计算类型 _T 的 bit 数。
    template<typename _T>
    inline constexpr
    auto ___maple_bitsof() {
        return sizeof(_T) * 8;
    }


    /// @brief  计算类型 _T 的 bit 数。
    ///         此宏使得 bitsof 的用法与 sizeof 相同。
    #define bitsof(ARG) ___maple_bitsof<ARG>()

} // namespace _Maple
#pragma pack(pop)
#pragma warning(pop)
