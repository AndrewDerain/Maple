#pragma once
#include "../_Detail/Foundation/Predeclars.hxx"
#include "Int64.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Foundation
{
    template<typename _Ty, Size _Count>
    struct ArrayT;


    template<typename _Ty, Size _Count>
    _Ty* begin(ArrayT<_Ty, _Count>& arr);


    template<typename _Ty, Size _Count>
    _Ty* end(ArrayT<_Ty, _Count>& arr);


    template<typename _Ty, Size _Count>
    const _Ty* cbegin(const ArrayT<_Ty, _Count>& arr);


    template<typename _Ty, Size _Count>
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

        [[maybe_unused]]
        Int64 Count() const;


        _Ty& operator[](Int64 index);


        /// @brief 赋值操作符。设为 default 以支持 standard_layout 和 trival。
        ArrayT& operator=(const ArrayT&) = default;


    protected:
        friend 
        _Ty* _Fantasia::Foundation::begin(ArrayT<_Ty, _Count>&);


        friend 
        _Ty* _Fantasia::Foundation::end(ArrayT<_Ty, _Count>&);


        _Ty _Eles[_Count];
    };


    // POD 校验。standard layout and trivial。
    static_assert(std::is_trivial_v<ArrayT<int, 5>>, "ArrayT must be trivial!");
    static_assert(std::is_standard_layout_v<ArrayT<int, 5>>, "ArrayT must be standard layout!");


    template<typename _Ty, int64_t _Count>
    [[maybe_unused]] 
    Int64 ArrayT<_Ty, _Count>::Count() const {
        return _Count;
    }


    template<typename _Ty, int64_t _Count>
    
    _Ty& ArrayT<_Ty, _Count>::operator[](Int64 index) {
        return _Eles[index];
    }


    template<typename _Ty, Size _Count>
    
    _Ty* begin(ArrayT<_Ty, _Count>& arr) {
        return arr._Eles;
    }


    template<typename _Ty, Size _Count>
    
    _Ty* end(ArrayT<_Ty, _Count>& arr) {
        return arr._Eles + _Count;
    }

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)
