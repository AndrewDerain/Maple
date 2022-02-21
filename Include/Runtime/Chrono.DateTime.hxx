#pragma once
#include "Chrono.Basic.hxx"
#include "Foundation.Bool.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
__FANTASIA_CHRONO_DETAIL_BEGIN
namespace DateTime
{
    const int MaxStringValueSize = 23;
};
__FANTASIA_CHRONO_DETAIL_END


__FANTASIA_CHRONO_BEGIN
struct Day
{
    
};

struct Month
{
    /* data */
};

struct Year
{
    std::int16_t _StoredValue;

    std::string ToString();
    std::u8string s;
    char8_t ss;
    // Decade
    // Century
};


struct Second
{
    /* data */
};


struct Minute
{
    /* data */
};


struct Hour
{
    /* data */
};




struct DateTime
{
public:
    DateTime() = default;
    ~DateTime() = default;

    Bool ConvertToString() { return true; };
    Bool ConvertToNumber() { return true; };

    template<size_t _SourceSize>
    void operator=(const char (&source)[_SourceSize]) {
        std::conditional<
            (_SourceSize <= _Fantasia::Chrono::DateTime::MaxStringValueSize),
            DateTime_Assign, 
            DateTime_CannotAssign<false>
        >::type::Assign(this, source);
    }

// "20210221 13:44:58"
// auto s = "2021-02-12T13:44:58"
protected:
    struct DateTime_Assign {
        inline static void Assign(DateTime* dest, const char* source) {
            dest->_Storage.IsString = true;

            strncpy(
                dest->_Storage.StringValue.StoredValue, 
                source,
                _Fantasia::Chrono::DateTime::MaxStringValueSize);
        }
    };

    template<bool T>
    struct DateTime_CannotAssign {
        static_assert(T, "DateTime can only be assigned from string whitch size is no more than 23.");
    };
    
    union {
        bool IsString;

        struct StringStore {
            bool IsString;
            char StoredValue[_Fantasia::Chrono::DateTime::MaxStringValueSize];
        } StringValue;
        
        struct NumberStore {
            bool IsString;
            std::uint16_t StoredValue[6];
        } NumberValue = {false, {0}};
        
    } _Storage;
};
__FANTASIA_CHRONO_END
#pragma pack(pop)
#pragma warning(pop)

constexpr auto Size_DateTime = sizeof(Fantasia::Chrono::DateTime);
