#include <bits/stdc++.h>

#define int int64_t

using Factors = std::map<int, int>;

const int N = 200'000 + 10;
std::vector<bool> is_prime(N, true);
std::vector<int> divisible_prime(N);
std::vector<int> all_primes;

auto prime_sieve(int n)
{
    is_prime[1] = false;
    for (int x = 2; x <= n; ++x)
    {
        if (!is_prime[x])
            continue;
        divisible_prime[x] = x;
        all_primes.push_back(x);
        for (int j = 2 * x; j <= n; j += x)
        {
            is_prime[j] = false;
            divisible_prime[j] = x;
        }
    }
}

std::map<int, int> prime_occurrences;
auto prime_factors(int n) -> Factors
{
    Factors factors;
    while (n > 1)
    {
        const auto d = divisible_prime[n];
        ++factors[d];
        ++prime_occurrences[d];
        n /= d;
    }
    return factors;
}

auto solve() -> void
{
    prime_sieve(N - 2);

    auto& d_primes = all_primes;
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;
    std::vector<Factors> all_factors;
    all_factors.reserve(std::size(a));
    for (const auto& x : a)
        all_factors.push_back(prime_factors(x));
    int gcd_answer = 1;
    for (const auto& p : all_primes)
    {
        if (prime_occurrences[p] <= n - 2)
            continue;
        std::vector<int> all_exponents;
        for (const auto& factors : all_factors)
        {
            if (factors.find(p) != std::end(factors))
                all_exponents.push_back(factors.at(p));
            else
                all_exponents.push_back(0);
        }
        std::nth_element(std::begin(all_exponents), std::begin(all_exponents) + 1, std::end(all_exponents));
        int times = all_exponents[1];
        for (int i = 0; i < times; i++)
            gcd_answer *= p;
    }
    std::cout << gcd_answer << '\n';
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