
#include <catch2/catch_test_macros.hpp>
#include "Fantasia/Foundation"


using namespace _Fantasia;
using namespace _Fantasia::Foundation;


namespace UnitTest::Foundation::TestInt64
{

    TEST_CASE("Int64 should be plain old data type", "[Foundation][Int64]")
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
            CHECK(IntVal1 == 3);

            Int64 IntVal2{78};
            CHECK(IntVal2 == 78);

            Int64 IntVal3 = 889;
            CHECK(IntVal3 == 889);
        }

        SECTION("init from int64_t type value")
        {
            int64_t Val = 65;

            Int64 IntVal1(Val);
            CHECK(IntVal1 == Val);

            Int64 IntVal2{Val};
            CHECK(IntVal2 == Val);

            Int64 IntVal3 = Val;
            CHECK(IntVal3 == Val);
        }

        SECTION("init from uint64_t type value")
        {
            uint64_t Val0 = Int64::Max();

            Int64 IntVal1(Val0);
            CHECK(IntVal1 == Val0);
            
            Int64 IntVal2{Val0};
            CHECK(IntVal2 == Val0);

            Int64 IntVal3 = Val0;
            CHECK(IntVal3 == Val0);

            /*CHECK_THROWS_AS([] {
                uint64_t Val1 = std::numeric_limits<uint64_t>::max();
                Int64 IntVal0(Val1);
            }(), std::out_of_range);

            CHECK_THROWS_AS([] {
                uint64_t Val1 = std::numeric_limits<int64_t>::max();
                Val1 += 1;
                Int64 IntVal0(Val1);
            }(), std::out_of_range);*/
        }

        SECTION("init from char type value")
        {
            char CharVal = '9';

            Int64 IntVal1(CharVal);
            CHECK(IntVal1 == CharVal);

            Int64 IntVal2{CharVal};
            CHECK(IntVal2 == CharVal);

            Int64 IntVal3 = CharVal;
            CHECK(IntVal3 == CharVal);
        }

        SECTION("init from signed char type value")
        {
            signed char CharVal = ',';

            Int64 IntVal1(CharVal);
            CHECK(IntVal1 == CharVal);

            Int64 IntVal2{CharVal};
            CHECK(IntVal2 == CharVal);

            Int64 IntVal3 = CharVal;
            CHECK(IntVal3 == CharVal);
        }

        SECTION("init from unsigned char type value")
        {
            unsigned char CharVal = 'p';

            Int64 IntVal1(CharVal);
            CHECK(IntVal1 == CharVal);

            Int64 IntVal2{CharVal};
            CHECK(IntVal2 == CharVal);

            Int64 IntVal3 = CharVal;
            CHECK(IntVal3 == CharVal);
        }

        SECTION("init from short type value")
        {
            short ShortVal = 12000;

            Int64 IntVal1(ShortVal);
            CHECK(IntVal1 == ShortVal);

            Int64 IntVal2{ShortVal};
            CHECK(IntVal2 == ShortVal);

            Int64 IntVal3 = ShortVal;
            CHECK(IntVal3 == ShortVal);
        }

        SECTION("init from unsigned short type value")
        {
            unsigned short ShortVal = 12000;

            Int64 IntVal1(ShortVal);
            CHECK(IntVal1 == ShortVal);

            Int64 IntVal2{ShortVal};
            CHECK(IntVal2 == ShortVal);

            Int64 IntVal3 = ShortVal;
            CHECK(IntVal3 == ShortVal);
        }

        SECTION("init from int32_t type value")
        {
            int32_t Val = 65;

            Int64 IntVal1(Val);
            CHECK(IntVal1 == Val);

            Int64 IntVal2{Val};
            CHECK(IntVal2 == Val);

            Int64 IntVal3 = Val;
            CHECK(IntVal3 == Val);
        }

        SECTION("init from uint32_t type value")
        {
            uint32_t Val = 65;

            Int64 IntVal1(Val);
            CHECK(IntVal1 == Val);

            Int64 IntVal2{Val};
            CHECK(IntVal2 == Val);

            Int64 IntVal3 = Val;
            CHECK(IntVal3 == Val);
        }
    } // end of TEST_CASE("Int64 init" ...


    TEST_CASE("Int64 assign", "[Foundation][Int64]")
    {
        SECTION("assign from short")
        {
            short Val = 324;

            Int64 IntVal1(5);
            CHECK(IntVal1 == 5);

            IntVal1 = Val;
            CHECK(IntVal1 == Val);
        }

        SECTION("assign from unsigned short")
        {
            unsigned short Val = 334;

            Int64 IntVal1(5);
            CHECK(IntVal1 == 5);

            IntVal1 = Val;
            CHECK(IntVal1 == Val);
        }
    } // end of TEST_CASE("Int64 assign" ...


    TEST_CASE("Int64::ToString", "[Foundation][Int64]")
    {
        Int64 IntVal = 89;
        String StrVal = IntVal.ToString();

        CHECK(Algorithm::CompareString(StrVal, String("89")) == 0);
    }

}
