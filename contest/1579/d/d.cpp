#include <bits/stdc++.h>

struct Person {
  int id;
  int talks;

  bool operator<(const Person& rhs) const {
    return talks > rhs.talks;
  }
};

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) {
      int n; std::cin >> n;
      std::vector<int> a(n);
      for (auto& x : a) std::cin >> x;
      auto cmp = [&](int lhs, int rhs) { return a[lhs] > a[rhs]; };
      std::multiset<int, decltype(cmp)> active(cmp);
      for (int i = 0; i < n; i++) {
        if (a[i]) active.insert(i);
      }
      std::vector<std::pair<int, int>> talks;
      while (true) {
        if (active.size() <= 1) break;
        auto first_itr = active.begin();
        auto second_itr = std::next(first_itr);
        int first_id = *first_itr;
        int second_id = *second_itr;
        talks.emplace_back(first_id, second_id);
        a[first_id]--; a[second_id]--;
        active.erase(first_itr);
        active.erase(second_itr);
        if (a[first_id] != 0) active.insert(first_id);
        if (a[second_id] != 0) active.insert(second_id);
      }

      std::cout << talks.size() << "\n";
      if (!talks.empty()) for (auto [x, y] : talks) std::cout << x+1 << " " << y+1 << "\n";
    }

    return 0;
}
