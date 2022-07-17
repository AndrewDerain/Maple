//
// Created by 宋豪杰 on 2022/7/12.
//

#include <catch2/catch_test_macros.hpp>
#include "Maple/Runtime.hxx"


using namespace _Maple::Foundation;


namespace UnitTest::Foundation::TestEnumeration
{

    struct Enum_01
    {
        EnumerationImplementation(
            Enum_01,
            E01
        );
    };


    struct Enum_02
    {
        EnumerationImplementation(
            Enum_02,
            E01,
            E02
        );
    };


    struct Enum_03
    {
        EnumerationImplementation(
                Enum_03,
                E01,
                E02,
                E03
        );
    };


    struct Enum_04
    {
        EnumerationImplementation(
                Enum_04,
                E01,
                E02,
                E03,
                E04
        );
    };


    struct Enum_05
    {
        EnumerationImplementation(
                Enum_05,
                E01,
                E02,
                E03,
                E04,
                E05
        );
    };


    struct Enum_06
    {
        EnumerationImplementation(
                Enum_06,
                E01,
                E02,
                E03,
                E04,
                E05,
                E06
        );
    };


    struct Enum_07
    {
        EnumerationImplementation(
                Enum_07,
                E01,
                E02,
                E03,
                E04,
                E05,
                E06,
                E07
        );
    };


    TEST_CASE("Enumeration should be plain old data type", "[Foundation][Enumeration]")
    {
        CHECK(std::is_trivial_v<Enum_01>);
        CHECK(std::is_standard_layout_v<Enum_01>);

        CHECK(std::is_trivial_v<Enum_02>);
        CHECK(std::is_standard_layout_v<Enum_02>);

        CHECK(std::is_trivial_v<Enum_03>);
        CHECK(std::is_standard_layout_v<Enum_03>);

        CHECK(std::is_trivial_v<Enum_04>);
        CHECK(std::is_standard_layout_v<Enum_04>);

        CHECK(std::is_trivial_v<Enum_05>);
        CHECK(std::is_standard_layout_v<Enum_05>);

        CHECK(std::is_trivial_v<Enum_06>);
        CHECK(std::is_standard_layout_v<Enum_06>);

        CHECK(std::is_trivial_v<Enum_07>);
        CHECK(std::is_standard_layout_v<Enum_07>);
    }


    TEST_CASE("Enum_01", "[Foundation][Enumeration]")
    {
        using TargetType = Enum_01;

        TargetType Val0;
        TargetType Val1;

        Val0 = Val0.E01;
        CHECK(Val0 == Val0.E01);
        CHECK(Val0 == TargetType::E01);
        CHECK(strcmp(Val0.ToString(), "E01") == 0);

        Val1.FromString("E01");
        CHECK(Val0 == Val1);
    }


    TEST_CASE("Enum_02", "[Foundation][Enumeration]")
    {
        using TargetType = Enum_02;

        TargetType Val0, Val1;

        Val0 = Val0.E01;
        CHECK(Val0 == Val0.E01);
        CHECK(Val0 == TargetType::E01);
        CHECK(strcmp(Val0.ToString(), "E01") == 0);

        Val0 = Val0.E01;
        Val1.FromString("E01");
        CHECK(Val0 == Val1);

        Val0 = Val0.E02;
        Val1.FromString("E02");
        CHECK(Val0 == Val1);
    }


}