﻿
#include <Fantasia.Foundation.Int64.hxx>

#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_BEGIN
namespace Foundation 
{
    // constructor
    Int64::Int64(const Int64& other) noexcept :
        _Storage(other._Storage) {
    }

    Int64::Int64(Int64&& other) noexcept :
        _Storage(move(other._Storage)) {
    }

    Int64::Int64(const int32_t& value) noexcept : 
        _Storage(value) {
    }

    Int64::Int64(int32_t&& value) noexcept :
        _Storage(move(value)) {
    }

    Int64::Int64(const int64_t& value) noexcept {
        _Storage = value;
    }

    Int64::Int64(int64_t&& value) noexcept {
        _Storage = move(value);
    }

    Int64::operator int64_t() const noexcept {
        return _Storage; 
    }

    Int64::operator const int64_t &() noexcept {
        return _Storage;
    }

    // operators with self
    Int64 operator+(Int64 const& left, Int64 const& right) {
        return left._Storage + right._Storage;
    }

    Int64 operator-(Int64 const& left, Int64 const& right) {
        return left._Storage - right._Storage;
    }

    Int64 operator*(Int64 const& left, Int64 const& right) {
        return left._Storage * right._Storage;
    }

    Int64 operator/(Int64 const& left, Int64 const& right) {
        return left._Storage / right._Storage;
    }

    bool operator!=(Int64 const& left, Int64 const& right) {
        return left._Storage != right._Storage;
    }

    bool operator==(Int64 const& left, Int64 const& right) {
        return left._Storage == right._Storage;
    }

    bool operator>=(Int64 const& left, Int64 const& right) {
        return left._Storage >= right._Storage;
    }

    bool operator<=(Int64 const& left, Int64 const& right) {
        return left._Storage <= right._Storage;
    }

    bool operator>(Int64 const& left, Int64 const& right) {
        return left._Storage > right._Storage;
    }

    bool operator<(Int64 const& left, Int64 const& right) {
        return left._Storage < right._Storage;
    }
    

    // operators with int32_t
    Int64 operator+(Int64 const& left, int32_t const& right) {
        return left._Storage + right;
    }

    Int64 operator-(Int64 const& left, int32_t const& right) {
        return left._Storage - right;
    }

    Int64 operator*(Int64 const& left, int32_t const& right) {
        return left._Storage * right;
    }

    Int64 operator/(Int64 const& left, int32_t const& right) {
        return left._Storage / right;
    }

    bool operator!=(Int64 const& left, int32_t const& right) {
        return left._Storage != right;
    }

    bool operator==(Int64 const& left, int32_t const& right) {
        return left._Storage == right;
    }

    bool operator>=(Int64 const& left, int32_t const& right) {
        return left._Storage >= right;
    }

    bool operator<=(Int64 const& left, int32_t const& right) {
        return left._Storage <= right;
    }

    bool operator>(Int64 const& left, int32_t const& right) {
        return left._Storage > right;
    }

    bool operator<(Int64 const& left, int32_t const& right) {
        return left._Storage < right;
    }


    // operators with int64_t
    Int64 operator+(Int64 const& left, int64_t const& right) {
        return left._Storage + right;
    }

    Int64 operator-(Int64 const& left, int64_t const& right) {
        return left._Storage - right;
    }

    Int64 operator*(Int64 const& left, int64_t const& right) {
        return left._Storage * right;
    }

    Int64 operator/(Int64 const& left, int64_t const& right) {
        return left._Storage / right;
    }

    bool operator!=(Int64 const& left, int64_t const& right) {
        return left._Storage != right;
    }

    bool operator==(Int64 const& left, int64_t const& right) {
        return left._Storage == right;
    }

    bool operator>=(Int64 const& left, int64_t const& right) {
        return left._Storage >= right;
    }

    bool operator<=(Int64 const& left, int64_t const& right) {
        return left._Storage <= right;
    }

    bool operator>(Int64 const& left, int64_t const& right) {
        return left._Storage > right;
    }

    bool operator<(Int64 const& left, int64_t const& right) {
        return left._Storage < right;
    }

}
_FANTASIA_END
#pragma pack(pop)
#pragma warning(pop)
