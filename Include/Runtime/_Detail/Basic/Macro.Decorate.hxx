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


/// @brief 此宏表示此项目的使用者希望所有文件都是 Header only 的
#ifdef ___FANTASIA_OPTION_HEADER_ONLY
#   define __FANTASIA_OPTION_HEADER_ONLY
#endif


/// @brief 此宏表示此项目的使用者希望尽可能多的函数被定义为内连
#ifdef ___FANTASIA_OPTION_INLINE
#   define __FANTASIA_OPTION_INLINE 1
#endif


/// @brief 此宏指定某个函数在项目中总是被导出的
#define __api                ___FANTASIA_API 


/// @brief 此宏表示被修饰的函数适合内连，但也可以导出
#define __api_inline         ___FANTASIA_API_INLINE


/// @brief 此宏指定某个函数在项目中总是内连的
#define __always_inline       ___FANTASIA_ALWAYS_INLINE


/// @brief 此宏表示被修饰的函数是常量表达式，但也可以导出
#define __api_constexpr      ___FANTASIA_API_CONSTEXPR


/// @brief 此宏指定某个函数在项目中总是一个常量表达式，不导出
#define __always_constexpr   ___FANTASIA_ALWAYS_CONSTEXPR


// interface
#define ___FANTASIA_DECORATE_Fantasia_inline       ___FANTASIA_ALWAYS_INLINE
#define ___FANTASIA_DECORATE_Fantasia_constexpr    ___FANTASIA_ALWAYS_CONSTEXPR

#define ___FANTASIA_DECORATE_Fantasia_inline_constexpr \
    ___FANTASIA_ALWAYS_INLINE  ___FANTASIA_ALWAYS_CONSTEXPR


#define ___FANTASIA_DECORATE_Fantasia_api                ___FANTASIA_API
#define ___FANTASIA_DECORATE_Fantasia_api_inline         ___FANTASIA_API_INLINE
#define ___FANTASIA_DECORATE_Fantasia_api_constexpr      ___FANTASIA_API_CONSTEXPR

#define ___FANTASIA_DECORATE_Fantasia_api_inline_constexpr \
    ___FANTASIA_API_INLINE  ___FANTASIA_API_CONSTEXPR
// interface


#define ___FANTASIA_DECORATE_0  
#define ___FANTASIA_DECORATE_1(_D1)                 _D1
#define ___FANTASIA_DECORATE_2(_D1, _D2)            _D1 ## _ ## _D2
#define ___FANTASIA_DECORATE_3(_D1, _D2, _D3)       _D1 ## _ ## _D2 ## _ ## _D3
#define ___FANTASIA_DECORATE_4(_D1, _D2, _D3, _D4)    _D1 ## _ ## _D2 ## _ ## _D3 ## _ ## _D4


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
#define __Decorate(...)  ___FANTASIA_DECORATE(__VA_ARGS__)
    


// //constexpr auto x = 
// __Decorate(Fantasia, inline) auto x = 9;


// __Decorate(Fantasia, inline)auto x3 = 0;
// __Decorate(Fantasia, constexpr) auto x4 = ___FANTASIA_MF_ARG_COUNT();
// __Decorate(Fantasia, inline, constexpr)auto x5 = 0;

// __Decorate(Fantasia, api) auto x6 = 0;
// __Decorate(Fantasia, api, inline) auto x7 = 0;
// __Decorate(Fantasia, api, constexpr) auto x8 = 0;
// __Decorate(Fantasia, api, inline, constexpr) auto x9 = 0;



#define Property
