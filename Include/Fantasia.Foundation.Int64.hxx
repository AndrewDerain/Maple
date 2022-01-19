#pragma once
#include <Fantasia.Basic.Macro.Function.hxx>
#include <Fantasia.Basic.CodeLang.CXX.hxx>


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_BEGIN
namespace Foundation 
{
    struct Float64;    
}
_FANTASIA_END

_FANTASIA_DETAIL_BEGIN
_FANTASIA_DETAIL_END

_FANTASIA_BEGIN
namespace Foundation 
{

    struct Int64 
    {
    public: 
        Int64() = default;
        ~Int64() = default;

        Int64(const Int64& other);
        Int64(const Int64&& other);

        Int64(const int32_t& value);
        Int64(const int32_t&& value);

        Int64(const int64_t& value);
        Int64(const int64_t&& value);

        explicit operator int64_t() const;
        explicit operator int64_t const&();

        
    private:
        int64_t _Storage;

    private:
        friend Int64 operator+(Int64 const& left, Int64 const& right);
        friend Int64 operator-(Int64 const& left, Int64 const& right);
        friend Int64 operator*(Int64 const& left, Int64 const& right);
        friend Int64 operator/(Int64 const& left, Int64 const& right);
        friend bool operator!=(Int64 const& left, Int64 const& right);
        friend bool operator==(Int64 const& left, Int64 const& right);
        friend bool operator>=(Int64 const& left, Int64 const& right);
        friend bool operator<=(Int64 const& left, Int64 const& right);
        friend bool operator>(Int64 const& left, Int64 const& right);
        friend bool operator<(Int64 const& left, Int64 const& right);

        friend Int64 operator+(Int64 const& left, int32_t const& right);
        friend Int64 operator-(Int64 const& left, int32_t const& right);
        friend Int64 operator*(Int64 const& left, int32_t const& right);
        friend Int64 operator/(Int64 const& left, int32_t const& right);
        friend bool operator!=(Int64 const& left, int32_t const& right);
        friend bool operator==(Int64 const& left, int32_t const& right);
        friend bool operator>=(Int64 const& left, int32_t const& right);
        friend bool operator<=(Int64 const& left, int32_t const& right);
        friend bool operator>(Int64 const& left, int32_t const& right);
        friend bool operator<(Int64 const& left, int32_t const& right);

        friend Int64 operator+(Int64 const& left, int64_t const& right);
        friend Int64 operator-(Int64 const& left, int64_t const& right);
        friend Int64 operator*(Int64 const& left, int64_t const& right);
        friend Int64 operator/(Int64 const& left, int64_t const& right);
        friend bool operator!=(Int64 const& left, int64_t const& right);
        friend bool operator==(Int64 const& left, int64_t const& right);
        friend bool operator>=(Int64 const& left, int64_t const& right);
        friend bool operator<=(Int64 const& left, int64_t const& right);
        friend bool operator>(Int64 const& left, int64_t const& right);
        friend bool operator<(Int64 const& left, int64_t const& right);
    };

}
_FANTASIA_END
#pragma pack(pop)
#pragma warning(pop)
