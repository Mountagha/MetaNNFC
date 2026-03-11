#include <type_traits>

template<typename T, typename = void>
struct has_subtype {
    constexpr static bool value = false;
};

template<typename T>
struct has_subtype<T, std::void_t<typename T::type>> {
    constexpr static bool value = true;
};