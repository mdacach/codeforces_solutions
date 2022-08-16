#include <bits/stdc++.h>

#define int int64_t

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) {
      int n; std::cin >> n;
      if (n == 1) std::cout << "0 1\n";
      else {
        std::cout << -(n-1) << " " << n << "\n";
      }
    }

    return 0;
}
