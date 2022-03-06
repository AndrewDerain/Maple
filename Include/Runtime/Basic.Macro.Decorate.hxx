///
/// @file Basic.Macro.Decorate.hxx
/// 
/// @brief 本文件定义了提供给本项目开发者的一些修饰宏定义
/// 
/// @note 本文件中定义的宏均以两个下划线开始
/// @date 2021-02-20
/// 
#pragma once
#include "Basic.Macro.Preconfig.hxx"


/// @brief 项目根命名空间
#define __FANTASIA_BEGIN          ___FANTASIA_BEGIN
#define __FANTASIA_END            ___FANTASIA_END


/// @brief 此命名空间内放置非用户直接使用的类，枚举等等
#define __FANTASIA_DETAIL_BEGIN   ___FANTASIA_DETAIL_BEGIN
#define __FANTASIA_DETAIL_END     ___FANTASIA_DETAIL_END


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


#define Property
