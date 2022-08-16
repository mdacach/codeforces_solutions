#include <bits/stdc++.h>

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;

    int successful_moves = 0;
    int start_row = 1;
    int start_col = 1;
    int cur_row = start_row;
    int cur_col = start_col;
    int most_left = 0, most_right = 0, most_down = 0, most_up = 0;
    for (auto move : s)
    {
        if (move == 'R')
        {
            if (cur_col + 1 <= m)
            {
                cur_col++;
                successful_moves++;
            } else
            {
                if (start_col - most_left > 1)
                {
                    start_col--;
                    successful_moves++;
                } else
                {
                    std::cout << start_row << " " << start_col << "\n";
                    return;
                }
            }
        }
        else if (move == 'L')
        {
            if (cur_col - 1 >= 1)
            {
                cur_col--;
                successful_moves++;
            } else
            {
                if (start_col + most_right < m)
                {
                    start_col++;
                    successful_moves++;
                } else
                {
                    std::cout << start_row << " " << start_col << "\n";
                    return;
                }
            }
        }
        else if (move == 'U')
        {
            if (cur_row - 1 >= 1)
            {
                cur_row--;
                successful_moves++;
            } else
            {
                if (start_row + most_down < n)
                {
                    start_row++;
                    successful_moves++;
                } else
                {
                    std::cout << start_row << " " << start_col << "\n";
                    return;
                }
            }
        }
        else
        {
            if (cur_row + 1 <= n)
            {
                cur_row++;
                successful_moves++;
            } else
            {
                if (start_row - most_up > 1)
                {
                    start_row--;
                    successful_moves++;
                } else
                {
                    std::cout << start_row << " " << start_col << "\n";
                    return;
                }
            }
        }
        if (cur_col < start_col) most_left = std::max(most_left, start_col - cur_col);
        if (cur_col > start_col) most_right = std::max(most_right, cur_col - start_col);
        if (cur_row < start_row) most_up = std::max(most_up, start_row - cur_row);
        if (cur_row > start_row) most_down = std::max(most_down, cur_row - start_row);
    }
    std::cout << start_row << " " << start_col << "\n";
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
