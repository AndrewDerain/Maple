#pragma once
#include <Foundation/PackedEnum.h>

_FANTASIA_WARNING_DISABLE
_FANTASIA_BEGIN

/// @brief ��̨��������Э��
struct CounterConnectionProtocol
{
    enum _Type
    {
        /// @brief ʹ�� TCP Э�����̨����ͨ������
        TCP,

        /// @brief ʹ�� UDP Э�����̨����ͨ������
        UDP
    };

    packedenum(CounterConnectionProtocol, TCP, UDP);
};

_FANTASIA_END