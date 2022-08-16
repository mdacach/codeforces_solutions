#include <bits/stdc++.h>

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) {
      std::string s; std::cin >> s;
      std::map<char, int> count;
      for (auto x : s) count[x]++;
      std::cout << (count['A'] + count['C'] == count['B'] ? "YES" : "NO") << "\n";
    }


    return 0;
}
