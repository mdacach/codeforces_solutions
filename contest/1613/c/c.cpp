#include <bits/stdc++.h>

auto solve() -> void
{
    int number_attacks;
    std::cin >> number_attacks;
    int64_t monster_health;
    std::cin >> monster_health;
    std::vector<int> attacks;
    for (int i = 0; i < number_attacks; i++)
    {
        int t;
        std::cin >> t;
        attacks.push_back(t);
    }

    auto CanKill = [monster_health, attacks](const int64_t poison_time) -> bool
    {
        auto current_monster_health = monster_health;
        int previous_attack = attacks.front();
        for (const auto attack : attacks)
        {
            // how much damage did we do in the previous attack?
            int64_t timespan = attack - previous_attack;
            int64_t damage_dealt = std::min(poison_time, timespan);
            current_monster_health -= damage_dealt;
            previous_attack = attack;
        }
        current_monster_health -= poison_time;
        return current_monster_health <= 0;
    };

    int64_t l = 0; // always bad
    int64_t r = 1;    // always good
    while (!CanKill(r))
        r *= 2;
    while (r - l > 1)
    {
        int64_t m = l + (r - l) / 2;
        const auto good = CanKill(m);
        if (good)
            r = m;
        else
            l = m;
    }

    std::cout << r << '\n';
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