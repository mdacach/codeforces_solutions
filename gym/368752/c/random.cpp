// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[])
{
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(2, 4);
    int l = rand(15, 20);
    int k = rand(0, n - 1);
    std::cout << n << " " << l << " " << k << '\n';
    std::cout << 0 << " ";
    bool correct = false;
    while (!correct)
    {
        int prv = 0;
        std::vector<int> coords;
        for (int i = 0; i + 1 < n; ++i)
        {
            int s = rand(prv + 1, l);
            prv = s;
            coords.push_back(s);
            if (s == l)
                break;
        }
        if (coords.back() != l)
        {
            correct = true;
            for (auto x : coords)
                std::cout << x << " ";
            std::cout << '\n';
        }
    }

    for (int i = 0; i < n; ++i)
    {
        int s = rand(1, 10);
        std::cout << s << " ";
    }
    puts("");
}