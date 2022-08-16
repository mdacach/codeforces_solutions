#include <bits/stdc++.h>

auto solve() -> void
{
    int64_t a, b;
    std::cin >> a >> b;
    if (a == 0) std::cout << 1 << '\n';
    else
    {
        std::cout << a + 2 * b + 1 << '\n';
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