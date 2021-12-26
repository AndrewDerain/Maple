#pragma once
#include <Foundation/PackedEnum.h>

_FANTASIA_WARNING_DISABLE
_FANTASIA_BEGIN

/// @brief 柜台链接网络协议
struct CounterConnectionProtocol
{
    enum _Type
    {
        /// @brief 使用 TCP 协议与柜台建立通信链接
        TCP,

        /// @brief 使用 UDP 协议与柜台建立通信链接
        UDP
    };

    packedenum(CounterConnectionProtocol, TCP, UDP);
};

_FANTASIA_END