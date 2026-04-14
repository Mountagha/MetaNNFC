#include <type_traits>

namespace meta {

struct AccPolicy {

    struct AccuTypeCate {
        struct Add;
        struct Mul;
    };
    using Accu = AccuTypeCate::Add;

    struct isAveValueCate;
    static constexpr bool isAve = false;

    struct ValueTypeCate;
    using Value = float;
};
};