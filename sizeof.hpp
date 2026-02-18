
namespace meta {
    template<typename T> struct size_of {
        constexpr static size_t value = sizeof(T);
    };

    template<typename T> struct size_of<const T>: size_of<T> {};
    template<typename T> struct size_of<T&>: size_of<T> {};

    template<> struct size_of<void> {
        static_assert("size_of operator does not support void type.");
    };
}