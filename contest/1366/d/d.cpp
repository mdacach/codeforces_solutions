#include <bits/stdc++.h>

const int MAX = 1e7 + 10;
const int INF = 1e9;

std::vector<int> least_prime_factor(MAX, INF);

auto sieve() -> void
{
    for (int i = 2; i < MAX; i++)
    {
        if (least_prime_factor[i] != INF)
            continue;
        for (int j = i; j < MAX; j += i)
            least_prime_factor[j] = std::min(least_prime_factor[j], i);
    }
}

auto unique_factors(int n) -> std::set<int>
{
    std::set<int> factors;
    while (n > 1)
    {
        factors.insert(least_prime_factor[n]);
        n = n / least_prime_factor[n];
    }
    return factors;
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();

    int n;
    std::cin >> n;
    std::vector<int> ans1(n), ans2(n);
    for (int i = 0; i < n; i++)
    {
        int a; std::cin >> a;
        const auto f = unique_factors(a);
        if (f.size() == 1)
        {
            ans1[i] = -1;
            ans2[i] = -1;
        } else
        {
            int partial1 = 1, partial2 = 1;
            bool first = true;
            for (auto x : f)
            {
                if (first)
                {
                    partial1 = x;
                    first = false;
                } else
                {
                    partial2 *= x;
                }
            }
            ans1[i] = partial1;
            ans2[i] = partial2;
        }
    }
    for (auto x : ans1) std::cout << x << " ";
    std::cout << "\n";
    for (auto x : ans2) std::cout << x << " ";


    return 0;
}