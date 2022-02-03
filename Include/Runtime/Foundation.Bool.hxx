#pragma once
#include "Foundation.Basic.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_FOUNDATION_BEGIN
struct Bool 
{
public:
    Bool() noexcept = default;
    ~Bool() noexcept = default;

    Bool(const Bool& other) noexcept;
    Bool(Bool&& other) noexcept;

    Bool(const bool& value) noexcept;
    Bool(bool&& value) noexcept;

public:
    const char* ToString();

public:
    operator bool() const noexcept; 
    operator bool&() noexcept;

    const Bool& operator=(const Bool& other) noexcept;
    const Bool& operator=(Bool&& other) noexcept;

    const Bool& operator=(const bool& value) noexcept;
    const Bool& operator=(bool&& value) noexcept;

protected:
    bool _StoredValue;
};
_FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)

#ifdef _FANTASIA_HEADER_ONLY
#    include "../../Source/Runtime/Foundation.Bool.impl.hxx"
#endif
