//
// Created by 宋豪杰 on 2022/7/11.
//

#pragma once
#include "../Internal/Frame/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Frame
{

    /// @brief 类型系统基类，所有的类型信息实现类均继承于此类
    struct Type
    {
        /// @brief 判断当前类型是否从 type 继承而来
        /// @note 暂未实现
        virtual Bool Inherites(const Type& type) const = 0;


        /// @brief 判断指定的类型是否与当前类型相等
        virtual Bool Equals(const Type& type) const = 0;


        /// @brief 获取未经处理的原始类型名
        virtual const char* RawName() const = 0;


        /// @brief 获取当前类型所有的父类型
        virtual const ITypeCollection& Parents() const = 0;


        /// @brief 判断指定的类型是否与当前类型相等，与 Equals 的结果相同
        virtual bool operator==(const Type& type) const = 0;
    };



    /// @brief 类型集合
    struct ITypeCollection
    {
        /// @brief 获取集合中的元素数量
        virtual Int64 Count() const = 0;


        /// @brief 判断类型 type 是否在此集合中
        virtual Bool IsContains(const Type& type) const = 0;


        virtual void Print() const = 0;
    };



    /// @brief 用于判断某个对象是否有成员变量 ___maple_typeinfo
    template<typename T>
    struct ___maple_has_typeinfo;



    template<typename T>
    using is_has_typeinfo = ___maple_has_typeinfo<T>;



    template<typename T>
    using is_has_typeinfo_v = typename ___maple_has_typeinfo<T>::value;



    /// @brief
    template<typename T>
    struct ___maple_typeof;



    #define typeof(_TYPE) ___maple_typeof<_TYPE>::instance()


} // namespace _Maple::Frame
#pragma pack(pop)
#pragma warning(pop)


#include "../Internal/Frame/Type.inl"
