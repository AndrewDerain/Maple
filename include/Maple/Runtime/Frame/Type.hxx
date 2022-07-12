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

    class Type
    {
    public:
        Type() = default;

        Type(Type&&) = delete;

        Type(const Type&) = delete;

        Type& operator=(Type&&) = delete;


        virtual Bool IsInheritedFrom(const Type& type) const = 0;


        virtual Bool Equals(const Type& type) const = 0;

        //virtual Object* NewInstance(...) {return nullptr;};
        virtual const char* RawName() const = 0;


        virtual const set<const char*>& ParentRawNames() const = 0;
    };


    template<typename  _T>
    constexpr
    const auto& ___typeof() {
        return  _T::___MapleType::TypeInfo;
    }

    #define typeof(_OBJECT)  ___typeof<_OBJECT>()

} // namespace _Maple::TypeFrame
#pragma pack(pop)
#pragma warning(pop)