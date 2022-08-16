#include <bits/stdc++.h>

int rand(int a, int b) {
    return a + rand() % (b - a + 1);

}
auto main(int argc, char* argv[]) -> int32_t 
{
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int last = 0;
    int cnt = 0;
    while (cnt < 4) {
        int next = -1;
        while (next < last) {
            next = rand(2, 5);
        }
        std::cout << next << " ";
        last = next;
        cnt++;
    }
}