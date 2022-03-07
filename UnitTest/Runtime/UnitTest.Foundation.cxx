
#include <catch2/catch_test_macros.hpp>

#define protected public
#define ___FANTASIA_ENABLED_UNITTEST
#include <Fantasia.Foundation>


namespace UnitTest::Foundation::TestInt64
{
	using ::Fantasia::Int64;


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

			Int64 IntVal2{ 78 };
			CHECK(IntVal2._StoredValue == 78);

			Int64 IntVal3 = 889;
			CHECK(IntVal3._StoredValue == 889);
		}

		SECTION("init from char type value") {
			char CharVal = '9';

			Int64 IntVal1(CharVal);
			CHECK(IntVal1._StoredValue == CharVal);

			Int64 IntVal2 {CharVal};
			CHECK(IntVal2._StoredValue == CharVal);

			Int64 IntVal3 = CharVal;
			CHECK(IntVal3._StoredValue == CharVal);
		}

		SECTION("init from signed char type value")
		{
			signed char CharVal = ',';

			Int64 IntVal1(CharVal);
			CHECK(IntVal1._StoredValue == CharVal);

			Int64 IntVal2 {CharVal};
			CHECK(IntVal2._StoredValue == CharVal);

			Int64 IntVal3 = CharVal;
			CHECK(IntVal3._StoredValue == CharVal);
		}

		SECTION("init from unsigned char type value")
		{
			unsigned char CharVal = 'p';

			Int64 IntVal1(CharVal);
			CHECK(IntVal1._StoredValue == CharVal);

			Int64 IntVal2 {CharVal};
			CHECK(IntVal2._StoredValue == CharVal);

			Int64 IntVal3 = CharVal;
			CHECK(IntVal3._StoredValue == CharVal);
		}

	} // end of TEST_CASE("Int64 init" ...


}
