
#include <typeinfo>
#include <catch2/catch_test_macros.hpp>
#include "Maple/Runtime.hxx"
#include "Maple/Runtime/Internal/Algorithm/String.inl"


namespace Exp {

    using namespace _Maple;
    using namespace _Maple::Foundation;


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





    class Something
    {
    public:
        class ___TypeInfo__
        {
        public:
//            static set<SymbolType> Register(set<SymbolType> types, initializer_list<SymbolType> list) {
//                types.insert(list);
//                return types;
//            }
//
//            inline
//            static const set<SymbolType> _Types {Register(set<SymbolType>(), {SymbolType::_Maple_Foundation_Bool}) };


            static set<const char*> Register(set<const char*> types, initializer_list<set<const char*>> lists) {
                for(auto& list: lists)
                    types.insert(list.begin(), list.end());
                return types;
            }


            static constexpr const char* _RawName() {
                return __PRETTY_FUNCTION__;
            }


            inline
            static const set<const char*> _Parents {
                Register(
                    {_RawName()},
                    {{""},{""},{""}}
                )
            };

        };

        constexpr static const char* FuncName() {

            struct _t {
                inline static void func() { }
            };

            return &__PRETTY_FUNCTION__[19];
        }
    };



    #define MyType(_T) ___MAPLE_MF_CAT(_T , ___MAPLE_MF_ARG(typeid(_T).hash_code()))




    TEST_CASE("Demo") {

        MyBool flag(true);
        flag = true;
        flag = MyBool(true);

        //Foundation::Object b;
        //MyType(Bool);

        //MyObj obj;

        MyBool x1;
        x1 = flag;

        constexpr auto& t = typeof(Object);


        std::cout << IObject::ClassType().Equals(IObject::ClassType()) << std::endl;
        std::cout << sizeof(std::function<void(int, int)>) << std::endl;

       // std::cout << (*__IObject_TypeInfo::_Types.begin()).ToString() << std::endl;
    }

}
