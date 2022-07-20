
#include <catch2/catch_test_macros.hpp>
#include "Maple/Runtime.hxx"


using namespace _Maple::Foundation;


namespace UnitTest::Foundation::TestDouble
{

    TEST_CASE("Double should be plain old data type", "[Foundation][Double]")
    {
        CHECK(std::is_trivial_v<Double>);
        CHECK(std::is_standard_layout_v<Double>);
    }

    template<Double value>
    struct v {};

    TEST_CASE("Double should able to be template's parameter", "[Foundation][Double]")
    {
        v<32.8> v1;
    }

    TEST_CASE("Double value range", "[Foundation][Double]")
    {
        CHECK(Double::Max() == std::numeric_limits<double>::max());
        CHECK(Double::Min() == std::numeric_limits<double>::min());
    }


    TEST_CASE("Double init", "[Foundation][Int64]")
    {
        SECTION("empty") {
            Double Val1;
        }

        SECTION("init from literal integer value")
        {
            Double Val1(3);
            CHECK(Val1 == 3.0000000000000001);

            Double Val2{78};
            CHECK(Val2 == 78);

            Double Val3 = 889;
            CHECK(Val3 == 889);
        }

        SECTION("init from int64_t type value")
        {
            int64_t Val = 65;

            Double IntVal1(Val);
            CHECK(IntVal1 == Val);

            Double IntVal2{Val};
            CHECK(IntVal2 == Val);

            Double IntVal3 = Val;
            CHECK(IntVal3 == Val);
        }

        SECTION("init from uint64_t type value")
        {
            uint64_t UIntVal0 = Int64::Max();

            Double Val1(UIntVal0);
            CHECK(Val1 == UIntVal0);

            Double Val2{UIntVal0};
            CHECK(Val2 == UIntVal0);

            Double Val3 = UIntVal0;
            CHECK(Val3 == UIntVal0);

            uint64_t UIntVal1 = std::numeric_limits<uint64_t>::max();
            Double Val4(UIntVal1);
            CHECK(Val4 == UIntVal1);

            uint64_t UIntVal2 = std::numeric_limits<int64_t>::max();
            UIntVal2 += 1;
            Double Val5(UIntVal2);
            CHECK(Val5 == UIntVal2);
        }

        SECTION("init from char type value")
        {
            const char CharVal = '9';

            Double Val1(CharVal);
            CHECK(Val1 == CharVal);

            Double Val2{CharVal};
            CHECK(Val2 == CharVal);

            Double Val3 = CharVal;
            CHECK(Val3 == CharVal);
        }

        SECTION("init from signed char type value")
        {
            signed char CharVal = ',';

            Double Val1(CharVal);
            CHECK(Val1 == CharVal);

            Double Val2{CharVal};
            CHECK(Val2 == CharVal);

            Double Val3 = CharVal;
            CHECK(Val3 == CharVal);
        }

        SECTION("init from unsigned char type value")
        {
            unsigned char CharVal = 'p';

            Double Val1(CharVal);
            CHECK(Val1 == CharVal);

            Double Val2{CharVal};
            CHECK(Val2 == CharVal);

            Double Val3 = CharVal;
            CHECK(Val3 == CharVal);
        }

        SECTION("init from short type value")
        {
            short ShortVal = 12000;

            Double Val1(ShortVal);
            CHECK(Val1 == ShortVal);

            Double Val2{ShortVal};
            CHECK(Val2 == ShortVal);

            Double Val3 = ShortVal;
            CHECK(Val3 == ShortVal);
        }

        SECTION("init from unsigned short type value")
        {
            unsigned short ShortVal = 12000;

            Double Val1(ShortVal);
            CHECK(Val1 == ShortVal);

            Double Val2{ShortVal};
            CHECK(Val2 == ShortVal);

            Double Val3 = ShortVal;
            CHECK(Val3 == ShortVal);
        }

        SECTION("init from int32_t type value")
        {
            int32_t IntVal = 65;

            Double Val1(IntVal);
            CHECK(Val1 == IntVal);

            Double Val2{IntVal};
            CHECK(Val2 == IntVal);

            Double Val3 = IntVal;
            CHECK(Val3 == IntVal);
        }

        SECTION("init from uint32_t type value")
        {
            uint32_t IntVal = 65;

            Double Val1(IntVal);
            CHECK(Val1 == IntVal);

            Double Val2{IntVal};
            CHECK(Val2 == IntVal);

            Double Val3 = IntVal;
            CHECK(Val3 == IntVal);
        }
    } // end of TEST_CASE("Double init" ...

}
