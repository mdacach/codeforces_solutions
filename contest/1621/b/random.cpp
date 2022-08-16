// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    std::cout << 1 << '\n';
    int n = rand(2, 4);
    printf("%d\n", n);
    for(int i = 0; i < n; ++i) {
        int l = rand(1, 10);
        int r = rand(l, 10);
        int c = rand(1, 10);
        std::cout << l << " " << r << " " << c << '\n';
    }
    puts("");
}