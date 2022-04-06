//
// Created by 宋豪杰 on 2022/3/31.
//

#pragma once
#include "Fantasia/Runtime/Foundation/Int64.h"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Foundation
{

    template<typename _Ty, Size _Count>
    inline constexpr
    _Ty* begin(ArrayT<_Ty, _Count>& arr) {
        return arr._Eles;
    }


    template<typename _Ty, Size _Count>
    inline constexpr
    _Ty* end(ArrayT<_Ty, _Count>& arr) {
        return arr._Elements + _Count;
    }


    template<typename _Ty, int64_t _Count>
    Int64 ArrayT<_Ty, _Count>::Count() const {
        return _Count;
    }


    template<typename _Ty, int64_t _Count>
    inline constexpr
    _Ty& ArrayT<_Ty, _Count>::operator[](Int64 index) {
        return _Elements[index];
    }

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)