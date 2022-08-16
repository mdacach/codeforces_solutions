#include <bits/stdc++.h>

#define int int64_t

const int MAX = 100'000 + 10;
const int INF = 1e18;

// min_cost[i][0] = minimum cost for s[i] to be valid in its position
// min_cost[i][1] = minimum cost for s[i] REVERSED to be valid in its position
int min_cost[MAX][2];

auto solve() -> void
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        min_cost[i][0] = INF;
        min_cost[i][1] = INF;
    }

    std::vector<int> costs(n);
    for (int i = 0; i < n; ++i)
        std::cin >> costs[i];
    std::vector<std::string> strings(n);
    for (auto& s : strings)
        std::cin >> s;

    // first string is already valid
    min_cost[0][0] = 0;
    min_cost[0][1] = costs[0];
    for (int current_index = 1; current_index < n; ++current_index)
    {
        // check which transitions are valid, regarding lexicographical order
        const auto previous_index = current_index - 1;
        const auto& current_string = strings[current_index];
        const auto& current_reversed_string = std::string(std::rbegin(current_string), std::rend(current_string));
        const auto& previous_string = strings[previous_index];
        const auto& previous_reversed_string = std::string(std::rbegin(previous_string), std::rend(previous_string));
        if (current_string >= previous_string)
        {
            auto& current_value = min_cost[current_index][0];
            current_value = std::min(current_value, min_cost[previous_index][0]);
        }
        if (current_string >= previous_reversed_string)
        {
            auto& current_value = min_cost[current_index][0];
            current_value = std::min(current_value, min_cost[previous_index][1]);
        }
        if (current_reversed_string >= previous_string)
        {
            auto& current_value = min_cost[current_index][1];
            current_value = std::min(current_value, min_cost[previous_index][0] + costs[current_index]);
        }
        if (current_reversed_string >= previous_reversed_string)
        {
            auto& current_value = min_cost[current_index][1];
            current_value = std::min(current_value, min_cost[previous_index][1] + costs[current_index]);
        }
    }
    const auto ans = std::min(min_cost[n-1][0], min_cost[n-1][1]);
    std::cout << (ans == INF ? -1 : ans) << '\n';
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