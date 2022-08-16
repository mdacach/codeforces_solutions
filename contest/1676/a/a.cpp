#include <bits/stdc++.h>

auto solve() -> void
{
    std::string s;
    std::cin >> s;

    int sum1 = (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
    int sum2 = (s[3] - '0') + (s[4] - '0') + (s[5] - '0');

    std::cout << ((sum1 == sum2) ? "YES" : "NO") << '\n';
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