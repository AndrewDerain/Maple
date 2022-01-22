#pragma once
#include "Foundation.Enum.hxx"

#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_DETAIL_BEGIN
_FANTASIA_DETAIL_END

_FANTASIA_BEGIN
namespace System
{
    struct OperatingSystem
    {
        EnumElements
        {
            Windows,
            MacOS,
            Linux,
            Ubuntu,
        };
        
        EnumBasicActions(OperatingSystem,
            OpenGL, DirectX, Vulkan
        );
    };
    
}
_FANTASIA_END
#pragma pack(pop)
#pragma warning(pop)
