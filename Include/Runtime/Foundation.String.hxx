#pragma once
#include "Foundation.Basic.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_FOUNDATION_BEGIN
/// @brief 以 '\0' 字符结尾的字符串
class String
{
public:
    String() = default;
    ~String() = default;

    

protected:
    uint64_t _Size;
    char* _StoredValue = nullptr;
};
_FANTASIA_FOUNDATION_END

#pragma pack(pop)
#pragma warning(pop)
