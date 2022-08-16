#include <bits/stdc++.h>

auto all_divisors(int n) -> std::set<int>
{
    std::set<int> divisors{ 1, n };
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }
    return divisors;
}
auto solve() -> void
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    std::map<int, int> bit_count;
    for (const auto& x : a)
    {
        for (int b = 0; b < 31; b++)
        {
            if ((x >> b & 1) == 1)
                ++bit_count[b];
        }
    }

    int gcd = 0;
    for (const auto& [bit, count] : bit_count)
        gcd = std::gcd(gcd, count);

    if (gcd == 0)
    {
        for (int i = 1; i <= n; ++i)
            std::cout << i << " ";
        std::cout << '\n';
    }
    else
    {
        for (const auto d : all_divisors(gcd))
            std::cout << d << " ";
        std::cout << '\n';
    }
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