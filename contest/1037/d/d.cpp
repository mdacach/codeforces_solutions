#include <bits/stdc++.h>

const int N = 2e5 + 10;

std::unordered_set<int> adj[N];

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int x, y;
        std::cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    std::vector<int> order(n);
    for (auto& x : order) std::cin >> x;
    if (order.front() != 1)
    {
        std::cout << "No\n";
        return 0;
    }

    int current_parent_ptr = 0;
    int current_children_ptr = 1;
    while (current_children_ptr < n)
    {
        const auto current_parent = order[current_parent_ptr];
        auto sz = adj[current_parent].size();
        if (current_parent != 1) sz--; // undirected, remove parent link (will never decrement below 0, too)
        std::vector<int> nodes_in_order;
        nodes_in_order.reserve(sz);
        for (int i = 0; i < (int) sz; i++)
            nodes_in_order.push_back(order[current_children_ptr++]);
        for (auto x : nodes_in_order)
        {
            if (adj[current_parent].find(x) == adj[current_parent].end())
            {
                std::cout << "No\n";
                return 0;
            }
        }
        current_parent_ptr++;
    }
    std::cout << "Yes\n";

    return 0;
}