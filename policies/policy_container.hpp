#pragma once

namespace MetaNN
{
template<typename ...TPolices>
struct PolicyContainer;

template<typename T>
constexpr bool IsPolicyContainer = false;

template<typename...T>
constexpr bool IsPolicyContainer<PolicyContainer<T...>> = true;
} // namespace MetaNN  template<typename ...TPolices>