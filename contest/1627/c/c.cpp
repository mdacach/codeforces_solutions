#include <bits/stdc++.h>
const int N = 1e5 + 10;

using edge = std::pair<int, int>;
std::map<edge, int> edge_to_prime;
std::vector<int> adj[N];
bool visited[N];
int deg[N];

void dfs(int u, int p, int value)
{
    if (visited[u]) return;
    visited[u] = true;
    edge_to_prime[edge{p, u}] = value;
    for (auto neighbor : adj[u])
    {
        if (neighbor == p) continue;
        value = value == 2 ? 3 : 2;
        dfs(neighbor, u, value);
    }
}

auto solve() -> void
{
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        visited[i] = false;
        deg[i] = 0;
    }
    edge_to_prime.clear();

    bool has_answer = true;
    std::vector<edge> edges;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        edges.emplace_back(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
        if (deg[u] > 2 || deg[v] > 2) has_answer = false;
    }
    if (!has_answer)
    {
        std::cout << -1 << '\n';
        return;
    }

    dfs(1, 0, 2);
    for (const auto& e : edges)
    {
        if (edge_to_prime.find(e) == edge_to_prime.end())
        {
            auto inverse = edge{e.second, e.first};
            std::cout << edge_to_prime.at(inverse) << ' ';
        } else
        {
            std::cout << edge_to_prime.at(e) << ' ';
        }
    }
    std::cout << '\n';
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    while (n--)
        solve();

    return 0;
}