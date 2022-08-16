#include <bits/stdc++.h>

auto solve() -> void
{
    int a, b;
    std::cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        int until_here = i - a;
        if ((i | b) == b)
        {
            std::cout << until_here + 1 << '\n';
        }
    }
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;

    std::cout << ((1 << 0) & 3);
//    std::cin >> t;
//    while (t--)
//        solve();

    return 0;
}