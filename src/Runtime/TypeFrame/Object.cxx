
#include "Maple/Runtime/Frame/Object.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Frame
{

#pragma region IObject
    constexpr const IObject::___MapleType IObject::___MapleType::TypeInfo;


    IObject::~IObject() noexcept {
    }


    String IObject::ToString() const {
        return "IObject";
    }


    Bool IObject::Equals(const IObject *o) const {
        return this == o;
    }


    const Type& IObject::ClassType() noexcept {
        return IObject::___MapleType::TypeInfo;
    }


    const Type& IObject::ObjectType() const noexcept {
        return IObject::___MapleType::TypeInfo;
    }
#pragma endregion


#pragma region Object
    class ___MapleType_Object: public Type
    {
    public:
        static const ___MapleType_Object TypeInfo;


        virtual Bool IsInheritedFrom(const Type &type) const {
            return true;
        };


        virtual Bool Equals(const Type &type) const {
            return true;
        };


        virtual const char* RawName() const {
            return _RawName();
        }


        virtual const set<const char*>& ParentRawNames() const {
            return _Parents;
        }


    private:
        static constexpr const char *_RawName() {
            return __PRETTY_FUNCTION__;
        }


        constexpr
        static const set<const char *> &&Register(
                set<const char *> &&types,
                initializer_list<const char *> &&lists,
                initializer_list<set<const char *>> &&parents) {

            for (auto &list: parents)
                types.insert(list.begin(), list.end());
            types.insert(lists);
            return std::forward<set<const char *> &&>(types);
        }


        inline static
        const set<const char *> _Parents{
                Register({_RawName()},
                         {IObject::ClassType().RawName()},
                         {IObject::ClassType().ParentRawNames()})
        };


        static constexpr std::array<int,7> nn {};
    };


    constexpr const ___MapleType_Object ___MapleType_Object::TypeInfo;


    Object::~Object() noexcept {
    }


    String Object::ToString() const noexcept {
        return "Object";
    }


    Bool Object::Equals(const IObject *o) const noexcept {
        return this == o;
    }


    const Type& Object::ClassType() noexcept {
        return ___MapleType_Object::TypeInfo;
    }


    const Type& Object::ObjectType() const noexcept {
        return ___MapleType_Object::TypeInfo;
    }
#pragma endregion

} // namespace _Maple::Frame
#pragma pack(pop)
#pragma warning(pop)



#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple
{
} // namespace _Maple
#pragma pack(pop)
#pragma warning(pop)
