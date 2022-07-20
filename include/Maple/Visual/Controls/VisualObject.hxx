#pragma once
#include "../Internal/Controls/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Visual
{

    MapleDeco(TypeRegister)(VisualObject, Object)
    MapleDeco(Maple, Visual, ApiClass)
    Class VisualObject: Object
    {
    MapleObject(VisualObject)

    public:
        virtual ~VisualObject() noexcept;

        virtual String ToString();
    };

} // namespace _Maple::Visual
#pragma pack(pop)
#pragma warning(pop)
