//
// Created by 宋豪杰 on 2022/5/23.
//

#include <typeinfo>
#include <catch2/catch_test_macros.hpp>
#include "Maple/Foundation"
#include "Maple/Runtime/Internal/Algorithm/String.inl"


namespace Exp {

    using namespace _Maple;

    constexpr bool IsEqual(const char *lstr, const char *rstr) {
        for (int i = 0; lstr[i] != '\0' && rstr[i] != '\0'; i++)
            if (lstr[i] != rstr[i]) return false;
        return true;
    }


    template<typename _T, bool _False>
    struct no_partial_specialization {
        no_partial_specialization() {
            static_assert(_False, "no partial specialization for this type.");
        }
    };


    template<typename _T, typename _F>
    _T cast(_F &src) {
        no_partial_specialization<_F, false>();
        return _T();
    }


    template<>
    int64_t cast<int64_t, uint64_t>(uint64_t &src) {
        return src;
    }


    template<>
    char cast<char, uint64_t>(uint64_t &src) {
        //std::cout << __PRETTY_FUNCTION__ << std::endl;
        return src;
    }


    struct kk{
        EnumerationImplementation(kk,
                                  o,
                                  u,
                                  p);
    };


    TEST_CASE("Demo"){




        //std::cout << _Maple::Foundation::StringStackStorage::MaxIntegerValueOnStack() << std::endl;
        char str[56];
        //int64_t len = Algorithm::ConvertInt32ToString(-10, str);
        kk k1;
        k1 = k1.p;
        std::cout << k1.ToString() << std::endl;

        constexpr
        auto val = Foundation::Int64::Max().ToString();
        /*std::cout << val << std::endl;
        std::cout <<  Foundation::Int64::Min() << std::endl;
        std::cout <<  NumericLimits<double>::Max() << std::endl;
        std::cout << sizeof(Foundation::StringStackStorage) << "  |  " << sizeof(Foundation::StringHeapStorage) << std::endl;
        */
        //while(true){}
    }

}
