#include <bits/stdc++.h>

auto solve() -> void
{
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    int delta_x = std::abs(x1 - x2);
    int delta_y = std::abs(y1 - y2);
    std::cout << static_cast<int64_t>(delta_x) * delta_y + 1 << '\n';
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