
#include <type_traits>

namespace meta {
    template<typename T> struct size_of {
        using U = std::remove_cv_t<std::remove_reference_t<T>>;
        static_assert(!std::is_void<U>::value, "meta::size_of operator does not support void type.");
        static constexpr std::size_t value = sizeof(U);
    };

    template<typename T, std::size_t N>
    struct size_equals : std::integral_constant<bool, (size_of<T>::value == N)> {};

    template<typename T, std::size_t N> 
    constexpr bool size_equals_v = size_equals<T, N>::value;

    template<typename T>
    struct nested3 {
        using type = T;
    };

    template<typename T>
    struct nested2 {
        template<typename U>
        using type = nested3<U>;
    };

    template<typename V>
    struct nested {
        using type = nested2<V>;
    };
}