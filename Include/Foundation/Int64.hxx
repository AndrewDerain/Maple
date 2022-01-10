#pragma once

#include <BasicConfigs.hxx>
#include <_CXX/CXX.hxx>

#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_DETAIL_BEGIN
namespace Foundation {

}
_FANTASIA_DETAIL_END

_FANTASIA_BEGIN
namespace Foundation 
{

    struct Int64 
    {
    public: 
        Int64() = default;

        Int64(const int32_t& value);
        Int64(const int32_t&& value);

        Int64(const int64_t& value);
        Int64(const int64_t&& value);

        Int64(const Int64& arg);
        Int64(const Int64&& arg);

        Int64 operator+(const int32_t value);
        Int64 operator+(const Int64 arg);

        Int64 operator-(const Int64 arg);

        Int64 operator*(const Int64 arg);

        Int64 operator/(const Int64 arg);

        operator int64_t() ;

    private:
        int64_t _Storage;
    };


    inline Int64::Int64::Int64(const int32_t& value) {
        _Storage = value;
    }

    inline Int64::Int64(const int32_t&& value) {
        _Storage = move(value);
    }

    inline Int64::Int64(const int64_t& value) {
        _Storage = value;
    }

    inline Int64::Int64(const int64_t&& value){
        _Storage = move(value);
    }

    inline Int64::Int64(const Int64& arg) {
        _Storage = arg._Storage;
    }

    inline Int64::Int64(const Int64&& arg) {
        _Storage = move(arg._Storage);
    }

    inline Int64 Int64::operator+(const Int64 arg) {
        return _Storage + arg._Storage;
    }

    inline Int64 Int64::operator+(const int32_t value) {
        return _Storage + value;
    }

    inline Int64 Int64::operator-(const Int64 arg) {
        return _Storage - arg._Storage;
    }

    inline Int64 Int64::operator*(const Int64 arg) {
        return _Storage * arg._Storage;
    }

    inline Int64 Int64::operator/(const Int64 arg) {
        return _Storage / arg._Storage;
    }

    inline Int64::operator int64_t() {
        return _Storage;
    }
 
}
_FANTASIA_END
#pragma pack(pop)
#pragma warning(pop)
