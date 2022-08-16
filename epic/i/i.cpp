#include <bits/stdc++.h>

auto solve() -> void
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> divisors;
    for (int i = 1; 1LL * i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            divisors.push_back(n / i);
        }
    }
    std::sort(std::begin(divisors), std::end(divisors));
    divisors.erase(std::unique(std::begin(divisors), std::end(divisors)), std::end(divisors));

    std::cout << divisors[k - 1] << '\n';
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