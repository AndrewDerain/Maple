#pragma once
#include <BasicConfigs.h>
#include <Foundation/PackedEnum.h>

_FANTASIA_WARNING_DISABLE
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
