#include <bits/stdc++.h>

#define int int64_t

auto solve() -> void
{
    uint32_t n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    if (n == 1)
    {
        std::cout << 1 << ' ' << n << '\n';
        std::cout << 0 << '\n';
        std::cout << 1 << ' ' << n << '\n';
        std::cout << 0 << '\n';
        std::cout << 1 << ' ' << n << '\n';
        std::cout << -1 * a.front() << '\n';
        return;
    }

    // first operation
    {
        std::cout << 1 << ' ' << n << '\n';
        std::cout << 0 << ' ';
        for (uint32_t i = 1; i < n; ++i)
            std::cout << -1 * int(n) * a[i] << ' ';
        std::cout << '\n';
    }
    {
        std::cout << 2 << ' ' << n << '\n';
        for (uint32_t i = 1; i < n; ++i)
        {
            std::cout << a[i] * int(n - 1) << ' ';
        }
        std::cout << '\n';
    }
    {
        std::cout << 1 << " " << 1 << '\n';
        std::cout << -1 * a.front() << '\n';
    }
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