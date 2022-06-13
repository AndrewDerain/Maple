//
// Created by 宋豪杰 on 2022/6/12.
//
#pragma once
#include "../Basic/Bit.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Algorithm
{

    template<std::integral _T>
    inline constexpr
    void Swap(_T& right, _T& left) noexcept {

        right   ^= left;
        left    ^= right;
        right   ^= left;
    }


    template<std::signed_integral _T>
    inline constexpr
    bool IsNegative(_T value) noexcept {
        return value >> (bitsof(_T) - 1);
    }


    template<std::signed_integral _T>
    inline constexpr
    _T Abs(_T value) noexcept {
        _T sign = value >> (bitsof(_T) - 1);
        return (value ^ sign) - sign;
    }

} // namespace _Fantasia::Algorithm
#pragma pack(pop)
#pragma warning(pop)
