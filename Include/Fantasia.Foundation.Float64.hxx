#pragma once
#include <Fantasia.Basic.Macro.Function.hxx>
#include <Fantasia.Basic.CodeLang.CXX.hxx>

#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_BEGIN
namespace Foundation 
{
    struct Int64;
}
_FANTASIA_END

_FANTASIA_DETAIL_BEGIN
_FANTASIA_DETAIL_END

_FANTASIA_BEGIN
namespace Foundation 
{
    
struct Float64
{
public:
    Float64() = default;
    ~Float64() = default;

    Float64(Float64 const& other);
    Float64(Float64 const&& other);

    Float64(double const& value);
    Float64(double const&& value);

    explicit operator double() const;

private:
    double _Storage;

private:
    friend Float64 operator+(Float64 const& left, Int64 const& right);
    friend Float64 operator-(Float64 const& left, Int64 const& right);
    // friend Float64 operator*(Float64 const& left, Int64 const& right);
    // friend Float64 operator/(Float64 const& left, Int64 const& right);
    // friend bool operator!=(Float64 const& left, Int64 const& right);
    // friend bool operator==(Float64 const& left, Int64 const& right);
    // friend bool operator>=(Float64 const& left, Int64 const& right);
    // friend bool operator<=(Float64 const& left, Int64 const& right);
    // friend bool operator>(Float64 const& left, Int64 const& right);
    // friend bool operator<(Float64 const& left, Int64 const& right);


};

    
} // end of Foundation
_FANTASIA_END
#pragma pack(pop)
#pragma warning(pop)
