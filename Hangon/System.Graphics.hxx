#pragma once
#include "System.Basic.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
__FANTASIA_SYSTEM_DETAIL_BEGIN
__FANTASIA_SYSTEM_DETAIL_END

__FANTASIA_SYSTEM_BEGIN
namespace System
{
    struct GraphicsDriverCategory
    {
        enum EnumUnifyTypeName
        {
            OpenGL,
            DirectX,
            Vulkan
        };
        
        EnumBasicActions(GraphicsDriverCategory,
            OpenGL, DirectX, Vulkan
        );
    };
    
}
__FANTASIA_SYSTEM_END
#pragma pack(pop)
#pragma warning(pop)
