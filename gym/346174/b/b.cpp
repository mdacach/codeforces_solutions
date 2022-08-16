#include <bits/stdc++.h>

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) {
      int n, q;
      std::cin >> n >> q;
      std::vector<int> even_sum(n+1), odd_sum(n+1);
      std::string signs;
      std::cin >> signs;
      for (int i = 0; i < signs.size(); i++) {
        int add = (signs[i] == '+' ? 1 : -1);
        if ((i + 1) % 2 == 0) {
          even_sum[i+1] = even_sum[i] + add;
          odd_sum[i+1] = odd_sum[i];
        } else {
          odd_sum[i+1] = odd_sum[i] + add;
          even_sum[i+1] = even_sum[i];
        }
      }
      while (q--) {
        int l, r;
        std::cin >> l >> r;
        int even = even_sum[r] - even_sum[l-1];
        int odd = odd_sum[r] - odd_sum[l-1];
        if (even == odd) {
          std::cout << 0 << "\n";
        } else if ((r - l) % 2 == 0) {
          std::cout << 1 << "\n";
        } else {
          std::cout << 2 << "\n";
        }
      }
    }

    return 0;
}
