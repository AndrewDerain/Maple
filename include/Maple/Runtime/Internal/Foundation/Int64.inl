#pragma once
#include "../../Foundation/Bool.hxx"
#include "../../Foundation/Int32.hxx"
#include "../../Foundation/Float64.hxx"
#include "../../Foundation/String.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
{

    inline constexpr
	Int64 Int64::Max() noexcept {
		return NumericLimits<int64_t>::Max();
	};


    inline constexpr
	Int64 Int64::Min() noexcept {
		return NumericLimits<int64_t>::Min();
	}


    inline constexpr
	Int64::Int64(const int64_t value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    Int64::Int64(const uint64_t value) noexcept {
        Algorithm::AssignWithOverflowCheck(_StoredValue, value);
	}


    inline constexpr
    Int64::Int64(const char value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    Int64::Int64(const signed char value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    Int64::Int64(const unsigned char value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    Int64::Int64(const short value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    Int64::Int64(const unsigned short value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    Int64::Int64(const int32_t value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    Int64::Int64(const uint32_t value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    String Int64::ToString() const {
        return String(_StoredValue);
    }


    inline constexpr
    Int64::operator int64_t const&() const noexcept {
		return _StoredValue;
	}


    inline constexpr
    Int64::operator int64_t&() noexcept {
		return _StoredValue;
	}


    inline constexpr
    Int64& Int64::operator=(const Float64 other) noexcept {
        Algorithm::AssignWithOverflowCheck(_StoredValue, (double)other);
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(const short value) noexcept {
		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(const unsigned short value) noexcept {
		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(const int32_t value) noexcept {
		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(const uint32_t value) noexcept {
		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(const int64_t value) noexcept {
		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(const uint64_t value) noexcept {
        Algorithm::AssignWithOverflowCheck(_StoredValue, value);
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(const double value) noexcept {
        Algorithm::AssignWithOverflowCheck(_StoredValue, value);
		return *this;
	}

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)
