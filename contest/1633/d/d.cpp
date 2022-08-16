#include <bits/stdc++.h>

const int MAX = 1e3 + 5;
const int INF = 1e9 + 10;
const int K = 1e6 + 10;
std::array<int, MAX> min_steps;

std::array<int, K> best_rewards; // with K operations left

auto precompute() -> void
{
    min_steps.fill(INF);
    min_steps[1] = 0;
    for (int i = 1; i < MAX; i++)
        for (int x = 1; x <= i; x++)
            if (i + i / x < MAX)
                min_steps[i + i / x] = std::min(min_steps[i + i / x], min_steps[i] + 1);
}

auto solve() -> void
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> want(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> want[i];
    std::vector<int> rewards(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> rewards[i];

    for (int i = n; i >= 1; i--)
    {
        for (int left = 0; left <= k; left++)
        {
            // if we were to "pick" a[i]

            int cost = min_steps[want[i]];
            if (cost > left) continue;
            int next_rewards = best_rewards[left] + rewards[i];
            best_rewards[left - cost] = std::max(best_rewards[left - cost], next_rewards);
        }
    }

    int answer = 0;
    for (int left = 0; left <= k; left++) answer = std::max(answer, best_rewards[left]);
    std::cout << answer << '\n';

    best_rewards.fill(0);
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    precompute();

    int t;
    std::cin >> t;
    auto& debug = min_steps;
    while (t--)
        solve();

    return 0;
}