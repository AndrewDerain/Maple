#pragma once
#include <Runtime/Foundation.String.hxx>
#include <Runtime/Foundation.Int64.hxx>


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_FOUNDATION_BEGIN
_FANTASIA_INLINE
Int64 String::MaxCapicity(){
    return std::numeric_limits<std::uint16_t>::max();    
}

_FANTASIA_INLINE
String::String(const char* value) {
    auto vallen = strlen(value);
    
    if(vallen < _Fantasia::String::StackMaxCapicity) {
        
    }
}

_FANTASIA_INLINE 
Int64
String::Length() {
    return 0;
}

_FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)
