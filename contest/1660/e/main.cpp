#include <bits/stdc++.h>

auto solve() -> void
{
    uint32_t n;
    std::cin >> n;
    std::vector<std::vector<char>> grid(n, std::vector<char>(n));
    for (uint32_t i = 0; i < n; ++i)
        for (uint32_t j = 0; j < n; ++j)
            std::cin >> grid[i][j];

    // how many ones we can get in place is the minimum of rows/cols

    std::vector<std::vector<uint32_t>> row_to_possible(n);
    for (uint32_t i = 0; i < n; ++i)
    {
        for (uint32_t j = 0; j < n; ++j)
        {
            if (grid[i][j] == '1')
                row_to_possible[i].push_back(j);
        }
    }

    std::vector<std::vector<uint32_t>> col_to_possible(n);
    for (uint32_t j = 0; j < n; ++j)
    {
        for (uint32_t i = 0; i < n; ++i)
            if (grid[i][j] == '1')
                col_to_possible[j].push_back(i);
    }

    // now we have to take the "minimum" of those?

    std::vector<uint32_t> good_if_start(n);
    for (uint32_t current_row = 0; current_row < n; ++current_row)
    {
        uint32_t good_count = 0;
        for (uint32_t possible = 0; possible < n; ++possible)
        {

            // need to make this faster
        }
    }

    uint32_t total_ones = 0;
    for (uint32_t i = 0; i < n; ++i)
        for (uint32_t j = 0; j < n; ++j)
            total_ones += (grid[i][j] == '1');

    const auto correct = std::min(correct_rows, correct_cols);
    const auto ones_missing = n - correct;
    auto ans = ones_missing;
    if (total_ones > correct)
        ans += total_ones - correct;
    std::cout << ans << '\n';
    // the remaining must be zeros
    // how many do we need to change
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