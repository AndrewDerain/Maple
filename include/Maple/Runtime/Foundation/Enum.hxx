#pragma once
#include "../Internal/Foundation/Predeclars.hxx"
#include "String.hxx"


#define __MAPLE_ENUM_CTOR(_WRAP)                                                \
    private:                                                                    \
        _Type _Value;                                                           \
                                                                                \
    public:                                                                     \
        inline constexpr _WRAP()                    = default;                  \
                                                                                \
        inline constexpr ~_WRAP()                   = default;                  \
                                                                                \
        inline constexpr _WRAP(_WRAP&&)             = default;                  \
                                                                                \
        inline constexpr _WRAP(const _WRAP&)        = default;                  \
                                                                                \
        inline constexpr _WRAP(const _Type value)   { _Value = value; }         \
                                                                                \
        inline constexpr                                                        \
        operator _Type() const              { return _Value;}                   \
                                                                                \
        inline constexpr                                                        \
        _WRAP& operator=(_WRAP&&)           = default;                          \
                                                                                \
        inline constexpr                                                        \
        _WRAP& operator=(const _WRAP&)      = default;                          \
                                                                                \
        inline constexpr                                                        \
        _WRAP& operator=(const _Type value) { _Value = value; return *this; }   \


#define __MAPLE_ENUM_STRING_TYPE char*


#define __MAPLE_ENUM_TOSTR_BEG            switch(_Value) {
#define __MAPLE_ENUM_TOSTR_CASE(_ELE)         case _ELE: return #_ELE;
#define __MAPLE_ENUM_TOSTR_DEFA(_ELE)         default:   return #_ELE;
#define __MAPLE_ENUM_TOSTR_END            } return "";


#define __MAPLE_ENUM_FROMSTR_BEG
#define __MAPLE_ENUM_FROMSTR_CASE(_ELE)                                         \
            if(_Maple::Algorithm::CompareString(value, #_ELE) == 0) {           \
                _Value = _ELE; return;                                          \
            }
#define __MAPLE_ENUM_FROMSTR_DEFA(_ELE)   _Value = _ELE;
#define __MAPLE_ENUM_FROMSTR_END


#define __MAPLE_ENUM_CONVERTER_1(_E01)                                          \
    inline const __MAPLE_ENUM_STRING_TYPE ToString() const {                    \
        __MAPLE_ENUM_TOSTR_BEG                                                  \
            __MAPLE_ENUM_TOSTR_CASE(_E01)                                       \
        __MAPLE_ENUM_TOSTR_END                                                  \
    }                                                                           \
    inline void FromString(const __MAPLE_ENUM_STRING_TYPE value) {              \
        __MAPLE_ENUM_FROMSTR_BEG                                                \
            __MAPLE_ENUM_FROMSTR_CASE(_E01)                                     \
        __MAPLE_ENUM_FROMSTR_END                                                \
    }                                                                           \


#define __MAPLE_ENUM_CONVERTER_2(_E01, _E02)                                    \
    inline const __MAPLE_ENUM_STRING_TYPE ToString() const {                    \
        __MAPLE_ENUM_TOSTR_BEG                                                  \
            __MAPLE_ENUM_TOSTR_CASE(_E01)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E02)                                       \
        __MAPLE_ENUM_TOSTR_END                                                  \
    }                                                                           \
    inline void FromString(const __MAPLE_ENUM_STRING_TYPE value) {              \
        __MAPLE_ENUM_FROMSTR_BEG                                                \
            __MAPLE_ENUM_FROMSTR_CASE(_E01)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E02)                                     \
        __MAPLE_ENUM_FROMSTR_END                                                \
    }                                                                           \


#define __MAPLE_ENUM_CONVERTER_3(_E01, _E02, _E03)                              \
    inline const __MAPLE_ENUM_STRING_TYPE ToString() const {                    \
        __MAPLE_ENUM_TOSTR_BEG                                                  \
            __MAPLE_ENUM_TOSTR_CASE(_E01)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E02)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E03)                                       \
        __MAPLE_ENUM_TOSTR_END                                                  \
    }                                                                           \
    inline void FromString(const __MAPLE_ENUM_STRING_TYPE value) {              \
        __MAPLE_ENUM_FROMSTR_BEG                                                \
            __MAPLE_ENUM_FROMSTR_CASE(_E01)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E02)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E03)                                     \
        __MAPLE_ENUM_FROMSTR_END                                                \
    }                                                                           \


#define __MAPLE_ENUM_CONVERTER_4(_E01, _E02, _E03, _E04)                        \
    inline const __MAPLE_ENUM_STRING_TYPE ToString() const {                    \
        __MAPLE_ENUM_TOSTR_BEG                                                  \
            __MAPLE_ENUM_TOSTR_CASE(_E01)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E02)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E03)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E04)                                       \
        __MAPLE_ENUM_TOSTR_END                                                  \
    }                                                                           \
    inline void FromString(const __MAPLE_ENUM_STRING_TYPE value) {              \
        __MAPLE_ENUM_FROMSTR_BEG                                                \
            __MAPLE_ENUM_FROMSTR_CASE(_E01)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E02)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E03)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E04)                                     \
        __MAPLE_ENUM_FROMSTR_END                                                \
    }                                                                           \


#define __MAPLE_ENUM_CONVERTER_5(_E01, _E02, _E03, _E04, _E05)                  \
    inline const __MAPLE_ENUM_STRING_TYPE ToString() const {                    \
        __MAPLE_ENUM_TOSTR_BEG                                                  \
            __MAPLE_ENUM_TOSTR_CASE(_E01)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E02)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E03)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E04)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E05)                                       \
        __MAPLE_ENUM_TOSTR_END                                                  \
    }                                                                           \
    inline void FromString(const __MAPLE_ENUM_STRING_TYPE value) {              \
        __MAPLE_ENUM_FROMSTR_BEG                                                \
            __MAPLE_ENUM_FROMSTR_CASE(_E01)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E02)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E03)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E04)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E05)                                     \
        __MAPLE_ENUM_FROMSTR_END                                                \
    }                                                                           \


#define __MAPLE_ENUM_CONVERTER_6(_E01, _E02, _E03, _E04, _E05, _E06)            \
    inline const __MAPLE_ENUM_STRING_TYPE ToString() const {                    \
        __MAPLE_ENUM_TOSTR_BEG                                                  \
            __MAPLE_ENUM_TOSTR_CASE(_E01)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E02)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E03)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E04)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E05)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E06)                                       \
        __MAPLE_ENUM_TOSTR_END                                                  \
    }                                                                           \
    inline void FromString(const __MAPLE_ENUM_STRING_TYPE value) {              \
        __MAPLE_ENUM_FROMSTR_BEG                                                \
            __MAPLE_ENUM_FROMSTR_CASE(_E01)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E02)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E03)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E04)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E05)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E06)                                     \
        __MAPLE_ENUM_FROMSTR_END                                                \
    }                                                                           \


#define __MAPLE_ENUM_CONVERTER_7(_E01, _E02, _E03, _E04, _E05, _E06, _E07)      \
    inline const __MAPLE_ENUM_STRING_TYPE ToString() const {                    \
        __MAPLE_ENUM_TOSTR_BEG                                                  \
            __MAPLE_ENUM_TOSTR_CASE(_E01)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E02)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E03)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E04)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E05)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E06)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E07)                                       \
        __MAPLE_ENUM_TOSTR_END                                                  \
    }                                                                           \
    inline void FromString(const __MAPLE_ENUM_STRING_TYPE value) {              \
        __MAPLE_ENUM_FROMSTR_BEG                                                \
            __MAPLE_ENUM_FROMSTR_CASE(_E01)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E02)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E03)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E04)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E05)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E06)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E07)                                     \
        __MAPLE_ENUM_FROMSTR_END                                                \
    }                                                                           \


#define __MAPLE_ENUM_CONVERTER_8(_E01, _E02, _E03, _E04, _E05, _E06, _E07,      \
                                    _E08)                                       \
    inline const __MAPLE_ENUM_STRING_TYPE ToString() const {                    \
        __MAPLE_ENUM_TOSTR_BEG                                                  \
            __MAPLE_ENUM_TOSTR_CASE(_E01)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E02)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E03)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E04)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E05)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E06)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E07)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E08)                                       \
        __MAPLE_ENUM_TOSTR_END                                                  \
    }                                                                           \
    inline void FromString(const __MAPLE_ENUM_STRING_TYPE value) {              \
        __MAPLE_ENUM_FROMSTR_BEG                                                \
            __MAPLE_ENUM_FROMSTR_CASE(_E01)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E02)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E03)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E04)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E05)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E06)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E07)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E08)                                     \
        __MAPLE_ENUM_FROMSTR_END                                                \
    }         


#define __MAPLE_ENUM_CONVERTER_9(_E01, _E02, _E03, _E04, _E05, _E06, _E07,      \
                                    _E08, _E09)                                 \
    inline const __MAPLE_ENUM_STRING_TYPE ToString() const {                    \
        __MAPLE_ENUM_TOSTR_BEG                                                  \
            __MAPLE_ENUM_TOSTR_CASE(_E01)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E02)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E03)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E04)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E05)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E06)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E07)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E08)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E09)                                       \
        __MAPLE_ENUM_TOSTR_END                                                  \
    }                                                                           \
    inline void FromString(const __MAPLE_ENUM_STRING_TYPE value) {              \
        __MAPLE_ENUM_FROMSTR_BEG                                                \
            __MAPLE_ENUM_FROMSTR_CASE(_E01)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E02)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E03)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E04)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E05)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E06)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E07)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E08)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E09)                                     \
        __MAPLE_ENUM_FROMSTR_END                                                \
    } 


#define __MAPLE_ENUM_CONVERTER_10(_E01, _E02, _E03, _E04, _E05, _E06, _E07,     \
                                     _E08, _E09, _E10)                          \
    inline const __MAPLE_ENUM_STRING_TYPE ToString() const {                    \
        __MAPLE_ENUM_TOSTR_BEG                                                  \
            __MAPLE_ENUM_TOSTR_CASE(_E01)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E02)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E03)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E04)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E05)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E06)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E07)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E08)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E09)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E10)                                       \
        __MAPLE_ENUM_TOSTR_END                                                  \
    }                                                                           \
    inline void FromString(const __MAPLE_ENUM_STRING_TYPE value) {              \
        __MAPLE_ENUM_FROMSTR_BEG                                                \
            __MAPLE_ENUM_FROMSTR_CASE(_E01)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E02)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E03)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E04)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E05)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E06)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E07)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E08)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E09)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E10)                                     \
        __MAPLE_ENUM_FROMSTR_END                                                \
    } 


#define __MAPLE_ENUM_CONVERTER_11(_E01, _E02, _E03, _E04, _E05, _E06, _E07,     \
                                     _E08, _E09, _E10, _E11)                    \
    inline const __MAPLE_ENUM_STRING_TYPE ToString() const {                    \
        __MAPLE_ENUM_TOSTR_BEG                                                  \
            __MAPLE_ENUM_TOSTR_CASE(_E01)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E02)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E03)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E04)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E05)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E06)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E07)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E08)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E09)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E10)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E11)                                       \
        __MAPLE_ENUM_TOSTR_END                                                  \
    }                                                                           \
    inline void FromString(const __MAPLE_ENUM_STRING_TYPE value) {              \
        __MAPLE_ENUM_FROMSTR_BEG                                                \
            __MAPLE_ENUM_FROMSTR_CASE(_E01)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E02)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E03)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E04)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E05)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E06)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E07)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E08)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E09)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E10)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E11)                                     \
        __MAPLE_ENUM_FROMSTR_END                                                \
    } 


#define __MAPLE_ENUM_CONVERTER_12(_E01, _E02, _E03, _E04, _E05, _E06, _E07,     \
                                     _E08, _E09, _E10, _E11, _E12)              \
    inline const __MAPLE_ENUM_STRING_TYPE ToString() const {                    \
        __MAPLE_ENUM_TOSTR_BEG                                                  \
            __MAPLE_ENUM_TOSTR_CASE(_E01)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E02)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E03)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E04)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E05)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E06)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E07)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E08)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E09)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E10)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E11)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E12)                                       \
        __MAPLE_ENUM_TOSTR_END                                                  \
    }                                                                           \
    inline void FromString(const __MAPLE_ENUM_STRING_TYPE value) {              \
        __MAPLE_ENUM_FROMSTR_BEG                                                \
            __MAPLE_ENUM_FROMSTR_CASE(_E01)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E02)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E03)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E04)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E05)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E06)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E07)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E08)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E09)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E10)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E11)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E12)                                     \
        __MAPLE_ENUM_FROMSTR_END                                                \
    }


#define __MAPLE_ENUM_CONVERTER_13(_E01, _E02, _E03, _E04, _E05, _E06, _E07,     \
                                     _E08, _E09, _E10, _E11, _E12, _E13)        \
    inline const __MAPLE_ENUM_STRING_TYPE ToString() const {                    \
        __MAPLE_ENUM_TOSTR_BEG                                                  \
            __MAPLE_ENUM_TOSTR_CASE(_E01)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E02)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E03)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E04)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E05)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E06)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E07)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E08)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E09)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E10)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E11)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E12)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E13)                                       \
        __MAPLE_ENUM_TOSTR_END                                                  \
    }                                                                           \
    inline void FromString(const __MAPLE_ENUM_STRING_TYPE value) {              \
        __MAPLE_ENUM_FROMSTR_BEG                                                \
            __MAPLE_ENUM_FROMSTR_CASE(_E01)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E02)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E03)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E04)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E05)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E06)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E07)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E08)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E09)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E10)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E11)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E12)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E13)                                     \
        __MAPLE_ENUM_FROMSTR_END                                                \
    }


#define __MAPLE_ENUM_CONVERTER_14(_E01, _E02, _E03, _E04, _E05, _E06, _E07,     \
                                     _E08, _E09, _E10, _E11, _E12, _E13, _E14)  \
    inline const __MAPLE_ENUM_STRING_TYPE ToString() const {                    \
        __MAPLE_ENUM_TOSTR_BEG                                                  \
            __MAPLE_ENUM_TOSTR_CASE(_E01)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E02)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E03)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E04)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E05)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E06)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E07)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E08)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E09)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E10)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E11)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E12)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E13)                                       \
            __MAPLE_ENUM_TOSTR_CASE(_E14)                                       \
        __MAPLE_ENUM_TOSTR_END                                                  \
    }                                                                           \
    inline void FromString(const __MAPLE_ENUM_STRING_TYPE value) {              \
        __MAPLE_ENUM_FROMSTR_BEG                                                \
            __MAPLE_ENUM_FROMSTR_CASE(_E01)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E02)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E03)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E04)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E05)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E06)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E07)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E08)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E09)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E10)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E11)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E12)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E13)                                     \
            __MAPLE_ENUM_FROMSTR_CASE(_E14)                                     \
        __MAPLE_ENUM_FROMSTR_END                                                \
    } 


#define __MAPLE_ENUM_STRING_CONVERTER(...)                                      \
            ___MAPLE_MF_ARG(                                                    \
                ___MAPLE_MF_CAT(                                                \
                    __MAPLE_ENUM_CONVERTER_,                                    \
                    ___MAPLE_MF_ARG_COUNT(__VA_ARGS__)                          \
                )___MAPLE_MF_VAARGS_TRANS(__VA_ARGS__)                          \
            )                                                                   \


#define __EnumBasicActions(_WRAP, ...)                                          \
            __MAPLE_ENUM_CTOR(_WRAP)                                            \
            __MAPLE_ENUM_STRING_CONVERTER(__VA_ARGS__)                          \


#define EnumerationImplementation(_WRAP, ...)                                   \
            enum _Type {                                                        \
                ___MAPLE_MF_ARGS_EXPANDER(__VA_ARGS__)                          \
            };                                                                  \
            __EnumBasicActions(_WRAP, __VA_ARGS__)
