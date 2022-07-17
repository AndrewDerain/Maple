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


namespace UnitTest::Frame
{

    MapleDeco(TypeRegister)(Object)
    class Object
    {
    MapleObject(Object)

    public:
        Object() = default;


        virtual ~Object() noexcept{};


        virtual String ToString() const noexcept{return "";};


        virtual Bool Equals(const Object *o) const noexcept{return false;};
    };


    MapleDeco(TypeRegister)(X, Object)
    MapleDeco(Maple, Runtime, ApiClass)
    Class X: virtual public Object
    {
    MapleObject(X)

    public:
        X() = default;

        virtual ~X() noexcept{};


        virtual String ToString() const noexcept{return "";};


        virtual Bool Equals(const Object *o) const noexcept{return false;};
    };


    MapleDeco(TypeRegister)(Object2, X, Object)
    class Object2: virtual public X, virtual public Object {

        MapleObject(Object2)


        virtual ~Object2() noexcept{};


        virtual String ToString() const noexcept{return "";};


        virtual Bool Equals(const Object *o) const noexcept{return false;};
    };


    //constexpr ___Maple_TypeInfo_X ___Maple_TypeInfo_X::instance {};
//
//    template<typename T>
//    struct ___maple_has_typeinfo {
//
//        template<class type>
//        constexpr
//        static bool checker(decltype(type::___TypeInfo)*){ return true;};
//
//
//        template<typename type>
//        constexpr
//        static bool checker(type*){ return false; };
//
//
//        static constexpr bool value = checker<T>(nullptr);
//    };


    TEST_CASE("RemoveDu",""){
        const char* _Names[] = {"a", "a", "b", };
        int _Count = 3;

        int w = 0, r = 0;

        for (; r < _Count; ++r) {
            std::cout << "[" << _Names[w] << "][" << _Names[r] << "] " << Algorithm::CompareString(_Names[w], _Names[r]) << std::endl;
            if (Algorithm::CompareString(_Names[w], _Names[r]) != 0) {
                ++w;
                //_Types[w] = _Types[r];
                _Names[w] = _Names[r];
            }
        }

        _Count = w;

        std::cout << _Count << std::endl;

        for(auto i: _Names) std::cout << i;
        std::cout << std::endl;
    }

    
    TEST_CASE("TypeCollection", "[Frame][TypeCollection]")
    {
        std::cout << Object2::ClassType()._Name << std::endl;

        constexpr auto count = Object::ClassType().Parents().Count();
        std::cout << count << std::endl;
        std::cout << Object::ClassType().RawName() << std::endl;


        constexpr auto count2 = X::ClassType().RawName();
        std::cout << count2 << std::endl;

        std::cout << Object2::ClassType().Parents().Count() << std::endl;

        Object2::ClassType().Parents().Print();
        //using t = decltype(Object::___TypeInfo);

        std::cout << "-----------" << std::endl;
        std::cout << (___maple_has_typeinfo<_Maple::Frame::Object>::value) << std::endl;
        std::cout << (___maple_has_typeinfo<Object>::value) << std::endl;
        std::cout << ___maple_has_typeinfo<X>::value << std::endl;
        //std::cout << ___maple_has_typeinfo<X4>::value << std::endl;
        std::cout << ___maple_has_typeinfo<int>::value << std::endl;
        std::cout << (___maple_has_typeinfo<_Maple::Frame::Object>::value) << std::endl;


    }

}
