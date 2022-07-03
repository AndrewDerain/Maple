//
// Created by 宋豪杰 on 2022/7/2.
//

#pragma once
#include "Macro.Function.hxx"


#define ___MAPLE_MF_ARGS_EXPANDER_1(                                               \
            _01                                                                    \
            )                                                                      \
            _01


#define ___MAPLE_MF_ARGS_EXPANDER_2(                                               \
            _01, _02                                                               \
            )                                                                      \
            _01, _02


#define ___MAPLE_MF_ARGS_EXPANDER_3(                                               \
            _01, _02, _03                                                          \
            )                                                                      \
            _01, _02, _03


#define ___MAPLE_MF_ARGS_EXPANDER_4(                                               \
            _01, _02, _03, _04                                                     \
            )                                                                      \
            _01, _02, _03, _04


#define ___MAPLE_MF_ARGS_EXPANDER_5(                                               \
            _01, _02, _03, _04, _05                                                \
            )                                                                      \
            _01, _02, _03, _04, _05


#define ___MAPLE_MF_ARGS_EXPANDER_6(                                               \
            _01, _02, _03, _04, _05, _06                                           \
            )                                                                      \
            _01, _02, _03, _04, _05, _06


#define ___MAPLE_MF_ARGS_EXPANDER_7(                                               \
            _01, _02, _03, _04, _05, _06, _07                                      \
            )                                                                      \
            _01, _02, _03, _04, _05, _06, _07


#define ___MAPLE_MF_ARGS_EXPANDER_8(                                               \
            _01, _02, _03, _04, _05, _06, _07, _08                                 \
            )                                                                      \
            _01, _02, _03, _04, _05, _06, _07, _08


#define ___MAPLE_MF_ARGS_EXPANDER_9(                                               \
            _01, _02, _03, _04, _05, _06, _07, _08, _09                            \
            )                                                                      \
            _01, _02, _03, _04, _05, _06, _07, _08, _09


#define ___MAPLE_MF_ARGS_EXPANDER_10(                                              \
            _01, _02, _03, _04, _05, _06, _07, _08, _09, _10                       \
            )                                                                      \
            _01, _02, _03, _04, _05, _06, _07, _08, _09, _10


#define ___MAPLE_MF_ARGS_EXPANDER(...)                                          \
            ___MAPLE_MF_ARG(                                                    \
                ___MAPLE_MF_CAT(                                                \
                    ___MAPLE_MF_ARGS_EXPANDER_,                                 \
                    ___MAPLE_MF_ARG_COUNT(__VA_ARGS__)                          \
                )___MAPLE_MF_VAARGS_TRANS(__VA_ARGS__)                          \
            )
