#pragma once
#include <BasicConfigs.h>


#define _enum_constructor(Wrapper)                                           \
    private:                                                                 \
        _Type _Value;                                                        \
    public:                                                                  \
        inline Wrapper() = default;                                          \
        inline Wrapper(const Wrapper& wrapper) { _Value = wrapper._Value; }  \
        inline Wrapper(const _Type value)      { _Value = value; }           \
        inline operator _Type() const          { return _Value;}


#define _enum_to_string_begin              switch(_Value) {
#define _enum_to_string_case(element)          case element: return #element;
#define _enum_to_string_default(element)       default: return #element;
#define _enum_to_string_end                } \
                                           return "";

#define _enum_from_string_begin
#define _enum_from_string_case(element)    if(value.compare(#element) == 0) {_Value = element; return;}
#define _enum_from_string_default(element) enum_value = element;
#define _enum_from_string_end


/// 枚举字符串转换：1 个枚举成员
#define _enum_string_converter_1(e1)          \
    string_view ToString() {                  \
        _enum_to_string_begin                 \
            _enum_to_string_case(e1)          \
            _enum_to_string_end               \
    }                                         \
    void FromString(string_view value) {      \
        _enum_from_string_begin               \
            _enum_from_string_case(e1)        \
            _enum_from_string_end             \
    }                                         \

/// 枚举字符串转换：2 个枚举成员
#define _enum_string_converter_2(e1, e2)      \
    string_view ToString() {                  \
        _enum_to_string_begin                 \
            _enum_to_string_case(e1)          \
            _enum_to_string_case(e2)          \
            _enum_to_string_end               \
    }                                         \
    void FromString(string_view value) {      \
        _enum_from_string_begin               \
            _enum_from_string_case(e1)        \
            _enum_from_string_case(e2)        \
            _enum_from_string_end             \
    }                                         \

/// 枚举字符串转换：3 个枚举成员
#define _enum_string_converter_3(e1, e2, e3)  \
    string_view ToString() {                  \
        _enum_to_string_begin                 \
            _enum_to_string_case(e1)          \
            _enum_to_string_case(e2)          \
            _enum_to_string_case(e3)          \
            _enum_to_string_end               \
    }                                         \
    void FromString(string_view value) {      \
        _enum_from_string_begin               \
            _enum_from_string_case(e1)        \
            _enum_from_string_case(e2)        \
            _enum_from_string_case(e3)        \
            _enum_from_string_end             \
    }                                         \

/// 枚举字符串转换：4 个枚举成员
#define _enum_string_converter_4(             \
            e1, e2, e3, e4)                   \
    string_view ToString() {                  \
        _enum_to_string_begin                 \
            _enum_to_string_case(e1)          \
            _enum_to_string_case(e2)          \
            _enum_to_string_case(e3)          \
            _enum_to_string_case(e4)          \
            _enum_to_string_end               \
    }                                         \
    void FromString(string_view value) {      \
        _enum_from_string_begin               \
            _enum_from_string_case(e1)        \
            _enum_from_string_case(e2)        \
            _enum_from_string_case(e3)        \
            _enum_from_string_case(e4)        \
            _enum_from_string_end             \
    }                                         \

/// 枚举字符串转换：5 个枚举成员
#define _enum_string_converter_5(             \
            e1, e2, e3, e4, e5)               \
    string_view ToString() {                  \
        _enum_to_string_begin                 \
            _enum_to_string_case(e1)          \
            _enum_to_string_case(e2)          \
            _enum_to_string_case(e3)          \
            _enum_to_string_case(e4)          \
            _enum_to_string_case(e5)          \
            _enum_to_string_end               \
    }                                         \
    void FromString(string_view value) {      \
        _enum_from_string_begin               \
            _enum_from_string_case(e1)        \
            _enum_from_string_case(e2)        \
            _enum_from_string_case(e3)        \
            _enum_from_string_case(e4)        \
            _enum_from_string_case(e5)        \
            _enum_from_string_end             \
    }                                         \

/// 枚举字符串转换：6 个枚举成员
#define _enum_string_converter_6(             \
            e1, e2, e3, e4, e6)               \
    string_view ToString() {                  \
        _enum_to_string_begin                 \
            _enum_to_string_case(e1)          \
            _enum_to_string_case(e2)          \
            _enum_to_string_case(e3)          \
            _enum_to_string_case(e4)          \
            _enum_to_string_case(e5)          \
            _enum_to_string_case(e6)          \
            _enum_to_string_end               \
    }                                         \
    void FromString(string_view value) {      \
        _enum_from_string_begin               \
            _enum_from_string_case(e1)        \
            _enum_from_string_case(e2)        \
            _enum_from_string_case(e3)        \
            _enum_from_string_case(e4)        \
            _enum_from_string_case(e5)        \
            _enum_from_string_case(e6)        \
            _enum_from_string_end             \
    }                                         \

/// 枚举字符串转换：7 个枚举成员
#define _enum_string_converter_7(             \
            e1, e2, e3, e4, e6, e7)           \
    string_view ToString() {                  \
        _enum_to_string_begin                 \
            _enum_to_string_case(e1)          \
            _enum_to_string_case(e2)          \
            _enum_to_string_case(e3)          \
            _enum_to_string_case(e4)          \
            _enum_to_string_case(e5)          \
            _enum_to_string_case(e6)          \
            _enum_to_string_case(e7)          \
            _enum_to_string_end               \
    }                                         \
    void FromString(string_view value) {      \
        _enum_from_string_begin               \
            _enum_from_string_case(e1)        \
            _enum_from_string_case(e2)        \
            _enum_from_string_case(e3)        \
            _enum_from_string_case(e4)        \
            _enum_from_string_case(e5)        \
            _enum_from_string_case(e6)        \
            _enum_from_string_case(e7)        \
            _enum_from_string_end             \
    }                                         \

/// 枚举字符串转换：8 个枚举成员
#define _enum_string_converter_8(             \
            e1, e2, e3, e4, e6, e7, e8)       \
    string_view ToString() {                  \
        _enum_to_string_begin                 \
            _enum_to_string_case(e1)          \
            _enum_to_string_case(e2)          \
            _enum_to_string_case(e3)          \
            _enum_to_string_case(e4)          \
            _enum_to_string_case(e5)          \
            _enum_to_string_case(e6)          \
            _enum_to_string_case(e7)          \
            _enum_to_string_case(e8)          \
            _enum_to_string_end               \
    }                                         \
    void FromString(string_view value) {      \
        _enum_from_string_begin               \
            _enum_from_string_case(e1)        \
            _enum_from_string_case(e2)        \
            _enum_from_string_case(e3)        \
            _enum_from_string_case(e4)        \
            _enum_from_string_case(e5)        \
            _enum_from_string_case(e6)        \
            _enum_from_string_case(e7)        \
            _enum_from_string_case(e8)        \
            _enum_from_string_end             \
    }                                         \


#define _enum_string_convert(...)                        \
    _FANTASIA_MACROFUNC_ARG_T(                           \
        _FANTASIA_MACROFUNC_CAT(                         \
            _enum_string_converter_,                     \
            _FANTASIA_MACROFUNC_ARG_COUNT(__VA_ARGS__)   \
        )_FANTASIA_MACROFUNC_ARGS_TRANS(__VA_ARGS__)     \
    )                                                    \


#define packedenum(Wrapper, ...)                         \
    _enum_constructor(Wrapper)                           \
    _enum_string_convert(__VA_ARGS__)                    \
