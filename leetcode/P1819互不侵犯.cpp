#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <climits>
#include <bitset>
#include <cstring>
#include <cmath>

using namespace std;

long long f[15][2005][105], sit[2005], sta[2005];
int N, K, cnt = 0;

int conflict(int i, int j) {
    int x = sit[i], y = sit[j];
    if (x & y) return true;
    if (x & (y << 1)) return true;
    if (x & (y >> 1)) return true;
    return false;
}


int main() {

    scanf("%d%d", &N, &K);
    int nums = 1 << N;
    for (int i = 0; i < nums; i++) {
        if ((i & (i << 1)) == 0 && (i & (i >> 1)) == 0) {
            cnt++;
            sit[cnt] = i;
            int kingCnt = 0;
            int temp = i;
            while(temp != 0) {
                if (temp%2 == 1) {
                    kingCnt++;
                }
                temp >>= 1;
            }
            sta[cnt] = kingCnt;
        }
    }

    for (int j = 1; j <= cnt; j++) {
        f[1][j][sta[j]] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int x = 1; x <= cnt; x++) {
            for (int y = 1; y <= cnt; y++) {
                if (conflict(x, y)) { continue; }
                for (int j = sta[x]; j <= K; j++) {
                    f[i][x][j] += f[i-1][y][j - sta[x]];
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= cnt; i++) {
        ans += f[N][i][K];
    }

    cout << ans;


    return 0;
}
