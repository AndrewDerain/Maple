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
	Int64::Int64(int64_t value) noexcept:
		_StoredValue(value)
	{
	#ifdef ___FANTASIA_ENABLE_UNITTEST_Int64
		UnitTestHelper_Int64.OverloadFunctionName(
			"Int64::Int64(int64_t value) noexcept");
	#endif
	}


    inline constexpr
    Int64::Int64(uint64_t value)
	{
	#ifdef ___FANTASIA_ENABLE_UNITTEST_Int64
		UnitTestHelper_Int64.OverloadFunctionName(
				"Int64::Int64(uint64_t value)");
	#endif
		
		if(value <= Max())
			_StoredValue = value;
		else
			throw std::out_of_range(
				"value whitch type is uint64_t is larger than max value of Int64");
	}


    inline constexpr
    Int64::Int64(char value) noexcept:
		_StoredValue(value)
	{
	#ifdef ___FANTASIA_ENABLE_UNITTEST_Int64
		UnitTestHelper_Int64.OverloadFunctionName(
			"Int64::Int64(char value) noexcept");
	#endif
	}


    inline constexpr
    Int64::Int64(signed char value) noexcept:
		_StoredValue(value)
	{
	#ifdef ___FANTASIA_ENABLE_UNITTEST_Int64
		UnitTestHelper_Int64.OverloadFunctionName(
			"Int64::Int64(signed char value) noexcept");
	#endif
	}


    inline constexpr
    Int64::Int64(unsigned char value) noexcept:
		_StoredValue(value)
	{
	#ifdef ___FANTASIA_ENABLE_UNITTEST_Int64
		UnitTestHelper_Int64.OverloadFunctionName(
			"Int64::Int64(unsigned char value) noexcept");
	#endif
	}


    inline constexpr
    Int64::Int64(short value) noexcept:
		_StoredValue(value)
	{
	#ifdef ___FANTASIA_ENABLE_UNITTEST_Int64
		UnitTestHelper_Int64.OverloadFunctionName(
			"Int64::Int64(short value) noexcept");
	#endif
	}


    inline constexpr
    Int64::Int64(unsigned short value) noexcept:
		_StoredValue(value)
	{
	#ifdef ___FANTASIA_ENABLE_UNITTEST_Int64
		UnitTestHelper_Int64.OverloadFunctionName(
			"Int64::Int64(unsigned short value) noexcept");
	#endif
	}


    inline constexpr
    Int64::Int64(int32_t value) noexcept:
		_StoredValue(value)
	{
	#ifdef ___FANTASIA_ENABLE_UNITTEST_Int64
		UnitTestHelper_Int64.OverloadFunctionName(
			"Int64::Int64(int32_t value) noexcept");
	#endif
	}


    inline constexpr
    Int64::Int64(uint32_t value) noexcept:
		_StoredValue(value)
	{
	#ifdef ___FANTASIA_ENABLE_UNITTEST_Int64
		UnitTestHelper_Int64.OverloadFunctionName(
				"Int64::Int64(uint32_t value) noexcept");
	#endif
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
    Int64& Int64::operator=(Float64 other) noexcept {
		_StoredValue = (double)other;
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(short value) noexcept
	{
	#ifdef ___FANTASIA_ENABLE_UNITTEST_Int64
		UnitTestHelper_Int64.OverloadFunctionName(
				"Int64& Int64::operator=(short value) noexcept");
	#endif

		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(unsigned short value) noexcept
	{
	#ifdef ___FANTASIA_ENABLE_UNITTEST_Int64
		UnitTestHelper_Int64.OverloadFunctionName(
				"Int64& Int64::operator=(unsigned short value) noexcept");
	#endif

		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(int32_t value) noexcept {
		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(uint32_t value) noexcept {
		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(int64_t value) noexcept {
		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(uint64_t value) noexcept {
		_StoredValue = value;
		return *this;
	}


    inline constexpr
    Int64& Int64::operator=(double value) noexcept {
		_StoredValue = value;
		return *this;
	}

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)
