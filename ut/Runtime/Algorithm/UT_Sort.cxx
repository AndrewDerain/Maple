//
// Created by 宋豪杰 on 2022/7/13.
//
#include <catch2/catch_test_macros.hpp>
#include "Maple/Runtime/Internal/Algorithm/Sort.inl"
#include "Maple/Runtime/Foundation/Array.hxx"
#include <string>
#include <iostream>


using namespace _Maple;
using namespace _Maple::Algorithm;


namespace UnitTest::Algorithm
{

    struct Tag
    {

    public:
        inline constexpr
        Tag() {
            Heapsort::Sort(arr, 3);
        }

        int arr[65] = {8,9,};
    };


    namespace Demo
    {

        template<typename _Ty>
        struct TempCollection
        {

            constexpr
            TempCollection(){
            }


            template<typename type, class... list>
            constexpr
            TempCollection(type&& arg, list&&... args):
                    TempCollection(args...) {
                Arr[_Count] = arg;
                ++_Count;
            }


//            template<typename list, typename... lists>
//            constexpr
//            TempCollection(list&& arg, lists&&... args):
//                    TempCollection(args...) {
//
//                for(auto iter = arg.begin(); iter != arg.end(); ++iter){
//                    Arr[_Count] = *iter;
//                    ++_Count;
//                }
//            }


            constexpr
            int Count() const {
                return _Count;
            }


            int _Count = 0;
            _Ty Arr[1024] = {};
        };


        template<typename _Ty, TempCollection _Coll>
        struct Collection
        {

            inline constexpr
            Collection() {
                for(int i = 0; i < _Coll.Count(); ++i) {
                    Arr[i] = _Coll.Arr[i];
                }
            }

            _Ty Arr[_Coll.Count()];
        };


        TEST_CASE("Demo2") {

            constexpr Collection<int, TempCollection<int>{3,4,5,6,7,8}> x;
            //constexpr Collection<int,TempCollection<int>{ std::array<int,5>{}, std::array<int, 8>{}}> x2;
            //std::cout << x.
        }
    }


    TEST_CASE("Heapsort bbbb", "[Algorithm][Sort][nnn]")
    {

        const double g = 9;
        const double *g1 = &g;
        const double *g2 = &g;

        //constexpr bool larger = g1 == g2;

        constexpr Tag x;

        for(const auto i : x.arr) {
            std::cout << i << "   " ;
        }

        std::cout << std::endl;

        int x2 = 78;
        //CHECK(x2==2);
    }

}
