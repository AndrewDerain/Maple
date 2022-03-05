#pragma once
#include "Foundation.Basic.hxx"
#include "Foundation.Int64.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_DETAIL_BEGIN

template<typename _Ty, Size _Count>
__always_inline __always_constexpr
_Ty* begin(ArrayT<_Ty, _Count>& arr);


template<typename _Ty, Size _Count>
__always_inline __always_constexpr
_Ty* end(ArrayT<_Ty, _Count>& arr);


template<typename _Ty, Size _Count>
__always_inline __always_constexpr
const _Ty* cbegin(const ArrayT<_Ty, _Count>& arr);


template<typename _Ty, Size _Count>
__always_inline __always_constexpr
const _Ty* cend(const ArrayT<_Ty, _Count>& arr);


/// @brief 数组
template<typename _Ty, Size _Count>
struct ArrayT
{
public:
    /// @brief 构造函数。设为 default 以支持 standard_layout 和 trival。
    ArrayT() = default;


    /// @brief 析构函数。设为 default 以支持 standard_layout 和 trival。
    ~ArrayT() = default;


    /// @brief 拷贝构造函数。设为 default 以支持 standard_layout 和 trival。
    ArrayT(const ArrayT&) = default;


    __always_inline __always_constexpr
    Int64 Count() const;


    __always_inline __always_constexpr
    _Ty& operator[](Int64 index);


    /// @brief 赋值操作符。设为 default 以支持 standard_layout 和 trival。
    ArrayT& operator=(const ArrayT&) = default;


protected:
    friend __always_inline __always_constexpr 
    _Ty* _Fantasia::begin(ArrayT<_Ty, _Count>&);


    friend __always_inline __always_constexpr 
    _Ty* _Fantasia::end(ArrayT<_Ty, _Count>&);


    _Ty _Eles[_Count];
};


template<typename _Ty, int64_t _Count>
__always_inline __always_constexpr
Int64 ArrayT<_Ty, _Count>::Count() const {
    return _Count;
}


template<typename _Ty, int64_t _Count>
__always_inline __always_constexpr
_Ty& ArrayT<_Ty, _Count>::operator[](Int64 index) {
    return _Eles[index];
}


template<typename _Ty, Size _Count>
__always_inline __always_constexpr
_Ty* begin(ArrayT<_Ty, _Count>& arr) {
    return arr._Eles;
}


template<typename _Ty, Size _Count>
__always_inline __always_constexpr
_Ty* end(ArrayT<_Ty, _Count>& arr) {
    return arr._Eles + _Count;
}

__FANTASIA_FOUNDATION_DETAIL_END


__FANTASIA_FOUNDATION_BEGIN
template<typename _Ty, _Fantasia::Size _Count>
using Array = _Fantasia::ArrayT<_Ty, _Count>;
__FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)
