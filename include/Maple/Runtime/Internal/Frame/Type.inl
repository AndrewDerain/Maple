#pragma once


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)


namespace _Maple::Frame
{

    template<typename  _T>
    constexpr
    const auto& ___maple_typeof() {
        return  _T::___MapleType::TypeInfo;
    }


    template<typename T>
    struct ___maple_has_typeinfo {

        template<class type>
        constexpr
        static bool checker(decltype(type::___maple_typeinfo::instance)*){ return true; };


        template<typename type>
        constexpr
        static bool checker(type*){ return false; };


        static constexpr bool value = checker<T>(nullptr);
    };


    inline constexpr
    int TypeCollectionTransfer::Count() const {
        return _Count;
    }


    inline constexpr
    void TypeCollectionTransfer::Heapsort() {

        for(int i = _Count / 2; i >= 0; --i) {
            PercDown(i, _Count);
        }

        for(int i = _Count - 1; i > 0; --i) {

            auto type = _Types[0];
            _Types[0] = _Types[i];
            _Types[i] = type;

            auto name = _Names[0];
            _Names[0] = _Names[i];
            _Names[i] = name;

            PercDown(0, i);
        }
    }


    inline constexpr
    bool TypeCollectionTransfer::Smaller(const char * lval, const char* rval) {
        return Algorithm::CompareString(lval, rval) < 0;
    }


    inline constexpr
    bool TypeCollectionTransfer::Larger(const char * lval, const char* rval) {
        return Algorithm::CompareString(lval, rval) > 0;
    }


    inline constexpr
    bool TypeCollectionTransfer::Equal(const char * lval, const char* rval) {
        return Algorithm::CompareString(lval, rval) == 0;
    }


    inline constexpr
    void TypeCollectionTransfer::PercDown(int i, int count) {

        auto type = _Types[i];
        auto name = _Names[i];

        for(; LeftChild(i) < count; ) {

            int Child = LeftChild(i);

            if(Child != count - 1 && Larger(_Names[Child + 1], _Names[Child])) {
                ++Child;
            }

            if(Smaller(name, _Names[Child])) {
                _Types[i] = _Types[Child];
                _Names[i] = _Names[Child];
            }
            else break;

            i = Child;
        }

        _Types[i] = type;
        _Names[i] = name;
    }


    inline constexpr
    int TypeCollectionTransfer::LeftChild(int i) {
        return 2 * i + 1;
    }

    inline constexpr
    void TypeCollectionTransfer::RemoveDuplicate() {

        if (_Count <= 1) return;

        int w = 0, r = 0;

        for (; r < _Count; ++r) {
            if (!Equal(_Names[w], _Names[r])) {
                ++w;
                _Types[w] = _Types[r];
                _Names[w] = _Names[r];
            }
        }

        _Count = w + 1;
    }


    template<typename _T>
    struct ___maple_transfer_make {

        template<typename type>
        inline constexpr
        static std::enable_if_t<___maple_has_typeinfo<type>::value, void> Invoke(TypeCollectionTransfer& transfer) {

            for(int i = 0; i < type::___maple_typeinfo::instance._Types.Count() + 1; ++i, ++transfer._Count) {
                transfer._Types[transfer._Count] = type::___maple_typeinfo::instance._Types._Types[i];
                transfer._Names[transfer._Count] = type::___maple_typeinfo::instance._Types._Names[i];
            }
        }

        template<typename T>
        inline constexpr
        static std::enable_if_t<!___maple_has_typeinfo<T>::value, void> Invoke(TypeCollectionTransfer& transfer) {
        }
    };


    template<typename _Object, typename... _Objects>
    struct ___maple_transfer;


    template<typename _Object>
    struct ___maple_transfer<_Object>;


    template<typename _Object, typename... _Objects>
    struct ___maple_transfer {
        constexpr
        static void make(TypeCollectionTransfer& transfer) {
            ___maple_transfer_make<_Object>::template Invoke<_Object>(transfer);
            ___maple_transfer<_Objects...>::make(transfer);
        }
    };


    template<typename _Object>
    struct ___maple_transfer<_Object> {
        constexpr
        static void make(TypeCollectionTransfer& transfer) {
            ___maple_transfer_make<_Object>::template Invoke<_Object>(transfer);
        }
    };


    template<typename... _Objects>
    inline constexpr
    TypeCollectionTransfer ___maple_make_transfer() {
        TypeCollectionTransfer transfer;
        ___maple_transfer<_Objects..., void>::make(transfer);
        transfer.Heapsort();
        transfer.RemoveDuplicate();
        return transfer;
    }


    template<TypeCollectionTransfer _Transfer>
    inline constexpr
    TypeCollection<_Transfer>::TypeCollection() {

        for(int i = 0; i < _Transfer.Count(); ++i) {
            _Types[i] = _Transfer._Types[i];
            _Names[i] = _Transfer._Names[i];
        }
    }


    template<TypeCollectionTransfer _Transfer>
    inline constexpr
    TypeCollection<_Transfer>::TypeCollection(Type* type) {

        int i = 0;

        for(; i < _Transfer.Count(); ++i) {
            _Types[i] = _Transfer._Types[i];
            _Names[i] = _Transfer._Names[i];
        }

        _Types[i] = type;
    }


    template<TypeCollectionTransfer _Transfer>
    inline constexpr
    TypeCollection<_Transfer>::TypeCollection(Type* type, const char* name) {

        int i = 0;

        for(; i < _Transfer.Count(); ++i) {
            _Types[i] = _Transfer._Types[i];
            _Names[i] = _Transfer._Names[i];
        }

        _Types[i] = type;
        _Names[i] = name;
    }


    template<TypeCollectionTransfer _Transfer>
    inline constexpr
    Int64 TypeCollection<_Transfer>::Count() const {
        return _Transfer.Count();
    }


    template<TypeCollectionTransfer _Transfer>
    inline constexpr
    Bool TypeCollection<_Transfer>::IsContains(Type* o) const {
        return Bool();
    }


#define ___MAPLE_TYPE_SYSTEM_TYPEINFO_NAME(_T)                          \
            ___Maple_TypeInfo_ ## _T                                    \


#define ___MAPLE_TYPE_SYSTEM_TYPEINFO_INSTANCE_NAME(_T)                 \
            ____Maple_TypeInfo_ ## _T ## _Instance                      \


#define ___MAPLE_TYPE_SYSTEM_USING_TYPEINFO(_T)                         \
            template<typename T> friend struct ___maple_has_typeinfo;   \
            template<typename T> friend struct ___maple_transfer_make;  \
                                                                        \
            using ___maple_typeinfo =                                   \
                ___MAPLE_TYPE_SYSTEM_TYPEINFO_NAME(_T);                 \


#define ___MAPLE_TYPE_SYSTEM_QUERY_INTERFACE                            \
            inline constexpr static                                     \
            const ___maple_typeinfo& ClassType() noexcept {             \
                return ___maple_typeinfo::instance;                     \
            }                                                           \
                                                                        \
            virtual                                                     \
            const Type& ObjectType() const noexcept {                   \
                return ___maple_typeinfo::instance;                     \
            }                                                           \


#define ___MAPLE_TYPE_SYSTEM_TYPE_INFO(_TYPE, _INSTANCE, ...)           \
                                                                        \
    class _TYPE: public Type                                            \
    {                                                                   \
    public:                                                             \
        using _CollectionType =                                         \
            TypeCollection<___maple_make_transfer<__VA_ARGS__>()>;      \
                                                                        \
    public:                                                             \
        inline constexpr                                                \
        _TYPE() {                                                       \
             Algorithm::CopyString(                                     \
                _Name, 256,                                             \
                ___MAPLE_FUNCTION_SIGNATURE___,                         \
                sizeof(___MAPLE_FUNCTION_SIGNATURE___)                  \
             );                                                         \
        };                                                              \
                                                                        \
        inline constexpr                                                \
        virtual Bool IsInheritedFrom(const Type& type) const override { \
            return false;                                               \
        };                                                              \
                                                                        \
        inline constexpr                                                \
        virtual Bool Equals(const Type& type) const override{           \
            return false;                                               \
        };                                                              \
                                                                        \
        constexpr                                                       \
        virtual const _CollectionType& Parents() const override {       \
            return _Types;                                              \
        }                                                               \
                                                                        \
        inline constexpr                                                \
        virtual const char* RawName() const override {                  \
            return _Name;                                               \
        }                                                               \
                                                                        \
    public:                                                             \
        template<typename T>                                            \
        friend struct ___maple_transfer_make;                           \
                                                                        \
        char _Name[256] = {};                                               \
        _CollectionType _Types { this, _Name };                                \
                                                                        \
        static const _TYPE instance;                                    \
    };                                                                  \
                                                                        \
    constexpr _TYPE _TYPE::instance {};                                 \


#define ___MAPLE_DECORATE_TypeRegister(_T, ...)                         \
            ___MAPLE_TYPE_SYSTEM_TYPE_INFO(                             \
                ___MAPLE_TYPE_SYSTEM_TYPEINFO_NAME(_T),                 \
                ___MAPLE_TYPE_SYSTEM_TYPEINFO_INSTANCE_NAME(_T),        \
                __VA_ARGS__)                                            \



} // namespace _Maple::Frame
#pragma pack(pop)
#pragma warning(pop)
