#include <bits/stdc++.h>

auto solve()
{
    int x, y;
    std::cin >> x >> y;
    int n;
    if (x > y)
        n = x + y;
    else
    {
        n = (x + y) / 2;
        while (n % 2 == 0 && n >= x) n /= 2;
        n *= 2;
    }
    std::cout << n << '\n';
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