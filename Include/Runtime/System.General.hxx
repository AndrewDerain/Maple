#pragma once
#include "System.Basic.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_DETAIL_BEGIN
__FANTASIA_DETAIL_END

__FANTASIA_BEGIN
namespace System
{
    struct OperatingSystem
    {
        enum EnumUnifyTypeName
        {
            Windows,
            MacOS,
            Linux,
            Ubuntu,
        };
        
        EnumBasicActions(OperatingSystem,
            Windows, MacOS, Linux
        );
    };
    
}
__FANTASIA_END
#pragma pack(pop)
#pragma warning(pop)
