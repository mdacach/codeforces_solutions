#include <bits/stdc++.h>

bool is_better(const std::string &lhs, const std::string &rhs) {
  return lhs + rhs < rhs + lhs;
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::string s;
  std::cin >> s;
  std::string current_string;
  std::string best = s;
  for (int i = 0; i < n; i++) {
    current_string += s[i];
    if (is_better(current_string, best)) {
      best = current_string;
    }
  }
  while (best.size() < k) best += best;
  while (best.size() > k) best.pop_back();
  std::cout << best << "\n";

  return 0;
}
