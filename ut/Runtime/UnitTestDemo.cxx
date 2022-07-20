
#include <typeinfo>
#include <catch2/catch_test_macros.hpp>
#include "Maple/Runtime.hxx"
#include "Maple/Runtime/Internal/Algorithm/String.inl"

#include <array>


using namespace _Maple;
using namespace _Maple::Foundation;


namespace Exp
{

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


    struct MyBool : public Foundation::Bool
    {
        using Bool::Bool;
        using Bool::operator=;
    };


    struct Type
    {

    };


    struct TypeList
    {

    };


    TEST_CASE("Demo", "Demoxxx") {
        //std::cout << Object::ClassType().RawName() << std::endl;
    }


    template<typename _T>
    void signature() {
        std::cout << ___MAPLE_FUNCTION_SIGNATURE___ << std::endl;
    }
}
