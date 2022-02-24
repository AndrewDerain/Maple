#pragma once
#include "Basic.hxx"


// namespace _Fantasia
#define __FANTASIA_FOUNDATION_DETAIL_BEGIN \
    ___FANTASIA_DETAIL_BEGIN


#define __FANTASIA_FOUNDATION_DETAIL_END \
    ___FANTASIA_DETAIL_END


// namespace Fantasia
#define __FANTASIA_FOUNDATION_BEGIN \
    ___FANTASIA_BEGIN \


#define __FANTASIA_FOUNDATION_END \
    ___FANTASIA_END


__FANTASIA_FOUNDATION_BEGIN
struct Bool;
struct Int64;
struct String;
struct Float64;

template<size_t _FixedSize>
class FixedString;
__FANTASIA_FOUNDATION_END
