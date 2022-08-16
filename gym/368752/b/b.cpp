#include <bits/stdc++.h>

#define int int64_t

auto sum(const int n)
{
    return n * (n + 1) / 2;
}

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::vector<int> times(n);
    for (auto& x : times)
        std::cin >> x;
    std::vector<int> hps(n);
    for (auto& x : hps)
        std::cin >> x;

    // range needed for a monster of X hp is X
    // we must know is there's a range open

    // let's do the last monster separately
    int need_to_start_at = times.back() - hps.back() + 1;
    int damage_needed_at_the_end = hps.back();
    int total_mana = 0;
    for (int current_index = n - 2; current_index >= 0; current_index--)
    {
        int current_time = times[current_index];
        int current_hp = hps[current_index];
        if (need_to_start_at > current_time)
        {
            // we can finish the range of monsters
            total_mana += sum(damage_needed_at_the_end);
            damage_needed_at_the_end = 0;

            // then we kill this current one
            need_to_start_at = current_time - current_hp + 1;
            damage_needed_at_the_end = current_hp;
        } else
        {
            // this monster may need to increase the damage we do
            int damage_we_have = current_time - need_to_start_at + 1;
            if (damage_we_have >= current_hp)
            {
                // all good, this monster does not trouble us
                continue;
            } else
            {
                // we will need to start further back, and spend more mana at the end
                int damage_needed = current_hp - damage_we_have;
                need_to_start_at -= damage_needed;
                assert(need_to_start_at >= 0);
                damage_needed_at_the_end += damage_needed;
            }
        }
    }

    total_mana += sum(damage_needed_at_the_end);
    std::cout << total_mana << '\n';
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