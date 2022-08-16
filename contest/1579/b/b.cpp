#include <bits/stdc++.h>

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a)
      std::cin >> x;
    int index = 0;
    auto get_min = [&]() {
      int min = 1e9 + 10;
      int pos = -1;
      for (int i = index; i < n; i++) {
        if (a[i] < min) {
          min = a[i];
          pos = i;
        }
      }
      return pos;
    };
    auto shift = [&](int l, int r) {
      int prv = a[r];
      for (int i = r; i > l; i--) {
        a[i] = a[i - 1];
      }
      a[l] = prv;
    };
    int cnt = 0;
    std::vector<std::tuple<int, int, int>> actions;
    while (true) {
      int next = get_min();
      while (index < n && a[next] == a[index]) {
        index++;
        next = get_min();
      }
      if (index == n)
        break;
      if (index == next) {
        index++;
        continue;
      }
      actions.emplace_back(index, next, (next - index));
      shift(index, next);
      index++;
    }

    std::cout << actions.size() << "\n";
    if (!actions.empty())
      for (auto [x, y, z] : actions) {
        std::cout << x + 1 << " " << y + 1 << " " << z << "\n";
      }
  }

  return 0;
}
