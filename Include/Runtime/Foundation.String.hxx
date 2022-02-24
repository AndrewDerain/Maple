///
/// @file Foundation.String.hxx
/// 
/// @brief 本文件定义了字符串类型
/// 
/// @date 2022-02-03
/// 
#pragma once
#include "Foundation.Basic.hxx"
#include "Foundation.Enum.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_BEGIN

/// @brief 以 '\0' 字符结尾的字符串, 深拷贝实现。
class String
{
public:
    /// @brief 字符串所能存储的最大容量（以字节计算）。
    __api_inline
    static Int64 MaxCapicity();


    /// @brief 默认构造函数。
    __api_inline __api_constexpr
    String();


    /// @brief 默认析构函数。
    __api_inline __api_constexpr
    ~String();


    /// @brief 使用 c 样式字符串进行初始化。
    /// @note 如果 value 是空指针，此对象会被初始化为空字符串（""）。
    __api_inline __api_constexpr
    String(const char* value);


    /// @brief 获取字符串的长度
    /// @note 如果存储的是中文以及其他多字节字符，则返回的是占用内存的大小（不包含结尾的 '\0' 字符）。
    __api_inline
    Int64 Length() const;


    /// @brief 隐式转换为原始的 c 样式字符串。
    /// @note 此对象可以隐式转换为原始的 c 样式字符串，但不允许在此情况下对内容进行修改。
    __api_inline
    operator char const* const() const noexcept;


protected:
    enum {
        /// @brief Stack 上可以存储值的最大空间。
        StackMaxCapicity = 14
    };


    /// @brief 存储结构，负责存储字符串的值以及长度和已申请的内存容量信息。
    /// 短字符串在 Stack 上存储，长字符串在 Heap 上存储。
    union Storage 
    {
        /// @brief 栈存储器，使用此对象在栈上保存数据
        struct StackStore 
        {
            /// @note 仅用于在联合体中进行内存对齐
            bool IsOnStack;


            /// @brief 字符串中的字符数量
            char Length;


            /// @brief 栈上存储的字符串值
            char StoredValue[StackMaxCapicity];


            /// @brief 重置为空字符串
            /// @note 此函数只会设置 Length 和 StoredValue 属性
            __api_inline
            void Reset();


            /// @note 此函数只会设置 Length 和 StoredValue 属性
            __api_inline __api_constexpr
            void Set(const char* value, char len);
        };


        /// @brief 堆存储器，使用此对象在堆上保存数据
        struct HeapStore 
        {
            /// @note 仅用于在联合体中进行内存对齐
            bool          IsOnStack;


            /// @brief 字符串中的字符数量
            std::uint16_t Length;


            /// @brief 在堆上已申请的内存空间大小
            std::uint16_t Capicity;


            /// @brief 堆起始地址
            char*         StoredValue;


            /// @note 此函数只会设置 Length 和 StoredValue 属性
            __api_inline
            void Reset();


            /// @note 此函数只会设置 Length 和 StoredValue 属性
            __api
            void Set(const char* value, std::uint16_t len);


            /// @brief 释放堆上申请的内存
            __api
            void Deallocate();
        };

        bool       IsOnStack;
        HeapStore  Heap;
        StackStore Stack = {true, 0, ""};
    };


    /// @brief 内部对象
    Storage _Storage;


    /// @brief 内部函数，使用 c 样式字符串进行初始化。
    /// @note 如果 value 是空指针，此对象会被初始化为空字符串（""）。
    __api 
    void _Assign(const char* value);
};

__FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)



#ifdef __FANTASIA_OPTION_INLINE
#    include "../../Source/Runtime/Foundation.String.iapi.hxx"
#endif

#ifdef __FANTASIA_OPTION_HEADER_ONLY
#    include "../../Source/Runtime/Foundation.String.impl.cxx"
#endif
