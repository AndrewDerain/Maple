//
// Created by 宋豪杰 on 2022/3/31.
//

#pragma once
#include "../../Foundation/Int64.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
{

    template<typename _Ty, Size _Capacity>
    inline constexpr
    _Ty* begin(Array<_Ty, _Capacity>& arr) {
        return arr._Eles;
    }


    template<typename _Ty, Size _Capicity>
    inline constexpr
    _Ty* end(Array<_Ty, _Capicity>& arr) {
        return arr._Elements + _Capicity;
    }


    template<typename _Ty, int64_t _Capacity>
    Int64 Array<_Ty, _Capacity>::Capicity() const {
        return _Capacity;
    }


    template<typename _Ty, int64_t _Capacity>
    inline constexpr
    const _Ty & Array<_Ty, _Capacity>::operator[](const Int64 index) const {
        return _Elements[index];
    }

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)
