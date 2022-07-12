#pragma once
#include "../Internal/Foundation/Predeclars.hxx"
#include "Enum.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
{

    using RawSymbolName = const char*;





    struct SymbolType
    {
        EnumerationImplementation(
                SymbolType,

                _Maple_Foundation_Bool,
                _Maple_Foundation_Int32,
                _Maple_Foundation_Int64,
                _Maple_Foundation_Double,
                _Maple_Foundation_String,

                _Maple_Foundation_IObject,
                _Maple_Foundation_Object,
                _Maple_Foundation_VisualObject
        );


        int64_t HashCode;


    protected:
        const char* _SymbolRawName;
    };


    class TypeCollection
    {
    public:
        Bool IsContain();



    private:
        void* _Storage;
    };


    class ___TypeInfo__HashCode
    {
    public:
        static set<SymbolType> Register(set<SymbolType> types, initializer_list<SymbolType> list) {
            types.insert(list);
            return types;
        }

        inline
        static const set<SymbolType> _Types {Register(set<SymbolType>(), {SymbolType::_Maple_Foundation_Bool}) };
    };

}
#pragma pack(pop)
#pragma warning(pop)


#define ___TypeRegister(_TYPE, ...)                                     \
            struct ___ ## _TYPE ## _ ## TypeInfo                        \
            {                                                           \
            public:                                                     \
            };

#include "../Internal/Foundation/Types.inl"