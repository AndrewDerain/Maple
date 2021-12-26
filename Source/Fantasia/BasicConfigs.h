#pragma once


#define _FANTASIA_PACKING 8
#define _FANTASIA_PACK_PUSH __pragma(pack(push, _FANTASIA_PACKING))
#define _FANTASIA_PACK_POP  __pragma(pack(pop))



#define _FANTASIA_WARNING_DISABLE __pragma(warning(disable: 26812))


#define _FANTASIA_BEGIN \
_FANTASIA_PACK_PUSH \
    namespace Fantasia { \


#define _FANTASIA_END \
    } \
_FANTASIA_PACK_POP


#define _FANTASIA_MACROFUNC_ARGS_TRANS(...) (__VA_ARGS__)

#define _FANTASIA_MACROFUNC_CAT_MID(LEFT, RIGHT) LEFT ## RIGHT
#define _FANTASIA_MACROFUNC_CAT(LEFT, RIGHT)                     \
            _FANTASIA_MACROFUNC_CAT_MID(LEFT, RIGHT)

// 在编译期计算可变参数个数的辅助宏
#define _FANTASIA_MACROFUNC_ARG_T(ARGT) ARGT
#define _FANTASIA_MACROFUNC_ARG_N(                              \
            _01, _02, _03, _04, _05, _06, _07, _08, _09, _10,   \
            _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,   \
            _N, ...) _N  

#define _FANTASIA_MACROFUNC_ARG_H(...)                          \
            _FANTASIA_MACROFUNC_ARG_T(                          \
            _FANTASIA_MACROFUNC_ARG_N(__VA_ARGS__))

/// @brief 在编译期计算可变参数个数的宏
/// @note 支持10个以内的参数
#define _FANTASIA_MACROFUNC_ARG_COUNT(...)                      \
            _FANTASIA_MACROFUNC_ARG_H(__VA_ARGS__,              \
             20,  19,  18,  17,  16,  15,  14,  13,  12,  11,   \
             10,   9,   8,   7,   6,   5,   4,   3,   2,   1,   \
              0)



#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::string_view;

using std::uint32_t;