#include <bits/stdc++.h>

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::vector<int> values(n);
    for (int i = 0; i != n; ++i)
        std::cin >> values[i];
    std::multiset<int> worst_potions_drank;
    int64_t current_hp = 0;
    int total_potions = 0;
    auto DrinkPotion = [&current_hp, &total_potions](const auto& potion)
    {
        current_hp += potion; // note potion can be negative
        total_potions++;
    };
    auto TrySwap = [&worst_potions_drank, &current_hp](const auto& potion)
    {
        if (worst_potions_drank.empty())
            return;
        const auto& worst = worst_potions_drank.begin();
        if (potion > *worst)
        {
            current_hp += -(*worst - potion);
            worst_potions_drank.erase(worst);
            worst_potions_drank.insert(potion);
        }
    };
    for (int i = 0; i != n; i++)
    {
        const auto current_potion = values[i];
        if (current_potion >= 0)
            DrinkPotion(current_potion);
        else
        {
            // can we just drink it?
            if (current_hp + current_potion >= 0)
            {
                DrinkPotion(current_potion);
                worst_potions_drank.insert(current_potion); // it may be swapped out later
            }
            else
                TrySwap(current_potion);
        }
    }
    std::cout << total_potions << '\n';
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