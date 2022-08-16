#include <bits/stdc++.h>

#define int int64_t

const int MAX = 5 * 1'000'000 + 10;

int divisible_prime[MAX];
int sum_exponents[MAX];
void precompute()
{
    // prime sieve
    {
        for (int x = 2; x < MAX; ++x)
        {
            if (divisible_prime[x])
                continue;
            for (int m = x; m < MAX; m += x)
                divisible_prime[m] = x;
        }
    }
    // factor in log n
    // too slow
    {
        auto Factors = [](int value)
        {
            std::map<int, int> factors;
            while (value > 1)
            {
                int d = divisible_prime[value];
                ++factors[d];
                value /= d;
            }
            return factors;
        };

        auto NumberOfExponents = [&Factors](int value)
        {
            const auto factors = Factors(value);
            int sum_exponents = 0;
            for (const auto& [factor, exponent] : factors)
                sum_exponents += exponent;
            return sum_exponents;
        };
    }

    auto NumberOfExponents = [](int value)
    {
        int exponents = 0;
        while (value > 1)
        {
            int d = divisible_prime[value];
            exponents++;
            value /= d;
        }
        return exponents;
    };

    // to go from x! to (x+1)!, we have all divisors from x! plus all divisors for (x+1) (not factorial)
    sum_exponents[1] = 0;
    auto& d = sum_exponents;
    for (int i = 2; i < MAX; ++i)
        sum_exponents[i] = sum_exponents[i - 1] + NumberOfExponents(i);
}

auto solve() -> void
{
    int a, b;
    std::cin >> a >> b;
    std::cout << sum_exponents[a] - sum_exponents[b] << '\n';
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    precompute();

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}