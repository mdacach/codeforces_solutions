#include <bits/stdc++.h>

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s; std::cin >> s;
    int n = s.size();
    int cnt = 0;
    int removed = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            cnt++;
        else
        {
            if (cnt > 0) cnt--;
            else removed++;
        }
    }
    std::cout << n - (removed + cnt) << "\n";

    return 0;
}
