#include <bits/stdc++.h>

#define int int64_t

const int MAX = 505;
const int64_t INF = 1e18 + 10;

int64_t best_time[MAX][MAX];

auto solve() -> void
{
    int n, l, k;
    std::cin >> n >> l >> k;
    std::vector<int> coords(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> coords[i];
    coords.push_back(l); // final road
    std::vector<int> speeds(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> speeds[i];

    if (n == 1)
    {
        // don't have much choice here, must just go through
        assert(coords.size() == 3);
        int distance = coords[2] - coords[1];
        int speed = speeds[1];
        std::cout << distance * speed << '\n';
        return;
    }

    for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < MAX; ++j)
            best_time[i][j] = INF;
    best_time[1][0] = 0;

    auto& best_time_debug = best_time;
    for (int last_sign_taken = 1; last_sign_taken <= n; ++last_sign_taken)
    {
        int current_speed = speeds[last_sign_taken];
        for (int removed = 0; removed <= last_sign_taken - 1; ++removed)
        {
            int left_to_remove = k - removed;
            for (int next_sign = last_sign_taken + 1; next_sign <= n + 1; ++next_sign)
            {
                int need_to_remove = next_sign - last_sign_taken - 1;
                if (need_to_remove > left_to_remove)
                    continue;
                const auto distance = coords[next_sign] - coords[last_sign_taken];
                const auto current_state = best_time[last_sign_taken][removed];
                auto& next_state = best_time[next_sign][removed + need_to_remove];
                next_state = std::min(next_state, current_state + distance * current_speed);
            }
        }
    }

    int64_t answer = INF;
    for (int removed = 0; removed <= k; removed++) answer = std::min(answer, best_time[n+1][removed]);
    std::cout << answer << '\n';
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