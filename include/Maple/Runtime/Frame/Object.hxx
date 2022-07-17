﻿#pragma once
#include "../Internal/Frame/Predeclars.hxx"
#include "Type.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Frame
{

    /// @brief 使用此宏来定义 Object 类型的相关函数和类型定义
#define MapleObject(_TYPE)                                              \
            public:                                                    \
                ___MAPLE_TYPE_SYSTEM_USING_TYPEINFO(_TYPE)             \
            public:                                                     \
                ___MAPLE_TYPE_SYSTEM_QUERY_INTERFACE                    \
                                                                        \


    /// @brief 使用此宏来定义 接口 类型的相关函数和类型定义
#define MapleInterface(_TYPE)                                           \
            private:                                                    \
                ___MAPLE_TYPE_SYSTEM_USING_TYPEINFO(Object)             \


    MapleDeco(TypeRegister)(Object)
    MapleDeco(Maple, Runtime, ApiClass)
    Class Object
    {

        MapleObject(Object);


    public:
        Object() = default;


        virtual ~Object() noexcept;


        /// @brief 将对象转换为字符串，格式由实现决定
        virtual String ToString() const noexcept;


        /// @brief  判断指定的对象是否与当前对象相等
        ///         默认情况下，仅当地址相同时返回 true
        ///         子类可以重载此函数
        virtual Bool Equals(const Object *o) const noexcept;
    };

    //constexpr ___Maple_TypeInfo_Object ___Maple_TypeInfo_Object::instance {};
} // namespace _Maple::Frame
#pragma pack(pop)
#pragma warning(pop)
