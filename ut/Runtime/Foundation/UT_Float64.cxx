
#include <catch2/catch_test_macros.hpp>
#include "Fantasia/Foundation"


using namespace _Fantasia::Foundation;


namespace UnitTest::Foundation::TestFloat64
{

    TEST_CASE("Float64 should be plain old data type", "[Foundation][Float64]")
    {
        CHECK(std::is_trivial_v<Float64>);
        CHECK(std::is_standard_layout_v<Float64>);
    }


    TEST_CASE("Float64 value range", "[Foundation][Float64]")
    {
        CHECK(Float64::Max() == std::numeric_limits<double>::max());
        CHECK(Float64::Min() == std::numeric_limits<double>::min());
    }


    TEST_CASE("Float64 init", "[Foundation][Int64]")
    {
        SECTION("empty") {
            Float64 Val1;
        }

        SECTION("init from literal integer value")
        {
            Float64 Val1(3);
            CHECK(Val1 == 3.0000000000000001);

            Float64 Val2{78};
            CHECK(Val2 == 78);

            Float64 Val3 = 889;
            CHECK(Val3 == 889);
        }

        SECTION("init from int64_t type value")
        {
            int64_t Val = 65;

            Float64 IntVal1(Val);
            CHECK(IntVal1 == Val);

            Float64 IntVal2{Val};
            CHECK(IntVal2 == Val);

            Float64 IntVal3 = Val;
            CHECK(IntVal3 == Val);
        }

        SECTION("init from uint64_t type value")
        {
            uint64_t UIntVal0 = Int64::Max();

            Float64 Val1(UIntVal0);
            CHECK(Val1 == UIntVal0);

            Float64 Val2{UIntVal0};
            CHECK(Val2 == UIntVal0);

            Float64 Val3 = UIntVal0;
            CHECK(Val3 == UIntVal0);

            uint64_t UIntVal1 = std::numeric_limits<uint64_t>::max();
            Float64 Val4(UIntVal1);
            CHECK(Val4 == UIntVal1);

            uint64_t UIntVal2 = std::numeric_limits<int64_t>::max();
            UIntVal2 += 1;
            Float64 Val5(UIntVal2);
            CHECK(Val5 == UIntVal2);
        }

        SECTION("init from char type value")
        {
            const char CharVal = '9';

            Float64 Val1(CharVal);
            CHECK(Val1 == CharVal);

            Float64 Val2{CharVal};
            CHECK(Val2 == CharVal);

            Float64 Val3 = CharVal;
            CHECK(Val3 == CharVal);
        }

        SECTION("init from signed char type value")
        {
            signed char CharVal = ',';

            Float64 Val1(CharVal);
            CHECK(Val1 == CharVal);

            Float64 Val2{CharVal};
            CHECK(Val2 == CharVal);

            Float64 Val3 = CharVal;
            CHECK(Val3 == CharVal);
        }

        SECTION("init from unsigned char type value")
        {
            unsigned char CharVal = 'p';

            Float64 Val1(CharVal);
            CHECK(Val1 == CharVal);

            Float64 Val2{CharVal};
            CHECK(Val2 == CharVal);

            Float64 Val3 = CharVal;
            CHECK(Val3 == CharVal);
        }

        SECTION("init from short type value")
        {
            short ShortVal = 12000;

            Float64 Val1(ShortVal);
            CHECK(Val1 == ShortVal);

            Float64 Val2{ShortVal};
            CHECK(Val2 == ShortVal);

            Float64 Val3 = ShortVal;
            CHECK(Val3 == ShortVal);
        }

        SECTION("init from unsigned short type value")
        {
            unsigned short ShortVal = 12000;

            Float64 Val1(ShortVal);
            CHECK(Val1 == ShortVal);

            Float64 Val2{ShortVal};
            CHECK(Val2 == ShortVal);

            Float64 Val3 = ShortVal;
            CHECK(Val3 == ShortVal);
        }

        SECTION("init from int32_t type value")
        {
            int32_t IntVal = 65;

            Float64 Val1(IntVal);
            CHECK(Val1 == IntVal);

            Float64 Val2{IntVal};
            CHECK(Val2 == IntVal);

            Float64 Val3 = IntVal;
            CHECK(Val3 == IntVal);
        }

        SECTION("init from uint32_t type value")
        {
            uint32_t IntVal = 65;

            Float64 Val1(IntVal);
            CHECK(Val1 == IntVal);

            Float64 Val2{IntVal};
            CHECK(Val2 == IntVal);

            Float64 Val3 = IntVal;
            CHECK(Val3 == IntVal);
        }
    } // end of TEST_CASE("Float64 init" ...

}