///
/// @file Foundation.Int64.hxx
/// 
/// @brief 本文件定义了64位整数类型
/// 
/// @date 2022-01-22
/// 
#pragma once
#include "Foundation.Basic.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_FOUNDATION_DETAIL_BEGIN

/// @brief 64位整数类型
struct Int64
{
public:
    __api_inline __api_constexpr
    static Int64 Max() noexcept;


    __api_inline __api_constexpr
    static Int64 Min() noexcept;


    /// @brief 构造函数。设为 default 以支持 standard_layout 和 trivial。
    Int64() = default;


    /// @brief 析构函数。设为 default 以支持 standard_layout 和 trivial。
    ~Int64() = default;


    /// @brief 拷贝构造函数。设为 default 以支持 standard_layout 和 trivial。
    Int64(const Int64&) = default;


    __api_inline __api_constexpr
    Int64(int64_t value) noexcept;


	__api_inline
	explicit Int64(uint64_t value);


    __api_inline __api_constexpr
    explicit Int64(char value) noexcept;


	__api_inline __api_constexpr
	explicit Int64(signed char value) noexcept;


	__api_inline __api_constexpr
	explicit Int64(unsigned char value) noexcept;


    __api_inline __api_constexpr
    explicit Int64(short value) noexcept;


    __api_inline __api_constexpr
    explicit Int64(unsigned short value) noexcept;


    __api_inline __api_constexpr
    explicit Int64(int32_t value) noexcept;


	__api_inline __api_constexpr
	explicit Int64(uint32_t value) noexcept;


    /// @brief 转换为字符串
    __api
    String ToString() const;


    __api_inline __api_constexpr
    operator int64_t const&() const noexcept;


    __api_inline __api_constexpr
    operator int64_t&() noexcept;


    /// @brief 赋值操作符。设为 default 以支持 standard_layout 和 trivial。
    Int64& operator=(const Int64&) = default;


    __api_inline __api_constexpr
    Int64& operator=(Float64 other) noexcept;


	__api_inline __api_constexpr
	Int64& operator=(short value) noexcept;


    __api_inline __api_constexpr
    Int64& operator=(unsigned short value) noexcept;


    __api_inline __api_constexpr
    Int64& operator=(int32_t value) noexcept;


    __api_inline __api_constexpr
    Int64& operator=(long long int value) noexcept;


    __api_inline __api_constexpr
    Int64& operator=(double value) noexcept;


protected:
    int64_t _StoredValue;
};

__FANTASIA_FOUNDATION_DETAIL_END


__FANTASIA_FOUNDATION_BEGIN
using _Fantasia::Int64;
__FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)


#ifdef __FANTASIA_OPTION_INLINE
#    include "../../Source/Runtime/Foundation.Int64.iapi.hxx"
#endif

#ifdef __FANTASIA_OPTION_HEADER_ONLY
#    include "../../Source/Runtime/Foundation.Int64.impl.cxx"
#endif
