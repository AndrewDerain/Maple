//
// Created by 宋豪杰 on 2022/6/12.
//
#pragma once
#include "Fantasia/Runtime/Internal/Basic/CodeLang.CXX.hxx"
#include "Number.inl"


namespace _Fantasia::Algorithm
{

    inline constexpr
    int64_t CountStringLength(const char *string) noexcept {
        int64_t len = 0;
        while (string[len] != '\0') len++;
        return len;
    }


    inline constexpr
    int64_t CompareString(
            const char         *left,
            const int64_t       left_length,
            const char         *right,
            const int64_t       right_length) noexcept {

        for (int64_t i = 0; i < left_length && i < right_length; ++i) {
            if (left[i] != right[i])
                return left[i] - right[i];
        }

        return left_length - right_length;
    }


    inline constexpr
    int64_t CompareString(const char *left, const char *right) noexcept {

        int64_t left_length = CountStringLength(left);
        int64_t right_length = CountStringLength(right);

        return CompareString(left, left_length, right, right_length);
    }


    /// @param left_capacity 必须大于0
    inline constexpr
    void CopyString(
            char*           left,
            int64_t         left_capacity,
            const char*     right,
            int64_t         right_length) {

        int i = 0; --left_capacity;

        for(; i < left_capacity && i < right_length; ++i) {
            left[i] = right[i];
        }

        left[i] = '\0';
    }


    template<std::integral _LenTy>
    inline constexpr
    void CatenateStringT(
            char           *left,
            _LenTy         &left_length,
            _LenTy          left_capacity,
            const char     *right,
            _LenTy          right_length) {

        int li = left_length, ri = 0; --left_capacity;

        for(; li < left_capacity && ri < right_length; ++li, ++ri) {
            left[li] = right[ri];
        }

        left[li] = '\0';
        left_length = li;
    }


    inline constexpr
    void CatenateString(
            char           *left,
            int8_t         &left_length,
            int8_t          left_capacity,
            const char     *right,
            int8_t          right_length) {

        CatenateStringT(left, left_length, left_capacity, right, right_length);
    }


    inline constexpr
    void CatenateString(
            char           *left,
            uint16_t       &left_length,
            uint16_t        left_capacity,
            const char     *right,
            uint16_t        right_length) {

        CatenateStringT(left, left_length, left_capacity, right, right_length);
    }


    template<std::integral _T>
    inline constexpr
    int8_t ConvertSignedIntegerToStringT(
            _T              ival,
            char           *sval) {

        bool is_negative = IsNegative(ival);
        ival = Abs(ival);

        int8_t slen = 0;
        do{
            sval[slen++] = ival % 10 + '0';
        } while (ival /= 10);

        if(is_negative) sval[slen++] = '-';
        sval[slen] = '\0';

        for(int lpos = 0, rpos = slen - 1; lpos < rpos; ++lpos, --rpos) {
            Swap(sval[lpos], sval[rpos]);
        }

        return slen;
    }


    template<std::integral _T>
    inline constexpr
    int8_t ConvertUnsignedIntegerToStringT(
            _T              ival,
            char           *sval) {

        int8_t slen = 0;
        do{
            sval[slen++] = ival % 10 + '0';
        } while (ival /= 10);

        sval[slen] = '\0';

        for(int lpos = 0, rpos = slen - 1; lpos < rpos; ++lpos, --rpos) {
            Swap(sval[lpos], sval[rpos]);
        }

        return slen;
    }


    inline constexpr
    int8_t ConvertInt16ToString(
            int16_t         ival,
            char           *sval) {

        return ConvertSignedIntegerToStringT(ival, sval);
    }


    inline constexpr
    int8_t ConvertUInt16ToString(
            uint16_t        ival,
            char           *sval) {

        return ConvertUnsignedIntegerToStringT(ival, sval);
    }


    inline constexpr
    int8_t ConvertInt32ToString(
            int32_t         ival,
            char           *sval) {

        return ConvertSignedIntegerToStringT(ival, sval);
    }


    inline constexpr
    int8_t ConvertUInt32ToString(
            uint32_t        ival,
            char           *sval) {

        return ConvertUnsignedIntegerToStringT(ival, sval);
    }

}