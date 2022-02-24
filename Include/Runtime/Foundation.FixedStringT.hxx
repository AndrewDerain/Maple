#pragma once
#include "Foundation.Basic.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_BEGIN

template<typename _Ty, size_t _Size>
struct ArrayT
{
public:
    __always_inine
    ArrayT();

    
    __always_inine
    ~ArrayT();


protected:
    _Ty _Eles[_Size];
};


template<typename _Ty, size_t _Size>
__always_inine
ArrayT<_Ty, _Size>::ArrayT():
    _Eles{} {
}


template<typename _Ty, size_t _Size>
__always_inine
ArrayT<_Ty, _Size>::~ArrayT() {
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

__FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)
