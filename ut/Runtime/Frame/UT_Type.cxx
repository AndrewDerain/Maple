//
// Created by 宋豪杰 on 2022/7/13.
//
#include <catch2/catch_test_macros.hpp>
#include "Maple/Runtime/Internal/Algorithm/Sort.inl"
#include "Maple/Runtime/Foundation/Array.hxx"
#include "Maple/Runtime/Frame/Type.hxx"
#include "Maple/Runtime/Frame/Object.hxx"
#include <iostream>


//
using namespace _Maple::Algorithm;

//using _Maple::Object;
using _Maple::Foundation::Bool;
using _Maple::String;

MapleDeco(TypeRegister)(X, _Maple::Object)
MapleDeco(Maple, Runtime, ApiClass)
Class X : virtual public _Maple::Object
{
MapleObject(X)

public:
    X() = default;

    virtual ~X() noexcept{};


    virtual String ToString() const noexcept{return "";};


    virtual Bool Equals(const Object *o) const noexcept{return false;};
};


namespace UnitTest::Frame::TestType
{
    using namespace _Maple;


    MapleDeco(TypeRegister)(Object2, X, Object)
    class Object2: virtual public X, virtual public Object
    {
        MapleObject(Object2)


        virtual ~Object2() noexcept {}


        virtual String ToString() const noexcept { return ""; }


        virtual Bool Equals(const Object *o) const noexcept { return false; }
    };


    TEST_CASE("RemoveDu","")
    {
        const char* _Names[] = {"a", "a", "b", };
        int _Count = 3;

        int w = 0, r = 0;

        for (; r < _Count; ++r) {
            std::cout << "[" << _Names[w] << "][" << _Names[r] << "] "
            << Algorithm::CompareString(_Names[w], _Names[r]) << std::endl;
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

        char name[256]; int len;
        _Maple::Frame::___maple_extract_type_name(
                name, 256,
                "_Maple::Frame::___Maple_TypeInfo_Object::___Maple_TypeInfo_Object()",
                sizeof("_Maple::Frame::___Maple_TypeInfo_Object::___Maple_TypeInfo_Object()")
                );

        std::cout << name << std::endl;


        _Maple::Frame::___maple_extract_type_name(
                name, 256,
                "___Maple_TypeInfo_Object::___Maple_TypeInfo_Object()",
                sizeof("___Maple_TypeInfo_Object::___Maple_TypeInfo_Object()")
        );

        //constexpr auto x1 = typeof(X)._RawName();
        //constexpr TypeName<___maple_make_typename_transfer(___Maple_TypeInfo_X::_RawName())> x;

        std::cout << name << std::endl;


        constexpr auto count = typeof(Object);

        std::cout << typeof(Object).RawName() << std::endl;

        constexpr auto count2 = X::ClassType().RawName();
        std::cout << count2 << std::endl;

        std::cout << Object2::ClassType().RawName() << std::endl;
        std::cout << Object2::ClassType().Parents().Count() << std::endl;
        Object2::ClassType().Parents().Print();

        std::cout << "-----------" << std::endl;
        std::cout << (___maple_has_typeinfo<_Maple::Frame::Object>::value) << std::endl;
        std::cout << (___maple_has_typeinfo<Object>::value) << std::endl;
        std::cout << ___maple_has_typeinfo<X>::value << std::endl;
        std::cout << ___maple_has_typeinfo<int>::value << std::endl;
        std::cout << (___maple_has_typeinfo<_Maple::Frame::Object>::value) << std::endl;
    }

}
