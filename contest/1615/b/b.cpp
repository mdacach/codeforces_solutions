#include <bits/stdc++.h>

const int N = 2e5 + 5;
int bits_set_until[32][N];

auto precompute() -> void
{
    for (int b = 0; b < 31; b++)
        for (int i = 1; i <= 2e5; i++)
            bits_set_until[b][i] = bits_set_until[b][i - 1] + ((1 << b & i) > 0);
}

auto solve() -> void
{
    int L, R;
    std::cin >> L >> R;
    int max_set = 0;
    for (int b = 0; b < 31; b++)
        max_set = std::max(max_set, bits_set_until[b][R] - bits_set_until[b][L-1]);
    std::cout << (R - L + 1) - max_set << '\n';
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