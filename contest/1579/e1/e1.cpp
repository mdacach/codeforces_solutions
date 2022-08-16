#include <bits/stdc++.h>

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) {
      int n; std::cin >> n;
      std::vector<int> p(n);
      for (auto& x : p) std::cin >> x;
      std::deque<int> queue;

      queue.push_front(p[0]);
      for (int i = 1; i < n; i++) {
        int front = queue.front();
        if (p[i] > front) queue.push_back(p[i]);
        else queue.push_front(p[i]);
      }
      for (auto x : queue) std::cout << x << " ";
      std::cout << "\n";
    }

    return 0;
}
