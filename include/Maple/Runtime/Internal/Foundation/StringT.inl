//
// Created by 宋豪杰 on 2022/3/31.
//

#pragma once
#include "../../Foundation/String.hxx"
#include "../../Foundation/StringT.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Maple::Foundation
{

    template<size_t _FixedSize>
    inline constexpr
    Bool operator==(
            const StringT<_FixedSize>& _Left,
            const char* const _Right) {

        return (_Left._Equal(_Right));
    }


    template<size_t _FixedSize>
    inline constexpr
    void StringT<_FixedSize>::Assign(const char* str) {
        CopyString(
                this->data(),
                _FixedSize,
                str,
                Algorithm::CountStringLength(str));
    }


    template<size_t _FixedSize>
    template<size_t _SourceSize>
    inline
    void StringT<_FixedSize>::Assign(StringT<_SourceSize>& source_str) {
        std::conditional<
                (_SourceSize <= _FixedSize),
                _FixedString_assign_from_smaller<_FixedSize, _SourceSize>,
                _FixedString_assign_from_larger<_FixedSize, _SourceSize>
            >::type::assign(this, source_str);
    }


    template<size_t _FixedSize>
    inline constexpr
    const char* StringT<_FixedSize>::c_str() {
        return this->data();
    }


    template<size_t _FixedSize>
    inline constexpr
    size_t StringT<_FixedSize>::Length() const {
        return strlen(this->data());
    }


    template<size_t _FixedSize>
    inline constexpr
    int StringT<_FixedSize>::Compare(const char* str) {
        return CompareString(this->data(), str);
    }


    template<size_t _FixedSize>
    inline constexpr
    StringT<_FixedSize>& StringT<_FixedSize>::operator=(const char* str) {
        Assign(str);
        return *this;
    }


    template<size_t _FixedSize>
    inline bool StringT<_FixedSize>::_Equal(const char* const right) const {
        return strcmp(this->data(), right) == 0;
    }

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)
