#pragma once
#include "Foundation.Int64.decl.hxx"

#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_FOUNDATION_BEGIN

Int64::Int64(const Int64& other) noexcept :
    StoredValue(other.StoredValue) {
}

Int64::Int64(Int64&& other) noexcept :
    StoredValue(move(other)){
}

Int64::Int64(const int32_t& value) noexcept :
    StoredValue(value) {
}

Int64::Int64(int32_t&& value) noexcept:
    StoredValue(value) {
};

Int64::Int64(const int64_t& value) noexcept :
    StoredValue(value) {
}

Int64::Int64(int64_t&& value) noexcept :
    StoredValue(move(value)) {
}

Int64::operator int64_t&() {
    return StoredValue;
}

Int64& Int64::operator=(const Int64& other) {
    StoredValue = other.StoredValue;
    return *this;
}

Int64& Int64::operator=(Int64&& other) noexcept {
    StoredValue = other.StoredValue;
    return *this;
}

Int64 Int64::Max() {
    return numeric_limits<int64_t>::max();
};

Int64 Int64::Min() {
    return numeric_limits<int64_t>::min();
}
_FANTASIA_FOUNDATION_END
#pragma pack(pop)
#pragma warning(pop)
