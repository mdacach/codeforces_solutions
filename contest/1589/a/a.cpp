#include <bits/stdc++.h>

auto solve() -> void
{
    int u, v;
    std::cin >> u >> v;
    std::cout << -(1LL * u * u) << " " << 1LL * v * v << '\n';
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