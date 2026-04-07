#include <type_traits>

namespace meta {

    template<bool cur, typename TNext>
    constexpr static bool AndValue = false;

    template<typename TNext>
    constexpr static bool AndValue<true, TNext> = TNext::value;

    template<std::size_t... Ns>
    struct allOnes;

    template<>
    struct allOnes<> {
        constexpr static bool value = true;
    };

    template<std::size_t N>
    struct allOnes<N> {
        constexpr static bool value = (N == 1);
    };

    template<std::size_t N, std::size_t... Ns>
    struct allOnes<N, Ns...> {
        constexpr static bool is_first_one = allOnes<N>::value;
        constexpr static bool value = AndValue<
                                    is_first_one, allOnes<Ns...>>;
    };
};