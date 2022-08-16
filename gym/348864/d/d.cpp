#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::map<int, int> topic_counter;
    std::map<int, int> diff_counter;
    std::vector<std::pair<int, int>> problems;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        topic_counter[a]++;
        diff_counter[b]++;
        problems.emplace_back(a, b);
    }

    int64_t all_triples = 1LL * n * (n-1) * (n-2) / 6;
    int64_t bad_triples = 0;
    for (auto [a, b] : problems) {
        // when this problem is the "middling" problem
        // we have a problem with the same topic and
        // another with the same difficulty
        // note they can't be equal
        bad_triples += 1LL * (topic_counter[a] - 1) * (diff_counter[b] - 1); // remove this
    }
    std::cout << all_triples - bad_triples << "\n";
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) solve();


    return 0;
}
