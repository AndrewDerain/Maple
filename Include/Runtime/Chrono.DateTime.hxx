#pragma once
#include "Chrono.Basic.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_CHRONO_DETAIL_BEGIN
namespace DateTime
{
    const int MaxStrValSize = 18;
};
_FANTASIA_CHRONO_DETAIL_END


_FANTASIA_CHRONO_BEGIN
struct DateTime
{
public:
    DateTime() = default;
    ~DateTime() = default;

    void ConvertToString() {};
    void ConvertToNumber() {};

    template<size_t _SourceSize>
    void operator=(const char (&source)[_SourceSize]) {
        std::conditional<
            (_SourceSize <= _Fantasia::Chrono::DateTime::MaxStrValSize),
            DateTime_Assign, 
            DateTime_CannotAssign
        >::type::Assign(this, source);
    }

// "20210221 13:44:58"
protected:
    struct DateTime_Assign {
        inline static void Assign(DateTime* dest, const char* source) {
            strcpy(dest->_Storage.StrVal, source);
        }
    };

    struct DateTime_CannotAssign {
    };
    
    union {
        char  StrVal[_Fantasia::Chrono::DateTime::MaxStrValSize];
        short NumVal[6];
    } _Storage = {0};
};
_FANTASIA_CHRONO_END
#pragma pack(pop)
#pragma warning(pop)
