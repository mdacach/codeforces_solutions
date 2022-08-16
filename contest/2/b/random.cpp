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
    int n = rand(1, 5);
    printf("%d\n", n);
    set<int> used;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; j++)
        {
            int x = rand(1, 100);
            printf("%d ", x);
        }
        printf("\n");
    }
}