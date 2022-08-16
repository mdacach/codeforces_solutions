#include <bits/stdc++.h>

auto solve()
{
    int a, b;
    std::cin >> a >> b;
    if (a < b) std::swap(a, b);
    int ans = 0;
    int diff = a - b;
    int teams = diff / 2;
    teams = std::min(teams, b);
    a -= teams * 3;
    b -= teams;
    teams += std::min(a, b) / 2;
    std::cout << teams << '\n';
//    if ((diff / 3) <= b)
//    {
//        int teams = (diff / 3);
//        a -= teams * 3;
//        b -= teams;
//        ans = teams + (b / 2);
//    } else
//    {
//        int teams = b;
//        ans = teams;
//    }
//    std::cout << ans << '\n';
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) solve();

    return 0;
}