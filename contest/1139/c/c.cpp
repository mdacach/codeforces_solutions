#include <bits/stdc++.h>

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

std::vector<int> adj[N];
std::vector<int> size(N);
std::vector<bool> visited(N);

int mul(int a, int b)
{
    return (1LL * a * b) % MOD;
}

int binary_exp(int b, int e)
{
    assert(e >= 0);
    int res = 1;
    while (e)
    {
        if (e & 1) res = mul(res, b);
        b = mul(b, b);
        e = e >> 1;
    }
    return res;
}

void dfs(int u, int p)
{
    visited[u] = true;
    size[u] = 1;
    for (auto neighbor : adj[u])
    {
        if (neighbor == p)
            continue;
        dfs(neighbor, u);
        size[u] += size[neighbor];
    }
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, x;
        std::cin >> u >> v >> x;
        if (x == 1)
            continue; // skip black edges
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> component_sizes;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1);
            component_sizes.push_back(size[i]);
        }
    }

    int no_black = 0;
    for (auto size : component_sizes)
    {
        no_black += binary_exp(size, k);
        no_black %= MOD;
    }

    int all_ways = binary_exp(n, k);
    int ans = all_ways - no_black;
    while (ans < 0) ans += MOD;
    std::cout << ans << "\n";

    return 0;
}
