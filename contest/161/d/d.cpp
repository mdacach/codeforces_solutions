#include <bits/stdc++.h>

const int N = 50000 + 5;
const int K = 500 + 5;

std::vector<int> adj[N];
int distance_in_subtree[N][K];

auto populate_in_subtree(int current, int parent = 0) -> void
{
    auto& adj_debug = adj;
    auto& debug = distance_in_subtree;
    distance_in_subtree[current][0] = 1;
    std::vector<int> to_add(K);
    for (const auto& neighbor : adj[current])
    {
        if (neighbor == parent)
            continue;
        populate_in_subtree(neighbor, current);
        for (int k = 0; k < K - 1; k++)
            distance_in_subtree[current][k + 1] += distance_in_subtree[neighbor][k];
    }
}

int k_for_answer = 0;
int64_t global_answer = 0;
auto compute_answer(int current, int parent = 0) -> void
{
    // let's root the tree on this guy
    // current vertex can be the ENDPOINT of a pair
    {
        // we have all calculated already, as distance_in_subtree[current][k]
        global_answer += distance_in_subtree[current][k_for_answer];
    }
    // or it can be the middlepoint of a pair
    {
        // try to combine vertices in subtrees of children of current

        std::vector<int> total_with_distance(k_for_answer + 1);
        for (const auto& child : adj[current])
        {
            if (child == parent)
                continue;
            for (int distance = 0; distance < k_for_answer; ++distance)
                total_with_distance[distance + 1] += distance_in_subtree[child][distance];
        }

        int64_t answer_here = 0;
        for (const auto& child : adj[current])
        {
            if (child == parent)
                continue;
            for (int distance_first_subtree = 0; distance_first_subtree < k_for_answer; ++distance_first_subtree)
            {
                const auto vertices_here = distance_in_subtree[child][distance_first_subtree];
                const auto distance_needed_other = k_for_answer - 1 - distance_first_subtree;
                if (distance_needed_other <= 0) continue;
                // we will double count some vertices
                const auto vertices_other =
                    total_with_distance[distance_needed_other] - distance_in_subtree[child][distance_needed_other - 1];
                answer_here += 1LL * vertices_here * vertices_other;
            }
        }
        global_answer += answer_here / 2; // we have double counted all pairs
    }

    for (const auto& neighbor : adj[current])
    {
        if (neighbor == parent)
            continue;

        compute_answer(neighbor, current);
    }
}

auto solve() -> void
{
    auto& debug = distance_in_subtree;
    int n, k;
    std::cin >> n >> k;
    k_for_answer = k;
    for (int i = 0; i + 1 < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    populate_in_subtree(1);

    compute_answer(1);

    std::cout << global_answer << '\n';
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    //    std::cin >> t;
    while (t--)
        solve();

    return 0;
}