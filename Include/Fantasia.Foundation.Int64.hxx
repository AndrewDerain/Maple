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
        Int64() noexcept = default;
        ~Int64() noexcept = default;

        Int64(const Int64& other) noexcept;
        Int64(Int64&& other) noexcept;

        Int64(const int32_t& value) noexcept;
        Int64(int32_t&& value) noexcept;

        Int64(const int64_t& value) noexcept;
        Int64(int64_t&& value) noexcept;

        explicit operator int64_t() const noexcept;
        explicit operator const int64_t &() noexcept;

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
