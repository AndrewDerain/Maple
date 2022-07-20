
#include "Maple/Runtime/Frame/Object.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Frame
{

    String Object::ToString() const noexcept {
        return "Object";
    }


    Bool Object::Equals(const Object *o) const noexcept {
        return this == o;
    }

} // namespace _Maple::Frame
#pragma pack(pop)
#pragma warning(pop)



#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple
{
} // namespace _Maple
#pragma pack(pop)
#pragma warning(pop)
