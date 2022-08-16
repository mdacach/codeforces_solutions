#include <bits/stdc++.h>

#define int int64_t

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> powers;
    for (int p = 1; p <= (int64_t) 1e18; p *= 2)
        powers.push_back(p);
    int l, r;
    std::cin >> l >> r;
    if (l == r)
    {
        std::cout << 0 << "\n";
        return 0;
    }
    while (true)
    {
        const auto next_power = std::prev(std::upper_bound(powers.begin(), powers.end(), r));
        if (*next_power > l)
        {
            // we can use next_power and next_power - 1
            std::cout << (*next_power xor (*next_power - 1)) << "\n";
            return 0;
        }
        else
        {
            l -= *next_power;
            r -= *next_power;
        }
    }
    assert(false);

    return 0;
}