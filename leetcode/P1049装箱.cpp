#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <climits>
#include <bitset>

using namespace std;

bitset<20001> bits;

int main() {
    int V, N;
    scanf("%d%d", &V, &N);

    bits[0] = true;

    int a;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);

        bits = bits | (bits << a);
    }

    for (int i = V; i >= 0; i--) {
        if (bits[i]) {
            printf("%d", V-i);
            return 0;
        }
    }

    return 0;
}
