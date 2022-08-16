#include <bits/stdc++.h>

auto solve() -> void
{
    int n, m;
    std::cin >> n >> m;

    int64_t big = 1LL * (n + m + 2) * (n + m + 1) * (n + m) / 6;
    int64_t small1 = 1LL * (n + 1) * (n) * (n - 1) / 6;
    int64_t small2 = 1LL * (m + 1) * (m) * (m - 1) / 6;
    int64_t answer = big;
    if (n > 2) answer -= small1;
    if (m > 2) answer -= small2;
    std::cout << answer << '\n';
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