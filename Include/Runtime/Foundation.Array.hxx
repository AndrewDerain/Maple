#pragma once
#include "Foundation.Basic.hxx"
#include "Foundation.Int64.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_DETAIL_BEGIN

template<typename _Ty, Size _Size>
__always_inine
_Ty* begin(ArrayT<_Ty, _Size>& arr);


template<typename _Ty, Size _Size>
__always_inine
_Ty* end(ArrayT<_Ty, _Size>& arr);


template<typename _Ty, Size _Size>
struct ArrayT
{
public:
    __always_inine
    ArrayT() : _Eles{} {};


    __always_inine
    ~ArrayT() {};


    __always_inine __always_constexpr
    Int64 Count();


    __always_inine 
    _Ty& operator[](Int64 index);


protected:
    friend inline _Ty* _Fantasia::begin(ArrayT<_Ty, _Size>&);
    friend inline _Ty* _Fantasia::end(ArrayT<_Ty, _Size>&);

    _Ty _Eles[_Size];
};


template<typename _Ty, int64_t _Size>
__always_inine __always_constexpr
Int64 ArrayT<_Ty, _Size>::Count() {
    return _Size;
}


template<typename _Ty, int64_t _Size>
__always_inine
_Ty& ArrayT<_Ty, _Size>::operator[](Int64 index) {
    return _Eles[index];
}


template<typename _Ty, Size _Size>
__always_inine
_Ty* begin(ArrayT<_Ty, _Size>& arr) {
    return arr._Eles;
}


template<typename _Ty, Size _Size>
__always_inine
_Ty* end(ArrayT<_Ty, _Size>& arr) {
    return arr._Eles + _Size;
}


/// @brief 以 '\0' 字符结尾的固定长度字符串
/// @param _FixedSize 字符串长度，包含 '\0' 字符
template<typename _Derivative, size_t _FixedSize>
struct FixedStringT
{
public:
    __always_inine
    FixedStringT();


    __always_inine
    ~FixedStringT();


};


template<typename _Derivative, size_t _FixedSize>
__always_inine
FixedStringT<_Derivative, _FixedSize>::FixedStringT() {
    
}

__FANTASIA_FOUNDATION_DETAIL_END


__FANTASIA_FOUNDATION_BEGIN
using _Fantasia::ArrayT;
__FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)
