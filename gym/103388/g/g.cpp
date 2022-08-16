#include <bits/stdc++.h>

#define int int64_t

const int MAX = 1e15 + 10;

std::vector<int> fib{ 2, 3 };
std::vector<int> ans;
std::map<int, int> fib_to_As;

void build_answer()
{
    std::string res;
    for (auto x : ans)
    {
        res += std::string(fib_to_As[x], 'A');
        res += 'B';
    }
    std::cout << res << "\n";
}

void find_fib_factors(int n, std::size_t index)
{
    if (index >= fib.size())
        return;
    if (n == 1)
    {
        build_answer();
        exit(0);
    }
    const auto current_fib = fib[index];
    if (n % current_fib == 0)
    {
        ans.push_back(current_fib);
        find_fib_factors(n / current_fib, index);
        find_fib_factors(n / current_fib, index + 1);
        ans.pop_back();
    }
    find_fib_factors(n, index + 1);
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a = 2;
    fib_to_As[2] = 1;
    int b = 3;
    fib_to_As[3] = 2;
    int cnt = 3;
    while (b < MAX)
    {
        int t = a;
        a = b;
        b = a + t;
        fib.push_back(b);
        fib_to_As[b] = cnt++;
    }
    std::reverse(fib.begin(), fib.end());

    int n;
    std::cin >> n;
    if (n == 1)
        std::cout << "B\n";
    else
        find_fib_factors(n, 0);
    std::cout << "IMPOSSIBLE\n";

    return 0;
}