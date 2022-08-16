#include <bits/stdc++.h>

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s; std::cin >> s;
    std::map<char, std::set<int>> char_to_pos;
    for (int i = 0; i < s.size(); i++)
        char_to_pos[s[i]].insert(i);
    int q; std::cin >> q;
    while (q--) {
        int type; std::cin >> type;
        if (type == 1)
        {
            int pos; char c;
            std::cin >> pos >> c;
            char_to_pos[s[pos-1]].erase(pos-1);
            s[pos-1] = c;
            char_to_pos[c].insert(pos-1);
        } else
        {
            int l, r;
            std::cin >> l >> r;
            int count = 0;
            for (const auto& [letter, positions] : char_to_pos)
            {
                const auto where = positions.lower_bound(l-1);
                if (where != positions.end() && *where < r) count++;
            }
            std::cout << count << "\n";
        }
    }

    return 0;
}
