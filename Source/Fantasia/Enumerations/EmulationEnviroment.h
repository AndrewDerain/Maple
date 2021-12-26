#pragma once
#include <Foundation/PackedEnum.h>

_FANTASIA_WARNING_DISABLE
_FANTASIA_BEGIN

/// @brief 交易环境
struct EmulationEnviroment
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

    packedenum(EmulationEnviroment, Simulation, Emulation, Reality);
};

_FANTASIA_END