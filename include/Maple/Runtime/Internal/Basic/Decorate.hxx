///
/// @file Basic.Macro.Decorate.hxx
/// 
/// @brief 本文件定义了提供给本项目开发者的一些修饰宏定义
/// 
/// @note 本文件中定义的宏均以两个下划线开始
/// @date 2021-02-20
/// 
#pragma once
#include "Preconfig.hxx"
#include "Macro.Function.hxx"


/// @breif Decorate impl


#define ___MAPLE_DECORATE_0


#define ___MAPLE_DECORATE_1(_D1)                                        \
            _D1


#define ___MAPLE_DECORATE_2(_D1, _D2)                                   \
            _D1 ## _ ## _D2


#define ___MAPLE_DECORATE_3(_D1, _D2, _D3)                              \
            _D1 ## _ ## _D2 ## _ ## _D3


#define ___MAPLE_DECORATE_4(_D1, _D2, _D3, _D4)                         \
            _D1 ## _ ## _D2 ## _ ## _D3 ## _ ## _D4


#define ___MAPLE_DECORATE(...)                                          \
    ___MAPLE_MF_CAT(                                                    \
        ___MAPLE_DECORATE_,                                             \
        ___MAPLE_MF_ARG (                                               \
            ___MAPLE_MF_CAT(                                            \
                ___MAPLE_DECORATE_, ___MAPLE_MF_ARG_COUNT(__VA_ARGS__)  \
                )                                                       \
                ___MAPLE_MF_VAARGS_TRANS(__VA_ARGS__)                   \
        )                                                               \
    )


#define __decorate(...)     ___MAPLE_DECORATE(__VA_ARGS__)
