#pragma once
#include "../Basic/CodeLang.CXX.hxx"
#include "../Basic/Macro.Preconfig.hxx"
#include "../Basic/Macro.Decorate.hxx"


namespace _Fantasia::Foundation
{

    using Size = std::int64_t;


    struct Bool;


    struct Int64;


    struct String;


    struct Float64;


    template<size_t _FixedSize>
    class FixedString;


    template<typename _Ty, Size _Size>
    struct ArrayT;

} // _Fantasia::Foundation


// // Bool的单元测试辅助宏
// #ifdef ___FANTASIA_ENABLE_UNITTEST_Bool
// #   define ___FANTASIA_UnitTestHelper_Bool \
//     	___FANTASIA_UnitTestHelper_(Bool)
// #	define ___FANTASIA_UnitTestHelper_Bool_Setter \
// 		___FANTASIA_UnitTestHelper_Setter(Bool)
// #else
// #   define ___FANTASIA_UnitTestHelper_Bool
// #	define ___FANTASIA_UnitTestHelper_Bool_Setter
// #endif


// // Int64的单元测试辅助宏
// #ifdef ___FANTASIA_ENABLE_UNITTEST_Int64
// #   define ___FANTASIA_UnitTestHelper_Int64 \
// 		___FANTASIA_UnitTestHelper_(Int64)

// 	extern __api ___FANTASIA_UnitTestHelper_Int64;
// #else
// #	define ___FANTASIA_UnitTestHelper_Int64
// #	define ___FANTASIA_UnitTestHelper_Int64_OverloadFunctionName(_NAME)
// #endif
