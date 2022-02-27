#pragma once
#include "Foundation.Basic.hxx"
#include "Foundation.Int64.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_DETAIL_BEGIN

template<typename _Ty, Size _Size>
__always_inine __always_constexpr
_Ty* begin(ArrayT<_Ty, _Size>& arr);


template<typename _Ty, Size _Size>
__always_inine __always_constexpr
_Ty* end(ArrayT<_Ty, _Size>& arr);


template<typename _Ty, Size _Size>
__always_inine __always_constexpr
const _Ty* cbegin(const ArrayT<_Ty, _Size>& arr);


template<typename _Ty, Size _Size>
__always_inine __always_constexpr
const _Ty* cend(const ArrayT<_Ty, _Size>& arr);


/// @brief 数组
template<typename _Ty, Size _Size>
struct ArrayT
{
public:
    __always_inine __always_constexpr
    ArrayT() : _Eles{} {};


    __always_inine __always_constexpr
    ~ArrayT() {};


    __always_inine __always_constexpr
    Int64 Count() const;


    __always_inine __always_constexpr
    _Ty& operator[](Int64 index);


protected:
    friend __always_inine __always_constexpr 
    _Ty* _Fantasia::begin(ArrayT<_Ty, _Size>&);


    friend __always_inine __always_constexpr 
    _Ty* _Fantasia::end(ArrayT<_Ty, _Size>&);


    _Ty _Eles[_Size];
};


template<typename _Ty, int64_t _Size>
__always_inine __always_constexpr
Int64 ArrayT<_Ty, _Size>::Count() const {
    return _Size;
}


template<typename _Ty, int64_t _Size>
__always_inine __always_constexpr
_Ty& ArrayT<_Ty, _Size>::operator[](Int64 index) {
    return _Eles[index];
}


template<typename _Ty, Size _Size>
__always_inine __always_constexpr
_Ty* begin(ArrayT<_Ty, _Size>& arr) {
    return arr._Eles;
}


template<typename _Ty, Size _Size>
__always_inine __always_constexpr
_Ty* end(ArrayT<_Ty, _Size>& arr) {
    return arr._Eles + _Size;
}

__FANTASIA_FOUNDATION_DETAIL_END


__FANTASIA_FOUNDATION_BEGIN
template<typename _Ty, _Fantasia::Size _Size>
using Array = _Fantasia::ArrayT<_Ty, _Size>;
__FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)
