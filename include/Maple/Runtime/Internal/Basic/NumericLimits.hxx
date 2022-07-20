//
// Created by 宋豪杰 on 2022/6/21.
//

#pragma once
#include "CodeLang.CXX.hxx"
#include "Preconfig.hxx"

#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple
{

    template<typename _Src, typename _Forms = _Src>
    class NumericLimits
    {
    public:
        static constexpr _Forms Max() {
            return std::numeric_limits<_Src>::max();
        }


        static constexpr _Forms Min() {
            return std::numeric_limits<_Src>::min();
        }


        static constexpr _Forms MaxLength() {

            _Forms length = 1;
            _Src quotient = Max();

            while (quotient /= 10) {
                ++length;
            }

            return length;
        }
    };


    template<>
    class NumericLimits<int64_t, double> {
    public:
        static constexpr double Max() {
            return 9223372036854775807.0;
        }
    };

}
#pragma pack(pop)
#pragma warning(pop)
