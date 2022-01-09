#pragma once
#include <_CompileTime/MacroFunction.hxx>
#include <_CXX/Includes.hxx>


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


#define _FANTASIA_ENUM_CONVERTER_1(_E1)                                           \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E1)                                        \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E1)                                      \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }                                                                             \


#define _FANTASIA_ENUM_CONVERTER_2(_E1, _E2)                                      \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E1)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E2)                                        \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E1)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E2)                                      \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }                                                                             \


#define _FANTASIA_ENUM_CONVERTER_3(_E1, _E2, _E3)                                 \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E1)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E2)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E3)                                        \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E1)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E2)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E3)                                      \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }                                                                             \


#define _FANTASIA_ENUM_CONVERTER_4(_E1, _E2, _E3, _E4)                            \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E1)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E2)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E3)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E4)                                        \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E1)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E2)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E3)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E4)                                      \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }                                                                             \


#define _FANTASIA_ENUM_CONVERTER_5(_E1, _E2, _E3, _E4, _E5)                       \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E1)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E2)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E3)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E4)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E5)                                        \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E1)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E2)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E3)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E4)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E5)                                      \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }                                                                             \


#define _FANTASIA_ENUM_CONVERTER_6(_E1, _E2, _E3, _E4, _E5, _E6)                  \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E1)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E2)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E3)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E4)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E5)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E6)                                        \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E1)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E2)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E3)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E4)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E5)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E6)                                      \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }                                                                             \


#define _FANTASIA_ENUM_CONVERTER_7(_E1, _E2, _E3, _E4, _E5, _E6, _E7)             \
    inline const char* ToString() {                                               \
        _FANTASIA_ENUM_TOSTR_BEG                                                  \
            _FANTASIA_ENUM_TOSTR_CASE(_E1)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E2)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E3)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E4)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E5)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E6)                                        \
            _FANTASIA_ENUM_TOSTR_CASE(_E7)                                        \
        _FANTASIA_ENUM_TOSTR_END                                                  \
    }                                                                             \
    inline void FromString(const char* value) {                                   \
        _FANTASIA_ENUM_FROMSTR_BEG                                                \
            _FANTASIA_ENUM_FROMSTR_CASE(_E1)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E2)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E3)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E4)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E5)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E6)                                      \
            _FANTASIA_ENUM_FROMSTR_CASE(_E7)                                      \
        _FANTASIA_ENUM_FROMSTR_END                                                \
    }                                                                             \


#define _FANTASIA_ENUM_STRING_CONVERTER(...)                                      \
            _FANTASIA_MF_ARG(                                                     \
                _FANTASIA_MF_CAT(                                                 \
                    _FANTASIA_ENUM_CONVERTER_,                                    \
                    _FANTASIA_MF_ARG_COUNT(__VA_ARGS__)                           \
                )_FANTASIA_MF_VAARGS_TRANS(__VA_ARGS__)                           \
            )                                                                     \


#define EnumBasicAction(_WRAP, ...)                                               \
            _FANTASIA_ENUM_CTOR(_WRAP)                                            \
            _FANTASIA_ENUM_STRING_CONVERTER(__VA_ARGS__)                          \
