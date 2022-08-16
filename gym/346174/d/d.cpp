#include <bits/stdc++.h>

void solve() {
  std::string res;
  std::cin >> res;
  int n = res.size();
  std::set<char> seen;
  std::vector<char> removed_order;
  for (int i = n - 1; i >= 0; i--) {
    if (seen.find(res[i]) == seen.end()) {
      seen.insert(res[i]);
      removed_order.push_back(res[i]);
    }
  }
  std::map<char, int> frequency;
  for (auto x : res)
    frequency[x]++;

  std::map<char, int> must_have;
  int total_times = seen.size();
  for (auto x : removed_order) {
    if (frequency[x] % (total_times)) {
      std::cout << -1 << "\n";
      return;
    }
    must_have[x] = frequency[x] / total_times;
    total_times--;
  }

  int get_until = 0;
  for (int i = 0; i < n; i++) {
    char ch = res[i];
    if (must_have[ch] > 0) {
      must_have[ch]--;
      get_until = i;
    }
  }

  std::reverse(removed_order.begin(), removed_order.end());
  auto ans = res.substr(0, get_until + 1);

  std::string final_string;
  std::set<char> to_remove;
  for (auto ch : removed_order) {
    for (auto x : ans) {
      if (to_remove.find(x) == to_remove.end()) {
        final_string += x;
      }
    }
    to_remove.insert(ch);
  }
  if (final_string != res) {
    std::cout << -1 << "\n";
    return;
  }
  std::cout << ans << " ";
  for (auto x : removed_order) std::cout << x;
  std::cout << "\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
