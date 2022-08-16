#include <bits/stdc++.h>

const int N = 2e5 + 5;

std::vector<int> adj[N];
int indegree[N];

void solve() {
  int n; std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int k; std::cin >> k;
    for (int j = 0; j < k; j++) {
      int v; std::cin >> v;
      adj[v].push_back(i);
    }
    indegree[i] = k;
  }

  std::priority_queue<int, std::vector<int>, std::greater<>> pq;
//  std::queue<int> pq;
  // who starts
  for (int i = n; i >= 1; i--) {
    if (indegree[i] == 0) pq.push(i);
  }

  std::priority_queue<int, std::vector<int>, std::greater<>> next;
//  std::queue<int> next;
  int ans = 0;
  int visited = 0;
  while (!pq.empty()) {
    int v = pq.top(); pq.pop();
    visited++;
    for (auto x : adj[v]) {
      indegree[x]--;
      if (indegree[x] == 0) {
        if (x > v) pq.push(x);
        else next.push(x);
      }
    }

    if (pq.empty()) {
      pq = next;
      while (!next.empty()) next.pop();
      ans++;
    }
  }

  assert(visited <= n);
  if (visited != n) {
    std::cout << -1 << "\n";
  } else {
    std::cout << ans << "\n";
  }

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    indegree[i] = 0;
  }
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) solve();

  return 0;
}
