#pragma once
#include "Foundation.Enum.hxx"

#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_BEGIN

/// @brief 柜台交易环境
struct CounterEnviroment
{
    EnumElements
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
#pragma pack(pop)
#pragma warning(pop)
