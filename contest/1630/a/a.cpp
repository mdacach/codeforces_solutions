#include <bits/stdc++.h>

auto solve() -> void
{
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> pairs;
    if (k == n - 1)
    {
        if (n == 4)
        {
            std::cout << -1 << '\n';
            return;
        }
        pairs.emplace_back(n-1, n-2);
        pairs.emplace_back(n-3, 1);
        pairs.emplace_back(0, 2);
        for (int i = 3; i <= (n-1)/2; i++)
            pairs.emplace_back(i, (n - 1) - i);
        for (const auto& [x, y] : pairs)
            std::cout << x << "  " << y << '\n';
        return;
    }
    if (k == 0)
    {
        for (int i = 0; i <= (n - 1) / 2; i++)
            pairs.emplace_back(i, n - 1 - i);
        for (const auto& [x, y] : pairs)
            std::cout << x << "  " << y << '\n';
        return;
    }
    // k should be with (k - (n - 1))
    int previous_match = (n - 1) - k;
    pairs.emplace_back(k, n - 1);
    pairs.emplace_back(previous_match, 0);
    for (int i = 1; i <= (n - 1) / 2; i++)
    {
        if (i == k || i == previous_match)
            continue;
        pairs.emplace_back(i, n - 1 - i);
    }
    for (const auto& [x, y] : pairs)
        std::cout << x << "  " << y << '\n';
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