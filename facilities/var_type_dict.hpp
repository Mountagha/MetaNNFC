#include <type_traits>


namespace NSVarTypeDict {

struct NullParamter;

template<std::size_t N, template<typename...> class TCont, typename...T>
struct Create_ {
    using type = typename Create_<N - 1, TCont, NullParamter, T...>::type;
};

template<template<typename...> class TCont, typename...T>
struct Create_<0, TCont, T...> {
    using type = TCont<T...>;
};

template<typename...TParameters>
struct VarTypeDict {

    template<typename ... TTypes>
    struct Values {
    public:
        using Keys = VarTypeDict;

        template<typename TKey>
        using ValueType = Sequential::At<Values, Sequential::Order<VarTypeDict, TKey>>;

        template<typename TKey>
        constexpr static bool IsValueEmpty = std::is_same_v<ValueType<TKey>, NullParamter>;
        Values() = default;

        Values(std::shared_ptr<void>(&&input)[sizeof...(TTypes)])
        {
            for (std::size_t i = 0; i < sizeof...(TTypes); ++i) {
                m_tuples[i] = std::move(input[i]);
            }
        }
    public:
        template<typename TTag, typename TVal>
        auto Set(TVal&& val) && {
            using namespace NSMultiTypeDict;
            constexpr static std::size_t TagPos = Tag2ID<TTag, TParameters...>;

            using rawVal = std::decay_t<TVal>;
            rawVal* tmp = new rawVal(std::forward<TVal>(val));
            m_tuple[TagPos] = std::shared_ptr<void>(tmp,
                [](void* ptr) {
                    rawVal* nptr = static_cast<rawVal*>(ptr);
                    delete nptr;
                });

            using new_type = NewTupleType<rawVal, TagPos, Values<>, TTypes...>;
            return new_type(std::move(m_tuple));
        }

        template<typename TTag>
        const auto& Get() const;
    private:
        std::shared_ptr<void> m_tuple[sizeof...(TTypes)];
    };
public:
    static auto Create() {
        using namespace NSVarTypeDict;
        using type = typename Create_<sizeof...(TParameters), Values>::type;
        return type{};
    }
};

} // namespace.