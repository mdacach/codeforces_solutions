#include <bits/stdc++.h>

const int N = 4040;
std::vector<int> adj[N];
char coloring[N];

int answer = 0;
// I guess we could use white - black here too
struct colors
{
    int black;
    int white;
};
colors count_subtrees(int current, int parent)
{

    int black = 0;
    int white = 0;
    for (auto neighbor : adj[current])
    {
        if (neighbor == parent)
            continue;
        auto [child_black, child_white] = count_subtrees(neighbor, current);
        black += child_black;
        white += child_white;
    }

    if (coloring[current] == 'W')
        ++white;
    else
        ++black;

    if (white == black)
        answer++;

    return colors{ black, white };
}

auto solve() -> void
{
    int n;
    std::cin >> n;

    for (int child = 2; child <= n; ++child)
    {
        int parent;
        std::cin >> parent;
        adj[parent].push_back(child);
    }

    for (int vertex = 1; vertex <= n; ++vertex)
        std::cin >> coloring[vertex];

    count_subtrees(1, 0);
    std::cout << answer << '\n';

    answer = 0;
    for (int vertex = 1; vertex <= n; ++vertex)
        adj[vertex].clear();
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