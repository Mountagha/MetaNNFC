
namespace meta {
    template<typename T> struct size_of {
        using U = std::remove_cv_t<std::remove_reference_t<T>>;
        static_assert(!std::is_void<U>, "meta::size_of operator does not support void type.");
        static constexpr std::size_t value = sizeof(U);
    };

    template<typename T, std::size_t N> 
    struct size_equals: std::bool_constant<(size_of<T>::value == N)> {};

    template<typename T, std::size_t N> 
    inline constexpr bool size_equals_v = size_equals_v<T, N>::value;

}