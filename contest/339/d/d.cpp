#include <bits/stdc++.h>

int n;
std::vector<int> a;
std::vector<int> tree;

std::unordered_map<int, int> index_to_tree;

void build(int x, int lx, int rx, int d)
{
    if (lx >= rx)
        return;
    if (rx - lx == 1)
    {
//        index_to_tree[lx] = x;
        tree[x] = a[lx];
    }
    else
    {
        int m = lx + (rx - lx) / 2;
        build(2 * x + 1, lx, m, d + 1);
        build(2 * x + 2, m, rx, d + 1);
        if ((n - d) % 2 == 0)
            tree[x] = tree[2 * x + 1] xor tree[2 * x + 2];
        else
            tree[x] = tree[2 * x + 1] bitor tree[2 * x + 2];
    }
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m;
    std::cin >> n >> m;
    a.resize(1 << n);
    for (auto& x : a)
        std::cin >> x;
    tree.resize(2 * (1 << n) - 1);
    build(0, 0, (1 << n), 0);

    const int deregue = (1 << n) - 1;
    while (m--)
    {
        int p, b;
        std::cin >> p >> b;
        p--;
//        int in_tree = index_to_tree[p];
        int in_tree = deregue + p;
        tree[in_tree] = b;
        int current = (in_tree - 1) / 2;
        int d = 1;
        while (true)
        {
            if ( d % 2)
                tree[current] = tree[current * 2 + 1] bitor tree[current * 2 + 2];
            else
                tree[current] = tree[current * 2 + 1] xor tree[current * 2 + 2];
            if (current == 0) break;
            current = (current - 1) / 2;
            d++;
        }
        std::cout << tree[0] << "\n";
    }

    return 0;
}
