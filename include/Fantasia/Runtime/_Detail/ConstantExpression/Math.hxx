#pragma once
#include "Fantasia/Runtime/_Detail/Basic/CodeLang.CXX.hxx"
#include "Fantasia/Runtime/_Detail/Basic/Macro.Preconfig.hxx"
#include "Fantasia/Runtime/_Detail/Basic/Macro.Decorate.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::ConstantExpression
{

    /// @brief  求绝对值
    inline constexpr
    double Abs(double value) {
        if(value < 0)
            value = - value;
        return value;
    }


    inline constexpr
    int32_t Abs(int32_t value) {
        if(value < 0)
            value = -value;
        return value;
    }


    /// @brief  求平方根
    inline constexpr
    double Sqrt(double value) {

        return 0;
    }


    inline constexpr
    int32_t Ave(int32_t va, int32_t vb) {
        return (va & vb) + ((va ^ vb) >> 1);
    }

} // _Fantasia::ConstantExpression
#pragma pack(pop)
#pragma warning(pop)