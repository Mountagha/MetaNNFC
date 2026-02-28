#include <iostream>
#include "conditional.hpp"
#include "sizeof.hpp"

int main() {
    meta::conditional_t<true, int, float> x = 3;
    meta::conditional_t<false, int, float> y = 1.0f;
    std::cout << x << " " << y << "\n";

    static_assert(meta::size_of<int>::value == sizeof(int));

    std::cout << meta::size_equals_v<int, 4> << "\n";
}