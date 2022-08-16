#include <bits/stdc++.h>

auto ceil(const int64_t lhs, const int64_t rhs) -> int64_t
{
    return (lhs + rhs - 1) / rhs;
}

auto solve() -> void
{
    int64_t hero_health, hero_damage;
    std::cin >> hero_health >> hero_damage;
    int64_t monster_health, monster_damage;
    std::cin >> monster_health >> monster_damage;
    int total_upgrades;
    std::cin >> total_upgrades;
    int w, a;
    std::cin >> w >> a;

    auto SlaysMonster = [monster_damage, monster_health](const int64_t hero_health, const int64_t hero_damage)
    {
        const auto hero_rounds_needed = ceil(monster_health, hero_damage);
        const auto rounds_survived = ceil(hero_health, monster_damage);
        // as hero attacks first, they can win if the #rounds is equal
        return hero_rounds_needed <= rounds_survived;
    };

    for (int weapon_upgrades = 0; weapon_upgrades <= total_upgrades; weapon_upgrades++)
    {
        const auto armor_upgrades = total_upgrades - weapon_upgrades;
        const auto new_hero_damage = hero_damage + weapon_upgrades * w;
        const auto new_hero_health = hero_health + armor_upgrades * a;
        if (SlaysMonster(new_hero_health, new_hero_damage))
        {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
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