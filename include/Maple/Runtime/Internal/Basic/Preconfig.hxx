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


/// @brief 全局字节对齐选项，此项目默认为 8 字节对齐
#define ___MAPLE_PACKING 8


/// @brief 可以忽略的错误警告
#define ___MAPLE_WARNING_DISABLE_IDS \
            26812


/// @brief 调试
#ifdef ___MAPLE_DEBUG
#   define __MAPLE_DEBUG
#endif


/// @brief [___MAPLE_API]
/// @details 此宏指定某个函数在项目中是被导出的
#if defined(_WIN32) || defined(__CYGWIN__)
#   if defined(__GNUC__)
#       if defined(___MAPLE_EXPORTS)
#           define ___MAPLE_API __attribute__ ((dllexport))
#       else
#           define ___MAPLE_API __attribute__ ((dllimport))
#       endif
#   endif
#   if defined(_MSC_VER)
#       if defined(___MAPLE_EXPORTS)
#           define ___MAPLE_API __declspec (dllexport)
#       else
#           define ___MAPLE_API __declspec (dllimport)
#       endif
#   endif
#else
#   if defined(__GNUC__)
#       if defined(___MAPLE_EXPORTS)
#           define ___MAPLE_API __attribute__ ((visibility ("default")))
#       else
#           define ___MAPLE_API __attribute__ ((visibility ("default")))
#       endif
#   endif
#endif


#define ___MAPLE_DECORATE_Maple_Api             ___MAPLE_API
#define ___MAPLE_DECORATE_Maple_ApiClass        class ___MAPLE_API
