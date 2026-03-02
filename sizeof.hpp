
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

}