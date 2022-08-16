#include <bits/stdc++.h>

auto simulate(int rolls) -> bool
{
    //    std::random_device rd;                       // obtain a random number from hardware
    //    std::mt19937 gen(rd());                      // seed the generator
    //    std::uniform_int_distribution<> distr(1, 6); // define the range

    std::array<int, 7> values{};
    for (int n = 0; n < rolls; ++n)
    {
        //        int value = distr(gen);
        int value = 1 + (std::rand() % (6 - 1 + 1));
        ++values[value];
    }

    for (int v = 2; v <= 6; ++v)
        if (values[v] > values[v - 1])
            return false;
    return true;
}

auto solve() -> void
{
    int rolls = 1;
    std::cin >> rolls;
    int64_t total = 10000000;
    int correct = 0;
    for (int64_t i = 0; i < total; ++i)
        correct += simulate(rolls);
    std::cout << std::fixed << std::setprecision(9);
    std::cout << (long double) correct / total << '\n';
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