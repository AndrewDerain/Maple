#pragma once
#include "../Internal/Foundation/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
{

    template<typename _Ty, Size _Capacity>
    inline constexpr
    _Ty* begin(Array<_Ty, _Capacity>& arr);


    template<typename _Ty, Size _Capacity>
    inline constexpr
    _Ty* end(Array<_Ty, _Capacity>& arr);


    /// @brief  数组
    /// @note   满足 standard layout 和 trivial
    template<typename _Ty, Size _Capacity>
    struct Array
    {
    public:
        /// @brief 构造函数。设为 default 以支持 standard_layout 和 trivial。
        Array() = default;


        /// @brief 析构函数。设为 default 以支持 standard_layout 和 trivial。
        ~Array() = default;


        /// @brief 移动构造函数。设为 default 以支持 standard_layout 和 trivial。
        Array(Array&&) = default;


        /// @brief 拷贝构造函数。设为 default 以支持 standard_layout 和 trivial。
        Array(const Array&) = default;


        Int64 Capacity() const;


        inline constexpr
        const _Ty& operator[](const Int64 index) const;


        /// @brief 赋值操作符。设为 default 以支持 standard_layout 和 trivial。
        Array& operator=(Array&&) = default;


        /// @brief 赋值操作符。设为 default 以支持 standard_layout 和 trivial。
        Array& operator=(const Array&) = default;


    protected:
        _Ty _Elements[_Capacity];

    
    private:
        template<typename, Size> 
        friend _Ty* begin(Array<_Ty, _Capacity>& arr);


        template<typename, Size> 
        friend _Ty* end(Array<_Ty, _Capacity>& arr);
    };


    // POD 校验。standard layout and trivial。
    static_assert(std::is_trivial_v<Array<int, 5>>, "ArrayT must be trivial!");
    static_assert(std::is_standard_layout_v<Array<int, 5>>, "ArrayT must be standard layout!");

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)

#include "../Internal/Foundation/Array.inl"
