#include <bits/stdc++.h>

#define int int64_t

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--)
    {
        int x0; std::cin >> x0;
        int n; std::cin >> n;
        int rmd = n % 4;
        int diff = 0;
        if (rmd == 0) diff = 0;
        else if (rmd == 1) diff = -n;
        else if (rmd == 2) diff = 1;
        else diff = n + 1;
        if (x0 % 2) diff = -diff;
        std::cout << x0 + diff << '\n';
    }


    return 0;
}
