
#include "Fantasia/Runtime/Foundation/Int64.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Foundation
{

    __decorate(Fantasia, api)
    String 
    Int64::ToString() const {
        String result;
        result = std::to_string(_StoredValue).c_str();
        return result;
    }

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)
