#include <bits/stdc++.h>

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) {
      int n; std::cin >> n;
      std::string row1; std::cin >> row1;
      std::string row2; std::cin >> row2;
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (row1[i] == row2[i] && row1[i] == '1') ok = false;
      }
      std::cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}
