
#include <Fantasia.Foundation.Integral.hxx>
#include <Fantasia.Basic.Template.Expander.hxx>

namespace UnitTest::Foundation::TestIntegral
{

    using namespace Fantasia::Foundation;


    template<typename _WrapTy, typename _BasalTy>
    struct MMMMMMM
    {
        MMMMMMM() = default;
        MMMMMMM(const _BasalTy m) {}

        void Out(_BasalTy v){
            std::cout << v << std::endl;
        }

        _WrapTy& operator=(const _WrapTy& another) {
            _Value = another._Value;
            return *this;
        }

        int64_t _Value;
    };


    struct wkk : virtual public
        Fantasia::Template::InheritanceChainExpander<wkk, MMMMMMM, std::string, char, int64_t>
    {
    };

    int RunAll() {
        
        int value;

        wkk wkk1;

        wkk1.Out(8);
        wkk1.Out('k');
        
        wkk1.print(89);

        wkk1._Value = 9;
        wkk1._Value = 67;
        
        return 0;
    }

}
