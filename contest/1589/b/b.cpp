#include <bits/stdc++.h>

auto solve() -> void
{
    int n, m;
    std::cin >> n >> m;
    if (n == 1 || m == 1)
    {
        if (n < m)
            std::swap(n, m);
        std::cout << n / 3 + (n % 3 == 0 ? 0 : 1) << '\n';
        return;
    }
    // cut into stripes
    // vertically
    const auto ans1 = [&]
    {
        int vertically = n / 3;
        int leftover = (n % 3) * ((m / 3) + (m % 3 != 0));
        return m * vertically + leftover;
    }();

    // horizontally
    const auto ans2 = [&]
    {
        int horizontally = m / 3;
        int leftover = (m % 3) * ((n / 3) + (n % 3 != 0));
        return n * horizontally + leftover;
    }();
    std::cout << std::min(ans1, ans2) << '\n';
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