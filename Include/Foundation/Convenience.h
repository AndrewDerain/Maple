#pragma once

template<typename T, typename ...Args>
T* mnew(Args... args) {
    return new T(args);
}
