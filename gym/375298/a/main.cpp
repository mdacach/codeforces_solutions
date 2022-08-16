#include <bits/stdc++.h>

std::vector<uint32_t> even_powers;

void compute_even_powers()
{
    int i = 4;
    while (i <= 1e9)
    {
        even_powers.push_back(i);
        i *= 4;
    }
}

auto solve() -> void
{
    uint32_t n;
    std::cin >> n;
    for (const auto& x : even_powers)
    {
        if (x == n)
        {
            std::cout << "Alice\n";
            return;
        }
        if (x > n)
            break;
    }
    if (__builtin_popcount(n) == 1)
        std::cout << "Bob\n";
    else if (n % 2 == 0)
        std::cout << "Alice\n";
    else
        std::cout << "Bob\n";
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    compute_even_powers();

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}