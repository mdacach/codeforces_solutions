#include <bits/stdc++.h>

void solve() {
  int n; std::cin >> n;
  char c; std::cin >> c;
  std::string s; std::cin >> s;

  if (std::all_of(s.begin(), s.end(), [&c](char x) { return x == c;})) {
    std::cout << 0 << "\n";
    return;
  }

  for (int step = 1; step <= n; step++) {
    bool all_c = true;
    for (int i = step-1; i < n; i+=step) {
      if (s[i] != c) all_c = false;
    }
    if (all_c) {
      std::cout << 1 << "\n";
      std::cout << step << "\n";
      return;
    }
  }

  std::cout << 2 << "\n";
  std::cout << n << " " << n-1 << "\n";
}


int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) solve();

    return 0;
}
