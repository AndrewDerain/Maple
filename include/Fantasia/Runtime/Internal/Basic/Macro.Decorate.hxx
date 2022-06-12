///
/// @file Basic.Macro.Decorate.hxx
/// 
/// @brief 本文件定义了提供给本项目开发者的一些修饰宏定义
/// 
/// @note 本文件中定义的宏均以两个下划线开始
/// @date 2021-02-20
/// 
#pragma once
#include "Macro.Preconfig.hxx"
#include "Macro.Function.hxx"


/// @breif Decorate impl


#define ___FANTASIA_DECORATE_0
#define ___FANTASIA_DECORATE_1(_D1)                     _D1
#define ___FANTASIA_DECORATE_2(_D1, _D2)                _D1 ## _ ## _D2
#define ___FANTASIA_DECORATE_3(_D1, _D2, _D3)           _D1 ## _ ## _D2 ## _ ## _D3
#define ___FANTASIA_DECORATE_4(_D1, _D2, _D3, _D4)      _D1 ## _ ## _D2 ## _ ## _D3 ## _ ## _D4


#define ___FANTASIA_DECORATE(...) \
    ___FANTASIA_MF_CAT( \
        ___FANTASIA_DECORATE_, \
        ___FANTASIA_MF_ARG ( \
            ___FANTASIA_MF_CAT( \
                ___FANTASIA_DECORATE_, ___FANTASIA_MF_ARG_COUNT(__VA_ARGS__) \
                ) \
                ___FANTASIA_MF_VAARGS_TRANS(__VA_ARGS__) \
        ) \
    )



/// 可用的参数值
/// TODO: 
#define __decorate(...)     ___FANTASIA_DECORATE(__VA_ARGS__)
