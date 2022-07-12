
#include "Maple/Visual/VisualObject.hxx"
#include "Maple/Runtime/Foundation/String.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Visual
{

    VisualObject::~VisualObject() noexcept {

    }


    String VisualObject::ToString() {
        return "VisualObject";
    }

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)
