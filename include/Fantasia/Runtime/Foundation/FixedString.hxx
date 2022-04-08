#pragma once
#include "Fantasia/Runtime/_Detail/Foundation/Predeclars.hxx"


#pragma warning(push)
#pragma warning(disable: ___FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, ___FANTASIA_PACKING)
namespace _Fantasia::Foundation
{
    template<size_t _FixedSize>
    class FixedString;


    template<size_t _FixedSize>
    inline constexpr
    Bool operator==(
        const FixedString<_FixedSize>& _Left, 
        const char* const _Right);


    /// @brief 以 '\0' 字符结尾的固定长度字符串
    /// @param _FixedSize 字符串长度，包含 '\0' 字符
    template<size_t _FixedSize>
    class FixedString :
        public std::array<char, _FixedSize>
    {
    public:
        FixedString() = default;


        ~FixedString() = default;


        inline void Assign(const char* str = "") {
            strncpy(this->data(), str, _FixedSize);
            this->data()[_FixedSize - 1] = '\0'; 
        }


        template<size_t _SourceSize>
        inline void Assign(FixedString<_SourceSize>& source_str) {
            std::conditional <
                (_SourceSize <= _FixedSize),
                _FixedString_assign_from_smaller<_FixedSize, _SourceSize>,
                _FixedString_assign_from_larger<_FixedSize, _SourceSize>
            >::type::assign(this, source_str);
        }


        inline const char* c_str() {
            return this->data();
        }


        inline size_t Length() const {
            return strlen(this->data());
        }


        inline int Compare(const char* str) {
            return strcmp(this->data(), str);
        }


        inline FixedString<_FixedSize>& operator=(const char* str) {
            Assign(str);
            return *this;
        }


    private:
        template<size_t _dest_size, size_t _small_size>
        struct _FixedString_assign_from_smaller {
            inline static void assign(
                FixedString<_dest_size>* dest,
                FixedString<_small_size>& source) {
                strcpy(dest->data(), source.data());
            }
        };


        template<size_t _dest_size, size_t _larger_size>
        struct _FixedString_assign_from_larger {
            inline static void assign(
                FixedString<_dest_size>* dest,
                FixedString<_larger_size>& source) {

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
        friend Bool operator==(const FixedString<_Size>&, const char* const);


        bool _Equal(const char* const right) const {
            return strcmp(this->data(), right) == 0;
        }
    };


    template<size_t _FixedSize>
    inline constexpr
    Bool operator==(
        const FixedString<_FixedSize>& _Left, 
        const char* const _Right) {
            
        return (_Left._Equal(_Right));
    }

} // namespace _Fantasia::Foundation
#pragma pack(pop)
#pragma warning(pop)
