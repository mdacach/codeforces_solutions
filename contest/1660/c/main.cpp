#include <bits/stdc++.h>

const uint32_t INF = 1e9;

auto solve() -> void
{
    std::string s;
    std::cin >> s;

    std::map<char, std::vector<uint32_t>> char_to_positions;
    for (uint32_t i = 0; i < std::size(s); ++i)
        char_to_positions[s[i]].push_back(i);

    std::vector<uint32_t> cost_until(std::size(s) + 1, INF);
    cost_until[0] = 0;
    for (uint32_t i = 0; i < std::size(s); ++i)
    {
        const auto current_char = s[i];
        const auto& char_positions = char_to_positions.at(current_char);
        const auto next_same = std::upper_bound(std::begin(char_positions), std::end(char_positions), i);
        // we can either remove this character, or make it a pair with next one
        if (next_same == std::end(char_positions))
        {
            // we do not have any next characters to make a pair, so we need to remove this guy
            cost_until[i + 1] = std::min(cost_until[i + 1], cost_until[i] + 1);
        }
        else
        {
            // remove everyone inbetween
            const auto next = *next_same + 1;
            const auto between = *next_same - i - 1;
            cost_until[next] = std::min(cost_until[next], cost_until[i] + between);

            // remove this current guy
            cost_until[i + 1] = std::min(cost_until[i + 1], cost_until[i] + 1);
        }
    }
    std::cout << cost_until[std::size(s)] << '\n';
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