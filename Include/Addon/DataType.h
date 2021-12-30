#pragma once
#include <BasicConfigs.h>
#include <Foundation/PackedEnum.h>

_FANTASIA_WARNING_DISABLE
_FANTASIA_BEGIN

/// @brief 柜台交易环境
struct CounterEnviroment
{
    enum _Type
    {
        /// @brief 表示当前交易环境为仿真交易环境
        Simulation,

        /// @brief 表示当前交易环境为模拟交易环境
        Emulation,

        /// @brief 表示当前交易环境为实盘交易环境
        Reality
    };

    EnumBasicAction(CounterEnviroment, Simulation, Emulation, Reality)
};


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

    EnumBasicAction(CounterConnectionProtocol, TCP, UDP)
};


// 基础证券类型
struct SecuritiesCategory
{
    enum _Type
    {
        Commodity,              // 商品
        Stock,                  // 股票
        Fund,                   // 基金
        Bond,                   // 债券
        Index                   // 指数
    };

    EnumBasicAction(SecuritiesCategory, Commodity, Stock, Fund, Bond, Index)
};

_FANTASIA_END
