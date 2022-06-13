//
// Created by 宋豪杰 on 2022/5/23.
//

#include <typeinfo>
#include <catch2/catch_test_macros.hpp>
#include "Fantasia/Foundation"
#include "Fantasia/Runtime/Internal/Algorithm/String.inl"


namespace Exp {

    using namespace _Fantasia;

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

    struct EnumTest
    {
        enum EnumUnifyTypeName {
            One,
            Two
        };

        EnumBasicActions(EnumTest, One, Two);
    };




    TEST_CASE("Demo"){
        //std::cout << _Fantasia::Foundation::StringStackStorage::MaxIntegerValueOnStack() << std::endl;
        char str[56];
        int64_t len = Algorithm::ConvertInt32ToString(-10, str);

        //std::cout << len << std::endl;
        //std::cout << str << std::endl;
    }

}


