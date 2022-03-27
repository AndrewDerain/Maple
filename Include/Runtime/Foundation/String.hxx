///
/// @file Foundation.String.hxx
/// 
/// @brief 本文件定义了字符串类型
/// 
/// @date 2022-02-03
/// 
#pragma once
#include "../_Detail/Foundation/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Foundation
{

    /// @brief 栈存储器，使用此对象在栈上保存数据
    struct StringStackStorage
    {
    public:
        /// @brief Stack 上可以存储值的最大空间（包含'\0'）。
        static inline constexpr
        Int64 Capacity() noexcept;


        /// @brief 额外预分配空间
        static inline constexpr
        Int64 ReservedSpaceCapacity() noexcept;


        /// @brief Stack 上可存储的最大整数
        static inline constexpr
        Int64 MaxIntegerValueOnStack() noexcept;


        /// @brief Stack 上可存储的最小整数
        static inline constexpr
        Int64 MinIntegerValueOnStack() noexcept;


        /// @brief Stack 上可存储的最大浮点数（非科学计数法）
        static inline constexpr
        Float64 MaxFloatValueOnStack() noexcept;


        /// @brief Stack 上可存储的最小浮点数（非科学计数法）
        static inline constexpr
        Float64 MinFloatValueOnStack() noexcept;


        inline constexpr
        StringStackStorage();


        inline constexpr
        Bool IsOnStack() const noexcept;


        /// @brief 字符串中的字符数量
        inline constexpr
        Int64 Length() const;


        /// @brief 值
        inline constexpr
        char* StoredValue();


        /// @brief 值
        inline constexpr
        const char* StoredValue() const;


        /// @brief 重置为空字符串
        /// @note 此函数只会设置 Length 和 StoredValue 属性
        inline constexpr
        void Reset();


        /// @note 此函数只会设置 Length 和 StoredValue 属性
        inline constexpr
        void Set(const char* value, std::int8_t len);


        inline
        void Catenate(const char* value, int64_t len);


        inline constexpr
        void Catenate(const char* value, int64_t len) const;


    protected:
        /// @brief Stack 上可以存储值的最大空间（包含'\0'）。
        static constexpr const int64_t _StackMaxCapacity 		= 14;


        /// @brief 额外预分配空间
        static constexpr const int64_t _ReservedSpaceCapacity	= _StackMaxCapacity * 5;


        /// @brief Stack 上可存储的最大整数, 取决于 _StackMaxCapacity 的大小
        /// @see _StackMaxCapacity
        static constexpr const int64_t _MaxIntegerValueOnStack 	= 9999999999999;


        /// @brief Stack 上可存储的最小整数
        /// @see _StackMaxCapacity
        static constexpr const int64_t _MinIntegerValueOnStack 	= -999999999999;


        /// @brief Stack 上可存储的最大浮点数（非科学计数法）
        /// @see _StackMaxCapacity
        static constexpr const double _MaxFloatValueOnStack 	= 9999999999999;


        /// @brief Stack 上可存储的最小浮点数（非科学计数法）
        /// @see _StackMaxCapacity
        static constexpr const double _MinFloatValueOnStack    	= -0.0000000001;


        /// @note 也用于进行内存对齐
        bool _IsOnStack;


        /// @brief 字符串中的字符数量
        /// @note 不包含结束符 '\0'
        std::int8_t _Length;


        /// @brief 栈上存储的字符串值
        char _StoredValue[_StackMaxCapacity];
    };



    /// @brief 堆存储器，使用此对象在堆上保存数据
    struct StringHeapStorage
    {
    public:
        /// @brief 在堆上已申请的内存空间大小
        inline constexpr
        Int64 Capacity() const;


        /// @brief 字符串中的字符数量
        inline constexpr
        Int64 Length() const;


        /// @brief 值
        inline constexpr
        const char* StoredValue() const;


        inline
        void Initialize();


        /// @note 此函数只会设置 Length 和 StoredValue 属性
        inline
        void Reset();


        /// @note 此函数只会设置 Length 和 StoredValue 属性
        __decorate(Fantasia, api)
        void Set(const char* value, std::uint16_t len);


        /// @brief 直接使用外部申请的内存空间进行替换
        inline constexpr
        void Replace(char* memory, std::uint16_t length, std::uint16_t capacity);


        /// @brief 释放堆上申请的内存
        __decorate(Fantasia, api)
        void Deallocate();


        /// #brief 增大堆空间
        void Extend(std::uint64_t size);


        inline constexpr
        void Catenate(const char* value, int64_t len);


    protected:
        /// @note 也用于进行内存对齐
        bool          _IsOnStack;


        /// @brief 字符串中的字符数量
        std::uint16_t _Length;


        /// @brief 在堆上已申请的内存空间大小
        std::uint16_t _Capacity;


        /// @brief 堆起始地址
        char*         _StoredValue;
    };



    /// @brief 存储结构，负责存储字符串的值以及长度和已申请的内存容量信息。
    /// 短字符串在 Stack 上存储，长字符串在 Heap 上存储。
    struct StringStorage
    {
    public:
        inline constexpr
        StringHeapStorage& Heap();


        inline constexpr
        const StringHeapStorage& Heap() const;


        inline constexpr
        StringStackStorage& Stack();


        inline constexpr
        const StringStackStorage& Stack() const;


        inline constexpr
        Bool IsOnStack() const;


    protected:
        StringStackStorage _MemorySpace;
    };




//    char* begin(String& string);
//    char* end(String& string);




    /// @brief 以 '\0' 字符结尾的字符串, 深拷贝实现。
    class String
    {
    public:
        /// @brief 字符串所能存储的最大容量（以字节计算）。
        [[maybe_unused]]
        inline constexpr
        static Int64 MaxCapacity();


        /// @brief 获取字符串的长度
        /// @note 如果存储的是中文以及其他多字节字符，
        /// 则返回的是占用内存的大小（不包含结尾的 '\0' 字符）。
        [[maybe_unused]]
        inline constexpr
        Int64 Length() const;


        /// @brief 字符串占用的内存空间
        [[maybe_unused]]
        inline constexpr
        Int64 Capacity() const;


        /// @brief 默认构造函数。
        inline constexpr
        String();


        /// @brief 默认析构函数。
        inline constexpr
        ~String();


        /// @brief 使用 c 样式字符串进行初始化。
        /// @note 如果 value 是空指针，此对象会被初始化为空字符串（""）。
        inline constexpr
        String(const char* value);


        /// @brief 追加内容
        inline constexpr
        String& Catenate(const String& value);


        /// @brief 追加内容
        inline constexpr
        String& Catenate(const Bool& value);


        /// @brief 追加内容
        inline
        String& Catenate(const char* value);


        inline constexpr
        const String& Catenate(const char* value) const;


        /// @brief 追加内容
        template<Size _Size> inline constexpr
        String& Catenate(const char (&value)[_Size]);


        /// @brief 隐式转换为原始的 c 样式字符串。
        /// @note 此对象可以隐式转换为原始的 c 样式字符串，但不允许在此情况下对内容进行修改。
        inline constexpr
        operator char const* const() const noexcept;


    protected:
        /// @brief 内部对象, 存储字符串的值
        StringStorage _Storage;


        //void _Assign(const String& other);


        /// @brief 内部函数，使用 c 样式字符串进行初始化。
        /// @note 如果 value 是空指针，此对象会被初始化为空字符串（""）。
        inline constexpr
        void _Catenate(const char* value);


        /// @brief 内部函数，追加内容
        inline constexpr
        void _Catenate(const char* value, int64_t len);


        /// @brief 内部函数，将 Stack 上的内容转移到 Heap 上。
        /// @param reserved_space 需要预分配的空间大小
        __decorate(Fantasia, api)
        void _MoveToHeap(int64_t reserved_space);


        /// @brief 追加内容到堆上
        __decorate(Fantasia, api)
        void _AppendOnHeap(const char* value, int64_t len);
    };


    static_assert(std::is_standard_layout_v<String>, "String must be standard layout!");


    inline constexpr
    Int64 CountStringLength(const char* string) noexcept;


    inline constexpr
    Int64 CompareString(const String& left, const String& right) noexcept;


    inline constexpr
    void CopyString(
            char*           left,
            std::int64_t    left_capacity,
            const char*     right,
            std::int64_t    right_len);


    inline constexpr
    void CatenateString(
            char*           left,
            std::int64_t    left_length,
            std::int64_t    left_capacity,
            const char*     right,
            std::int64_t    right_length);


    inline constexpr
    Bool operator==(const String& left, const String& right) noexcept;


    inline constexpr
    Bool operator!=(const String& left, const String& right) noexcept;


    inline constexpr
    Bool operator>(const String& left, const String& right) noexcept;


    inline constexpr
    Bool operator<(const String& left, const String& right) noexcept;


    inline constexpr
    Bool operator>=(const String& left, const String& right) noexcept;


    inline constexpr
    Bool operator<=(const String& left, const String& right) noexcept;

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)


#include "../_Detail/Foundation/String.inli.hxx"
