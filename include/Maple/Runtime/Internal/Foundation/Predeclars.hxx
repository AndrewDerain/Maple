#pragma once
#include "../../Internal/Basic/CodeLang.CXX.hxx"
#include "../../Internal/Basic/Preconfig.hxx"
#include "../../Internal/Basic/Macro.ArgsExpander.hxx"
#include "../../Internal/Basic/Decorate.hxx"
#include "Maple/Runtime/Internal/Algorithm/String.inl"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Maple::Foundation
{

    /// @brief  表示数据的大小
    using Size = std::int64_t;

    template<typename _Ty, Size _Count>
    struct ArrayT;

    struct Bool;

    struct Float64;

    struct Int32;
    struct Int64;

    struct String;

    template<size_t _FixedSize>
    class StringT;

} // _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)
