
#include <Foundation/Int64.hxx>
#include <Foundation/Float64.hxx>

#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_DETAIL_BEGIN
_FANTASIA_DETAIL_END

_FANTASIA_BEGIN
namespace Foundation 
{

    // constructor
    Float64::Float64(Float64 const& other) :
        _Storage(other._Storage) {}

    Float64::Float64(Float64 const&& other) :
        _Storage(move(other._Storage)) {}

    Float64::Float64(double const& value) :
        _Storage(value) {}

    Float64::Float64(double const&& value) :
        _Storage(move(value)) {}

    Float64::operator double() const {
        return _Storage;
    }

    // operator 
    inline Float64 operator+(Float64 const& left, Int64 const& right) {
        return left._Storage + (int64_t const&)right;
    }

    inline Float64 operator-(Float64 const& left, Int64 const& right) {
        return left._Storage - (int64_t const&)right;
    }

    // inline Float64 operator*(Int64 const& left, Int64 const& right);
    // inline Float64 operator/(Int64 const& left, Int64 const& right);
    // inline bool operator!=(Int64 const& left, Int64 const& right);
    // inline bool operator==(Int64 const& left, Int64 const& right);
    // inline bool operator>=(Int64 const& left, Int64 const& right);
    // inline bool operator<=(Int64 const& left, Int64 const& right);
    // inline bool operator>(Int64 const& left, Int64 const& right);
    // inline bool operator<(Int64 const& left, Int64 const& right);

    
}
_FANTASIA_END
#pragma pack(pop)
#pragma warning(pop)
