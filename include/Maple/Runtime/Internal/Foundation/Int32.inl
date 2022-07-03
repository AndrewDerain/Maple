#pragma once
#include "../../Foundation/Bool.hxx"
#include "../../Foundation/Float64.hxx"
#include "../../Foundation/String.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
{

    inline constexpr
	Int32 Int32::Max() noexcept {
		return std::numeric_limits<int32_t>::max();
	};


    inline constexpr
	Int32 Int32::Min() noexcept {
		return std::numeric_limits<int32_t>::min();
	}


    inline constexpr
	Int32::Int32(const int32_t value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    Int32::Int32(const uint32_t value) {
        Algorithm::AssignWithOverflowCheck(_StoredValue, value);
    }


    inline constexpr
    Int32::Int32(const char value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    Int32::Int32(const signed char value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    Int32::Int32(const unsigned char value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    Int32::Int32(const short value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    Int32::Int32(const unsigned short value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    Int32::Int32(const int64_t value) noexcept {
        Algorithm::AssignWithOverflowCheck(_StoredValue, value);
	}


    inline constexpr
    Int32::Int32(const uint64_t value) noexcept {
        Algorithm::AssignWithOverflowCheck(_StoredValue, value);
	}


    inline constexpr
    String Int32::ToString() const {
        return String(_StoredValue);
    }


    inline constexpr
    Int32::operator int32_t const&() const noexcept {
		return _StoredValue;
	}


    inline constexpr
    Int32::operator int32_t&() noexcept {
		return _StoredValue;
	}


    inline constexpr
    Int32& Int32::operator=(const Float64 other) noexcept {
        Algorithm::AssignWithOverflowCheck(_StoredValue, (double)other);
		return *this;
	}


    inline constexpr
    Int32& Int32::operator=(const short value) noexcept {
		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int32& Int32::operator=(const unsigned short value) noexcept {
		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int32& Int32::operator=(const int32_t value) noexcept {
		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int32& Int32::operator=(const uint32_t value) noexcept {
        Algorithm::AssignWithOverflowCheck(_StoredValue, value);
		return *this;
	}


    inline constexpr
    Int32& Int32::operator=(const int64_t value) noexcept {
        Algorithm::AssignWithOverflowCheck(_StoredValue, value);
		return *this;
	}


    inline constexpr
    Int32& Int32::operator=(const uint64_t value) noexcept {
        Algorithm::AssignWithOverflowCheck(_StoredValue, value);
		return *this;
	}


    inline constexpr
    Int32& Int32::operator=(const double value) noexcept {
        Algorithm::AssignWithOverflowCheck(_StoredValue, value);
		return *this;
	}

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)
