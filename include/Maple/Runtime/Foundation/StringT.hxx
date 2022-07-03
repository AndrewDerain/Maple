#pragma once
#include "../Internal/Foundation/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___MAPLE_WARNING_DISABLE_IDS)
#pragma pack(push, ___MAPLE_PACKING)
namespace _Maple::Foundation
{

    template<size_t _FixedSize>
    inline constexpr
    Bool operator==(
        const StringT<_FixedSize>& _Left,
        const char* const _Right);


    /// @brief 以 '\0' 字符结尾的固定长度字符串
    /// @param _FixedSize 字符串长度，包含 '\0' 字符
    template<size_t _FixedSize>
    class StringT :
        public std::array<char, _FixedSize>
    {
    public:
        StringT() = default;


        ~StringT() = default;


        inline constexpr
        void Assign(const char* str = "");


        template<size_t _SourceSize>
        inline 
        void Assign(StringT<_SourceSize>& source_str);


        inline constexpr
        const char* c_str();


        inline constexpr
        size_t Length() const;


        inline constexpr
        int Compare(const char* str);


        inline constexpr
        StringT<_FixedSize>& operator=(const char* str);


    private:
        template<size_t _dest_size, size_t _small_size>
        struct _FixedString_assign_from_smaller {
            inline static void assign(
                    StringT<_dest_size>* dest,
                    StringT<_small_size>& source) {
                strcpy(dest->data(), source.data());
            }
        };


        template<size_t _dest_size, size_t _larger_size>
        struct _FixedString_assign_from_larger {
            inline static void assign(
                    StringT<_dest_size>* dest,
                    StringT<_larger_size>& source) {

                size_t source_len = strnlen(source.c_str(), _larger_size) + 1;

                if (source_len <= _dest_size) {
                    memcpy(dest->_Elems, source.data(), source_len);
                }
                else {
                    memcpy(dest->data(), source.data(), _dest_size);
                    dest->_Elems[_dest_size - 1] = '\0';
                }
            }
        };


        template<size_t _Size>
        inline constexpr
        friend Bool operator==(const StringT<_Size>&, const char* const);


        inline
        bool _Equal(const char* const right) const;
    };

} // namespace _Maple::Foundation
#pragma pack(pop)
#pragma warning(pop)

#include "../Internal/Foundation/StringT.inl"
