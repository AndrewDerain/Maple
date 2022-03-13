/// 
/// @file Basic.Macro.Precofig.hxx
/// 
/// @brief 本文件定义了项目的预配置宏, 无需直接
/// 在项目代码中使用本文件中的宏。
/// 
/// @note 本文件中定义的宏均以三个下划线开始
/// @date 2021-02-20
/// 
#pragma once
#include "../Fantasia.CompileConfig"


/// @brief 用户设定的 header only 模式
#ifdef fantasia_enable_header_only
#   define ___FANTASIA_OPTION_HEADER_ONLY
#endif


/// @brief 用户设定的项目内连等级
#if defined(fantasia_enable_inline)
#   define ___FANTASIA_OPTION_INLINE
#endif


/// @brief 全局字节对齐选项，此项目默认为 8 字节对齐
#define ___FANTASIA_PACKING 8


/// @brief 可以忽略的错误警告
#define ___FANTASIA_WARNING_DISABLE_IDS \
            26812


/// @brief 项目根命名空间
#define ___FANTASIA_BEGIN              \
            namespace Fantasia {     
#define ___FANTASIA_END                \
            }                        


/// @brief 此命名空间内放置非用户直接使用的类，枚举等等
#define ___FANTASIA_DETAIL_BEGIN       \
            namespace _Fantasia {    
#define ___FANTASIA_DETAIL_END         \
            }


/// @brief [___FANTASIA_ALWAYS_EXPORT] - Always export
#if defined(_WIN32) || defined(__CYGWIN__)
#   if defined(__GNUC__)
#       if defined(___FNATASIA_EXPORTS)
#           define ___FANTASIA_ALWAYS_EXPORT __attribute__ ((dllexport))
#       else
#           define ___FANTASIA_ALWAYS_EXPORT __attribute__ ((dllimport))
#       endif
#   endif
#   if defined(_MSC_VER)
#       if defined(___FNATASIA_EXPORTS)
#           define ___FANTASIA_ALWAYS_EXPORT __declspec (dllexport)
#       else
#           define ___FANTASIA_ALWAYS_EXPORT __declspec (dllimport)
#       endif
#   endif
#else
#   if defined(__GNUC__)
#       if defined(___FNATASIA_EXPORTS)
#           define ___FANTASIA_ALWAYS_EXPORT __attribute__ ((visibility ("default")))
#       else
#           define ___FANTASIA_ALWAYS_EXPORT __attribute__ ((visibility ("default")))
#       endif
#   endif
#endif


/// @brief [___FANTASIA_ALWAYS_INLINE] - Always inline
#define ___FANTASIA_ALWAYS_INLINE           inline


/// @brief [___FANTASIA_ALWAYS_CONSTEXPR] 
#define ___FANTASIA_ALWAYS_CONSTEXPR        constexpr


/// @brief [___FANTASIA_API] - Api
#if defined(___FANTASIA_OPTION_HEADER_ONLY)
#    define ___FANTASIA_API                 ___FANTASIA_ALWAYS_INLINE
#else
#    define ___FANTASIA_API                 ___FANTASIA_ALWAYS_EXPORT
#endif


/// @brief [___FANTASIA_API_INLINE] - Api inline
#if defined(___FANTASIA_OPTION_HEADER_ONLY)
#    define ___FANTASIA_API_INLINE          ___FANTASIA_ALWAYS_INLINE
#else
#    if defined(___FANTASIA_OPTION_INLINE)
#        define ___FANTASIA_API_INLINE      ___FANTASIA_ALWAYS_INLINE
#    else
#        define ___FANTASIA_API_INLINE      ___FANTASIA_ALWAYS_EXPORT
#    endif
#endif


/// @brief 
#if defined(___FANTASIA_OPTION_HEADER_ONLY)
#    define ___FANTASIA_API_CONSTEXPR       ___FANTASIA_ALWAYS_CONSTEXPR
#else
#    if defined(___FANTASIA_OPTION_INLINE)
#        define ___FANTASIA_API_CONSTEXPR   ___FANTASIA_ALWAYS_CONSTEXPR
#    else
#        define ___FANTASIA_API_CONSTEXPR   
#    endif
#endif
