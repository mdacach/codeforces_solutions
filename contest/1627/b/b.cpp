#include <bits/stdc++.h>

auto solve() -> void
{
    int n, m;
    std::cin >> n >> m;
    // we need a 2d grid
    std::vector<std::vector<bool>> grid(n + 1, std::vector<bool>(m + 1));
    using cell = std::pair<int, int>;
    using node = std::tuple<int, int, int>;
    std::queue<node> queue;
    // add the center
    std::vector<int> vertical_center{ (n + 1) / 2 };
    if (n % 2 == 0)
        vertical_center.push_back(n / 2 + 1);
    std::vector<int> horizontal_center{ (m + 1) / 2 };
    if (m % 2 == 0)
        horizontal_center.push_back(m / 2 + 1);
    std::vector<cell> centers;
    for (auto vc : vertical_center)
        for (auto hc : horizontal_center)
            centers.emplace_back(vc, hc);
    std::map<cell, bool> visited;
    int base_distance = n / 2 + m / 2;
    int increment = 0;
    for (auto c : centers)
    {
        auto [x, y] = c;
        queue.emplace(x, y, 0);
        visited[cell{x, y}] = true;
    }
    auto is_valid = [&n, &m, &visited](int x, int y)
    {
        if (x <= 0)
            return false;
        if (x > n)
            return false;
        if (y <= 0)
            return false;
        if (y > m)
            return false;
        auto as_cell = cell{ x, y };
        if (visited[as_cell])
            return false;
        return true;
    };

    std::vector<int> answers;
    while (!queue.empty())
    {
        auto [x, y, inc] = queue.front();
        queue.pop();
        if (is_valid(x + 1, y))
        {
            queue.emplace(x + 1, y, inc + 1);
            visited[cell{ x + 1, y }] = true;
        }
        if (is_valid(x - 1, y))
        {
            queue.emplace(x - 1, y, inc + 1);
            visited[cell{ x - 1, y }] = true;
        }
        if (is_valid(x, y + 1))
        {
            queue.emplace(x, y + 1, inc + 1);
            visited[cell{ x, y + 1 }] = true;
        }
        if (is_valid(x, y - 1))
        {
            queue.emplace(x, y - 1, inc + 1);
            visited[cell{ x, y - 1 }] = true;
        }
        answers.push_back(base_distance + inc);
    }
    for (auto x : answers)
        std::cout << x << " ";
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