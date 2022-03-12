#pragma once
#include "Basic.Macro.Decorate.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
// _FANTASIA_DETAIL_BEGIN

// namespace _expander_test
// {
//     template<typename... _ArgTys>
//     struct expand_one;

//     template<typename _ArgTy, typename... _ArgTys>
//     struct expand_two;

//     template<>
//     struct expand_one<> {};

//     template<typename... Args>
//     struct expand_one: expand_two<Args...> {};

//     template<typename _ArgTy, typename... _ArgTys>
//     struct expand_two: expand_one<_ArgTys...> {};


//     // 
//     template<typename _BaseTy, typename... _ArgTys>
//     struct expandx_one;

//     template<typename _BaseTy>
//     struct expandx_one<_BaseTy> {};

//     template<typename _BaseTy, typename... _ArgTys>
//     struct expandx_one: _BaseTy{};


//     template<typename _ArgTy, typename... _ArgTys>
//     struct expandx_two;

//     template<typename _ArgTy>
//     struct expandx_two<_ArgTy> {};

//     template<typename _ArgTy, typename... _ArgTys>
//     struct expandx_two: expandx_one<expandx_two<_ArgTys...>, _ArgTys...>{};

//     // 
//     namespace ex
//     {
//         template<template<typename X> typename _Basic, typename... _ArgTys>
//         struct expand_one;

//         template<template<typename X> typename _Basic, typename _ArgTy, typename... _ArgTys>
//         struct expand_two;

//         template<template<typename X> typename _Basic>
//         struct expand_one<_Basic> {};

//         template<template<typename X> typename _Basic, typename _ArgTy>
//         struct expand_two<_Basic, _ArgTy>: _Basic<_ArgTy>
//         {
//             /* data */
//         };


//         template<
//             template<typename X> typename _Basic, 
//             typename... Args>
//         struct expand_one: expand_two<_Basic, Args...> {};

//         template<
//             template<typename X> typename _Basic, 
//             typename _ArgTy, 
//             typename... _ArgTys>
//         struct expand_two: expand_one<_Basic, _ArgTys...> {};

//         template<typename _Ty>
//         struct intermodel{};

//         struct gg : expand_two<intermodel, int>
//         {
//             /* data */ 
//         };

//     }
// }
// _FANTASIA_DETAIL_END


// _FANTASIA_DETAIL_BEGIN
// namespace Template::InheritanceChain
// {
// template<template<typename X> typename _Basic, typename... _ArgTys>
// struct Deliver;

// template<template<typename X> typename _Basic, typename _ArgTy, typename... _ArgTys>
// struct Expander;

// template<template<typename X> typename _Basic>
// struct Deliver<_Basic> {};

// template<template<typename X> typename _Basic, typename _ArgTy>
// struct Expander<_Basic, _ArgTy>: _Basic<_ArgTy>  {};

// template<template<typename X> typename _Basic, typename... _ArgTys>
// struct Deliver : virtual public Expander<_Basic, _ArgTys...> {};

// template<template<typename X> typename _Basic, typename _ArgTy, typename... _ArgTys>
// struct Expander: virtual public Deliver<_Basic, _ArgTys...> {};
// }
// _FANTASIA_DETAIL_END

// _FANTASIA_BEGIN
// namespace Template
// {
// template<template<typename X> typename _Basic, typename... _ArgTy>
// using InheritanceChainExpander = 
//     _Fantasia::Template::InheritanceChain::Expander<_Basic, _ArgTy...>;
// }
// _FANTASIA_END


__FANTASIA_DETAIL_BEGIN
namespace Template::InheritanceChain
{
template<
    typename _Wrapper, 
    template<typename _T1, typename _T2> 
        typename _Basic, 
    typename... _ArgTys>
struct Deliver;


template<
    typename _Wrapper, 
    template<typename _T1, typename _T2> typename _Basic, 
    typename _ArgTy, 
    typename... _ArgTys>
struct Expander;


template<
    typename _Wrapper, 
    template<typename _T1, typename _T2> typename _Basic>
struct Deliver<_Wrapper, _Basic> {};


template<
    typename _Wrapper, 
    template<typename _T1, typename _T2> typename _Basic, 
    typename _ArgTy>
struct Expander<_Wrapper, _Basic, _ArgTy> : 
    virtual _Basic<_Wrapper, _ArgTy>{};


template<
    typename _Wrapper, 
    template<typename _T1, typename _T2> typename _Basic, 
    typename... _ArgTys>
struct Deliver : virtual public Expander<_Wrapper, _Basic, _ArgTys...> {};


template<
    typename _Wrapper, 
    template<typename _T1, typename _T2> typename _Basic, 
    typename _ArgTy, 
    typename... _ArgTys>
struct Expander: 
    virtual public Deliver<_Wrapper, _Basic, _ArgTys...> 
    {
    };
}
__FANTASIA_DETAIL_END


__FANTASIA_BEGIN
namespace Template
{
template<typename _Wrapper, template<typename _T1, typename _T2> typename _Basic, typename... _ArgTy>
using InheritanceChainExpander = 
    _Fantasia::Template::InheritanceChain::Expander<_Wrapper, _Basic, _ArgTy...>;
}
__FANTASIA_END
#pragma pack(pop)
#pragma warning(pop)
