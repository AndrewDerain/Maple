/// 
/// @file Basic.Macro.UserDefinition.hxx
/// 
/// @brief 本文件定义宏运算相关宏
/// 
/// @date 2021-02-20
/// 
#pragma once


#define ___FANTASIA_MF_ARG(_ARG) _ARG
#define ___FANTASIA_MF_ARG_TRANS(_ARG) (_ARG)


#define ___FANTASIA_MF_VAARGS(...) __VA_ARGS__
#define ___FANTASIA_MF_VAARGS_TRANS(...) (__VA_ARGS__)


#define ___FANTASIA_MF_CAT_I(_ARG1, _ARG2) _ARG1 ## _ARG2
#define ___FANTASIA_MF_CAT(_ARG1, _ARG2) ___FANTASIA_MF_CAT_I(_ARG1, _ARG2)


#define ___FANTASIA_MF_ARG_COUNT_N(                                      \
            _01, _02, _03, _04, _05, _06, _07, _08, _09, _10,            \
            _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,            \
            _N, ...) _N                                                  \


#define ___FANTASIA_MF_ARG_COUNT_TRANS(...)                              \
            ___FANTASIA_MF_ARG(                                          \
            ___FANTASIA_MF_ARG_COUNT_N(__VA_ARGS__))                     \


/// @brief 计算宏参数的个数
#define ___FANTASIA_MF_ARG_COUNT(...)                                    \
            ___FANTASIA_MF_ARG_COUNT_TRANS(__VA_ARGS__,                  \
             20,  19,  18,  17,  16,  15,  14,  13,  12,  11,            \
             10,   9,   8,   7,   6,   5,   4,   3,   2,   1,            \
              0)
