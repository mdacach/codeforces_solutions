#include <bits/stdc++.h>

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;
    std::map<int, int> left_to_right_diag;
    std::map<int, int> right_to_left_diag;
    std::vector<std::pair<int, int>> positions;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        positions.emplace_back(x, y);
    }
    std::sort(positions.begin(), positions.end());
    int64_t ans = 0;
    for (auto [x, y] : positions)
    {
        int left_hash = x - y; // identifies left to right diag
        int right_hash = x + y; // identifies right to left diag
        ans += left_to_right_diag[left_hash];
        ans += right_to_left_diag[right_hash]; // all bishops here will make a new pair
        left_to_right_diag[left_hash]++;
        right_to_left_diag[right_hash]++;
    }
    std::cout << ans << "\n";

    return 0;
}
