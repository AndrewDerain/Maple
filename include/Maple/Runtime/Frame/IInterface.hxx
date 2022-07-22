//
// Created by 宋豪杰 on 2022/7/20.
//

#pragma once
#include "../Internal/Frame/Predeclars.hxx"
#include "Type.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple
{

    /// @brief 使用此宏来定义 接口 类型的相关函数和类型定义
    #define MapleInterface(_TYPE)                                       \
                private:                                                \
                    ___MAPLE_TYPE_SYSTEM_USING_TYPEINFO(_TYPE)          \


    MapleDeco(TypeRegister)(IInterface)
    struct IInterface
    {
    MapleInterface(IInterface)

    public:
        virtual void* QueryInterface(const Type& type) const = 0;
    };

} // namespace _Maple
#pragma pack(pop)
#pragma warning(pop)