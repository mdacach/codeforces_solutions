#include <bits/stdc++.h>

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    int ans_x = 0, ans_y = 0;
    while (t--)
    {
        int n, m;
        std::cin >> n >> m;
        std::string moves; std::cin >> moves;
        int cur_x = 0, cur_y = 0;
        int most_left = 0, most_right = 0, most_up = 0, most_down = 0;
        for (auto move : moves)
        {
            if (move == 'R') cur_x++;
            if (move == 'L') cur_x--;
            if (move == 'U') cur_y++;
            if (move == 'D') cur_y--;
            most_left = std::max(most_left, -cur_x);
            most_right = std::max(most_right, cur_x);
            most_down = std::max(most_down, -cur_y);
            most_up = std::max(most_up, cur_y);


            int left = most_left + 1;
            int right = most_right - 1;
            if (right > left) break;
            int up = most_up - 1;
            int down = most_down + 1;
            if (up > down) break;
            ans_x = left;
            ans_y = m - right - 1;
        }
        std::cout << ans_x << " " << ans_y << "\n";
    }

    return 0;
}
