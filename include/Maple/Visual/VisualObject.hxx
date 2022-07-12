#pragma once
#include "../Runtime/Internal/Foundation/Predeclars.hxx"
#include "Maple/Runtime/TypeFrame/Object.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Visual
{

    MapleDeco(Maple, ApiClass)
    Class VisualObject: Object
    {
    public:
        virtual ~VisualObject() noexcept;

        virtual String ToString();
    };

} // namespace _Maple::Visual
#pragma pack(pop)
#pragma warning(pop)