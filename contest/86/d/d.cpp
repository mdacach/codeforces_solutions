// https://codeforces.com/contest/86/problem/D
// with Hilbert order: https://codeforces.com/blog/entry/61203
#include <bits/stdc++.h>

//#define int int64_t

const int BLOCK_SIZE = 450;

struct Query
{
    int left, right, block, index;

    Query() = delete; // testing this
    Query(int l, int r, int i) : left{ l }, right{ r }, block{ l / BLOCK_SIZE }, index{ i } {}

    bool operator<(const Query& other) const
    {
        const int this_block = block;
        const int other_block = other.block;
        if (this_block != other_block)
            return this_block < other_block;
        else // testing parity
            return this_block % 2  == 0 ? right < other.right : right > other.right;
    };
}; // what?

struct Answer
{
    std::array<int, static_cast<int>(1e6 + 5)> frequency{};
    int64_t sum = 0;

    void insert(int x)
    {
        const auto previous_frequency = frequency[x];
        const auto previous_contribution = 1LL * previous_frequency * previous_frequency * x;
        const auto new_contribution = 1LL * (previous_frequency + 1) * (previous_frequency + 1) * x;
        frequency[x]++;
        sum += new_contribution - previous_contribution;
    }

    void remove(int x)
    {
        assert(frequency[x]);
        const auto previous_frequency = frequency[x];
        const auto previous_contribution = 1LL * previous_frequency * previous_frequency * x;
        const auto new_contribution = 1LL * (previous_frequency - 1) * (previous_frequency - 1) * x;
        frequency[x]--;
        sum += new_contribution - previous_contribution;
    }
};

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t;
    std::cin >> n >> t;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::vector<Query> queries;
    queries.reserve(t);
    for (int query_index = 0; query_index < t; query_index++)
    {
        int l, r;
        std::cin >> l >> r;
        queries.emplace_back(l, r, query_index);
    }
    std::sort(queries.begin(), queries.end());
    std::vector<int64_t> answers(t);
    int current_left = 0;
    int current_right = 0;
    Answer answer;
    for (const auto &[this_left, this_right, block, index] : queries)
    {
        for (int r = current_right + 1; r <= this_right; r++)
            answer.insert(a[r]);
        for (int l = current_left - 1; l >= this_left; l--)
            answer.insert(a[l]);
        for (int l = current_left; l < this_left; l++)
            if (l)
                answer.remove(a[l]);
        for (int r = current_right; r > this_right; r--)
            answer.remove(a[r]);
        current_left = this_left;
        current_right = this_right;
        answers[index] = answer.sum;
    }
    for (const auto& x : answers)
        std::cout << x << "\n";

    return 0;
}