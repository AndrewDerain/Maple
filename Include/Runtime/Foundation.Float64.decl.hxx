#pragma once
#include "Foundation.basic.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_FOUNDATION_BEGIN
struct Int64;
_FANTASIA_FOUNDATION_END


_FANTASIA_FOUNDATION_BEGIN
struct Float64
{
public:
    Float64() = default;
    ~Float64() = default;

    Float64(const Float64& other) noexcept;
    Float64(Float64&& other) noexcept;

    Float64(double const& value) noexcept;
    Float64(double&& value) noexcept;

public:

public:
    operator double() const noexcept;
    operator double&() noexcept;

    Float64& operator=(const Float64& other);
    Float64& operator=(Float64&& other);

    Float64& operator=(const double& value);
    Float64& operator=(double&& value);

protected:
    double _StoredValue;
};

_FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)
