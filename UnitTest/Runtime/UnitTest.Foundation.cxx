
#include <catch2/catch_test_macros.hpp>


//#include <Runtime/Basic.Tracer.hxx>
#include <Fantasia.Foundation>


constexpr bool IsEqual(const char* lstr, const char* rstr)
{
	for(int i = 0; lstr[i] != '\0' && rstr[i] != '\0'; i++)
		if(lstr[i] != rstr[i]) return false;
	return true;
}


template<bool v>
struct no_partial_specialization
{
	no_partial_specialization(){
		static_assert(v, "no partial specialization for type.");
	}
};


template<typename _T, typename _F>
_T cast(_F& src){
	no_partial_specialization<false>();
	return _T();
}


template<>
int64_t cast<int64_t, uint64_t>(uint64_t& src){
	return src;
}


template<>
char cast<char, uint64_t>(uint64_t& src){
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	return src;
}


namespace UnitTest::Foundation::TestInt64
{
	using ::Fantasia::Int64;


	TEST_CASE("Demo"){
		uint64_t uintv = 23;
		int64_t intv = 0;

		intv = cast<int64_t>(uintv);
		auto m = cast<char>(uintv);
		//intv = cast<double>(uintv);
		CHECK(intv == uintv);
	}


	TEST_CASE("Int64 shoule be plain old data type", "[Foundation][Int64]")
	{
		CHECK(std::is_trivial_v<Int64>);
		CHECK(std::is_standard_layout_v<Int64>);
	}


	TEST_CASE("Int64 value range", "[Foundation][Int64]")
	{
		CHECK(Int64::Max() == std::numeric_limits<int64_t>::max());
		CHECK(Int64::Min() == std::numeric_limits<int64_t>::min());
	}


	TEST_CASE("Int64 init", "[Foundation][Int64]")
	{
		SECTION("empty") {
			Int64 IntVal1;
		}

		SECTION("init from literal integer value")
		{
			Int64 IntVal1(3);
			CHECK(IntVal1._StoredValue == 3);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
					"Int64::Int64(int32_t value) noexcept"));

			Int64 IntVal2{ 78 };
			CHECK(IntVal2._StoredValue == 78);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
					"Int64::Int64(int32_t value) noexcept"));

			Int64 IntVal3 = 889;
			CHECK(IntVal3._StoredValue == 889);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
					"Int64::Int64(int32_t value) noexcept"));
		}

		SECTION("init from int64_t type value")
		{
			int64_t Val = 65;

			Int64 IntVal1(Val);
			CHECK(IntVal1._StoredValue == Val);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				   	"Int64::Int64(int64_t value) noexcept"));

			Int64 IntVal2 {Val};
			CHECK(IntVal2._StoredValue == Val);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				  	"Int64::Int64(int64_t value) noexcept"));

			Int64 IntVal3 = Val;
			CHECK(IntVal3._StoredValue == Val);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
					"Int64::Int64(int64_t value) noexcept"));
		}

		SECTION("init from uint64_t type value")
		{
			uint64_t Val0 = Int64::Max();

			Int64 IntVal1(Val0);
			CHECK(IntVal1._StoredValue == Val0);
			// CHECK(IsEqual(
			// 		UnitTestHelper_Int64.OverloadFunctionName(),
			// 		"Int64::Int64(uint64_t value)"));

			Int64 IntVal2 {Val0};
			CHECK(IntVal2._StoredValue == Val0);
			// CHECK(IsEqual(
			// 		UnitTestHelper_Int64.OverloadFunctionName(),
			// 		"Int64::Int64(uint64_t value)"));

			Int64 IntVal3 = Val0;
			CHECK(IntVal3._StoredValue == Val0);
			// CHECK(IsEqual(
			// 		UnitTestHelper_Int64.OverloadFunctionName(),
			// 		"Int64::Int64(uint64_t value)"));

			CHECK_THROWS_AS([]{
				uint64_t Val1 = std::numeric_limits<uint64_t>::max();
				Int64 IntVal0(Val1);
			}(), std::out_of_range);

			CHECK_THROWS_AS([]{
				uint64_t Val1 = std::numeric_limits<int64_t>::max();
				Val1 += 1;
				Int64 IntVal0(Val1);
			}(), std::out_of_range);
		}

		SECTION("init from char type value")
		{
			char CharVal = '9';

			Int64 IntVal1(CharVal);
			CHECK(IntVal1._StoredValue == CharVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				   	"Int64::Int64(char value) noexcept"));

			Int64 IntVal2 {CharVal};
			CHECK(IntVal2._StoredValue == CharVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				  	"Int64::Int64(char value) noexcept"));

			Int64 IntVal3 = CharVal;
			CHECK(IntVal3._StoredValue == CharVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				  	"Int64::Int64(char value) noexcept"));
		}

		SECTION("init from signed char type value")
		{
			signed char CharVal = ',';

			Int64 IntVal1(CharVal);
			CHECK(IntVal1._StoredValue == CharVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				  	"Int64::Int64(signed char value) noexcept"));

			Int64 IntVal2 {CharVal};
			CHECK(IntVal2._StoredValue == CharVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				  	"Int64::Int64(signed char value) noexcept"));

			Int64 IntVal3 = CharVal;
			CHECK(IntVal3._StoredValue == CharVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				  	"Int64::Int64(signed char value) noexcept"));
		}

		SECTION("init from unsigned char type value")
		{
			unsigned char CharVal = 'p';

			Int64 IntVal1(CharVal);
			CHECK(IntVal1._StoredValue == CharVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				  	"Int64::Int64(unsigned char value) noexcept"));

			Int64 IntVal2 {CharVal};
			CHECK(IntVal2._StoredValue == CharVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				  	"Int64::Int64(unsigned char value) noexcept"));

			Int64 IntVal3 = CharVal;
			CHECK(IntVal3._StoredValue == CharVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				   	"Int64::Int64(unsigned char value) noexcept"));
		}

		SECTION("init from short type value")
		{
			short ShortVal = 12000;

			Int64 IntVal1(ShortVal);
			CHECK(IntVal1._StoredValue == ShortVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				   	"Int64::Int64(short value) noexcept"));

			Int64 IntVal2 {ShortVal};
			CHECK(IntVal2._StoredValue == ShortVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				  	"Int64::Int64(short value) noexcept"));

			Int64 IntVal3 = ShortVal;
			CHECK(IntVal3._StoredValue == ShortVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				   	"Int64::Int64(short value) noexcept"));
		}

		SECTION("init from unsigned short type value")
		{
			unsigned short ShortVal = 12000;

			Int64 IntVal1(ShortVal);
			CHECK(IntVal1._StoredValue == ShortVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				   	"Int64::Int64(unsigned short value) noexcept"));

			Int64 IntVal2 {ShortVal};
			CHECK(IntVal2._StoredValue == ShortVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				   	"Int64::Int64(unsigned short value) noexcept"));

			Int64 IntVal3 = ShortVal;
			CHECK(IntVal3._StoredValue == ShortVal);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				   	"Int64::Int64(unsigned short value) noexcept"));
		}

		SECTION("init from int32_t type value")
		{
			int32_t Val = 65;

			Int64 IntVal1(Val);
			CHECK(IntVal1._StoredValue == Val);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				   	"Int64::Int64(int32_t value) noexcept"));

			Int64 IntVal2 {Val};
			CHECK(IntVal2._StoredValue == Val);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				   	"Int64::Int64(int32_t value) noexcept"));

			Int64 IntVal3 = Val;
			CHECK(IntVal3._StoredValue == Val);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				  	"Int64::Int64(int32_t value) noexcept"));
		}

		SECTION("init from uint32_t type value")
		{
			uint32_t Val = 65;

			Int64 IntVal1(Val);
			CHECK(IntVal1._StoredValue == Val);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				  	"Int64::Int64(uint32_t value) noexcept"));

			Int64 IntVal2 {Val};
			CHECK(IntVal2._StoredValue == Val);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				   	"Int64::Int64(uint32_t value) noexcept"));

			Int64 IntVal3 = Val;
			CHECK(IntVal3._StoredValue == Val);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				  	"Int64::Int64(uint32_t value) noexcept"));
		}
	} // end of TEST_CASE("Int64 init" ...


	TEST_CASE("Int64 assign", "[Foundation][Int64]")
	{
		SECTION("assign from short")
		{
			short Val = 324;

			Int64 IntVal1(5);
			CHECK(IntVal1._StoredValue == 5);

			IntVal1 = Val;
			CHECK(IntVal1._StoredValue == Val);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				  	"Int64& Int64::operator=(short value) noexcept"));
		}

		SECTION("assign from unsigned short")
		{
			unsigned short Val = 334;

			Int64 IntVal1(5);
			CHECK(IntVal1._StoredValue == 5);

			IntVal1 = Val;
			CHECK(IntVal1._StoredValue == Val);
			CHECK(IsEqual(
					UnitTestHelper_Int64.OverloadFunctionName(),
				  	"Int64& Int64::operator=(unsigned short value) noexcept"));
		}
	} // end of TEST_CASE("Int64 assign" ...
}
