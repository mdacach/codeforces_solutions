#include <bits/stdc++.h>

#define int int64_t
const int MOD = 1e9 + 7;
const int N = 1010;
int fact[N];

long long inv(long long a, long long b = MOD)
{
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

int mul(int a, int b)
{
    return (a * b) % MOD;
}

auto number_of_ways(const std::map<char, int>& freq) -> int
{
    int total_freq = 0;
    for (auto [c, f] : freq)
        total_freq += f;

    std::vector<int> repeated;
    for (auto [c, f] : freq)
    {
        assert(f % 2 == 0);
        repeated.push_back(f / 2);
    }
    assert(total_freq % 2 == 0);
    int to_choose = total_freq / 2;
    // factorial / repeated...
    int answer = fact[to_choose];
    for (auto x : repeated)
        answer = mul(answer, inv(fact[x]));
    return answer;
}

auto solve() -> void
{
    std::string s;
    std::cin >> s;

    int odd_freqs = 0;
    std::map<char, int> freq;
    for (auto c : s)
        ++freq[c];

    for (auto [c, f] : freq)
        if (f % 2)
            ++odd_freqs;

    if (odd_freqs > 1)
    {
        std::cout << 0 << '\n';
    }
    else if (odd_freqs == 1)
    {
        char middle;
        for (auto [c, f] : freq)
            if (f % 2)
                middle = c;

        --freq[middle];
        std::cout << number_of_ways(freq) << '\n';
    }
    else
    {
        std::cout << number_of_ways(freq) << '\n';
    }
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = mul(fact[i - 1], i);

    int t = 1;
//    std::cin >> t;
    while (t--)
        solve();

    return 0;
}