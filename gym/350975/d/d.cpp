#include <bits/stdc++.h>

void solve()
{
    std::string path;
    std::cin >> path;
    const auto n = path.size();
    int x = 0, y = 0;
    std::map<char, std::pair<int, int>> char_to_pos;
    std::vector<std::pair<int, int>> all_positions;
    for (size_t i = 0; i < n; i++)
    {
        if (path[i] == 'L')
            x--;
        else if (path[i] == 'R')
            x++;
        else if (path[i] == 'U')
            y++;
        else
            y--;
        if (!(x == 0 && y == 0))
            all_positions.emplace_back(x, y);
        char_to_pos[path[i]] = { x, y };
    }

    auto simulate = [&](std::pair<int, int> obstacle)
    {
        int x = 0, y = 0;
        for (size_t i = 0; i < n; i++)
        {
            int new_x = x, new_y = y;
            if (path[i] == 'L')
                new_x = x - 1;
            else if (path[i] == 'R')
                new_x = x + 1;
            else if (path[i] == 'U')
                new_y = y + 1;
            else
                new_y = y - 1;
            if (std::make_pair(new_x, new_y) != obstacle)
            {
                x = new_x;
                y = new_y;
            }
        }
        return x == 0 && y == 0;
    };
    for (auto p : all_positions)
    {
        if (simulate(p))
        {
            std::cout << p.first << " " << p.second << "\n";
            return;
        }
    }

    std::cout << 0 << " " << 0 << "\n";
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}
