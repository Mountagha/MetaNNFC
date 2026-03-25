#include <iostream>
#include "conditional.hpp"
#include "sizeof.hpp"
#include "nested.hpp"
#include "sub_type.hpp"

int main() {
    meta::conditional_t<true, int, float> x = 3;
    meta::conditional_t<false, int, float> y = 1.0f;
    std::cout << x << " " << y << "\n";

    static_assert(meta::size_of<int>::value == sizeof(int));

    std::cout << meta::size_equals_v<int, 4> << "\n";


    // nested.
    using s1 = meta::Meta1_<2>;
    using s2 = s1::type<3>;
    using s3 = s2::type<4>;

    static_assert(s3::value == 9, "wrong result");

    // Direct chained use:
    static_assert(meta::Meta1_<2>::type<3>::type<4>::value == 9, "wrong result.");

    // has subtype
    struct A {
        using type = int;
    };
    struct B {

    };
    static_assert(meta::has_subtype<A>::value, "A should have subtype");
    static_assert(!meta::has_subtype<B>::value, "B should not have subtype.");

    return 0;
}