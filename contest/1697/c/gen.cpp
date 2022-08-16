#include <bits/stdc++.h>

// generate a random number in [a, b]
int rand(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[])
{
    // seed the randomness
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int t = 1;
    int n = 3;
    std::cout << t << '\n' << n << '\n';
    for (int i = 0; i < n; ++i)
    {
        int r = rand(0, 2);
        std::cout << char('a' + r);
    }
    std::cout << '\n';
    for (int i = 0; i < n; ++i)
    {
        int r = rand(0, 2);
        std::cout << char('a' + r);
    }
    std::cout << '\n';
}
