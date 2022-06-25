//
// Created by 宋豪杰 on 2022/6/13.
//

#pragma once
#include "../Internal/Basic/CodeLang.CXX.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Algorithm
{
    /// @brief 计算字符串的长度，不包含字符 '\0'
    inline constexpr
    int64_t CountStringLength(const char *string) noexcept;


    /// @brief 计算字符串的长度，不包含字符 '\0'，返回的长度不会超过 upperlimit
    inline constexpr
    int64_t CountStringLength(const char *string, int64_t upperlimit) noexcept;

    
    /// @brief 比较字符串
    /// @retval > 0 表示 left > right
    /// @retval < 0 表示 left < right
    /// @retval = 0 表示 left == right
    inline constexpr
    int64_t CompareString(
            const char         *left,
            const int64_t       left_length,
            const char         *right,
            const int64_t       right_length) noexcept;


    /// @brief 比较字符串
    /// @retval > 0 表示 left > right
    /// @retval < 0 表示 left < right
    /// @retval = 0 表示 left == right
    inline constexpr
    int64_t CompareString(const char *left, const char *right) noexcept;


    /// @brief 复制字符串
    /// @param left_capacity 必须大于0
    inline constexpr
    void CopyString(
            char*           left,
            int64_t         left_capacity,
            const char*     right,
            int64_t         right_length) noexcept;

    
    /// @brief 拼接字符串
    template<std::integral _LenTy>
    inline constexpr
    void CatenateString(
            char           *left,
            _LenTy         &left_length,
            _LenTy          left_capacity,
            const char     *right,
            _LenTy          right_length) noexcept;


    /// @brief 将有符号整数转换为字符串
    /// @param ival 被转换的有符号整数
    /// @param sval 转换结果
    /// @note 需要保证传入的 sval 有足够的空间容纳转换后的结果
    template<std::signed_integral _T>
    inline constexpr
    int8_t ConvertSignedIntegerToString(
            _T              ival,
            char           *sval) noexcept;


    /// @brief 将无符号整数转换为字符串
    /// @param ival 被转换的有符号整数
    /// @param sval 转换结果
    /// @note 需要保证传入的 sval 有足够的空间容纳转换后的结果
    template<std::unsigned_integral _T>
    inline constexpr
    int8_t ConvertUnsignedIntegerToString(
            _T              ival,
            char           *sval) noexcept;

} // namespace _Fantasia::Algorithm
#pragma pack(pop)
#pragma warning(pop)


#include "../Internal/Algorithm/String.inl"
