#include <bits/stdc++.h>

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    auto check_odd = [&](int m)
    {
        int picked = 0;
        for (auto x : a)
        {
            if (x <= m || picked % 2)
            {
                picked++;
            }
        }
        return picked >= k;
    };

    auto check_even = [&](int m)
    {
        int picked = 0;
        for (auto x : a)
        {
            if (x <= m || picked % 2 == 0)
            {
                picked++;
            }
        }
        return picked >= k;
    };

    auto check = [&](int m) { return (check_even(m) || check_odd(m)); };

    int l = 0;
    int r = 1e9;
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (check(m)) r = m;
        else l = m;
    }

    std::cout << r << "\n";

    return 0;
}