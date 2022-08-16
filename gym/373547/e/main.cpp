#include <bits/stdc++.h>

#define int int64_t

auto solve() -> void
{
    int n;
    std::cin >> n;
    if (n == 1)
        std::cout << 1 << '\n';
    else if (n == 2)
        std::cout << 2 << '\n';
    else if (n == 3)
        std::cout << 6 << '\n';
    else
    {
        int ans = 1;
        int l = n - 5;
        int r = n;
        for (int a = l; a <= r; ++a)
        {
            for (int b = l; b <= r; ++b)
            {
                for (int c = l; c <= r; ++c)
                {
                    if (std::min({a, b, c}) <= 0) continue;
                    ans = std::max(ans, std::lcm(a, std::lcm(b, c)));
                }
            }
        }
        std::cout << ans << '\n';
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