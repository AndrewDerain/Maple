
#include <catch2/catch_test_macros.hpp>
#include "Fantasia/Foundation"


using namespace _Fantasia;
using namespace _Fantasia::Algorithm;
using namespace _Fantasia::Foundation;


namespace UnitTest::Foundation::TestString
{

    const char *Tag = "[Foundation][String]";


    // A common random string for String test
    std::string random_string[10] = {
            "This is a random number [" + std::to_string(rand()) + "]",
            "This is a random number [" + std::to_string(rand()) + "]",
            "This is a random number [" + std::to_string(rand()) + "]",
            "This is a random number [" + std::to_string(rand()) + "]",
            "This is a random number [" + std::to_string(rand()) + "]",
            "This is a random number [" + std::to_string(rand()) + "]",
            "This is a random number [" + std::to_string(rand()) + "]",
            "This is a random number [" + std::to_string(rand()) + "]",
            "This is a random number [" + std::to_string(rand()) + "]",
            "This is a random number [" + std::to_string(rand()) + "]"
    };


    TEST_CASE("CountStringLength", Tag) {

        SECTION("Normal") {
            CHECK(CountStringLength("") == 0);
            CHECK(CountStringLength("2") == 1);
            CHECK(CountStringLength("1234567890") == 10);
        }

        SECTION("Count with constant expression") {
            constexpr auto Count0 = CountStringLength("");
            constexpr auto Count1 = CountStringLength("2");
            constexpr auto Count2 = CountStringLength("1234567890");

            CHECK(Count0 == 0);
            CHECK(Count1 == 1);
            CHECK(Count2 == 10);
        }
    }


    TEST_CASE("CompareString", Tag) {

        SECTION("Normal") {
            String Val1 = "12345";
            String Val2 = "12345";
            String Val3 = "24689";

            CHECK(CompareString(Val1, Val2) == 0);
            CHECK(CompareString(Val1, Val3) != 0);

            CHECK(CompareString(Val2, Val3) < 0);
            CHECK(CompareString(Val3, Val2) > 0);
        }

        SECTION("Compare with constant expression") {

            constexpr String Val1 = "12345";
            constexpr String Val2 = "12345";
            constexpr String Val3 = "24689";

            constexpr bool cmp1 = CompareString(Val1, Val2) == 0;
            CHECK(cmp1);

            constexpr bool cmp2 = CompareString(Val1, Val3) != 0;
            CHECK(cmp2);

            constexpr bool cmp3 = CompareString(Val2, Val3) < 0;
            CHECK(cmp3);

            constexpr bool cmp4 = CompareString(Val3, Val2) > 0;
            CHECK(cmp4);
        }
    }


    /// @note The size of Heap and Stack Storage must be the same
    TEST_CASE("StringStorage", Tag) {
        constexpr auto size = sizeof(String);
        CHECK(sizeof(StringHeapStorage) == sizeof(StringStackStorage));
    }


    TEST_CASE("String::MaxCapacity", Tag) {

        CHECK(String::MaxCapacity() == std::numeric_limits<std::uint16_t>::max());

        constexpr Int64 capacity = String::MaxCapacity();
        CHECK(String::MaxCapacity() == capacity);
    }


    TEST_CASE("Range based for-loop for String") {
        constexpr String Val1 = "12345";
        int i = 0;

        for (auto c: Val1) {
            CHECK(c == Val1[i++]);
        }
    }


    TEST_CASE("String::Length", Tag) {

        SECTION("Normal") {
            String Target = random_string[0].c_str();

            CHECK(bool(Target.IsOnStack()) == false);
            CHECK(Target.Length() == random_string[0].length());
        }

        SECTION("Constexpr") {
            constexpr String string = "Hello, world!";
            CHECK(string.Length() == sizeof("Hello, world!") - 1);
        }
    }


    TEST_CASE("String::Capacity", Tag) {

        SECTION("On stack") {
            String Target = "Hello, world!";
            CHECK(Target.Capacity() == StringStackStorage::Capacity());
        }

        SECTION("On stack with constant expression ") {
            constexpr String Target = "Hello, world!";
            CHECK(Target.Capacity() == StringStackStorage::Capacity());
        }

        SECTION("On Heap") {
            String Target = random_string[0].c_str();
            CHECK(bool(Target.IsOnStack()) == false);
        }
    }


    TEST_CASE("String constructor", "[Foundation][String]") {

        SECTION("Initialize on stack") {

            String Val1 = "12345";
            String Val2 = "12345";
            String Val3 = "24689";

            CHECK(CompareString(Val1, Val2) == 0);
            CHECK(CompareString(Val1, Val3) != 0);

            CHECK(CompareString(Val2, Val3) < 0);
            CHECK(CompareString(Val3, Val2) > 0);
        }

        SECTION("Initialize on heap") {
            for (auto &string: random_string) {
                String Target = string.c_str();

                CHECK(!Target.IsOnStack());
                CHECK(strcmp(Target, string.c_str()) == 0);
            }
        }

        SECTION("Twice assign on heap") {
            String Val1 = random_string[0].c_str();
            Val1 = random_string[1].c_str();

            CHECK(Val1 == String(random_string[1].c_str()));

            std::string LongStr;

            for(int i = 0; i <= 4; ++i)
                LongStr += random_string[i];

            Val1 = LongStr.c_str();
            CHECK(Val1 == String(LongStr.c_str()));
        }

        SECTION("Initialize with constant expression") {

            constexpr String Val1 = "123456";
            constexpr String Val2 = "24689";
            constexpr String Val3 = "123456";

            CHECK(Val1.Length() == sizeof("123456") - 1);
            CHECK(Val2.Length() == sizeof("24689")  - 1);
            CHECK(Val3.Length() == sizeof("123456") - 1);

            constexpr Bool cmp_r1 = Val1 == Val2;
            CHECK(cmp_r1 == false);

            constexpr Bool cmp_r2 = Val1 == Val3;
            CHECK(cmp_r2 == true);
        }
    }


    TEST_CASE("String destructor", "[Foundation][String]") {
        constexpr String Val = "234352";
        CHECK(Val == String("234352"));
    }


    TEST_CASE("String::Catenate(const char* value)", Tag) {

        SECTION("Normal on stack") {
            std::string_view val1 = "Constant ...";
            String Target = "Constant ...";

            CHECK(bool(Target.IsOnStack()) == true);
            CHECK(Target.Length() == sizeof("Constant ...") - 1);
            CHECK(CompareString(Target, "Constant ...") == 0);

            Target.Catenate("m");
            CHECK(bool(Target.IsOnStack()) == true);
            CHECK(Target.Length() == sizeof("Constant ...m") - 1);
            CHECK(CompareString(Target, "Constant ...") > 0);
        }

        SECTION("Normal on heap") {
            std::string val1 = "Normal behavior while value is on the heap.";
            String Target = "Normal behavior while value is on the ";

            Target.Catenate("heap.");
            CHECK(!Target.IsOnStack());
            CHECK(Target.Length() == val1.length());
            CHECK(strcmp(Target, val1.c_str()) == 0);
        }

        SECTION("Catenate with constant expression") {

            constexpr String Target1 = "123456789012";

            constexpr String Target2 = Target1
                    .Catenate("x2")
                    .Catenate("|233")
                    .Catenate("123233456");

            CHECK(Target2 > Target1);
            CHECK(CompareString(Target2, "123456789012x2|233123") == 0);
        }

        SECTION("Move to heap") {
            String Val1 = "009";
            Val1.Catenate(random_string[0].c_str());

            std::string LongStr;

            for(int i = 0; i <= 4; ++i)
                LongStr += random_string[i];

            Val1.Catenate(LongStr.c_str());
            CHECK(Val1 != String(LongStr.c_str()));
        }
    }


    TEST_CASE("String::operator=(const char* value)", Tag) {

        String Target = "";

        Target = "0123456789012";
        CHECK(bool(Target.IsOnStack()) == true);
        CHECK(Target.Length() == sizeof("0123456789012") - 1);
        CHECK(CompareString(Target, "0123456789012") == 0);

        Target = "01234567890123-More on the heap";
        CHECK(bool(Target.IsOnStack()) == false);
        CHECK(Target.Length() == sizeof("01234567890123-More on the heap") - 1);
        CHECK(CompareString(Target, "01234567890123-More on the heap") == 0);
    }

}