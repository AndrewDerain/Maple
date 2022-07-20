///
/// @file Foundation.String.hxx
/// 
/// @brief 本文件定义了字符串类型
/// 
/// @date 2022-02-03
/// 
#pragma once
#include "../Internal/Foundation/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, 1)
namespace _Maple::Foundation
{

    /// @brief 堆存储器，使用此对象在堆上保存数据
    struct StringHeapStorage
    {
    public:
        /// @brief 在堆上已申请的内存空间大小
        inline
        Int64 Capacity() const;


        /// @brief 字符串中的字符数量
        inline
        Int64 Length() const;


        /// @brief 值
        inline
        const char* Data() const;


        inline
        void Initialize();


        /// @note 此函数只会设置 Length 和 Data 属性
        MapleDeco(Maple, Runtime, Api)
        void Assign(const char* value, uint64_t len);


        /// @brief 直接使用外部申请的内存空间进行替换
        inline
        void Replace(char* memory, uint64_t length, uint64_t capacity);


        /// @brief 释放堆上申请的内存
        MapleDeco(Maple, Runtime, Api)
        void Deallocate();


        MapleDeco(Maple, Runtime, Api)
        void Catenate(const char* value, uint64_t len);


        /// @brief 增大堆空间
        MapleDeco(Maple, Runtime, Api)
        void Extend(uint64_t size);


    protected:
        /// @note 用于进行内存对齐
        bool        _IsOnStack;


        /// @brief 字符串中的字符数量
        uint64_t    _Length;


        /// @brief 在堆上已申请的内存空间大小
        uint64_t    _Capacity;


        /// @brief 堆起始地址
        char*       _StoredValue;
    };

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
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
        uint64_t MaxIntegerValueOnStack() noexcept;


        /// @brief Stack 上可存储的最小整数
        static inline constexpr
        Int64 MinIntegerValueOnStack() noexcept;


        /// @brief Stack 上可存储的最大浮点数（非科学计数法）
        static inline constexpr
        Double MaxFloatValueOnStack() noexcept;


        /// @brief Stack 上可存储的最小浮点数（非科学计数法）
        static inline constexpr
        Double MinFloatValueOnStack() noexcept;


        inline constexpr
        StringStackStorage();


        inline constexpr
        Bool IsOnStack() const noexcept;


        /// @brief 字符串中的字符数量
        inline constexpr
        Int64 Length() const;


        /// @brief 值
        inline constexpr
        const char* Data() const;


        /// @brief 重置为空字符串
        inline constexpr
        void Reset();


        /// @note 此函数只会设置 Length 和 Data 属性
        inline constexpr
        void Assign(const char* value, int8_t len);


        template<std::signed_integral _T>
        inline constexpr
        void Assign(_T value);


        template<std::unsigned_integral _T>
        inline constexpr
        void Assign(_T value);


        inline constexpr
        void Catenate(const char* value, int8_t len);


    protected:
        /// @brief Stack 上可以存储值的最大空间（包含'\0'）。
        static constexpr const int8_t _StackMaxCapacity 		= 23;


        /// @brief 额外预分配空间
        static constexpr const int64_t _ReservedSpaceCapacity	= _StackMaxCapacity * 5;


        /// @brief Stack 上可存储的最大整数, 取决于 _StackMaxCapacity 的大小
        /// @see _StackMaxCapacity                                2021-09-11 13:00:11
        ///                                                       9223372036854775807
        ///                                                       18446744073709551615|
        ///                                                       123456789012345678901  21 // 24
        static constexpr const uint64_t _MaxIntegerValueOnStack = NumericLimits<uint64_t>::Max();


        /// @brief Stack 上可存储的最小整数
        /// @see _StackMaxCapacity
        static constexpr const int64_t _MinIntegerValueOnStack 	= NumericLimits<int64_t>::Min();


        /// @brief Stack 上可存储的最大浮点数（非科学计数法）
        /// @see _StackMaxCapacity
        static constexpr const double _MaxFloatValueOnStack 	= 9999999999999;


        /// @brief Stack 上可存储的最小浮点数（非科学计数法）
        /// @see _StackMaxCapacity
        static constexpr const double _MinFloatValueOnStack    	= -0.0000000001;


        /// @note 仅用于进行内存对齐
        bool    _IsOnStack;


        /// @brief 字符串中的字符数量
        /// @note 不包含结束符 '\0'
        int8_t  _Length;


        /// @brief 栈上存储的字符串值
        char    _StoredValue[_StackMaxCapacity];
    };


    /// @brief 存储结构，负责存储字符串的值以及长度和已申请的内存容量信息。
    /// 短字符串在 Stack 上存储，长字符串在 Heap 上存储。
    struct StringStorage
    {
    public:
        inline
        StringHeapStorage& Heap();


        inline
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


    inline constexpr
    const char* begin(const String& string);


    inline constexpr
    const char* end(const String& string);


    /// @brief  以 '\0' 字符结尾的字符串, 深拷贝实现。
    /// @note   满足 standard layout
    struct String
    {
    public:
        /// @brief 字符串所能存储的最大容量（以字节计算）
        inline constexpr
        static Int64 MaxCapacity();


        /// @brief 获取字符串的长度
        /// @note 如果存储的是中文以及其他多字节字符
        /// 则返回的是占用内存的大小（不包含结尾的 '\0' 字符）
        inline constexpr
        Int64 Length() const;


        /// @brief 字符串占用的内存空间
        inline constexpr
        Int64 Capacity() const;


        /// @brief 默认构造函数。
        inline constexpr
        String();


        /// @brief 默认析构函数。
        inline constexpr
        ~String();


        inline constexpr
        String(const String& other);


        /// @brief 使用 c 样式字符串进行初始化。
        /// @note 如果 value 是空指针，此对象会被初始化为空字符串（""）。
        inline constexpr
        String(const char* value);


        inline constexpr explicit
        String(int8_t value);


        inline constexpr explicit
        String(int16_t value);

        
        inline constexpr explicit
        String(int32_t value);


        inline constexpr explicit
        String(int64_t value);


        inline constexpr explicit
        String(uint8_t value);


        inline constexpr explicit
        String(uint16_t value);


        inline constexpr explicit
        String(uint32_t value);


        inline constexpr explicit
        String(uint64_t value);


        /// @brief 追加内容
        inline
        String& Catenate(const String& value);


        /// @brief 追加内容
        inline
        String& Catenate(const Bool& value);


        /// @brief 追加内容
        inline
        String& Catenate(const char* value);


        inline constexpr
        const String Catenate(const char* value) const;


        inline constexpr
        Bool IsOnStack() const;


        /// @brief 隐式转换为原始的 c 样式字符串。
        /// @note 此对象可以隐式转换为原始的 c 样式字符串，但不允许在此情况下对内容进行修改。
        inline constexpr
        operator char const* const() const noexcept;


        inline constexpr
        String& operator=(const char* value);


    protected:
        /// @brief 内部对象, 存储字符串的值
        StringStorage _Storage;


        /// @brief 使用 c 样式字符串进行初始化。
        /// @note 如果 value 是空指针，此对象会被初始化为空字符串（""）。
        inline constexpr
        void _Assign(const char* value);


        inline constexpr
        void _Assign(const char* value, uint32_t length);


        /// @brief 追加内容到字符串末尾
        inline
        void _Catenate(const char* value, int64_t len);


        /// @brief 将 Stack 上的内容转移到 Heap 上。
        /// @param reserved_space 需要预分配的空间大小
        MapleDeco(Maple, Runtime, Api)
        void _MoveToHeap(int64_t reserved_space);


        /// @brief 追加内容到堆上
        MapleDeco(Maple, Runtime, Api)
        void _CatenateOnHeap(const char* value, int64_t len);


    private:
        inline constexpr
        friend const char* begin(const String&);


        inline constexpr
        friend const char* end(const String&);
    };


    static_assert(std::is_standard_layout_v<String>, "String must be standard layout!");


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

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)


#include "../Internal/Foundation/String.inl"
