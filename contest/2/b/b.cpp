#include <bits/stdc++.h>

#define int int64_t

const int N = 1010;
const int INF = 1e9;

int matrix[N][N];
int twos[N][N];
int fives[N][N];
int min_twos[N][N];
int min_fives[N][N];

struct Answer
{
    int trailing_zeros;
    std::string way;
};

auto solve(int n) -> Answer
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int temp = matrix[i][j];
            while (temp % 2 == 0)
            {
                temp /= 2;
                twos[i][j]++;
            }
            while (temp % 5 == 0)
            {
                temp /= 5;
                fives[i][j]++;
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            min_twos[i][j] = INF;
            min_fives[i][j] = INF;
        }
    }
    min_twos[0][1] = 0;
    min_fives[1][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            min_twos[i][j] = std::min(min_twos[i - 1][j], min_twos[i][j - 1]) + twos[i][j];
            min_fives[i][j] = std::min(min_fives[i - 1][j], min_fives[i][j - 1]) + fives[i][j];
        }
    }

    const auto& table = min_twos[n][n] < min_fives[n][n] ? min_twos : min_fives;
    const auto& numbers = min_twos[n][n] < min_fives[n][n] ? twos : fives;
    int parent_x = n;
    int parent_y = n;
    std::string way;
    while (parent_x != 1 || parent_y != 1)
    {
        // if going back is a valid transition, we have an answer that way
        const auto current_answer = table[parent_x][parent_y];
        const auto current_number = numbers[parent_x][parent_y];
        if (parent_x > 1 && table[parent_x - 1][parent_y] + current_number == current_answer)
        {
            parent_x--;
            way.push_back('D');
        }
        else if (parent_y > 1 && table[parent_x][parent_y - 1] + current_number == current_answer)
        {
            parent_y--;
            way.push_back('R');
        }
        else
        {
            assert(false); // we should have a way always
        }
    }

    std::reverse(way.begin(), way.end());
    return { table[n][n], way };
}

auto with_zero(int n) -> Answer
{
    int zero_x = -1;
    int zero_y = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (matrix[i][j] == 0)
            {
                zero_x = i;
                zero_y = j;
                break;
            }
        }
    }
    assert(zero_x != -1);
    int cur_x = 1;
    int cur_y = 1;
    std::string way;
    for (; cur_x < zero_x; cur_x++)
        way.push_back('D');
    for (; cur_y < zero_y; cur_y++)
        way.push_back('R');
    for (; cur_x < n; cur_x++)
        way.push_back('D');
    for (; cur_y < n; cur_y++)
        way.push_back('R');
    return { 1, way };
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    bool has_zero = false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> matrix[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            has_zero = has_zero || matrix[i][j] == 0;

    if (!has_zero)
    {
        auto answer = solve(n); // uses matrix
//        std::cout << answer.trailing_zeros << "\n";
        std::cout << answer.trailing_zeros << "\n" << answer.way << "\n";
    } else
    {
        auto answer_with_zero = with_zero(n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                matrix[i][j] = matrix[i][j] == 0 ? 10 : matrix[i][j];
        auto answer = solve(n); // uses matrix
        if (answer.trailing_zeros > 0)
            answer = answer_with_zero;
//        std::cout << answer.trailing_zeros << "\n";
        std::cout << answer.trailing_zeros << "\n" << answer.way << "\n";
    }



    return 0;
}