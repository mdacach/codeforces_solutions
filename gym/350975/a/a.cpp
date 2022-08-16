#include <bits/stdc++.h>

#define int int64_t

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;
    std::sort(a.begin(), a.end());
    const auto all_attacks = std::accumulate(a.begin(), a.end(), int64_t(0));
    int m;
    std::cin >> m;
    while (m--)
    {
        int x, y;
        std::cin >> x >> y;
        int ans = std::numeric_limits<int64_t>::max();
    // test either the weakest strong enough man
    // or the strongest but not enough
    strong:
    {
        // weakest strong man
        auto to_slay_dragon = std::upper_bound(a.begin(), a.end(), x);
        if (to_slay_dragon == a.end())
            goto weak;
        auto remaining = all_attacks - *to_slay_dragon;
        auto need_to_buy = std::max<int64_t>(0, y - remaining);
        ans = std::min(ans, need_to_buy);
    }
    weak:
    {
        // strongest but not enough
        auto to_slay_dragon = std::upper_bound(a.begin(), a.end(), x);
        if (to_slay_dragon == a.begin())
            goto end;
        to_slay_dragon = std::prev(to_slay_dragon);
        auto need_here = x - *to_slay_dragon;
        auto remaining = all_attacks - *to_slay_dragon;
        auto need_to_buy = need_here + std::max<int64_t>(0, y - remaining);
        ans = std::min(ans, need_to_buy);
    }
    end:
        std::cout << ans << "\n";
    }

    return 0;
}
