#include <bits/stdc++.h>

const int N = 100 + 5;
const int MOD = 1e9 + 7;

int total_ways[N];
int ways_with_only_less[N];

auto solve() -> void {
    int n, k, d;
    std::cin >> n >> k >> d;

    total_ways[0] = 1;
    for (int current_sum = 0; current_sum <= n; ++current_sum) {
        for (int current_edge = 1; current_edge <= k; ++current_edge) {
            if (current_sum + current_edge > n) continue;
            auto &this_state = total_ways[current_sum];
            auto &next_state = total_ways[current_sum + current_edge];
            next_state += this_state;
            next_state %= MOD;
        }
    }

    ways_with_only_less[0] = 1;
    for (int current_sum = 0; current_sum <= n; ++current_sum) {
        for (int current_edge = 1; current_edge < d; ++current_edge) {
            if (current_sum + current_edge > n) continue;
            auto &this_state = ways_with_only_less[current_sum];
            auto &next_state = ways_with_only_less[current_sum + current_edge];
            next_state += this_state;
            next_state %= MOD;
        }
    }

    const auto ans = total_ways[n] - ways_with_only_less[n];
    std::cout << (ans >= 0 ? ans : ans + MOD) << '\n';
}

auto main() -> int32_t {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;
//    std::cin >> t;
    while (t--)
        solve();

    return 0;
}