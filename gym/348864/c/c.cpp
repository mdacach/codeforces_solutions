#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a)
    std::cin >> x;

  int64_t sum = std::accumulate(a.begin(), a.end(), 0LL);
  if (2 * sum % n) {
    // we would need fractional numbers
    std::cout << 0 << "\n";
    return;
  }
  int64_t want = 2 * sum / n;
  std::map<int, int> freq;
  int64_t ways = 0;
  for (auto x : a) {
    int remaining = want - x;
    ways += freq[remaining];
    freq[x]++;
  }
  std::cout << ways << "\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--)
    solve();

  return 0;
}
