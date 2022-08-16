#include <bits/stdc++.h>

auto solve() -> void
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> matrix[i][j];
    int reference_number = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (reference_number % 2 != matrix[i][j] % 2)
                matrix[i][j]++;
            reference_number = !reference_number;
        }
        reference_number = i % 2;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cout << matrix[i][j] << " \n"[j == m];
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