#include <bits/stdc++.h>

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> wants(n);
    for (int i = 0; i < n; i++)
      std::cin >> wants[i];
    for (auto &x : wants)
      x--;

    std::vector<bool> gifted(n);
    std::vector<std::pair<int, int>> pairs;
    std::map<int, int> gift_map;
    for (int i = 0; i < n; i++) {
      if (!gifted[wants[i]]) {
        //        pairs.emplace_back(i, wants[i]);
        gift_map[i] = wants[i];
        gifted[wants[i]] = true;
      }
    }
    int ans = 0;
    std::vector<int> not_given, not_received;
    for (int i = 0; i < n; i++) {
      if (!gifted[i])
        not_received.push_back(i);
      ans += gifted[i];
    }
    for (int i = 0; i < n; i++) {
      if (!gift_map.count(i))
        not_given.push_back(i);
    }
    assert(not_given.size() == not_received.size());

    bool ok = false;
    if (not_given.size() == 1) {
      if (not_given.front() == not_received.front()) {
        int left = not_given.front();
        int wanted = wants[left];
        int previous;
        for (auto [person, gifted] : gift_map) {
          if (gifted == wanted)
            gift_map[person] = left;
        }
        gift_map[left] = wanted;
      } else {
        gift_map[not_given.front()] = not_received.front();
      }
      ok = true;
    }

    if (!ok) {
      int size = not_given.size();
      auto check_not_equal = [&]() {
        for (int i = 0; i < size; i++) {
          int person = not_given[i];
          int other = not_received[i];
          if (person == other) {
            return false;
          }
        }
        return true;
      };
      auto rng = std::default_random_engine{};
      while (!check_not_equal()) {
        std::shuffle(not_given.begin(), not_given.end(), rng);
      }

      for (int i = 0; i < size; i++) {
        int person = not_given[i];
        int other = not_received[i];
        gift_map[person] = other;
      }
    }

    std::cout << ans << "\n";
    for (auto [x, y] : gift_map)
      std::cout << y + 1 << " ";
    std::cout << "\n";
  }

  return 0;
}
