#pragma once
#include "Fantasia/Runtime/Foundation/Bool.hxx"
#include "Fantasia/Runtime/Foundation/Float64.hxx"
#include "Fantasia/Runtime/Foundation/String.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Foundation
{
    inline constexpr
	Int64 Int64::Max() noexcept {
		return std::numeric_limits<int64_t>::max();
	};


    inline constexpr
	Int64 Int64::Min() noexcept {
		return std::numeric_limits<int64_t>::min();
	}


    inline constexpr
	Int64::Int64(const int64_t value) noexcept:
		_StoredValue(value) {
	}


    inline constexpr
    Int64::Int64(const uint64_t value) {

		if(value <= Max())
			_StoredValue = value;
		else
			throw std::out_of_range(
				"value whitch type is uint64_t is larger than max value of Int64");
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
    Int64::operator int64_t const&() const noexcept {
		return _StoredValue;
	}


    inline constexpr
    Int64::operator int64_t&() noexcept {
		return _StoredValue;
	}


    inline constexpr
    Int64& Int64::operator=(const Float64 other) noexcept {
		_StoredValue = (double)other;
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
		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(const double value) noexcept {
		_StoredValue = value;
		return *this;
	}

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)
