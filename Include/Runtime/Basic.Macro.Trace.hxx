/// 
/// @file Basic.Macro.Trace.hxx
/// 
/// @brief 本文件定义了 Trace 相关宏
/// 
/// @note 本文件中定义的宏均以三个下划线开始
/// @date 2021-02-20
/// 
#pragma once
#include "Basic.Tracer.hxx"


#define ___FANTASIA_TRACE_ARG_NO_COMMA \
    _Fantasia::Tracer ___ParentTracer 


#define ___FANTASIA_TRACE_ARG \
    , ___FANTASIA_TRACE_ARG_NO_COMMA


#define ___FANTASIA_TRACE_SCOPE \
    _Fantasia::Tracer ___Tracer(__PRETTY_FUNCTION__);


#define ___FANTASIA_TRACE_SCOPE_CALL_STACK \
    _Fantasia::Tracer ___Tracer( \
        __PRETTY_FUNCTION__, ___ParentTracer)


#define ___FANTASIA_TRACE_WRITE_VAR(_VAR) \
    { \
        std::stringstream content; \
        content << "Name=\"" << #_VAR << "\"" << " Content=\"" << _VAR << "\""; \
        ___Tracer.WriteLine(content.str().c_str()); \
    }


#define ___FANTASIA_TRACE_WRITE_LINE(_CONTENT) \
    { \
        std::stringstream content; \
        content << " Content=\"" << _CONTENT << "\""; \
        ___Tracer.WriteLine(content.str()); \
    }


#define _InternalTraceScope          ___FANTASIA_TRACE_SCOPE
#define _InternalTraceVar(_VAR)      ___FANTASIA_TRACE_WRITE_VAR(_VAR)
#define _InternalTraceLine(_LINE)    ___FANTASIA_TRACE_WRITE_LINE(_LINE)
