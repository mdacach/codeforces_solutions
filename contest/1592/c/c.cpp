#include <bits/stdc++.h>

const int N = 1e5 + 5;

std::array<int, N> values;
std::array<std::vector<int>, N> adj;
struct Edge
{
    int from, to;
};
Edge removed;
int current_xor = 0;
int ans_depth = -1;
int ans_xor = 0;
bool found_ans = false;
void dfs(int u, int p = 0, int d = -1)
{
    current_xor = 0;
    for (auto neighbor : adj[u])
    {
        if (neighbor == p)
            continue;
        dfs(neighbor, u, d + 1);
        current_xor ^= values[u];
    }
    if (current_xor == ans_xor)
    {
        if (d > ans_depth)
        {
            removed = { p, u };
            ans_depth = d;
        }
    }
}

void dfs2(int u, int p = 0)
{
    current_xor = 0;
    for (auto neighbor : adj[u])
    {
        if (neighbor == p)
            continue;
        if (u == removed.from && neighbor == removed.to)
            continue;
        dfs2(neighbor, u);
        current_xor ^= values[u];
    }
    if (current_xor == ans_xor)
        found_ans = true;
}
auto clear(int n)
{
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        values[i] = 0;
    }
    found_ans = false;
    ans_xor = 0;
    ans_depth = -1;
    current_xor = 0;
};

auto solve()
{
    int n, k;
    std::cin >> n >> k;
    clear(n);

    for (int i = 1; i <= n; i++)
        std::cin >> values[i];
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans_xor =
        std::accumulate(values.begin(), values.end(), 0, [](auto& accum, auto& current) { return accum ^ current; });
    dfs(1);
    if (ans_xor == 0)
    {
        std::cout << "YES\n";
        return;
    }
    if (ans_depth == -1)
    {
        std::cout << "NO\n";
        return;
    }
    dfs2(1);
    std::cout << (found_ans ? "YES\n" : "NO\n");
}


auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}