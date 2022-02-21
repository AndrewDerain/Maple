#pragma once
#include "Network.Basic.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_NETWORK_DETAIL_BEGIN
struct IPv4
{
    char Seg[4];
    unsigned short Port;
};
__FANTASIA_NETWORK_DETAIL_END



__FANTASIA_NETWORK_BEGIN

/// @brief 网络传输协议
struct CommunicationsProtocol
{
    enum EnumUnifyTypeName
    {
        /// @brief 传输控制协议
        TCP,

        /// @brief 用户数据报协议
        UDP,

        /// @brief 超文本传输协议
        HTTP,

        /// @brief 安全超文本传输协议
        HTTPS
    };

    EnumBasicActions(CommunicationsProtocol, 
        TCP, UDP, HTTP, HTTPS
    )
};


/// @brief 网络协议版本
struct InternetProtocolVersion
{
    enum EnumUnifyTypeName
    {
        IPv4,
        IPv6
    };

    EnumBasicActions(InternetProtocolVersion, 
        IPv4, IPv6
    )
};


/// @brief 网络地址
struct NetworkAddress
{
    CommunicationsProtocol  Protocol;
    InternetProtocolVersion Version;

    union{
        _Fantasia::Network::IPv4 _Addv4;
    };


};

__FANTASIA_NETWORK_END
#pragma pack(pop)
#pragma warning(pop)
