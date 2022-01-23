﻿#pragma once


#define _FANTASIA_MF_ARG(_ARG) _ARG
#define _FANTASIA_MF_ARG_TRANS(_ARG) (_ARG)


#define _FANTASIA_MF_VAARGS(...) __VA_ARGS__
#define _FANTASIA_MF_VAARGS_TRANS(...) (__VA_ARGS__)


#define __FANTASIA_MF_CAT(_ARG1, _ARG2) _ARG1 ## _ARG2
#define _FANTASIA_MF_CAT(_ARG1, _ARG2) __FANTASIA_MF_CAT(_ARG1, _ARG2)


#define __FANTASIA_MF_ARG_COUNT_N(                                       \
            _01, _02, _03, _04, _05, _06, _07, _08, _09, _10,            \
            _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,            \
            _N, ...) _N                                                  \

#define __FANTASIA_MF_ARG_COUNT_TRANS(...)                               \
            _FANTASIA_MF_ARG(                                            \
            __FANTASIA_MF_ARG_COUNT_N(__VA_ARGS__))                      \

#define _FANTASIA_MF_ARG_COUNT(...)                                      \
            __FANTASIA_MF_ARG_COUNT_TRANS(__VA_ARGS__,                   \
             20,  19,  18,  17,  16,  15,  14,  13,  12,  11,            \
             10,   9,   8,   7,   6,   5,   4,   3,   2,   1,            \
              0)                                                         