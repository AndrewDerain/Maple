#pragma once
#include "../Internal/Foundation/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Foundation
{

    template<typename _Ty, Size _Count>
    inline constexpr
    _Ty* begin(ArrayT<_Ty, _Count>& arr);


    template<typename _Ty, Size _Count>
    inline constexpr
    _Ty* end(ArrayT<_Ty, _Count>& arr);


    /// @brief  数组
    /// @note   满足 standard layout 和 trivial
    template<typename _Ty, Size _Count>
    struct ArrayT
    {
    public:
        /// @brief 构造函数。设为 default 以支持 standard_layout 和 trivial。
        ArrayT() = default;


        /// @brief 析构函数。设为 default 以支持 standard_layout 和 trivial。
        ~ArrayT() = default;


        /// @brief 移动构造函数。设为 default 以支持 standard_layout 和 trivial。
        ArrayT(ArrayT&&) = default;


        /// @brief 拷贝构造函数。设为 default 以支持 standard_layout 和 trivial。
        ArrayT(const ArrayT&) = default;


        Int64 Count() const;


        inline constexpr
        _Ty& operator[](const Int64 index);


        /// @brief 赋值操作符。设为 default 以支持 standard_layout 和 trivial。
        ArrayT& operator=(ArrayT&&) = default;


        /// @brief 赋值操作符。设为 default 以支持 standard_layout 和 trivial。
        ArrayT& operator=(const ArrayT&) = default;


    protected:
        _Ty _Elements[_Count];

    
    private:
        template<typename, Size> 
        friend _Ty* begin(ArrayT<_Ty, _Count>& arr);


        template<typename, Size> 
        friend _Ty* end(ArrayT<_Ty, _Count>& arr);
    };


    // POD 校验。standard layout and trivial。
    static_assert(std::is_trivial_v<ArrayT<int, 5>>, "ArrayT must be trivial!");
    static_assert(std::is_standard_layout_v<ArrayT<int, 5>>, "ArrayT must be standard layout!");

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)

#include "../Internal/Foundation/ArrayT.inl"
