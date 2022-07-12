#pragma once
#include "../Internal/Frame/Predeclars.hxx"
#include "Type.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Frame
{

    MapleDeco(Maple, ApiClass)
    Class IObject
    {
    public:
        virtual ~IObject() noexcept = 0;


        virtual String ToString() const = 0;


        virtual Bool Equals(const IObject *o) const = 0;


    //  Maple Type System Interfaces
    private:
        class ___MapleType: public Type
        {
        public:
            static const ___MapleType TypeInfo;


            virtual Bool IsInheritedFrom(const Type& type) const {
                return false;
            };


            virtual Bool Equals(const Type& type) const {
                return true;
            };


            virtual const char* RawName() const {
                return _RawName();
            }


            virtual const set<const char*>& ParentRawNames() const {
                return _Parents;
            }


        private:
            static constexpr const char* _RawName() {
                return __PRETTY_FUNCTION__;
            }


            static const set<const char*>&& Register(set<const char*>&& types, initializer_list<set<const char*>>&& lists) {
                for(auto& list: lists)
                    types.insert(list.begin(), list.end());
                return std::forward<set<const char*>&&>(types);
            }


            inline static
            const set<const char*> _Parents {
                    Register({},{})
            };
        };


        template<class _T>
        friend constexpr const auto& ___typeof();

    public:
        /// @brief 获取类的类型信息
        static const Type& ClassType() noexcept;


        /// @brief 获取实际对象的类型信息
        virtual const Type& ObjectType() const noexcept = 0;
    };



    MapleDeco(Maple, ApiClass)
    Class Object: public IObject
    {
    public:
        Object() = default;


        virtual ~Object() noexcept;


        virtual String ToString() const noexcept override;


        virtual Bool Equals(const IObject *o) const noexcept override;


    //  Maple Type System Interfaces
    public:
        static const Type& ClassType() noexcept;


        virtual const Type& ObjectType() const noexcept override;
    };



} // namespace _Maple::Frame
#pragma pack(pop)
#pragma warning(pop)
