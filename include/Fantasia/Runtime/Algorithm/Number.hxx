//
// Created by 宋豪杰 on 2022/6/13.
//

#pragma once
#include "../Internal/Basic/CodeLang.CXX.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Algorithm
{

    template<std::integral _T>
    inline constexpr
    void Swap(_T& right, _T& left) noexcept;


    template<std::signed_integral _T>
    inline constexpr
    bool IsNegative(_T value) noexcept;


    template<std::signed_integral _T>
    inline constexpr
    _T Abs(_T value) noexcept;

} // namespace _Fantasia::Algorithm
#pragma pack(pop)
#pragma warning(pop)


#include "../Internal/Algorithm/Number.inl"
