
#include <catch2/catch_test_macros.hpp>
#include "Maple/Runtime.hxx"


using namespace _Maple;
using namespace _Maple::Foundation;


namespace UnitTest::Foundation::TestInt32
{

    TEST_CASE("Int32 should be plain old data type", "[Foundation][Int32]")
    {
        CHECK(std::is_trivial_v<Int32>);
        CHECK(std::is_standard_layout_v<Int32>);
    }


    template<Int32 _Value>
    struct v {
        static constexpr auto value = _Value;
    };


    TEST_CASE("Int32 should able to be template's parameter", "[Foundation][Int32]")
    {
        v<32> v1;
    }


    TEST_CASE("Int32 value range", "[Foundation][Int32]")
    {
        CHECK(Int32::Max() == std::numeric_limits<int32_t>::max());
        CHECK(Int32::Min() == std::numeric_limits<int32_t>::min());
    }


    TEST_CASE("Int32 init", "[Foundation][Int32]")
    {
        SECTION("empty") {
            Int32 IntVal1;
        }

        SECTION("init from literal integer value")
        {
            Int32 IntVal1(3);
            CHECK(IntVal1 == 3);

            Int32 IntVal2{78};
            CHECK(IntVal2 == 78);

            Int32 IntVal3 = 889;
            CHECK(IntVal3 == 889);
        }

        SECTION("init from int64_t type value")
        {
            int64_t Val = 65;

            Int32 IntVal1(Val);
            CHECK(IntVal1 == Val);

            Int32 IntVal2{Val};
            CHECK(IntVal2 == Val);

            Int32 IntVal3 = Val;
            CHECK(IntVal3 == Val);
        }

        SECTION("init from uint64_t type value")
        {
            uint64_t Val0 = Int32::Max();

            Int32 IntVal1(Val0);
            CHECK(IntVal1 == Val0);

            Int32 IntVal2{Val0};
            CHECK(IntVal2 == Val0);

            Int32 IntVal3 = Val0;
            CHECK(IntVal3 == Val0);
        }

        SECTION("init from char type value")
        {
            char CharVal = '9';

            Int32 IntVal1(CharVal);
            CHECK(IntVal1 == CharVal);

            Int32 IntVal2{CharVal};
            CHECK(IntVal2 == CharVal);

            Int32 IntVal3 = CharVal;
            CHECK(IntVal3 == CharVal);
        }

        SECTION("init from signed char type value")
        {
            signed char CharVal = ',';

            Int32 IntVal1(CharVal);
            CHECK(IntVal1 == CharVal);

            Int32 IntVal2{CharVal};
            CHECK(IntVal2 == CharVal);

            Int32 IntVal3 = CharVal;
            CHECK(IntVal3 == CharVal);
        }

        SECTION("init from unsigned char type value")
        {
            unsigned char CharVal = 'p';

            Int32 IntVal1(CharVal);
            CHECK(IntVal1 == CharVal);

            Int32 IntVal2{CharVal};
            CHECK(IntVal2 == CharVal);

            Int32 IntVal3 = CharVal;
            CHECK(IntVal3 == CharVal);
        }

        SECTION("init from short type value")
        {
            short ShortVal = 12000;

            Int32 IntVal1(ShortVal);
            CHECK(IntVal1 == ShortVal);

            Int32 IntVal2{ShortVal};
            CHECK(IntVal2 == ShortVal);

            Int32 IntVal3 = ShortVal;
            CHECK(IntVal3 == ShortVal);
        }

        SECTION("init from unsigned short type value")
        {
            unsigned short ShortVal = 12000;

            Int32 IntVal1(ShortVal);
            CHECK(IntVal1 == ShortVal);

            Int32 IntVal2{ShortVal};
            CHECK(IntVal2 == ShortVal);

            Int32 IntVal3 = ShortVal;
            CHECK(IntVal3 == ShortVal);
        }

        SECTION("init from int32_t type value")
        {
            int32_t Val = 65;

            Int32 IntVal1(Val);
            CHECK(IntVal1 == Val);

            Int32 IntVal2{Val};
            CHECK(IntVal2 == Val);

            Int32 IntVal3 = Val;
            CHECK(IntVal3 == Val);
        }

        SECTION("init from uint32_t type value")
        {
            uint32_t Val = 65;

            Int32 IntVal1(Val);
            CHECK(IntVal1 == Val);

            Int32 IntVal2{Val};
            CHECK(IntVal2 == Val);

            Int32 IntVal3 = Val;
            CHECK(IntVal3 == Val);
        }
    } // end of TEST_CASE("Int32 init" ...


    TEST_CASE("Int32 assign", "[Foundation][Int32]")
    {
        SECTION("assign from short")
        {
            short Val = 324;

            Int32 IntVal1(5);
            CHECK(IntVal1 == 5);

            IntVal1 = Val;
            CHECK(IntVal1 == Val);
        }

        SECTION("assign from unsigned short")
        {
            unsigned short Val = 334;

            Int32 IntVal1(5);
            CHECK(IntVal1 == 5);

            IntVal1 = Val;
            CHECK(IntVal1 == Val);
        }
    } // end of TEST_CASE("Int32 assign" ...


    TEST_CASE("Int32::ToString", "[Foundation][Int32]")
    {
        Int32 IntVal = 89;
        String StrVal = IntVal.ToString();

        CHECK(Algorithm::CompareString(StrVal, String("89")) == 0);
    }
}
