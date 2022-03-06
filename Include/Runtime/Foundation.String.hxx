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
__FANTASIA_FOUNDATION_DETAIL_BEGIN

/// @brief 以 '\0' 字符结尾的字符串, 深拷贝实现。
class String
{
public:
    /// @brief 字符串所能存储的最大容量（以字节计算）。
	[[maybe_unused]]
	__api_inline __api_constexpr
    static Int64 MaxCapicity();


    /// @brief 获取字符串的长度
    /// @note 如果存储的是中文以及其他多字节字符，则返回的是占用内存的大小（不包含结尾的 '\0' 字符）。
	[[maybe_unused]]
	__api_inline __api_constexpr
    Property Int64 Length() const;


    /// @brief 字符串占用的内存空间
    [[maybe_unused]]
	__api_inline __api_constexpr
    Property Int64 Capicity() const;


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


    /// @brief 追加内容
    __api_inline __api_constexpr
    String& Append(const String& value);


    /// @brief 追加内容
    __api_inline __api_constexpr
    String& Append(const Bool& value);


    /// @brief 追加内容
    __api_inline __api_constexpr
    String& Append(const char* value);


    /// @brief 隐式转换为原始的 c 样式字符串。
    /// @note 此对象可以隐式转换为原始的 c 样式字符串，但不允许在此情况下对内容进行修改。
    __api_inline __api_constexpr
    operator char const* const() const noexcept;


	/// @brief 追加内容
	template<Size _Size>
	__always_inline  __always_constexpr
	String& Append(const char (&value)[_Size]) {
		_Append(value, strlen(value));
		return *this;
	}

protected:
    enum {
        /// @brief Stack 上可以存储值的最大空间。
        StackMaxCapicity = 14,

        /// @brief 额外预分配空间
        ReservedSpaceCapicity = StackMaxCapicity * 5
    };


    /// @brief 存储结构，负责存储字符串的值以及长度和已申请的内存容量信息。
    /// 短字符串在 Stack 上存储，长字符串在 Heap 上存储。
    union Storage
    {
        /// @brief 栈存储器，使用此对象在栈上保存数据
        struct StackStore
        {
            /// @note 仅用于在联合体中进行内存对齐
			[[maybe_unused]]
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
			[[maybe_unused]]
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


    /// @brief 内部对象, 存储字符串的值
    Storage _Storage;


    /// @brief 内部函数，使用 c 样式字符串进行初始化。
    /// @note 如果 value 是空指针，此对象会被初始化为空字符串（""）。
    __api_inline __api_constexpr
    void _Assign(const char* value);


    /// @brief 内部函数，追加内容
    __api_inline __api_constexpr
    void _Append(const char* value, int64_t len);


    /// @brief 内部函数，将 Stack 上的内容转移到 Heap 上。
    /// @param reserved_space 需要预分配的空间大小
    __api
    void _MoveToHeap(int64_t reserved_space);


    /// @brief 追加内容到栈上
    __api_inline __api_constexpr
    void _AppendOnStack(const char* value, int64_t len);


    /// @brief 追加内容到堆上
    __api
    void _AppendOnHeap(const char* value, int64_t len);
};

__FANTASIA_FOUNDATION_DETAIL_END


__FANTASIA_FOUNDATION_BEGIN
using _Fantasia::String;
__FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)


#ifdef __FANTASIA_OPTION_INLINE
#    include "../../Source/Runtime/Foundation.String.iapi.hxx"
#endif

#ifdef __FANTASIA_OPTION_HEADER_ONLY
#    include "../../Source/Runtime/Foundation.String.impl.cxx"
#endif
