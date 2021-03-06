#pragma once


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)


namespace _Maple::Frame
{

    /// @brief 状态转移辅助类
    struct TypeCollectionTransfer
    {
    public:
        /// @brief 已经存储的类型信息数量
        int         _Count       = 0;


        /// @brief 类型信息集合
        Type *      _Types[1024] = {nullptr};


        /// @brief 类型原始名，在数组中的位置与 _Types 保持同步
        const char* _Names[1024] = {nullptr};


        constexpr
        TypeCollectionTransfer() = default;


        constexpr
        ~TypeCollectionTransfer() = default;


        constexpr
        TypeCollectionTransfer(const TypeCollectionTransfer& transfer) = default;


        constexpr
        TypeCollectionTransfer& operator=(const TypeCollectionTransfer&) = default;


        inline constexpr
        int Count() const;


        inline constexpr
        void Heapsort();


        inline constexpr
        void RemoveDuplicate();


    protected:
        inline constexpr
        bool Smaller(const char * lval, const char* rval);


        inline constexpr
        bool Larger(const char * lval, const char* rval);


        inline constexpr
        bool Equal(const char * lval, const char* rval);


        inline constexpr
        void PercDown(int i, int count);


        inline constexpr
        static int LeftChild(int i);
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

        for(; LeftChild(i) < count;) {

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


    /// @brief  编译时集合类型
    ///         _Key 元素会被排序，采用二分法对 _Key 进行查找
    /// @param _Key
    /// @param _Size 集合可容纳的最大元素数量
    template<TypeCollectionTransfer _Transfer>
    class TypeCollection: public ITypeCollection
    {
    public:
        inline constexpr
        TypeCollection();


        inline constexpr
        TypeCollection(Type* type, const char* name);


        inline constexpr
        Int64 Count() const override;


        inline constexpr
        Bool IsContains(const Type& type) const override;


        void Print() const override;


    protected:
        friend struct TypeCollectionTransfer;


        template<typename _T>
        friend struct ___maple_transfer_make;


        /// @brief 类型信息集合
        Type*       _Types[_Transfer.Count() + 1] = {0};


        /// @brief 类型原始名，在数组中的位置与 _Types 保持同步
        const char* _Names[_Transfer.Count() + 1] = {0};
    };


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
    Bool TypeCollection<_Transfer>::IsContains(const Type& type) const {
        // TODO
        return Bool();
    }


    template<TypeCollectionTransfer _Transfer>
    inline
    void TypeCollection<_Transfer>::Print() const {

        for(int i = 0; i <= Count(); ++i) {
            std::cout << _Names[i] << "  [?=]  " << _Types[i]->RawName() << std::endl;
        }
    }



    template<typename T>
    struct ___maple_has_typeinfo
    {
    protected:
        template<class type>
        constexpr
        static bool checker(decltype(type::___maple_typeinfo::instance)*) {
            return true;
        };


        template<typename type>
        constexpr
        static bool checker(type*) {
            return false;
        };


    public:
        static constexpr bool value = checker<T>(nullptr);
    };



    template<typename T>
    struct ___maple_typeof
    {
    protected:
        template<class type>
        constexpr
        static auto checker(decltype(type::___maple_typeinfo::instance)*) {
            return type::___maple_typeinfo::instance;
        };


        template<typename type>
        constexpr
        static void checker(type*) {
        };


    public:
        static constexpr auto instance() {
            return checker<T>(nullptr);
        }
    };



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



    /// @example raw: _Maple::Frame::___Maple_TypeInfo_Object::___Maple_TypeInfo_Object()
    inline constexpr
    int ___maple_extract_type_name(char* name, int capacity, const char * raw, int raw_len) {

        int name_len = 0;

        // namespace start end position
        int nspos = 0, nepos = 0;

        // type name start end position
        int tspos = 0, tepos = raw_len - 3;


        while(raw[tepos] != ':') --tepos;
        tepos -= 2;

        tspos = raw_len - (raw_len - tepos - 3) * 2 + 1;
        nepos = tspos == 0 ? -1 : tspos - 1;
        tspos = tspos + sizeof("___Maple_TypeInfo_") - 1;

        for(; nspos <= nepos && name_len < capacity; ++nspos, ++name_len)
            name[name_len] = raw[nspos];

        for(; tspos <= tepos && name_len < capacity; ++tspos, ++name_len)
            name[name_len] = raw[tspos];

        name[name_len] = '\0';

        return name_len;
    }



#define ___MAPLE_TYPE_SYSTEM_TYPEINFO_NAME_PREFIX                       \
            ___Maple_TypeInfo_                                          \



#define ___MAPLE_TYPE_SYSTEM_TYPEINFO_NAME(_T)                          \
            ___MAPLE_MF_CAT(                                            \
                ___MAPLE_TYPE_SYSTEM_TYPEINFO_NAME_PREFIX, _T)          \



#define ___MAPLE_TYPE_SYSTEM_TYPEINFO_INSTANCE_NAME(_T)                 \
            ___MAPLE_MF_CAT(                                            \
                ___MAPLE_TYPE_SYSTEM_TYPEINFO_NAME(_T), _Instance)      \



#define ___MAPLE_TYPE_SYSTEM_USING_TYPEINFO(_T)                         \
            template<typename T>                                        \
            friend struct _Maple::Frame::___maple_has_typeinfo;         \
                                                                        \
            template<typename T>                                        \
            friend struct _Maple::Frame::___maple_transfer_make;        \
                                                                        \
            template<typename T>                                        \
            friend struct _Maple::Frame::___maple_typeof;               \
                                                                        \
            using ___maple_typeinfo =                                   \
                ___MAPLE_TYPE_SYSTEM_TYPEINFO_NAME(_T);                 \



#define ___MAPLE_TYPE_SYSTEM_INTERFACE                                  \
            inline constexpr static                                     \
            const _Maple::Frame::Type&                                  \
            ClassType() noexcept {                                      \
                return ___maple_typeinfo::instance;                     \
            }                                                           \
                                                                        \
            virtual                                                     \
            const _Maple::Frame::Type&                                  \
            ObjectType() const noexcept {                               \
                return ___maple_typeinfo::instance;                     \
            }                                                           \



#define ___MAPLE_TYPE_SYSTEM_TYPE_INFO(_CLASS, _TYPE, _INSTANCE, ...)   \
    class _TYPE final: public _Maple::Frame::Type                       \
    {                                                                   \
    private:                                                            \
        friend class _CLASS;                                            \
                                                                        \
        template<typename T>                                            \
        friend struct _Maple::Frame::___maple_has_typeinfo;             \
                                                                        \
        template<typename T>                                            \
        friend struct _Maple::Frame::___maple_transfer_make;            \
                                                                        \
        template<typename T>                                            \
        friend struct _Maple::Frame::___maple_typeof;                   \
                                                                        \
        using ClassTypes = const                                        \
            _Maple::Frame::TypeCollection<                              \
                _Maple::Frame::___maple_make_transfer<                  \
                    __VA_ARGS__>()>;                                    \
                                                                        \
    public:                                                             \
        inline constexpr                                                \
        _TYPE() {                                                       \
             _Maple::Frame::___maple_extract_type_name(                 \
                _Name, 256,                                             \
                ___MAPLE_FUNCTION_SIGNATURE___,                         \
                sizeof(___MAPLE_FUNCTION_SIGNATURE___)                  \
             );                                                         \
        };                                                              \
                                                                        \
        inline constexpr virtual                                        \
        _Maple::Foundation::Bool                                        \
        Inherits(const _Maple::Frame::Type& type) const override {      \
            return _Types.IsContains(type);                             \
        };                                                              \
                                                                        \
        inline constexpr virtual                                        \
        _Maple::Foundation::Bool                                        \
        Equals(const _Maple::Frame::Type& type) const override{         \
            return false;                                               \
        };                                                              \
                                                                        \
        inline constexpr virtual                                        \
        ClassTypes&                                                     \
        Parents() const override {                                      \
            return _Types;                                              \
        }                                                               \
                                                                        \
        inline constexpr virtual                                        \
        const char*                                                     \
        RawName() const override {                                      \
            return _Name;                                               \
        }                                                               \
                                                                        \
        inline constexpr virtual                                        \
        bool                                                            \
        operator==(const _Maple::Frame::Type& type) const override {    \
            return RawName() == type.RawName();                         \
        }                                                               \
                                                                        \
    private:                                                            \
        static const _TYPE instance;                                    \
                                                                        \
        char        _Name[256]      { };                                \
        int         _NameLength     { };                                \
        ClassTypes  _Types          { this, _Name };                    \
    };                                                                  \
                                                                        \
    constexpr _TYPE _TYPE::instance {};                                 \



#define ___MAPLE_DECORATE_TypeRegister(_CLASS, ...)                     \
            ___MAPLE_TYPE_SYSTEM_TYPE_INFO(                             \
                _CLASS,                                                 \
                ___MAPLE_TYPE_SYSTEM_TYPEINFO_NAME(_CLASS),             \
                ___MAPLE_TYPE_SYSTEM_TYPEINFO_INSTANCE_NAME(_CLASS),    \
                __VA_ARGS__)                                            \

} // namespace _Maple::Frame
#pragma pack(pop)
#pragma warning(pop)
