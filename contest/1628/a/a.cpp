#include <bits/stdc++.h>

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::vector<int> values(n);
    for (auto& x : values)
        std::cin >> x;

    std::map<int, std::set<int>> value_to_positions;
    for (int i = 0; i < n; i++)
        value_to_positions[values[i]].insert(i);

    auto is_empty = [&value_to_positions](const int key)
    { return value_to_positions.find(key) == value_to_positions.end() || value_to_positions[key].empty(); };

    std::vector<int> answer;
    int got_until = -1;
    while (true) // building the answers
    {
        int last_value = -1;
        for (int mex = 0;; mex++)
        {
            if (is_empty(mex))
                break;
            const auto& positions = value_to_positions[mex];
            got_until = std::max(got_until, *positions.begin());
            last_value = mex;
        }

        // all the rest will be single
        if (last_value == -1)
        {
            for (int i = 0; i < n - got_until - 1; i++)
                answer.push_back(0);
            break;
        }

        // update the positions to reflect who we've already removed
        for (int mex = 0; mex <= last_value; mex++)
        {
            auto& positions = value_to_positions[mex];
            while (!positions.empty() && *positions.begin() <= got_until)
                positions.erase(positions.begin());
        }
        answer.push_back(last_value + 1);
    }
    std::cout << answer.size() << '\n';
    for (const auto& x : answer) std::cout << x << " ";
    std::cout << '\n';
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