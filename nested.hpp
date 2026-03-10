#include <type_traits>

namespace meta {
    
    // Level 3: final metafunction
    template<std::size_t A, std::size_t B, std::size_t C>
    struct Result_ {
        constexpr static std::size_t value = A + B + C;
    };

    // Level 2: returns another metafunction after receiving 
    template<std::size_t A, std::size_t B>
    struct Meta2_ {
        template<std::size_t C>
        using type = Result_<A, B, C>;
    };

    // Level 1: returns another metafunction after receiving A
    template<std::size_t A>
    struct Meta1_ {
        template<std::size_t B>
        using type = Meta2_<A, B>;
    };
}