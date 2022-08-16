#include <bits/stdc++.h>

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto&& x : a) std::cin >> x;
    int increasing_left = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i-1]) increasing_left++;
        else break;
    }
    int increasing_right = 1;
    for (int i = n-2; i >= 0; i--)
    {
        if (a[i] > a[i+1]) increasing_right++;
        else break;
    }
    if (increasing_left % 2 || increasing_right % 2) std::cout << "Alice\n";
    else std::cout << "Bob\n";

    return 0;
}
