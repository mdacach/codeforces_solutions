#include <bits/stdc++.h>

auto smallest_equivalent(std::string_view s) -> std::string
{
    if (s.length() % 2 != 0)
        return std::string(s); // we can't split it anymore
    auto m = s.length() / 2;
    auto left = smallest_equivalent(s.substr(0, m));
    auto right = smallest_equivalent(s.substr(m, s.length()));
    return std::min(left + right, right + left);
}

auto solve() -> void
{
    std::string a, b;
    std::cin >> a >> b;

    const auto smallest_a = smallest_equivalent(a);
    const auto smallest_b = smallest_equivalent(b);
    std::cout << (smallest_a == smallest_b ? "YES\n": "NO\n");
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
//    std::cin >> t;
    while (t--)
        solve();

    return 0;
}