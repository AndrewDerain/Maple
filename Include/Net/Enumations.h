#pragma once
#include <BasicConfigs.hxx>
#include <Foundation/PackedEnum.hxx>

#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_BEGIN

namespace Net
{

    /// @brief 网络连接协议
    struct ConnectionProtocol
    {
        enum _Type
        {
            /// @brief 使用 TCP 建立网络连接
            TCP,

            /// @brief 使用 UDP 建立网络连接
            UDP
        };

        EnumBasicAction(ConnectionProtocol, TCP, UDP)
    };



}

_FANTASIA_END
#pragma pack(pop)
#pragma warning(pop)
