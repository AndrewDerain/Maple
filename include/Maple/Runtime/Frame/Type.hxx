//
// Created by 宋豪杰 on 2022/7/11.
//

#pragma once
#include "../Internal/Frame/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Frame
{

    struct ITypeCollection;


    /// @brief 类型系统基类，所有的类型信息实现类均继承于此类
    struct Type
    {
        virtual Bool IsInheritedFrom(const Type& type) const = 0;


        virtual Bool Equals(const Type& type) const = 0;


        virtual const char* RawName() const = 0;


        virtual const ITypeCollection& Parents() const = 0;
    };


    /// @brief 类型集合
    struct ITypeCollection
    {
        virtual Int64 Count() const = 0;

        virtual Bool IsContains(Type* o) const = 0;
    };


    /// @brief 获取 Maple 数据类型的类型信息
    template<typename  _T>
    constexpr
    const auto& ___maple_typeof();


    /// @brief  获取 Maple 数据类型的类型信息
    ///         此宏使得 bitsof 的用法与 sizeof 相同。
    #define typeof(_OBJECT)  ___maple_typeof<_OBJECT>()


    /// @brief 用于判断某个对象是否有成员变量 ___TypeInfo
    template<typename T>
    struct ___maple_has_typeinfo;


    /// @brief 状态转移辅助类
    struct TypeCollectionTransfer
    {
    public:
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


    public:
        int         _Count       = 0;
        Type *      _Types[1024] = {nullptr};
        const char* _Names[1024] = {nullptr};
    };


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
        TypeCollection(Type* type);


        inline constexpr
        TypeCollection(Type* type, const char* name);


        /// @brief 获取集合中的元素数量
        inline constexpr
        Int64 Count() const override;


        inline constexpr
        Bool IsContains(Type* o) const override;


        void Print() const {

            std::cout << __FUNCTION__ << Count() << std::endl;

            for(int i = 0; i <= Count(); ++i) {
                std::cout << _Names[i] << "  [?=]  " << _Types[i]->RawName() << std::endl;
            }
        }

    public:
        friend struct TypeCollectionTransfer;
        Type*       _Types[_Transfer.Count() + 1] = {0};
        const char* _Names[_Transfer.Count() + 1] = {0};
    };



} // namespace _Maple::Frame
#pragma pack(pop)
#pragma warning(pop)


#include "../Internal/Frame/Type.inl"
