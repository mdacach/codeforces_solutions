#include <bits/stdc++.h>

auto solve() -> void
{
    int a, b, c;
    std::cin >> a >> b >> c;
    int sum = a + c;
    int diff = std::abs(sum - 2*b);
    if (diff % 3 == 0) std::cout << 0 << '\n';
    else std::cout << 1 << '\n';
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) solve();

    return 0;
}