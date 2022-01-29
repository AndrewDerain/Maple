#pragma once
#include <Runtime/Basic.Macro.ProjectDefine.hxx>
#include <Runtime/Foundation.Enum.hxx>

#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_BEGIN
namespace Finance
{

// 基础证券类型
struct Securities
{
    enum EnumUnifyTypeName 
    {
        /// @brief 商品
        Commodity,

        /// @brief 股票
        Stock,

        /// @brief 基金
        Fund,

        /// @brief 债券
        Bond,

        /// @brief 指数
        Index
    };

    EnumBasicActions(Securities, 
        Commodity, Stock, Fund, Bond, Index
    )
};


// 衍生品类型
struct Derivative
{
    enum EnumUnifyTypeName 
    {
        /// @brief 即期
        Spot,

        /// @brief 远期
        Forward,

        /// @brief 掉期
        Swap,

        /// @brief 期货
        Futures,

        /// @brief 期权
        Options
    };

    EnumBasicActions(Derivative,
        Spot, Forward, Swap, Futures, Options
    )
};


// 交易柜台
struct Counter
{
    enum EnumUnifyTypeName 
    {
        /// @brief 无柜台
        None, 

        /// @brief 上期技术CTP柜台
        CTP,

        /// @brief 上期技术Mini CTP柜台
        CTPMini
    };
    
    EnumBasicActions(Counter, 
        None, CTP
    )
};


/// @brief 柜台交易环境
struct CounterEnviroment
{
    enum EnumUnifyTypeName 
    {
        /// @brief 表示当前交易环境为仿真交易环境
        Simulation,

        /// @brief 表示当前交易环境为模拟交易环境
        Emulation,

        /// @brief 表示当前交易环境为实盘交易环境
        Reality
    };

    EnumBasicActions(CounterEnviroment, 
        Simulation, Emulation, Reality)
};


// 期权权利类型
struct OptionsRights
{
    enum EnumUnifyTypeName 
    {
        /// @brief 看涨期权
        Call,

        /// @brief 看跌期权
        Put
    };

    EnumBasicActions(OptionsRights,
        Call, 
        Put
    )
};


// 交易所
struct Exchange
{
    enum EnumUnifyTypeName 
    {    
        /// @brief 未知（CTP行情一般不会有ExchangeID返回）
        Unknow,

        /// @brief 北京证券交易所
        BJSE,

        /// @brief 郑州商品交易所
        CZCE,    
        
        /// @brief 中国金融期货交易所
        CFFEX,

        /// @brief 大连商品交易所
        DCE,

        /// @brief 上海期货交易所
        SHFE,

        /// @brief 深圳证券交易所
        SZSE,

        /// @brief 上海证券交易所
        SHSE,

        /// @brief 沪港通
        SHHK,

        /// @brief 深港通
        SZHK
    };

    EnumBasicActions(Exchange,
        Unknow, 
        BJSE, 
        CZCE, CFFEX,
        DCE,
        SHFE, SZSE, SHSE, SHHK, SZHK
    )
};


// 交易方向
struct TradeDirection
{
    enum EnumUnifyTypeName 
    {
        /// @brief 买入开仓
        BuyOpen,

        /// @brief 买入平仓
        BuyClose,

        /// @brief 卖出开仓
        SellOpen,

        /// @brief 卖出平仓
        SellClose
    };

    EnumBasicActions(TradeDirection, 
        BuyOpen, BuyClose, SellOpen, SellClose
    )

    bool IsBuy() {
        return _Value == BuyOpen || _Value == BuyClose;
    }

    bool IsSell() {
        return _Value == SellOpen || _Value == SellClose;
    }

    bool IsOpen() {
        return _Value == BuyOpen || _Value == SellOpen;
    }

    bool IsClose() {
        return _Value == BuyClose || _Value == SellClose;
    }
};


// 交易目的
struct TradePurpose
{
    enum EnumUnifyTypeName 
    {
        /// @brief 投机
        Speculation,

        /// @brief 套利
        Arbitrage,

        /// @brief 对冲
        Hedge,

        /// @brief 做市商
        MarketMaker
    };

    EnumBasicActions(TradePurpose,
        Speculation, Arbitrage, Hedge, MarketMaker
    )
};


// 委托状态
struct EntrustStatus
{
    enum EnumUnifyTypeName 
    {
        /// @brief 柜台已接受此次委托单
        CounterAccepted,

        /// @brief 柜台已拒绝此次委托单
        CounterRejected,

        /// @brief 委托单已报送交易所
        SubmitToExchange,

        /// @brief 交易所已接受
        ExchangeAccepted,

        /// @brief 交易所已拒绝
        ExchangeRejected,

        /// @brief 部分成交
        PartTraded,

        /// @brief 全部成交
        AllTraded,

        /// @brief 已撤销
        Canceled
    };

    EnumBasicActions(EntrustStatus, 
        CounterAccepted,
        CounterRejected,
        SubmitToExchange,
        ExchangeAccepted,
        ExchangeRejected,
        PartTraded,
        AllTraded,
        Canceled)
};



    
}
_FANTASIA_END
#pragma pack(pop)
#pragma warning(pop)
