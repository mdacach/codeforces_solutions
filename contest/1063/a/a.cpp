#include <bits/stdc++.h>

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;
    std::string s; std::cin >> s;
    std::sort(s.begin(), s.end());
    std::cout << s << "\n";

    return 0;
}
