#pragma once
#include "../../Internal/Basic/CodeLang.CXX.hxx"
#include "../../Internal/Basic/Macro.ArgsExpander.hxx"
#include "../../Internal/Basic/Preconfig.hxx"
#include "../../Internal/Basic/Decorate.hxx"
#include "../../Internal/Algorithm/String.inl"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
{

    /// @brief  表示数据的大小
    using Size = std::int64_t;

    template<typename _Ty, Size _Count>
    struct Array;

    struct Bool;

    struct Byte;

    struct Int32;

    struct Int64;

    struct String;

    struct Double;

    template<size_t _FixedSize>
    class StringT;

} // _Maple::Foundation

namespace _Maple { using namespace _Maple::Foundation; }
#pragma pack(pop)
#pragma warning(pop)
