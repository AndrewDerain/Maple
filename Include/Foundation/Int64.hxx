#pragma once

#include <BasicConfigs.hxx>
#include <_CXX/CXX.hxx>

#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_BEGIN
namespace Foundation
{

class Int64
{
    public:
        Int64() = default;

        Int64(Int64& arg) {
            _Storage = arg._Storage;
        }

        Int64(Int64&& arg) {
            _Storage = move(arg._Storage);
        }

        Int64(int64_t& value) {
            _Storage = value;
        }

        Int64(int64_t&& value){
            _Storage = move(value);
        }

        Int64(double& value) {

        }

    private:
        int64_t _Storage;
        __int128_t s;
        
    private:
        void _CtorDouble(double& value, bool round_off = false) {
            _Storage = static_cast<int64_t>(value);
        }
};

}
_FANTASIA_END
#pragma pack(pop)
#pragma warning(pop)
