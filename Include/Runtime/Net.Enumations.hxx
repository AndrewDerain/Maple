#pragma once
#include "Foundation.Enum.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_BEGIN

namespace Net
{

    /// @brief 网络连接协议
    struct ConnectionProtocol
    {
        EnumElements
        {
            /// @brief 使用 TCP 建立网络连接
            TCP,

            /// @brief 使用 UDP 建立网络连接
            UDP
        };

        EnumBasicActions(ConnectionProtocol, TCP, UDP)
    };

}

_FANTASIA_END
#pragma pack(pop)
#pragma warning(pop)
