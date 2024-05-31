#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <climits>
#include <bitset>
#include <cstring>

using namespace std;

int iq[403];
int eq[403];

int f[2][800003];

int main() {
    int N;
    int maxeq = 0;
    int mineq = 0;
    int offset = 40000;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &iq[i], &eq[i]);
        if (eq[i] > 0) {
            maxeq += eq[i];
        } else {
            mineq += eq[i];
        }
    }

    memset(f, ~0x3f, sizeof(f));
//    for (int i = offset + mineq; i <= offset + maxeq; i++) {
//        f[0][i] = 0;
//    }

    f[0][offset] = 0;
    int k = 0;
    for (int i = 1; i <= N; i++) {
        k = 1-k;
        for (int j = offset + maxeq; j >= offset + mineq; j--) {
            f[k][j] = f[1-k][j];
            if ((j - eq[i-1]) <= offset + maxeq && (j - eq[i-1]) >= offset + mineq) {
                f[k][j] = max(f[k][j], f[1-k][j - eq[i-1]] + iq[i-1]);
            }
        }
    }

    int ans = 0;
    int index = N%2;

//    cout << maxeq << " " << mineq << endl;

    for (int j = offset + maxeq; j >= offset + mineq; j--) {
//        cout << j - offset << ": " << f[index][j] << endl;

        if (f[index][j] >= 0 && j - offset >= 0) {
            ans = max(ans, f[index][j] + j - offset);
        }
    }

    printf("%d", ans);

    return 0;
}
