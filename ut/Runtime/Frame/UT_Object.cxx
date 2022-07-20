//
// Created by 宋豪杰 on 2022/7/13.
//
#include <catch2/catch_test_macros.hpp>
#include "Maple/Runtime/Internal/Algorithm/Sort.inl"
#include "Maple/Runtime/Foundation/Array.hxx"
#include "Maple/Runtime/Frame/Type.hxx"
#include "Maple/Runtime/Frame/Object.hxx"
#include <string>
#include <iostream>


using namespace _Maple;
using namespace _Maple::Algorithm;


namespace UnitTest::Frame::TestObject
{

    MapleDeco(TypeRegister)(Animal, Object)
    class Animal: virtual public Object
    {
    MapleObject(Animal)

    public:
        String Name;


        Animal() = default;


        virtual ~Animal() noexcept {};


        virtual String ToString() const noexcept {
            return String("This is animal ").Catenate(Name);
        };


        virtual Bool Equals(const Object *o) const noexcept{

            if(o->ObjectType() == this->ObjectType()) {
                return dynamic_cast<const Animal*>(o)->Name == Name;
            }
            else return false;
        };
    };

    template<bool value>
    struct Action {

    };


    template<>
    struct Action<false> {

        static int Invoke() {
            thread_local int m = 90;
            return m;
        }
    };


    template<>
    struct Action<true> {

        constexpr
        static int Invoke() {
             int m = 90;
            return m;
        }
    };


    class Oj{

        class Ob{

        };

        constexpr static Ob x{};
    };

    TEST_CASE("Animal", "[Frame][Object]")
    {

        constexpr auto m = Action<true>::Invoke();


        Animal cendy;

        cendy.Name = "cindy";

        Object* obj = &cendy;

        std::cout << obj->Equals(&cendy) << std::endl;
        std::cout << obj->ToString() << std::endl;
    }
}
