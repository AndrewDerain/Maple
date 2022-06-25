//
// Created by 宋豪杰 on 2022/6/12.
//
#pragma once
#include "../Basic/Bit.hxx"
#include "../Basic/NumericLimits.hxx"


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


    template<std::integral _Dst, std::integral _Src>
    inline constexpr
    void AssignWithOverflowCheck(_Dst& dst, const _Src src) noexcept {

        [[likely]]
        if(src <= NumericLimits<_Dst>::Max())
            dst = src;
        else {
            //assert(src <= NumericLimits<_Dst>::Max());
            std::cout << __FUNCTION__  <<std::endl;
            dst = NumericLimits<_Dst>::Max();
        }
    }


    template<std::integral _Dst, std::floating_point _Src>
    inline constexpr
    void AssignWithOverflowCheck(_Dst& dst, const _Src src) noexcept {

        struct _DstSizeIsLarger {

            static void Invoke(_Dst& dst, const _Src src){
                dst = src;
            }
        };

        struct _DstSizeIsEqualOrSmaller {

            static void Invoke(_Dst& dst, const _Src src){

                [[likely]]
                if(src <= NumericLimits<_Dst>::Max())
                    dst = src;
                else {
                    assert(src <= NumericLimits<_Dst>::Max());
                    dst = NumericLimits<_Dst>::Max();
                }
            }
        };

        using Assigner =
                std::conditional_t<
                    (sizeof(_Dst) > sizeof(_Src)),
                    _DstSizeIsLarger,
                    _DstSizeIsEqualOrSmaller
                >;

        Assigner::Invoke(dst, src);
    }


    template<>
    inline constexpr
    void AssignWithOverflowCheck<int64_t, double>(int64_t& dst, const double src) noexcept {

        [[likely]]
        if(src < NumericLimits<int64_t, double>::Max())
            dst = src;
        else {
            assert((src < NumericLimits<int64_t, double>::Max()));
            dst = std::numeric_limits<int64_t>::max();
        }
    }

} // namespace _Fantasia::Algorithm
#pragma pack(pop)
#pragma warning(pop)
