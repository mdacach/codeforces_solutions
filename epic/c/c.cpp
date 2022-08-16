#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

// from splucs
class UnionFind
{
private:
    vector<int> parent, rank;

public:
    UnionFind(int N)
    {
        rank.assign(N + 9, 0);
        parent.assign(N + 9, 0);
        for (int i = 0; i < N; i++)
            parent[i] = i;
    }
    int find(int i)
    {
        while (i != parent[i])
            i = parent[i];
        return i;
    }
    bool isSameSet(int i, int j) { return find(i) == find(j); }
    void unionSet(int i, int j)
    {
        if (isSameSet(i, j))
            return;
        int x = find(i), y = find(j);
        if (rank[x] > rank[y])
            parent[y] = x;
        else
        {
            parent[x] = y;
            if (rank[x] == rank[y])
                rank[y]++;
        }
    }
};

typedef pair<int, int> ii;
typedef long long ll;

int N, M;
vector<std::pair<ll, std::tuple<int, int, int>>> edgeList; // (weight, two vertices) of the edge
std::vector<int> answer;

ll kruskal()
{
    ll cost = 0;
    UnionFind UF(N);
    pair<int, std::tuple<int, int, int>> edge;
    sort(edgeList.begin(), edgeList.end());
    for (int i = 0; i < M; i++)
    {
        edge = edgeList[i];
        auto [a, b, id] = edgeList[i].second;
        if (!UF.isSameSet(a, b))
        {
            cost += edge.first;
            answer.emplace_back(id);
            UF.unionSet(a, b);
        }
    }
    return cost;
}

auto solve() -> void
{
    std::cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        edgeList.emplace_back(1, std::make_tuple(a, b, i + 1));
    }
    kruskal();

    std::cout << std::size(answer) << '\n';
    std::sort(std::begin(answer), std::end(answer));
    for (const auto& x : answer)
        std::cout << x << " ";
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