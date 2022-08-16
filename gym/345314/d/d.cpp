#include <bits/stdc++.h>

#define int int64_t

const int N = 1e5 + 10;
std::vector<int> adj[N];
int left[N];
int right[N];
int best_with_left[N];
int best_with_right[N];

void DFS(int current, int parent) {
  // for this current node, I can put either L or R
  int sum_with_left = 0;
  int sum_with_right = 0;
  for (auto child : adj[current]) {
    if (child == parent) continue;

    DFS(child, current);

    auto l1 = std::abs(left[current] - left[child]) + best_with_left[child];
    auto l2 = std::abs(left[current] - right[child]) + best_with_right[child];
    sum_with_left += std::max(l1, l2);

    auto r1 = std::abs(right[current] - left[child]) + best_with_left[child];
    auto r2 = std::abs(right[current] - right[child]) + best_with_right[child];
    sum_with_right += std::max(r1, r2);
  }

  best_with_left[current] = sum_with_left;
  best_with_right[current] = sum_with_right;
}


void Solve() {
  int n; std:: cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b; std::cin >> a >> b;
    left[i] = a; right[i] = b;
  }

  for (int i = 0; i < n-1; i++) {
    int a, b;
    std::cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  DFS(1, 0);

  std::cout << std::max(best_with_left[1], best_with_right[1]) << "\n";

  for (int i = 0; i <= n; i++) {
    best_with_left[i] = 0;
    best_with_right[i] = 0;
    left[i] = 0;
    right[i] = 0;
    adj[i].clear();
  }
}


int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) Solve();

  return 0;
}
