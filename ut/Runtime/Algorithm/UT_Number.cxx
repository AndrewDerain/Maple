//
// Created by 宋豪杰 on 2022/6/13.
//
#include <catch2/catch_test_macros.hpp>
#include "Maple/Runtime/Internal/Algorithm/Number.inl"
#include <string>
#include <iostream>


using namespace _Maple;
using namespace _Maple::Algorithm;


namespace UnitTest::Algorithm
{

    TEST_CASE("Abs int8_t", "[Algorithm][Number]")
    {
        CHECK(Abs(-78) == 78);
        CHECK(Abs(89) == 89);
    }

}
