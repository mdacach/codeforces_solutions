#include <bits/stdc++.h>

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--)
    {
        std::string alphabet; std::cin >> alphabet;
        std::string s; std::cin >> s;
        int ans = 0;
        std::map<char, int> char_to_pos;
        for (int i = 0; i < alphabet.size(); i++) char_to_pos[alphabet[i]] = i;
        int pos = char_to_pos[s[0]];
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            ans += std::abs(char_to_pos[s[i]] - pos);
            pos = char_to_pos[s[i]];
        }
        std::cout << ans << "\n";
    }

    return 0;
}
