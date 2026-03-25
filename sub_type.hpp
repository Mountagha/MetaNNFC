#include <type_traits>

namespace meta {
template<typename... Ts>
struct make_void {
    typedef void type;
};

template<typename... Ts>
using void_t = typename make_void<Ts...>::type;

template<typename T, typename = void>
struct has_subtype {
    constexpr static bool value = false;
};

template<typename T>
struct has_subtype<T, void_t<typename T::type>> {
    constexpr static bool value = true;
};

}; // end of meta namespace.