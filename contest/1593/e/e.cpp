#include <bits/stdc++.h>

const int N = 4e5 + 10;
const int INF = 1e9;

std::vector<int> adj[N];         // adjacency list for BFS
std::vector<int> deg(N);         // vertex degree for identifying leaves
std::vector<int> dist(N, INF);   // distance from vertex to the closest leaf
                                 // determines when it will be cut
std::vector<bool> vis(N, false); // keep track of visited vertices

void solve() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    std::cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }

  // gather the leaves
  std::vector<int> leaves;
  for (int i = 1; i <= n; i++) {
    if (deg[i] <= 1)
      leaves.push_back(i);
  }

  // multisource bfs
  std::queue<int> bfs;
  for (auto leaf : leaves) {
    dist[leaf] = 0;
    bfs.push(leaf);
    vis[leaf] = true;
  }
  while (!bfs.empty()) {
    auto current_vertex = bfs.front();
    bfs.pop();
    for (auto neighbor : adj[current_vertex]) {
      if (vis[neighbor])
        continue;
      vis[neighbor] = true;
      dist[neighbor] = dist[current_vertex] + 1;
      bfs.push(neighbor);
    }
  }

  int removed = 0;
  for (int i = 1; i <= n; i++) {
    // leaf has dist 0 but is removed on k = 1
    // so we compare dist + 1 with k
    if (dist[i] + 1 <= k)
      removed++;
  }

  std::cout << n - removed << "\n";

  // clean up for next testcase
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    deg[i] = 0;
    dist[i] = INF;
    vis[i] = false;
  }
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
