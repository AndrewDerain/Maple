#pragma once
#include <Foundation/PackedEnum.h>

_FANTASIA_WARNING_DISABLE
_FANTASIA_BEGIN

/// @brief ���׻���
struct EmulationEnviroment
{
    enum _Type
    {
        /// @brief ��ʾ��ǰ���׻���Ϊ���潻�׻���
        Simulation,

        /// @brief ��ʾ��ǰ���׻���Ϊģ�⽻�׻���
        Emulation,

        /// @brief ��ʾ��ǰ���׻���Ϊʵ�̽��׻���
        Reality
    }; 

    packedenum(EmulationEnviroment, Simulation, Emulation, Reality);
};

_FANTASIA_END