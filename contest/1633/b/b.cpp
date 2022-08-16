#include <bits/stdc++.h>

auto solve() -> void
{
    std::string s;
    std::cin >> s;
    const auto ones = std::count(std::begin(s), std::end(s), '1');
    const auto zeros = s.size() - ones;
    if (ones == zeros)
    {
        std::cout << ones - 1 << '\n';
    }
    else
    {
        std::cout << std::min<int>(ones, zeros) << '\n';
    }
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}