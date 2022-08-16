#include <bits/stdc++.h>

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::map<int, std::vector<int>> sight_to_indices;
        int current_id = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x; std::cin >> x;
                sight_to_indices[x].push_back(current_id++);
            }
        }

        for (auto&& [sight, indices] : sight_to_indices) {
            std::sort(indices.begin(), indices.end());
        }

        std::vector<std::vector<int>> ans(n, std::vector<int>(m));
        int row = 0, col = 0;
        for (auto&& [sight, indices] : sight_to_indices) {
            int size = (int) indices.size();
            int id_here = 0;
            while (size) {
                int how_many = std::min(m - col, size);
                size -= how_many;
                int start_at = id_here + how_many - 1;
                for (int i = 0; i < how_many; i++) {
                    ans[row][col] = indices[start_at - i];
                    col++;
                }
                if (col == m) col = 0, row++;
                id_here += how_many;
            }
            assert(size == 0);
        }

        int64_t inconvenience = 0;
        for (auto&& r : ans) {
            std::vector<int> ids;
            ids.reserve(m);
            for (auto&& id : r) {
                int smaller = 0;
                for (auto prv : ids) {
                    smaller += prv < id;
                }
                inconvenience += smaller;
                ids.push_back(id);
            }
        }
        std::cout << inconvenience << "\n";
    }

    return 0;
}
