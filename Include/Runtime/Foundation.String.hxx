#pragma once
#include "Foundation.Basic.hxx"
#include "Foundation.Int64.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_FOUNDATION_BEGIN
/// @brief 以 '\0' 字符结尾的字符串
class String
{
public:
    /// @brief 字符串所能存储的最大容量（以字节计算）
    static Int64 MaxCapicity();

public:
    String() noexcept = default;
    ~String() noexcept = default;

    String(const char* value);

    Int64 Length();


public:
    //operator char*() const noexcept;
    //operator char*() noexcept;
         
protected:
    union Storage{
        bool  IsOnStack;

        struct StackStore{
            bool  IsOnStack;
            char  Size;
            char  StoredValue[14];
        } Stack = {true, 0, ""};

        struct HeapStore{
            bool  IsOnStack;
            std::uint16_t Size;
            std::uint16_t Cap;
            char*  StoredValue;
        } Heap;

    } _Storage;
};
//constexpr bool x = std::is_standard_layout_v<String>;
_FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)

#ifdef _FANTASIA_HEADER_ONLY
#    include "../../Source/Runtime/Foundation.String.impl.hxx"
#endif
