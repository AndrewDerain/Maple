#pragma once
#include "Basic.Macro.Function.hxx"
#include "Basic.CodeLang.CXX.hxx"

#define _FANTASIA_ENUM_CTOR(_WRAP)                                                \
    private:                                                                      \
        _Type _Value;                                                             \
    public:                                                                       \
        inline _WRAP() = default;                                                 \
        inline _WRAP(const _WRAP& wrapper)  { _Value = wrapper._Value; }          \
        inline _WRAP(const _Type value)     { _Value = value; }                   \
        inline operator _Type() const       { return _Value;}


#define _FANTASIA_ENUM_TOSTR_BEG            switch(_Value) {
#define _FANTASIA_ENUM_TOSTR_CASE(_ELE)         case _ELE: return #_ELE;
#define _FANTASIA_ENUM_TOSTR_DEFA(_ELE)         default: return #_ELE;
#define _FANTASIA_ENUM_TOSTR_END            }                                     \
                                            return "";


#define _FANTASIA_ENUM_FROMSTR_BEG
#define _FANTASIA_ENUM_FROMSTR_CASE(_ELE)   if(strcmp(value, #_ELE) == 0) {       \
                                               _Value = _ELE; return;             \
                                            }
#define _FANTASIA_ENUM_FROMSTR_DEFA(_ELE)   _Value = _ELE;
#define _FANTASIA_ENUM_FROMSTR_END


#define _FANTASIA_ENUM_CONVERTER_1(_E01)                                          \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E01)                                       \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E01)                                     \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }                                                                             \


#define _FANTASIA_ENUM_CONVERTER_2(_E01, _E02)                                    \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E01)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E02)                                       \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E01)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E02)                                     \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }                                                                             \


#define _FANTASIA_ENUM_CONVERTER_3(_E01, _E02, _E03)                              \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E01)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E02)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E03)                                       \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E01)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E02)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E03)                                     \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }                                                                             \


#define _FANTASIA_ENUM_CONVERTER_4(_E01, _E02, _E03, _E04)                        \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E01)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E02)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E03)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E04)                                       \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E01)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E02)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E03)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E04)                                     \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }                                                                             \


#define _FANTASIA_ENUM_CONVERTER_5(_E01, _E02, _E03, _E04, _E05)                  \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E01)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E02)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E03)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E04)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E05)                                       \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E01)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E02)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E03)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E04)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E05)                                     \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }                                                                             \


#define _FANTASIA_ENUM_CONVERTER_6(_E01, _E02, _E03, _E04, _E05, _E06)            \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E01)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E02)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E03)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E04)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E05)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E06)                                       \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E01)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E02)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E03)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E04)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E05)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E06)                                     \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }                                                                             \


#define _FANTASIA_ENUM_CONVERTER_7(_E01, _E02, _E03, _E04, _E05, _E06, _E07)      \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E01)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E02)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E03)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E04)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E05)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E06)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E07)                                       \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E01)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E02)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E03)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E04)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E05)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E06)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E07)                                     \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }                                                                             \

#define _FANTASIA_ENUM_CONVERTER_8(_E01, _E02, _E03, _E04, _E05, _E06, _E07,      \
                                   _E08)                                          \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E01)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E02)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E03)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E04)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E05)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E06)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E07)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E08)                                       \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E01)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E02)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E03)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E04)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E05)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E06)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E07)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E08)                                     \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }         

#define _FANTASIA_ENUM_CONVERTER_9(_E01, _E02, _E03, _E04, _E05, _E06, _E07,      \
                                   _E08, _E09)                                    \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E01)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E02)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E03)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E04)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E05)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E06)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E07)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E08)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E09)                                       \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E01)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E02)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E03)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E04)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E05)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E06)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E07)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E08)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E09)                                     \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    } 

#define _FANTASIA_ENUM_CONVERTER_10(_E01, _E02, _E03, _E04, _E05, _E06, _E07,     \
                                    _E08, _E09, _E10)                             \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E01)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E02)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E03)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E04)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E05)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E06)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E07)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E08)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E09)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E10)                                       \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E01)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E02)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E03)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E04)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E05)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E06)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E07)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E08)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E09)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E10)                                     \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    } 

#define _FANTASIA_ENUM_CONVERTER_11(_E01, _E02, _E03, _E04, _E05, _E06, _E07,     \
                                    _E08, _E09, _E10, _E11)                       \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E01)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E02)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E03)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E04)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E05)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E06)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E07)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E08)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E09)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E10)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E11)                                       \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E01)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E02)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E03)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E04)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E05)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E06)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E07)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E08)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E09)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E10)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E11)                                     \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    } 

#define _FANTASIA_ENUM_CONVERTER_12(_E01, _E02, _E03, _E04, _E05, _E06, _E07,     \
                                    _E08, _E09, _E10, _E11, _E12)                 \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E01)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E02)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E03)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E04)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E05)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E06)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E07)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E08)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E09)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E10)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E11)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E12)                                       \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E01)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E02)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E03)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E04)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E05)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E06)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E07)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E08)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E09)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E10)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E11)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E12)                                     \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    } 

#define _FANTASIA_ENUM_CONVERTER_13(_E01, _E02, _E03, _E04, _E05, _E06, _E07,     \
                                    _E08, _E09, _E10, _E11, _E12, _E13)           \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E01)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E02)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E03)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E04)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E05)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E06)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E07)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E08)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E09)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E10)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E11)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E12)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E13)                                       \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E01)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E02)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E03)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E04)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E05)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E06)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E07)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E08)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E09)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E10)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E11)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E12)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E13)                                     \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    } 

#define _FANTASIA_ENUM_CONVERTER_14(_E01, _E02, _E03, _E04, _E05, _E06, _E07,     \
                                    _E08, _E09, _E10, _E11, _E12, _E13, _E14)     \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E01)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E02)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E03)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E04)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E05)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E06)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E07)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E08)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E09)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E10)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E11)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E12)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E13)                                       \
            _FANTASIA_ENUM_TOSTR_CASE(_E14)                                       \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E01)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E02)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E03)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E04)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E05)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E06)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E07)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E08)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E09)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E10)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E11)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E12)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E13)                                     \
            _FANTASIA_ENUM_FROMSTR_CASE(_E14)                                     \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    } 


#define _FANTASIA_ENUM_STRING_CONVERTER(...)                                      \
            _FANTASIA_MF_ARG(                                                     \
                _FANTASIA_MF_CAT(                                                 \
                    _FANTASIA_ENUM_CONVERTER_,                                    \
                    _FANTASIA_MF_ARG_COUNT(__VA_ARGS__)                           \
                )_FANTASIA_MF_VAARGS_TRANS(__VA_ARGS__)                           \
            )                                                                     \


#define EnumBasicActions(_WRAP, ...)                                              \
            _FANTASIA_ENUM_CTOR(_WRAP)                                            \
            _FANTASIA_ENUM_STRING_CONVERTER(__VA_ARGS__)                          \


#define EnumUnifyTypeName _Type : std::int64_t
