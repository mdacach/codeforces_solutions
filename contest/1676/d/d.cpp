#include <bits/stdc++.h>

auto solve() -> void
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> grid[i][j];

    auto calculate_for_position = [&](int i, int j)
    {
        auto is_inside = [&](int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; };
        std::vector<int> diff_x{ 1, -1 };
        std::vector<int> diff_y{ 1, -1 };
        int res = grid[i][j];
        for (auto d_x : diff_x)
        {
            for (auto d_y : diff_y)
            {
                int x = i + d_x, y = j + d_y;
                while (is_inside(x, y))
                {
                    res += grid[x][y];
                    x += d_x;
                    y += d_y;
                }
            }
        }
        return res;
    };

    int best = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            best = std::max(best, calculate_for_position(i, j));
    std::cout << best << '\n';
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