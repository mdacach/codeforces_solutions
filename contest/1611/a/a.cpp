#include <bits/stdc++.h>

auto solve()
{
    std::string s; std::cin >> s;

    auto is_even = [&](char c) {
        return (c - '0') % 2 == 0;
    };

    if (is_even(s.back()))
    {
        std::cout << 0 << '\n';
    } else if (is_even(s.front()))
    {
        std::cout << 1 << '\n';
    } else
    {
        bool has_even = false;
        for (auto c : s) has_even = has_even || is_even(c);
        if (has_even)
        {
            std::cout << 2 << '\n';
        } else
        {
            std::cout << -1 << '\n';
        }
    }
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) solve();


    return 0;
}