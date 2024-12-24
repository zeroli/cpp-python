#pragma once

namespace cpy {
namespace detail {
struct empty {};

/// singleton class derives from B and generate sub-class D
/**
 *        B
 *        ^
 *        |
 * singleton<D, B>
 *        ^
 *        |
 *        D
 *
 */
template <typename D, typename B = empty>
struct singleton : B
{
    using singleton_base = singleton;

    // the singleton instance
    static D* instance() {
        static D d;
        return &d;
    }

    template <typename... Args>
    singleton(Args&&... args)
        : B(std::forward<Args>(args)...)
    {
    }
};
}  // namespace detail
}  // namespace cpy
